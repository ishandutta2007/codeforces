#include<stdio.h>
#include<string.h>
char s[110];
main(){
    int len=0,i=0,j=0,k,an=0;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
        for(j=i+1;j<len;j++){
            for(k=0;j+k<len&&s[i+k]==s[j+k];k++);
            if(an<k)an=k;
        }
    printf("%d\n",an);
}