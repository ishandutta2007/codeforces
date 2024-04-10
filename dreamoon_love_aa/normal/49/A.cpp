#include<stdio.h>
#include<string.h>
char s[1111];
bool cc(char c){
    return (c>='A'&&c<='Z')||(c>='a'&&c<='z');
}
char t[99]="AEIOUYaeiouy";
bool f(char c){
    int i;
    for(i=0;i<12;i++)
        if(c==t[i])return 1;
    return 0;
}
main(){
    gets(s);
    int i,len=strlen(s);
    for(i=len;i>=0&&!cc(s[i]);i--);
    if(f(s[i]))puts("YES");
    else puts("NO");
}