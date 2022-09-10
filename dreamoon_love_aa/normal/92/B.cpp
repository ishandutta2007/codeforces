#include<stdio.h>
#include<string.h>
char s[1000100];
main(){
    int i,an=0,re=0;
    scanf("%s",s);
    for(i=strlen(s)-1;i>=0;i--){
        re+=s[i]-'0';
        if(re%2==0)an++,re>>=1;
        else if(i==0){
            break;
        }
        else{
            an+=2;
            re=(re+1)/2;
        }
    }
    while(re>1){
        if(re&1){
            re++;
            an+=2;
            re>>=1;
        }
        else{
            an++;
            re>>=1;
        }
    }
    printf("%d\n",an);
}