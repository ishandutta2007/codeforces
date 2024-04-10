#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,m,q,a[N],dfn[N],low[N],cnt,nn,fa[N],sz[N],son[N],tp[N],idfn[N],d[N],mn[N*4],st[N],tt;char c[3];
multiset<int>s[N];
void cmin(int &x,int y){y<x?x=y:0;}
struct node{
    int ver[N*2],nxt[N*2],head[N],tot;
    void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
    void a(int x,int y){add(x,y);add(y,x);}
}G,T;
void build(int x,int l,int r){
    if(l==r){mn[x]=a[idfn[l]];return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    mn[x]=min(mn[x<<1],mn[x<<1|1]);
}
void change(int x,int l,int r,int p){
    if(l==r){mn[x]=a[idfn[l]];return;}
    int mid=(l+r)>>1;
    if(p<=mid)change(x<<1,l,mid,p);
    else change(x<<1|1,mid+1,r,p);
    mn[x]=min(mn[x<<1],mn[x<<1|1]);
}
int query(int x,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr)return mn[x];           
    int mid=(l+r)>>1,ret=1e9;
    if(ql<=mid)cmin(ret,query(x<<1,l,mid,ql,qr));
    if(qr>mid)cmin(ret,query(x<<1|1,mid+1,r,ql,qr));
    return ret;
}
void tarjan(int x){
    dfn[x]=low[x]=++cnt;st[++tt]=x;
    for(int i=G.head[x];i;i=G.nxt[i]){
        int y=G.ver[i];
        if(!dfn[y]){
            tarjan(y),cmin(low[x],low[y]);
            if(low[y]>=dfn[x]){
                T.a(++nn,x);int z;
                do{z=st[tt--];T.a(nn,z);}while(z!=y);
            }
        }
        else cmin(low[x],dfn[y]);
    }
}
void dfs1(int x,int ff){
    sz[x]=1;fa[x]=ff;d[x]=d[ff]+1;
    for(int i=T.head[x];i;i=T.nxt[i]){
        int y=T.ver[i];if(y==ff)continue;
        if(x>n)s[x].insert(a[y]);
        dfs1(y,x);sz[x]+=sz[y];
        sz[y]>sz[son[x]]?son[x]=y:0;
    }
    if(x>n)a[x]=*s[x].begin();
}
void dfs2(int x){
    dfn[x]=++cnt;idfn[cnt]=x;
    if(son[x])tp[son[x]]=tp[x],dfs2(son[x]);
    for(int i=T.head[x],y;i;i=T.nxt[i])
        if(!dfn[y=T.ver[i]])tp[y]=y,dfs2(y);
}
int solve(int x,int y){
    int ret=1e9;
    while(1){
        if(tp[x]==tp[y]){
            if(d[x]>d[y])swap(x,y);
            cmin(ret,query(1,1,nn,dfn[x],dfn[y]));
            break;
        }
        if(d[tp[x]]<d[tp[y]])swap(x,y);
        cmin(ret,query(1,1,nn,dfn[tp[x]],dfn[x]));
        x=fa[tp[x]];
    }
    if(x>n)cmin(ret,a[fa[x]]);
    return ret;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);nn=n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),G.a(x,y);
    tarjan(1);cnt=0;
    memset(dfn,0,sizeof(dfn));
    dfs1(1,0);tp[1]=1;dfs2(1);
    build(1,1,nn);
    for(int i=1,x,y;i<=q;i++){
        scanf("%s%d%d",c,&x,&y);
        if(c[0]=='C'){
            if(x!=1)s[fa[x]].erase(a[x]);
            a[x]=y;change(1,1,nn,dfn[x]);
            if(x!=1){
                s[fa[x]].insert(a[x]);
                a[fa[x]]=*s[fa[x]].begin();
                change(1,1,nn,dfn[fa[x]]);
            }
        }
        else printf("%d\n",solve(x,y));
    }
    return 0;
}