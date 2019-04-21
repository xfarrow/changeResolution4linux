#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu(void);

int main(void){
    menu();
    return 0;   
}

void menu(void){
    int selector;
    char resolutionPicker[16];
    char resolutionToSystem[64];
    char outputName[16];
    strcpy(outputName,"VGA-1");
        do{
            printf("\n");
            printf("1. Display available resolutions\n");
            printf("2. Change resolution\n");
            printf("3. Change output name [default: VGA-1]\n");
            printf("4. Display current resolution\n");
            printf("5. Exit\n");
            fflush(stdin);
            scanf("%d",&selector);
            switch(selector){
                case 1:
                    printf("\n");
                    system("xrandr");
                    break;
                case 2:
                    printf("\n");
                    printf("Insert resolution: [EG 1920x1080]");
                    scanf("%s",resolutionPicker);
                    strcpy(resolutionToSystem,"xrandr --output ");
                    strcat(resolutionToSystem, outputName);
                    strcat(resolutionToSystem, " --mode ");
                    strcat(resolutionToSystem,resolutionPicker);
                    system(resolutionToSystem);
                    break;
                case 3:
                    printf("\n");
                    printf("Enter output name: ");
                    scanf("%s",outputName);
                break;
                case 4:
                    printf("\n");
                    system("xrandr | grep '*'");
                    printf("\n");
                break;
            }
    }while(selector!=5);
}

