#include<stdio.h>
bool small(char c){return c>='a'&&c<='z';}
main(){
    int i,n=0;
    char s[999];
    scanf("%s",s);
    for(i=0;s[i];i++)
        if(small(s[i]))n++;
    if(n*2>=i){
        for(i=0;s[i];i++)
            if(!small(s[i]))s[i]+='a'-'A';
    }
    else{
        for(i=0;s[i];i++)
            if(small(s[i]))s[i]+='A'-'a';
    }
    puts(s);
}