#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
vector<int> G[maxn];
int val[maxn];
long long tot=-0x3f3f3f3f,cnt=0;
long long dfs(int u,int fa)
{
    long long ret=0;
    ret=val[u];
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa) continue;
        ret+=max(0LL,dfs(v,u));
    }
    tot=max(tot,ret);
    return ret;
}
long long dfs2(int u,int fa)
{
    long long ret=0;
    ret=val[u];
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa) continue;
        ret+=max(0LL,dfs2(v,u));
    }
    if(ret==tot)
    {
        cnt++;
        ret=0;
    }
    return ret;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
    }
    for(int i=0,u,v;i<n-1;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1);
    dfs2(1,-1);
    printf("%lld %lld\n",tot*cnt,cnt);
}