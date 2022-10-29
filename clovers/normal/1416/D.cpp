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
const ll INF=(ll)5e18;
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
int n,m,q,a[N],tot;
struct Edge{
    int x,y,tim;
    bool operator < (const Edge &rhs) const{
        return tim>rhs.tim;
    }
}E[N];
struct Query{int opt,x;}Q[N];
vector<int> v[N];
int fa[N][20],val[N],dfn[N],cnt=0,sz[N],id[N];
struct Segment_Tree{
    int mx[N<<2];
    void pushup(int x){
        if(a[id[mx[x<<1]]]>a[id[mx[x<<1|1]]]) mx[x]=mx[x<<1];
        else mx[x]=mx[x<<1|1];
    }
    void build(int x,int l,int r){
        if(l==r){mx[x]=l; return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void update(int x,int l,int r,int pos){
        if(l==r) return;
        int mid=(l+r)>>1;
        if(mid>=pos) update(x<<1,l,mid,pos);
        else update(x<<1|1,mid+1,r,pos);
        pushup(x);
    }
    int query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return mx[x];
        int mid=(l+r)>>1;
        if(mid<L) return query(x<<1|1,mid+1,r,L,R);
        if(mid>=R) return query(x<<1,l,mid,L,R);
        int ret1=query(x<<1,l,mid,L,R),ret2=query(x<<1|1,mid+1,r,L,R);
        if(a[id[ret1]]>a[id[ret2]]) return ret1;
        return ret2;
    }
}T;
namespace DSU{
    int fa[N];
    void init(){for(int i=1;i<=n+n;i++) fa[i]=i;}
    int getfather(int x){return fa[x]==x ? x : fa[x]=getfather(fa[x]);}
    void unite(int x,int y){//x->y
        x=getfather(x); y=getfather(y);
        if(x==y) return;
        fa[x]=y;
    }
    bool same(int x,int y){return getfather(x)==getfather(y);}
}
int vis[N];
void dfs(int u){
    vis[u]=1;
    dfn[u]=++cnt; sz[u]=1; id[cnt]=u;
    for(auto &to : v[u]){
        for(int i=1;i<=19;i++) fa[to][i]=fa[fa[to][i-1]][i-1];
        dfs(to); sz[u]+=sz[to];
    }
}
int find(int x,int ti){
    for(int i=19;i>=0;i--) if(val[fa[x][i]]>ti) x=fa[x][i];
    return x;
}

int main()
{
    n=read(); m=read(); q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) E[i].x=read(),E[i].y=read(),E[i].tim=q+1;
    DSU::init();
    for(int i=1;i<=q;i++){
        Q[i].opt=read(),Q[i].x=read();
        if(Q[i].opt==2) E[Q[i].x].tim=i;
    }
    sort(E+1,E+q+1); tot=n;
    for(int i=1;i<=m;i++){
        int x=DSU::getfather(E[i].x),y=DSU::getfather(E[i].y);
        if(x==y) continue;
        val[++tot]=E[i].tim;
        fa[x][0]=tot; DSU::fa[x]=tot; fa[y][0]=tot; DSU::fa[y]=tot; 
    }
    for(int i=1;i<tot;i++) v[fa[i][0]].push_back(i);
    for(int i=tot;i>=1;i--) if(!vis[i]) dfs(i);
    T.build(1,1,tot);
    for(int i=1;i<=q;i++){
        if(Q[i].opt==1){
            int x=find(Q[i].x,i);
            int pos=T.query(1,1,tot,dfn[x],dfn[x]+sz[x]-1);
            printf("%d\n",a[id[pos]]); a[id[pos]]=0;
            T.update(1,1,tot,pos);
        }
    }
    return 0;
}