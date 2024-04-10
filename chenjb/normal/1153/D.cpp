#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
using namespace std;
vector<int> g[510000];
int c[510000],dp[510000],son[510000];
void dfs(int u)
{
    if(g[u].size()==0)
    {
        son[u]=1; dp[u]=-1;
        return;
    }
    if(c[u])dp[u]=-510000;
    for(auto &v:g[u])
    {
        dfs(v);
        son[u]+=son[v];
        if(c[u])dp[u]=max(dp[u],dp[v]);
        else dp[u]+=dp[v];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=2;i<=n;i++)
    {
        int f;
        scanf("%d",&f);
        g[f].pb(i);
    }
    dfs(1);
    printf("%d\n",dp[1]+son[1]+1);
    return 0;
}