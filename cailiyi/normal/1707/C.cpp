#include<bits/stdc++.h>
#define N 100000
#define M 200000
using namespace std;
int n,m,u[M+5],v[M+5],fa[N+5],f[N+5][18],deep[N+5],sum[N+5],dfn[N+5],siz[N+5],tot;
bool vis[M+5];
vector<int> e[N+5];
inline int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void dfs(int x)
{
    deep[x]=deep[f[x][0]]+1,dfn[x]=++tot,siz[x]=1;
    for(int i=1;i<=17;++i) f[x][i]=f[f[x][i-1]][i-1];
    for(int y:e[x]) if(y!=f[x][0]) f[y][0]=x,dfs(y),siz[x]+=siz[y];
}
inline int lca(int u,int v)
{
    if(deep[u]<deep[v]) swap(u,v);
    for(int i=17;deep[u]!=deep[v];--i)
        if(deep[f[u][i]]>=deep[v]) u=f[u][i];
    if(u==v) return u;
    for(int i=17;f[u][0]!=f[v][0];--i)
        if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];
}
inline void add(int u,int val)
{
    sum[dfn[u]]+=val,sum[dfn[u]+siz[u]]-=val;
}
inline int jump(int u,int l)
{
    for(int i=17;f[u][0]!=l;--i)
        if(deep[f[u][i]]>deep[l]) u=f[u][i];
    return u;
}
inline void modify(int u,int v)
{
    if(u==v) return ++sum[1],void();
    int l=lca(u,v);
    if(deep[u]>deep[v]) swap(u,v);
    if(u!=l) add(u,1),add(v,1);
    else add(v,1),++sum[1],add(jump(v,u),-1);
}
int main()
{
    scanf("%d %d",&n,&m);
    iota(fa+1,fa+1+n,1);
    for(int i=1;i<=m;++i)
    {
        scanf("%d %d",u+i,v+i);
        if(find(u[i])!=find(v[i]))
        {
            vis[i]=1,fa[fa[v[i]]]=fa[u[i]];
            e[u[i]].push_back(v[i]);
            e[v[i]].push_back(u[i]);
        }
    }
    dfs(1);
    for(int i=1;i<=m;++i) if(!vis[i])
        modify(u[i],v[i]);
    for(int i=1;i<=n;++i) sum[i]+=sum[i-1];
    for(int i=1;i<=n;++i)
        putchar(sum[dfn[i]]==m-(n-1)?'1':'0');
    return 0;
}