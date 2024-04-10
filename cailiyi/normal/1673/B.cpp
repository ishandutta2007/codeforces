#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,tot;
char s[N+5];
bool vis[26];
inline bool check()
{
    tot=0,memset(vis,0,sizeof vis);
    for(n=0;s[n];++n) if(!vis[s[n]-'a']) vis[s[n]-'a']=1,++tot;
    for(int i=tot;i<n;++i) if(s[i-tot]!=s[i]) return false;
    return true;
}
int main()
{
    scanf("%d",&T);
    while(T--) scanf("%s",s),puts(check()?"YES":"NO");
    return 0;
}