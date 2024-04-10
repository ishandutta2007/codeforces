#include<stdio.h>
#include<string.h>
char s[1024][1024];
void put(char c,int x){
    while(x--)putchar(c);
}
main(){
    int i,l[1024],n=0,ma=0,u=0;
    while(gets(s[n])!=NULL){
        l[n]=strlen(s[n]);
        if(l[n]>ma)ma=l[n];
        n++;
    }
    put('*',ma+2);
    puts("");
    for(i=0;i<n;i++){
        putchar('*');
        if((ma-l[i])&1){
            if(!u)
                put(' ',(ma-l[i])/2);
            else
                put(' ',(ma-l[i]+1)/2);
        }
        else
            put(' ',(ma-l[i])/2);
        printf("%s",s[i]);
        if((ma-l[i])&1){
            if(!u)
                put(' ',(ma-l[i]+1)/2);
            else
                put(' ',(ma-l[i])/2);
                u^=1;
        }
        else
            put(' ',(ma-l[i])/2);
        puts("*");
    }
    put('*',ma+2);
    puts("");
}