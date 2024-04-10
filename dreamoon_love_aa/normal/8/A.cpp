#include<stdio.h>
#include<string.h>
char s1[100010],s2[100010],a[110],b[110];
int len,len_a,len_b;
bool Go(char s[]){
    int i,j;
    for(i=0;i<=len-len_a;i++){
        for(j=0;j<len_a;j++)
            if(s[i+j]!=a[j])break;
        if(j==len_a)break;
    }
    if(i>len-len_a)return 0;
    i+=len_a;
    for(;i<=len-len_b;i++){
        for(j=0;j<len_b;j++)
            if(s[i+j]!=b[j])break;
        if(j==len_b)break;
    }
    if(i<=len-len_b)return 1;
    return 0;
}
main(){
    int i;
    bool flag1,flag2;
    gets(s1);
    gets(a);
    gets(b);
    len=strlen(s1);
    len_a=strlen(a);
    len_b=strlen(b);
    for(i=0;i<len;i++)s2[i]=s1[len-1-i];
    flag1=Go(s1);
    flag2=Go(s2);
    if(flag1&&flag2)puts("both");
    else if(flag1)puts("forward");
    else if(flag2)puts("backward");
    else puts("fantasy");
}