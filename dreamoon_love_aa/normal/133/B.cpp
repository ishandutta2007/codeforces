#include<stdio.h>
#define MOD 1000003
main(){
    int i,now=0;
    char s[1024];
    gets(s);
    for(i=0;s[i];i++){
        now*=16;
        if(s[i]=='>')now+=8;
        if(s[i]=='<')now+=9;
        if(s[i]=='+')now+=10;
        if(s[i]=='-')now+=11;
        if(s[i]=='.')now+=12;
        if(s[i]==',')now+=13;
        if(s[i]=='[')now+=14;
        if(s[i]==']')now+=15;
        now%=MOD;
    }
    printf("%d\n",now);
}