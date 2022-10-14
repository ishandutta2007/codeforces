#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int num=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) num*=10,num+=ch-48,ch=getchar();
    return num;
}
int x,y;
int main(){
    int n=read();
    for(int i=1; i<=n; i++) x|=read();
    for(int i=1; i<=n; i++) y|=read();
    printf("%d\n",x+y);
    return 0;
}