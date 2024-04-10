#include<stdio.h>
#include<string.h>
main(){
    int n,len;
    char s[128];
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        len=strlen(s);
        if(len>10)
            printf("%c%d%c\n",s[0],len-2,s[len-1]);
        else printf("%s\n",s);
    }
}