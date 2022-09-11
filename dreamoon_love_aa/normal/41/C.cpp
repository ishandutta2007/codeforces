#include<stdio.h>
#include<string.h>
main(){
    int i,u=0;
    char s[999];
    scanf("%s",s);
    putchar(s[0]);
    for(i=1;s[i];i++){
        if(strncmp(s+i,"at",2)==0&&s[i+2]&&!u){
            putchar('@');
            u=1;
            i++;
        }
        else if(strncmp(s+i,"dot",3)==0&&s[i+3]){
            putchar('.');
            i+=2;
        }
        else putchar(s[i]);
    }
    puts("");
}