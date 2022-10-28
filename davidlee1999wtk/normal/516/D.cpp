#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define debug(x) cout<<#x<<"="<<x<<endl
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int e[N*2],h[N],d[N*2],pre[N*2],cou,n;
int fa[N][20],dep[N],maxd,lg,mi[N],sz[N],sum[N];
LL dis[N],d1[N],d2[N];
bool vis[N];
inline void Addedge(const int &from,const int &to,const int &ds)
{
    cou++;
    e[cou]=to,d[cou]=ds;
    pre[cou]=h[from];
    h[from]=cou;
}

void dfs1(int x)
{
    int i,v;
    vis[x]=1;
    for(i=h[x];i;i=pre[i])
    {
        v=e[i];
        if(!vis[v])
        {
            dfs1(v);
            if(d1[v]+d[i]>d1[x])
                d2[x]=d1[x],d1[x]=d1[v]+d[i];
            else if(d1[v]+d[i]>d2[x])
                d2[x]=d1[v]+d[i];
        }
    }
}

void dfs2(int x,LL now)
{
    int i,v;
    vis[x]=1;
    dis[x]=max(d1[x],now);
    for(i=h[x];i;i=pre[i])
    {
        v=e[i];
        if(!vis[v])
        {
            if(d1[v]==d1[x]-d[i])
                dfs2(v,max(d2[x],now)+d[i]);
            else
                dfs2(v,max(d1[x],now)+d[i]);
        }
    }
}

void dfs3(int x)
{
    int i,v;
    vis[x]=1;
    maxd=max(maxd,dep[x]);
    for(i=h[x];i;i=pre[i])
    {
        v=e[i];
        if(!vis[v])
        {
            dep[v]=dep[x]+1;
            fa[v][0]=x;
            dfs3(v);
            sz[x]+=sz[v];
        }
    }
    sz[x]++;
}

void initlca()
{
    int i,j;
    lg=int(log(maxd)/log(2)+0.5);
    for(j=1;j<=lg;j++)
        for(i=1;i<=n;i++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
}

int get(int x,LL l)
{
    int i;
    LL y=dis[x];
    for(i=lg;i>=0;i--)
        if(y<=dis[fa[x][i]]+l)
            x=fa[x][i];
    return fa[x][0];
}

void dfs4(int x)
{
    int i,v;
    vis[x]=1;
    sum[x]=0;
    for(i=h[x];i;i=pre[i])
    {
        v=e[i];
        if(!vis[v])
        {
            dfs4(v);
            sum[x]+=sum[v];
        }
    }
    sum[x]=sum[x]+1-mi[x];
}

int main()
{
    int i,a,b,c,rt,q,ans;
    LL md=(LL)INF*INF,l;
    //debug(md);
    cin>>n;
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Addedge(a,b,c);
        Addedge(b,a,c);
    }
    //if(n>=100000) return 0;
    dfs1(1);
    memset(vis,0,sizeof(vis));
    //if(n>=100000) return 0;
    dfs2(1,0);
    for(i=1;i<=n;i++)
        if(md>dis[i])
            rt=i,md=dis[i];
    dis[0]=-(LL)INF*INF;
    memset(vis,0,sizeof(vis));
    dep[rt]=1;
    fa[rt][0]=0;
    dfs3(rt);
    initlca();

    //for(i=1;i<=n;i++)
        //debug(dis[i]);
    //if(n>=100000) return 0;
    cin>>q;
    while(q--)
    {
        memset(mi,0,sizeof(mi));
        cin>>l;
        for(i=1;i<=n;i++)
            mi[get(i,l)]++;
        memset(vis,0,sizeof(vis));
        dfs4(rt);
        ans=0;
        for(i=1;i<=n;i++)
            ans=max(ans,sum[i]);
        cout<<ans<<endl;
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
// D. Drazil and Morning Exercise