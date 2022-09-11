#include<stdio.h>
#include<stdlib.h>
bool remove_zero(char s[]){
    int i,j;
    for(i=j=0;s[i];i++){
        if(s[i]!='0')s[j++]=s[i];
    }
    s[j]=0;
}
main(){
    char s1[32],s2[32],s3[32];
    int a,b,c,aa,bb,cc;
    scanf("%s%s",s1,s2);
    a=atoi(s1);
    b=atoi(s2);
    c=a+b;
    sprintf(s3,"%d",c);
    remove_zero(s1);
    remove_zero(s2);
    remove_zero(s3);
    aa=atoi(s1);
    bb=atoi(s2);
    cc=atoi(s3);
    if(aa+bb==cc)puts("YES");
    else puts("NO");
}