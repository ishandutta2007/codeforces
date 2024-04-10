#include<stdio.h>
#include<string.h>
int d[10];
main(){
    int i,j;
    char s1[99],s2[99],s3[99];
    gets(s1);
    gets(s2);
    for(i=0;s1[i];i++)d[s1[i]-'0']++;
    for(i=1;i<10&&!d[i];i++);
    j=0;
    if(i<10){
        s3[j++]=i+'0';
        d[i]--;
    }
    else{
        s3[j++]='0';
        d[0]--;
    }
    for(i=0;i<10;i++){
        while(d[i]){
            d[i]--;
            s3[j++]=i+'0';
        }
    }
    s3[j]=0;
    if(strcmp(s2,s3))puts("WRONG_ANSWER");
    else puts("OK");
}