/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)2e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=500005;
int n,m,ans[N];
struct Edge{int x,y,w;}E[N];
namespace DSU{
    int fa[N];
    void init(){for(int i=1;i<=n;i++) fa[i]=i;}
    int getfather(int x){return x==fa[x] ? x : fa[x]=getfather(fa[x]);}
    void unite(int x,int y){fa[getfather(x)]=getfather(y);}
    bool same(int x,int y){return getfather(x)==getfather(y);}
}
struct BIT{
    int a[N];
    int lowbit(int x){return x&(-x);}
    void update(int x,int val){for(int i=x;i<=n;i+=lowbit(i)) a[i]+=val;}
    int query(int x){int ret=0; for(int i=x;i;i-=lowbit(i)) ret+=a[i]; return ret;}
}T;
int sum[N],dfn[N],sz[N],dep[N],dfn_clock=0,top[N],son[N],fa[N];
vector<pii> v[N];
void dfs1(int u){
    sz[u]=1; son[u]=0;
    for(auto &e : v[u]) if(e.first!=fa[u]){
        int to=e.first,w=e.second;
        fa[to]=u; dep[to]=dep[u]+1; 
        sum[to]=sum[u]^w; dfs1(to);
        sz[u]+=sz[to]; if(sz[to]>sz[son[u]]) son[u]=to;
    }
}
void dfs2(int u){
    dfn[u]=++dfn_clock;
    if(son[u]) top[son[u]]=top[u],dfs2(son[u]);
    for(auto &e : v[u]) if(e.first!=fa[u]&&e.first!=son[u]){
        int to=e.first,w=e.second;
        top[to]=to; dfs2(to);
    }
}
int LCA(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]>dep[top[y]]) x=fa[top[x]];
        else y=fa[top[y]];
    }
    return dep[x]>dep[y] ? y : x;
}
int query(int x,int F){
    int ret=0;
    while(top[x]!=top[F]){
        int to=top[x];
        ret+=T.query(dfn[x])-T.query(dfn[to]-1);
        x=fa[to];
    }
    ret+=T.query(dfn[x])-T.query(dfn[F]);
    return ret;
}

int main()
{
    n=read(); m=read();
    DSU::init();
    for(int i=1;i<=m;i++){
        E[i].x=read(),E[i].y=read(),E[i].w=read();
        if(!DSU::same(E[i].x,E[i].y)){
            ans[i]=1;
            DSU::unite(E[i].x,E[i].y);
            v[E[i].x].push_back(mk(E[i].y,E[i].w));
            v[E[i].y].push_back(mk(E[i].x,E[i].w));
        }
    }
    for(int i=1;i<=n;i++) if(!dep[i]) dep[i]=1,dfs1(i);
    for(int i=1;i<=n;i++) if(!dfn[i]) top[i]=i,dfs2(i);
    for(int i=1;i<=m;i++) if(!ans[i]){
        int x=E[i].x,y=E[i].y;
        int lca=LCA(x,y);
        if((sum[x]^sum[y])^E[i].w){
            if(!(query(x,lca)+query(y,lca))){
                ans[i]=1;
                while(x!=lca) T.update(dfn[x],1),x=fa[x];
                while(y!=lca) T.update(dfn[y],1),y=fa[y];
            }
        }
    }   
    for(int i=1;i<=m;i++) if(ans[i]) puts("YES"); else puts("NO");
    return 0;
}