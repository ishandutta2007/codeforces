#include<stdio.h>
#include<stdlib.h>
int f(char s[]){
    int v;
    v=(atoi(s+1)%12)*60+atoi(s+4);
    if(s[7]=='p')v+=12*60;
    return v;
}
main(){
    char s[128];
    int n,last,now,an=1,cou=1;
    gets(s);
    n=atoi(s);
    last=0;
    while(n--){
        gets(s);
        now=f(s);
        if(now<last)an++;
        if(now==last){
            cou++;
            if(cou>10)an++,cou=1;
        }
        else cou=1;
        last=now;
    }
    printf("%d\n",an);
}