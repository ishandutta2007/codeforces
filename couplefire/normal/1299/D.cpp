#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 605
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,tot;
void madd(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void mdec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
struct edge
{
    int u,v,w;
};
vector<edge> E;
vector<P> G[MAXN];
int mark[MAXN],val[MAXN],fa[MAXN];
map<ll,int> mp;
vector<int> adj;
vector<edge> cross;
int pre[MAXM][MAXM];
void dfs(int v,int p)
{
    fa[v]=p;
    for(auto e:G[v])
    {
        if(e.F==p||mark[e.F]) continue;
        val[e.F]=val[v]^e.S;
        mark[e.F]=mark[v];
        dfs(e.F,v);
    }
}
ll save[MAXN],bas[MAXN];
bool used[MAXN];
int dp[MAXM],ndp[MAXM];

int get_id(ll x)
{
    if(x&1) return -1;
    if(mp.find(x)==mp.end())
    {
        mp[x]=++tot;
        save[tot]=x;
    }
    return mp[x];
}
int go(int x,int y)
{
    if(x==-1||y==-1) return -1;
    ll sx=save[x],sy=save[y],ret=sx|sy;
    if(pre[x][y]) return pre[x][y];
    for(int i=0;i<32;i++)
    {
        if((sx>>i)&1)
        {
            for(int j=0;j<32;j++)
            {
                if((sy>>j)&1)
                {
                    ret|=(1LL<<(i^j));
                }
            }
        }
    }
    return pre[x][y]=get_id(ret);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(P(v,w)); G[v].push_back(P(u,w));
        E.push_back((edge){u,v,w});
    }
    for(auto e:G[1])
    {
        adj.push_back(e.F);
        mark[e.F]=e.F; 
        val[e.F]=e.S;
    }
    for(auto e:G[1]) dfs(e.F,1);
    memset(pre,0,sizeof(pre));
    mp[0]=1; save[1]=0; dp[1]=1;
    tot=1;
    for(int i=1;i<=n;i++) bas[i]=1;
    for(auto e:E)
    {
        if(e.u==fa[e.v]||e.v==fa[e.u]) continue;
        if(mark[e.u]==mark[e.v])
        {
            int weight=val[e.u]^val[e.v]^e.w;
            bas[mark[e.u]]=go(bas[mark[e.u]],get_id(1LL<<weight));
        }
        else
        {
            cross.push_back(e);
        }
    }
    memset(used,false,sizeof(used));
    for(auto p:cross) used[p.u]=used[p.v]=true;
    for(auto p:cross)
    {
        
        int curtot=tot;
        for(int i=1;i<=tot;i++) ndp[i]=0;
        for(int i=1;i<=curtot;i++)
        {
            int id=i;
            madd(ndp[id],dp[i]);
            id=go(id,bas[p.u]);
            id=go(id,bas[p.v]);
            if(id!=-1) madd(ndp[id],2LL*dp[i]%MOD);
            id=go(id,get_id(1LL<<(val[p.u]^val[p.v]^p.w)));
            if(id!=-1) madd(ndp[id],dp[i]);
        }
        swap(dp,ndp);
    }
    for(auto x:adj)
    {
        if(used[x]) continue;
        int curtot=tot;
        for(int i=1;i<=tot;i++) ndp[i]=0;
        for(int i=1;i<=curtot;i++)
        {
            int id=i;
            madd(ndp[id],dp[i]);
            id=go(id,bas[x]);
            if(id!=-1) madd(ndp[id],dp[i]);
        }
        swap(dp,ndp);
    }
    int ans=0;
    for(int i=1;i<=tot;i++) madd(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}