#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+7;
typedef long long ll;
typedef pair<int,ll> pi;
pi dp[maxn][maxn],g[maxn];
int a[maxn];
int n,m;
typedef vector<int> vi;
vi G[maxn];
int sz[maxn];
void dfs(int u,int fa=-1)
{
    sz[u]=1;
    for(int i=0;i<=n;i++) dp[u][i]={-1e6,-1e15};
    dp[u][0]={0,a[u]};
    for(auto v:G[u])if(v!=fa)
    {
        dfs(v,u);
        for(int i=0;i<=min(m,sz[u]+sz[v]);i++) g[i]={-1e6,-1e15};
        for(int i=0;i<=min(sz[u],m)-1;i++)
        {
            for(int j=0;j+i<m&&j<=sz[v]-1;j++)
            {
                pi &c=dp[u][i],son=dp[v][j];
                pi mrg={c.first+son.first,c.second+son.second};
                g[i+j]=max(g[i+j],mrg);
                if(i+j+1<m)
                {
                    mrg={c.first+son.first+(son.second>0),c.second};
                    g[i+j+1]=max(g[i+j+1],mrg);
                }
            }
        }
        for(int i=0;i<min(m,sz[u]+sz[v]);i++) dp[u][i]=g[i];
        sz[u]+=sz[v];
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1,tmp;i<=n;i++)
        {
            G[i].clear();
            cin>>tmp;
            a[i]=tmp-a[i];
        }
        for(int i=0,u,v;i<n-1;i++)
        {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1);
        int ans=dp[1][m-1].first+(dp[1][m-1].second>0);
        cout<<ans<<'\n';
    }
}