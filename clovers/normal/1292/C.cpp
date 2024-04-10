#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mk make_pair
const int N=3005;
int n,sz[N],id[N];
bool vis[N][N];
vector<int> v[N];
int mx=0;

int fa[N],nxt[N][N];
int in[N],out[N],cnt=0;
long long dp[N][N],dep[N];
vector<int> len[N][N];
long long ans=0;
void dfs1(int u,int f,int flag)
{
    if(flag==1) sz[u]=1, in[u]=++cnt, id[cnt]=u;
    for(int i=0;i<(int)v[u].size();i++)
    {
        int to=v[u][i];
        if(to==f) continue;
        dep[to]=dep[u]+1;
        if(flag==1) fa[to]=u;
        dfs1(to,u,flag);
        if(flag==1)
        {
            sz[u]+=sz[to];
            dp[to][u]=sz[to]*(n-sz[to]);
            dp[u][to]=dp[to][u];
            ans=max(ans,dp[u][to]);
        }
    }
    if(flag==1)
    {
        int now=fa[u];
        while(now!=-1&&fa[now]!=-1)
        {
            nxt[fa[now]][u]=now;
            now=fa[now];
        } 
        out[u]=cnt;
    }
}

void init()
{
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        v[x].push_back(y); v[y].push_back(x);
    }
}

pii a[N];
bool isfa(int x,int y)
{
    if(dep[x]>dep[y]) swap(x,y);
    return in[x]<=in[y]&&out[x]>=out[y];
}

int main()
{
    init(); fa[1]=-1; 
    for(int i=n;i>=1;i--)
    {
        dep[i]=0;
        dfs1(i,-1,i);
        for(int j=1;j<=n;j++) 
        {
        	if(i!=j) len[i][dep[j]].push_back(j);
        	//cout<<i<<" "<<dep[j]<<" "<<j<<endl;
        }
    }
    for(int L=2;L<n;L++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<(int)len[i][L].size();j++)
            {
                int tmpx=i,tmpy=len[i][L][j];
                if(isfa(tmpx,tmpy)) 
                {
                    if(dep[tmpx]>dep[tmpy]) swap(tmpx,tmpy);
                    dp[tmpx][tmpy]=(n-sz[nxt[tmpx][tmpy]])*sz[tmpy];
                    dp[tmpx][tmpy]+=max(dp[tmpx][fa[tmpy]],dp[nxt[tmpx][tmpy]][tmpy]);
                }
                else
                {
                    dp[tmpx][tmpy]=sz[tmpx]*sz[tmpy];
                    dp[tmpx][tmpy]+=max(dp[tmpx][fa[tmpy]],dp[fa[tmpx]][tmpy]);
                }
                dp[tmpy][tmpx]=dp[tmpx][tmpy];
                ans=max(ans,dp[tmpx][tmpy]);
                //cout<<tmpx<<" "<<tmpy<<" "<<L<<" "<<dp[tmpx][tmpy]<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}