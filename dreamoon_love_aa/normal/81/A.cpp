#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
char s[200010];
stack<char>a;
main(){
    int i,len;
    gets(s);
    len=strlen(s);
    for(i=0;i<len;i++){
        if(!a.empty()&&a.top()==s[i]){
            a.pop();
        }
        else a.push(s[i]);
    }
    for(i=0;!a.empty();i++){
        s[i]=a.top();
        a.pop();
    }
    for(i--;i>=0;i--)putchar(s[i]);
    puts("");
}