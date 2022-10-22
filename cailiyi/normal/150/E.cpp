#include<bits/stdc++.h>
#define N 100000
using namespace std;
int n,L,R,c[N+5],l,r,mid,fa[N+5],depth[N+5];
vector<pair<int,int> > e[N+5];
pair<int,int> son[N+5];
int deep[N+5],dfn[N+5],tot;
namespace segment_tree
{
    int tag[N*4];
    pair<int,int> t[N*4];
    #define lson x<<1
    #define rson x<<1|1
    #define mid ((l+r)>>1)
    inline void build(int x,int l,int r)
    {
        tag[x]=0,t[x]={-N,0};if(l==r) return;
        build(lson,l,mid),build(rson,mid+1,r);
    }
    inline void push_down(int x,int l,int r)
    {
        if(l!=r) tag[lson]+=tag[x],tag[rson]+=tag[x];
        t[x].first+=tag[x],tag[x]=0;
    }
    inline void modify(int x,int l,int r,int p,pair<int,int> val)
    {
        push_down(x,l,r),t[x]=max(t[x],val);if(l==r) return;
        p<=mid?modify(lson,l,mid,p,val):modify(rson,mid+1,r,p,val);
    }
    inline void add(int x,int l,int r,int le,int ri,int val)
    {
        if(le<=l && r<=ri) return tag[x]+=val,push_down(x,l,r);
        push_down(x,l,r);if(l>ri || r<le) return;
        add(lson,l,mid,le,ri,val),add(rson,mid+1,r,le,ri,val),t[x]=max(t[lson],t[rson]);
    }
    inline pair<int,int> query(int x,int l,int r,int le,int ri)
    {
        push_down(x,l,r);
        if(le>ri || r<le || l>ri) return {-N,0};
        if(le<=l && r<=ri) return t[x];
        return max(query(lson,l,mid,le,ri),query(rson,mid+1,r,le,ri));
    }
    #undef lson
    #undef rson
    #undef mid
}
using namespace segment_tree;
#define y edge.first
#define w edge.second
namespace init
{
    inline void dfs1(int x)
    {
        for(pair<int,int> edge:e[x])
        {
            fa[y]=x,depth[y]=depth[x]+1;
            e[y].erase(find(e[y].begin(),e[y].end(),make_pair(x,w))),dfs1(y);
            if(deep[y]>deep[son[x].first]) son[x]=edge;
        }
        deep[x]=deep[son[x].first]+1;
    }
    inline void dfs2(int x)
    {
        dfn[x]=++tot;
        if(son[x].first) dfs2(son[x].first);
        for(pair<int,int> edge:e[x])
            if(y!=son[x].first) dfs2(y);
    }
}
inline int dis(int u,int v)
{
    int ret=0;
    for(;u!=v;++ret,u=fa[u])
        if(depth[u]<depth[v]) swap(u,v);
    return ret;
}
inline pair<int,int> dfs(int x)
{
    pair<int,int> temp={0,0};
    modify(1,1,n,dfn[x],{0,x});
    if(son[x].first) temp=dfs(son[x].first),
    add(1,1,n,dfn[x]+1,dfn[x]+deep[x]-1,son[x].second<c[mid]?-1:1);
    if(temp.first) return temp;
    for(pair<int,int> edge:e[x]) if(y!=son[x].first)
    {
        pair<int,int> temp=dfs(y);
        if(temp.first) return temp;
        add(1,1,n,dfn[y],dfn[y]+deep[y]-1,w<c[mid]?-1:1);
        for(int i=0;i<deep[y];++i)
        {
            pair<int,int> now=query(1,1,n,dfn[y]+i,dfn[y]+i);
            pair<int,int> maxn=query(1,1,n,dfn[x]+max(0,L-i-1),dfn[x]+min(R-i-1,deep[x]-1));
            if(now.first+maxn.first>=0) return {now.second,maxn.second};
        }
        for(int i=0;i<deep[y];++i) modify(1,1,n,dfn[x]+i+1,query(1,1,n,dfn[y]+i,dfn[y]+i));
    }
    pair<int,int> maxn=query(1,1,n,dfn[x]+L,dfn[x]+min(R,deep[x]-1));
    return maxn.first>=0?make_pair(x,maxn.second):make_pair(0,0);
}
#undef y
#undef w
pair<int,int> ans;
int main()
{
    scanf("%d %d %d",&n,&L,&R);
    for(int i=1,u,v,w;i<n;++i)
    {
        scanf("%d %d %d",&u,&v,&w),c[i]=w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    sort(c+1,c+n),c[0]=unique(c+1,c+n)-c-1;
    init::dfs1(1),init::dfs2(1);
    for(l=1,r=c[0];l!=r;)
    {
        mid=(l+r+1)>>1,build(1,1,n);
        dfs(1).first?l=mid:r=mid-1;
    }
    mid=l,build(1,1,n),ans=dfs(1);
    printf("%d %d\n",ans.first,ans.second);
    return 0;
}