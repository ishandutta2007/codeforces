#include<stdio.h>
#include<string.h>
char s[110],an[110];
bool used[110][27];
main(){
    int i,n,len;
    char o[110];
    bool zero=0;
    scanf("%s%d",o,&n);
    len=strlen(o);
    while(n--){
        scanf("%s",s);
        if(strncmp(s,o,len)==0){
            if(!zero){
                zero=1;
                strcpy(an,s);
            }
            else{
                if(strcmp(s,an)<0)strcpy(an,s);
            }
        }
    }
    if(!zero)strcpy(an,o);
    puts(an);
}