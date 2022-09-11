#include<stdio.h>
#include<string.h>
#define SIZE 1000010
char s1[SIZE],s2[SIZE];
char v[SIZE];
int len,ann,an[SIZE];
bool left(int x){
    return x<0||(v[x]&1);
}
bool right(int x){
    return x==len||(v[x]&2);
}
main(){
    int i,p;
    gets(s1);
    gets(s2);
    len=strlen(s1);
    for(i=0;i<len;i++){
        if(s1[i]==s2[i])v[i]|=1;
        else break;
    }
    for(i=len-1;i>0;i--){
        if(s1[i]==s2[i-1])v[i]|=2;
        else break;
    }
    for(i=0;i<len;i++)
        if(left(i-1)&&right(i+1))an[ann++]=i+1;
    printf("%d\n",ann);
    if(ann){
        for(i=0;i<ann;i++){
            if(i)putchar(' ');
            printf("%d",an[i]);
        }
        puts("");
    }
}