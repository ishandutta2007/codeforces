#include<stdio.h>
char s[1000100];
int f(int x){
    if(x<10)return 0;
    int an=0;
    while(x){
        an+=x%10;
        x/=10;
    }
    return f(an)+1;
}
main(){
    int i,an;
    while(gets(s)!=NULL){
        if(!s[1]){
            puts("0");
        }
        else{
            an=0;
            for(i=0;s[i];i++)an+=s[i]-'0';
            printf("%d\n",f(an)+1);
        }
    }
}