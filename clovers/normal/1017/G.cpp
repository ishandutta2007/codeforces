#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=202000;
const int inf=(int)2e9;

struct node{
    int sum,lazy=0,lz,rz,mx;// 
}tree[N*4];
int w[N],n,m;
int top[N],f[N],son[N],sz[N],dep[N],p[N];
int id[N],rk[N];
//rk:->  id:-> 

node operator + (node A,node B)
{
    node ret;
    ret.sum=A.sum+B.sum;
    ret.mx=max(A.mx,A.sum+B.mx);
    return ret;
} 

int first[N],nxt[N*2],point[N*2],e=0;
void add_edge(int x,int y)
{
    point[e]=y;
    nxt[e]=first[x];
    first[x]=e++;
}

void dfs1(int u)
{
    int maxsz=0;
    for(int i=first[u];i!=-1;i=nxt[i])
    {
        int v=point[i];
        if(v==f[u]) continue; 
        f[v]=u; dep[v]=dep[u]+1;
        dfs1(v); sz[u]+=sz[v];
        if(maxsz<sz[v])
        {
            maxsz=sz[v];
            son[u]=v;
        }
    }
    sz[u]++;
}

int cnt=0;
void dfs2(int u,int t)
{
    top[u]=t;
    rk[u]=++cnt;
    id[cnt]=u;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(int i=first[u];i!=-1;i=nxt[i])
    {
        int v=point[i];
        if(v==f[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}

int len(node fa)
{
    return fa.rz-fa.lz+1;
}

void pushup(node &fa,node ls,node rs)
{
    fa.sum=ls.sum+rs.sum;
    fa.lz=ls.lz; fa.rz=rs.rz;
    fa.mx=max(rs.sum+ls.mx,rs.mx);
} 

void pushdown(node &fa,node &ls,node &rs)
{
    if(!fa.lazy) return;
    ls.lazy=fa.lazy; rs.lazy=fa.lazy;
    ls.sum=fa.lazy*len(ls); rs.sum=fa.lazy*len(rs);
    ls.mx=-1; rs.mx=-1;
    fa.lazy=0;
}

void build(int x,int l,int r)
{
    if(l==r)
    {
        tree[x].sum=w[id[l]];//lid-> 
        tree[x].lz=l; tree[x].rz=l;
        tree[x].mx=w[id[l]];
        return;
    } 
    int mid=(l+r)>>1;
    build(x+x,l,mid);
    build(x+x+1,mid+1,r);
    pushup(tree[x],tree[x+x],tree[x+x+1]);
}

void update(int x,int l,int r,int L,int R,int upd)
{
    if(L<=l&&r<=R)
    {
        tree[x].sum=upd*len(tree[x]);
        if(L!=R) tree[x].lazy=upd;
        tree[x].mx=upd;
        return;
    }
    pushdown(tree[x],tree[x+x],tree[x+x+1]);
    int mid=(l+r)>>1;
    if(mid>=R) update(x+x,l,mid,L,R,upd);
    else if(mid<L) update(x+x+1,mid+1,r,L,R,upd);
    else
    {
        update(x+x,l,mid,L,R,upd);
        update(x+x+1,mid+1,r,L,R,upd);
    }
    pushup(tree[x],tree[x+x],tree[x+x+1]);
}

node query(int x,int l,int r,int L,int R)
{
    node ret;
    ret.sum=-inf; ret.mx=-inf;
    if(L<=l&&r<=R) return tree[x];
    pushdown(tree[x],tree[x+x],tree[x+x+1]);
    int mid=(l+r)>>1;
    if(mid>=R) return query(x+x,l,mid,L,R);
    else if(mid<L) return query(x+x+1,mid+1,r,L,R);
    else
    {
        ret=query(x+x+1,mid+1,r,L,R);
        ret=ret+query(x+x,l,mid,L,R);
    }
    return ret;
}

int max_line(int x,int y)
{
    node ret;
    ret.sum=-inf; ret.mx=-inf;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y); 
        if(ret.mx==-inf) ret=query(1,1,n,rk[top[x]],rk[x]);
        else ret=ret+query(1,1,n,rk[top[x]],rk[x]);
        x=f[top[x]];
        //topLCA 
    }
    if(rk[x]>rk[y]) swap(x,y);
    if(ret.mx==-inf) ret=query(1,1,n,rk[x],rk[y]);
    else ret=ret+query(1,1,n,rk[x],rk[y]);
    return ret.mx;
}

void init()
{
    memset(first,-1,sizeof(first));
    memset(nxt,-1,sizeof(nxt));
    memset(w,-1,sizeof(w));
    scanf("%d%d",&n,&m);
    dep[1]=1; f[1]=1;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&p[i]);
        add_edge(i,p[i]);
        add_edge(p[i],i);
    }
    dfs1(1);
    dfs2(1,1);
    //for(int i=1;i<=n;i++) T[rk[i]]=w[i];//-> 
    build(1,1,n);
}

void solve(int opt)
{
    //dfn 
    int x;
    if(opt==1)
    {
        scanf("%d",&x); 
        int tmp=query(1,1,n,rk[x],rk[x]).sum+1;
        update(1,1,n,rk[x],rk[x],tmp);
    }
    else if(opt==2)
    {
        scanf("%d",&x);
        update(1,1,n,rk[x],rk[x]+sz[x]-1,-1);
        if(x==1) return;
        int tmp=min(-max_line(p[x],1)-1,-1);//!!!!!
        update(1,1,n,rk[x],rk[x],tmp);
    }
    else 
    {
        scanf("%d",&x);
        int ans=max_line(x,1);
        if(ans>=0) puts("black");
        else puts("white");
    }
}

int main()
{
    init();
    for(int i=1;i<=m;i++)
    {
        int opt; scanf("%d",&opt);
        solve(opt);
    }
    return 0;
}