#include<cstdio>
char s[1000000];
int main(){
    gets(s);
    int a=0;
    int b=0;
    for(int i=0;s[i];i++){
        b=a;
        a=s[i]-'0';
    }
    puts((b*10+a)%4?"0":"4");
}