#include<bits/stdc++.h>
#define N 1000
#define mod 998244353
using namespace std;
int T,n,m,a[N+5],in[N+5];
vector<int> e[N+5];
inline int solve()
{
    for(int i=1;i<=n;++i)
    {
        vector<int> s;
        for(int j=1;j<=n;++j)
            if(a[j]) s.push_back(j);
        if(s.empty()) return i-1;
        for(int x:s) {--a[x];for(int y:e[x]) ++a[y];}
    }
    queue<int> q;
    for(int i=1;i<=n;++i) if(!in[i]) q.push(i);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int y:e[x])
        {
            a[y]=(a[x]+a[y])%mod;
            if(!(--in[y])) q.push(y);
        }
    }
    for(int i=1;i<=n;++i) if(e[i].empty()) return (n+a[i])%mod;
    return 0;
}
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i) scanf("%d",a+i),e[i].clear(),in[i]=0;
        for(int i=1,u,v;i<=m;++i) scanf("%d %d",&u,&v),e[u].push_back(v),++in[v];
        printf("%d\n",solve());
    }
    return 0;
}