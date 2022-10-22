#include<bits/stdc++.h>
#define N 100000
using namespace std;
int T,n,st[N+5],top,ans;
char s[N*2+5];
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %s",&n,s+1),ans=1;
        for(int i=1;i<=n*2;++i)
            if(s[i]=='(') st[++top]=i;
            else ans+=s[st[top--]+1]=='(' && s[i-1]==')';
        printf("%d\n",ans);
    }
    return 0;
}