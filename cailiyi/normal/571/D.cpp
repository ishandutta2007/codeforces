#include<bits/stdc++.h>
#define N 500000
using namespace std;
struct ufs
{
    int fa[N+5],siz[N+5],time[N+5];
    inline void init(int n) {for(int i=1;i<=n;++i) fa[i]=i,siz[i]=1,time[i]=0;}
    inline int gf(int x) {return fa[x]==x?x:gf(fa[x]);}
    inline void merge(int u,int v,int t)
    {
        u=gf(u),v=gf(v);
        if(siz[u]<siz[v]) swap(u,v);
        fa[v]=u,siz[u]+=siz[v],time[v]=t;
    }
}s1,s2;
int n,m,x,y,last[N+5];
vector<pair<int,long long> > add[N+5];
char opt[10];
inline int query_time(int x)
{
    int ret=last[x];
    for(;s2.fa[x]!=x;x=s2.fa[x]) if(s2.time[x]<last[s2.fa[x]]) ret=max(ret,last[s2.fa[x]]);
    return ret;
}
#define query(x,t) add[x].back().second-prev(lower_bound(add[x].begin(),add[x].end(),make_pair(t,0ll)))->second
inline long long query_sum(int x,int t)
{
    long long ret=query(x,t);
    for(;s1.fa[x]!=x;x=s1.fa[x]) ret+=query(s1.fa[x],max(t,s1.time[x]));
    return ret;
}
int main()
{
    scanf("%d %d",&n,&m),s1.init(n),s2.init(n);
    for(int i=1;i<=n;++i) add[i].push_back({-1,0});
    for(int i=1;i<=m;++i)
    {
        scanf("%s %d",opt,&x);
        if(opt[0]=='U') scanf("%d",&y),s1.merge(x,y,i);
        else if(opt[0]=='M') scanf("%d",&y),s2.merge(x,y,i);
        else if(opt[0]=='A') x=s1.gf(x),add[x].push_back({i,add[x].back().second+s1.siz[x]});
        else if(opt[0]=='Z') x=s2.gf(x),last[x]=i;
        else printf("%lld\n",query_sum(x,query_time(x)));
    }
    return 0;
}