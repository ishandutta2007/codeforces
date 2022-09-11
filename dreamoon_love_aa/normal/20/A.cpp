#include<stdio.h>
main(){
    int i,r=0;
    char s[110];
    scanf("%s",s);
    for(i=0;s[i];i++){
        if(s[i]=='/'){
            while(s[i+1]=='/')i++;
            if(s[i+1]){
                putchar('/');
                r=1;
            }
        }
        else{
            putchar(s[i]);
            r=1;
        }
    }
    if(r==0)putchar('/');
    puts("");
}