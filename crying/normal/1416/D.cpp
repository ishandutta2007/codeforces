#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=5e5+10;
int n,m,q,p[MAXN*2],ord[MAXN],a[MAXN],b[MAXN],w[MAXN];
int op[MAXN],u[MAXN],idx[MAXN];
int fa[MAXN],val[MAXN],tot,faa[MAXN];
vector<int>e[MAXN];
int vis[MAXN],dfn[MAXN],orz[MAXN],sz[MAXN],dfntot;
int top[MAXN][20];
bool cmp(int x,int y){return (w[x]!=w[y])?(w[x]>w[y]):(x<y);}
int Find(int x){
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
void dfs(int u){
    vis[u]=1;dfn[u]=++dfntot;sz[u]=1;orz[dfntot]=u;
    rep(i,1,19)top[u][i]=top[top[u][i-1]][i-1];
    for(auto v:e[u]){
        if(v==faa[u])continue;
        top[v][0]=u;
        dfs(v);
        sz[u]+=sz[v];
    }
}
int leap(int u,int lim){
    per(j,19,0){
        if(!top[u][j])continue;
        if(val[top[u][j]]<=lim)continue;
        u=top[u][j];
    }
    return u;
}
struct Seg{
    int maxn[MAXN<<3];
    void pushup(int x){maxn[x]=max(maxn[lc(x)],maxn[rc(x)]);}
    void build(int x,int l,int r){
        if(l==r){maxn[x]=p[orz[l]];return;}
        int mid=(l+r)>>1;build(lc(x),l,mid);build(rc(x),mid+1,r);
        pushup(x);
    }
    void upd(int x,int l,int r,int pos){
        if(l==r){maxn[x]=0;return;}
        int mid=(l+r)>>1;
        if(pos<=mid)upd(lc(x),l,mid,pos);
        else upd(rc(x),mid+1,r,pos);
        pushup(x);
    }
    int qry(int x,int l,int r,int ql,int qr){
        if(ql<=l && qr>=r)return maxn[x];
        int mid=(l+r)>>1,ret=0;
        if(ql<=mid)ret=max(ret,qry(lc(x),l,mid,ql,qr));
        if(qr>mid)ret=max(ret,qry(rc(x),mid+1,r,ql,qr));
        return ret;
    }
}t;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    rep(i,1,n)scanf("%d",&p[i]),ord[p[i]]=i;
    rep(i,1,m){scanf("%d%d",&a[i],&b[i]);idx[i]=i;w[i]=q+1;}
    rep(i,1,q){
        scanf("%d%d",&op[i],&u[i]);
        if(op[i]==2)w[u[i]]=i;
    }
    sort(idx+1,idx+1+m,cmp);
    rep(i,1,n)fa[i]=i;tot=n;
    rep(u,1,m){
        int i=idx[u];
        if(Find(a[i])==Find(b[i]))continue;
        tot++;fa[tot]=tot;val[tot]=w[i];
        faa[Find(a[i])]=faa[Find(b[i])]=tot;
        e[tot].pb(Find(a[i]));
        e[tot].pb(Find(b[i]));
        fa[Find(a[i])]=fa[Find(b[i])]=tot;
    }
    rep(i,1,tot){
        if(faa[i])continue;
        dfs(i);
    }
    t.build(1,1,tot);
    rep(i,1,q){
        if(op[i]==2)continue;
        int p=leap(u[i],i);
        int l=dfn[p],r=dfn[p]+sz[p]-1;
        int val=t.qry(1,1,tot,l,r);
        printf("%d\n",val);
        if(val){
            t.upd(1,1,tot,dfn[ord[val]]);
        }
    }
    return 0;
}