#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef pair<int,int>pii;
typedef long long LL;
const int N=6e5+5;
const int mod=1e9+7;
int n,qq,s,cnt,idl[N<<1],idr[N<<1];
vector<pii>g[N];
void buildl(int rt,int l,int r)
{
    idl[rt]=++cnt;
    if(l==r)return ;
    int m=l+r>>1;
    buildl(rt<<1,l,m);
    buildl(rt<<1|1,m+1,r);
    g[idl[rt<<1]].push_back(make_pair(idl[rt],0));
    g[idl[rt<<1|1]].push_back(make_pair(idl[rt],0));
}
void buildr(int rt,int l,int r)
{
    idr[rt]=++cnt;
    if(l==r)return ;
    int m=l+r>>1;
    buildr(rt<<1,l,m);
    buildr(rt<<1|1,m+1,r);
    g[idr[rt]].push_back(make_pair(idr[rt<<1],0));
    g[idr[rt]].push_back(make_pair(idr[rt<<1|1],0));
}
void pre(int rt,int l,int r)
{
    if(l==r)
    {
        g[l].push_back(make_pair(idl[rt],0));
        g[idr[rt]].push_back(make_pair(l,0));
        return;
    }
    int m=l+r>>1;
    pre(rt<<1,l,m);
    pre(rt<<1|1,m+1,r);
}
int w;
void addl(int rt,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)
    {
        g[idl[rt]].push_back(make_pair(cnt,w));
        return;
    }
    int m=l+r>>1;
    if(x<=m)addl(rt<<1,l,m,x,y);
    if(y>m)addl(rt<<1|1,m+1,r,x,y);
}
void addr(int rt,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)
    {
        g[cnt].push_back(make_pair(idr[rt],0));
        return;
    }
    int m=l+r>>1;
    if(x<=m)addr(rt<<1,l,m,x,y);
    if(y>m)addr(rt<<1|1,m+1,r,x,y);
}
struct Edge
{
    int v;
    LL w;
    bool operator<(const Edge &e)const
    {
        return w>e.w;
    }
};
priority_queue<Edge>q;
bool vis[N];
LL d[N];
void dij(int s)
{
    for(int i=1; i<=cnt; ++i)d[i]=-1,vis[i]=0;
    d[s]=0,q.push(Edge {s,0});
    while(!q.empty())
    {
        int u=q.top().v;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0; i<g[u].size(); ++i)
        {
            int v=g[u][i].first,w=g[u][i].second;
            if(!vis[v]&&(d[v]==-1||d[v]>d[u]+w))
            {
                d[v]=d[u]+w;
                q.push(Edge {v,d[v]});
            }
        }
    }
    for(int i=1; i<n; ++i)printf("%I64d ",d[i]);
    printf("%I64d\n",d[n]);
}
int main()
{
    scanf("%d%d%d",&n,&qq,&s);
    cnt=n;
    buildl(1,1,n);
    buildr(1,1,n);
    pre(1,1,n);
    while(qq--)
    {
        ++cnt;
        int op,l,r,x,y;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d%d",&x,&y,&w);
            addl(1,1,n,x,x);
            addr(1,1,n,y,y);
        }
        else if(op==2)
        {
            scanf("%d%d%d%d",&x,&l,&r,&w);
            addl(1,1,n,x,x);
            addr(1,1,n,l,r);
        }
        else
        {
            scanf("%d%d%d%d",&x,&l,&r,&w);
            addl(1,1,n,l,r);
            addr(1,1,n,x,x);
        }
    }
    dij(s);
    return 0;
}