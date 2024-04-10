#include<stdio.h>
#include<string.h>
main(){
    int i,j,k;
    char s[99];
    char input[10][99];
    scanf("%s",s);
    for(i=0;i<10;i++){
        scanf("%s",input[i]);
    }
    for(i=0;i<8;i++){
        for(j=0;j<10;j++){
            char c=s[i*10+10];
            s[i*10+10]=0;
            if(strcmp(s+i*10,input[j])==0){
                s[i*10+10]=c;
                break;
            }
            s[i*10+10]=c;
        }
        printf("%d",j);
    }
    puts("");
}