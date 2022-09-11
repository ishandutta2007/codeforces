#include<stdio.h>
#include<string.h>
main(){
    int len,i;
    char s1[111],s2[111];
    scanf("%s%s",s1,s2);
    len=strlen(s1);
    if(strlen(s2)!=len){
        puts("NO");
    }
    else{
        for(i=0;i<len;i++){
            if(s1[i]!=s2[len-1-i])break;
        }
        if(i<len)puts("NO");
        else puts("YES");
    }
}