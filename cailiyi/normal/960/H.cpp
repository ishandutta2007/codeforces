#include<bits/stdc++.h>
#define N 50000
using namespace std;
int n,m,q,C,f[N+5],fa[N+5],c[N+5];
vector<int> e[N+5];
namespace segment_tree
{
    struct node
    {
        int lson,rson,tag;
        long long sum,sqr;
    }t[N<<8];
    int tot;
    inline void push_down(int x,int l,int r)
    {
        if(l!=r)
        {
            if(!t[x].lson) t[x].lson=++tot;
            if(!t[x].rson) t[x].rson=++tot;
            t[t[x].lson].tag+=t[x].tag;
            t[t[x].rson].tag+=t[x].tag;
        }
        t[x].sqr+=1ll*t[x].tag*(1ll*(r-l+1)*t[x].tag+(t[x].sum<<1));
        t[x].sum+=1ll*(r-l+1)*t[x].tag,t[x].tag=0;
    }
    #define mid ((l+r)>>1)
    inline void add(int x,int l,int r,int le,int ri,int val)
    {
        push_down(x,l,r);if(l>ri || r<le) return;
        if(le<=l && r<=ri) return t[x].tag+=val,push_down(x,l,r);
        add(t[x].lson,l,mid,le,ri,val);
        add(t[x].rson,mid+1,r,le,ri,val);
        t[x].sum=t[t[x].lson].sum+t[t[x].rson].sum;
        t[x].sqr=t[t[x].lson].sqr+t[t[x].rson].sqr;
    }
}
using namespace segment_tree;
int siz[N+5],son[N+5],dfn[N+5],top[N+5];
inline void dfs1(int x)
{
    siz[x]=1;for(int y:e[x])
    {
        dfs1(y),siz[x]+=siz[y];
        if(siz[y]>siz[son[x]]) son[x]=y;
    }
}
inline void dfs2(int x,int fa)
{
    static int tot;
    dfn[x]=++tot,top[x]=fa;
    if(son[x]) dfs2(son[x],fa);
    for(int y:e[x]) if(y!=son[x]) dfs2(y,y);
}
inline void add(int x,int f,int val)
{
    for(;x;x=fa[top[x]]) add(f,1,n,dfn[top[x]],dfn[x],val);
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&q,&C),tot=m;
    for(int i=1;i<=n;++i) scanf("%d",f+i);
    for(int i=2;i<=n;++i) scanf("%d",fa+i),e[fa[i]].push_back(i);
    dfs1(1),dfs2(1,1);
    for(int i=1;i<=m;++i) scanf("%d",c+i);
    for(int i=1;i<=n;++i) add(i,f[i],1);
    int opt,x,w;
    while(q--)
    {
        scanf("%d %d",&opt,&x);
        if(opt==1) scanf("%d",&w),add(x,f[x],-1),add(x,f[x]=w,1);
        else push_down(x,1,n),printf("%.12lf\n",1ll*C*C+1.0*(c[x]*t[x].sqr-2*t[x].sum*C)*c[x]/n);
    }
    return 0;
}