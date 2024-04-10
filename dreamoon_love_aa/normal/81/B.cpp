#include<stdio.h>
bool is_digit(char c){
    return c>='0'&&c<='9';
}
main(){
    char s[512],an[1024];
    int i,now=0;
    gets(s);
    for(i=0;s[i];){
        if(s[i]=='.'){
            i+=3;
            if(now&&an[now-1]!=' ')an[now++]=' ';
            an[now++]='.';
            an[now++]='.';
            an[now++]='.';
        }
        else if(is_digit(s[i])){
            if(now&&(an[now-1]==','||is_digit(an[now-1]))){
                an[now++]=' ';
            }
            while(is_digit(s[i])){
                an[now++]=s[i++];
            }
        }
        else if(s[i]==','){
            if(now&&an[now-1]==',')an[now++]=' ';
            an[now++]=',';
            i++;
        }
        else i++;
    }
    an[now]=0;
    puts(an);
}