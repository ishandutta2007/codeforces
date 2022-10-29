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
int n,m,d[N],mxdep,mxid;
vector<pii> v[N]; pii E[N];
void dfs1(int u,int f){
    if(mxdep<d[u]) mxdep=d[u],mxid=u;
    for(auto &e : v[u]){
        int to=e.first,w=e.second;
        if(to==f) continue;
        d[to]=d[u]+1; dfs1(to,u);
    }
}
struct Tree{
    int a[N],dep[N],rt;
    int dfn[N],out[N],id[N],dfn_clock=0;
    int rev[N<<2],mx0[N<<2],mx1[N<<2];
    void pushup(int x){
        mx0[x]=max(mx0[x<<1],mx0[x<<1|1]);
        mx1[x]=max(mx1[x<<1],mx1[x<<1|1]);
    }
    void pushdown(int x){
        if(rev[x]){
            rev[x<<1]^=rev[x]; rev[x<<1|1]^=rev[x]; rev[x]=0;
            swap(mx0[x<<1],mx1[x<<1]); swap(mx0[x<<1|1],mx1[x<<1|1]);
        }
    }
    void build(int x,int l,int r){
        if(l==r){
            if(a[id[l]]==0) mx0[x]=dep[id[l]],mx1[x]=-inf;
            else mx0[x]=-inf,mx1[x]=dep[id[l]];
            return;
        }
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void update(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            rev[x]^=1;
            swap(mx0[x],mx1[x]);
            return;
        }
        int mid=(l+r)>>1; pushdown(x);
        if(mid>=L) update(x<<1,l,mid,L,R);
        if(mid<R) update(x<<1|1,mid+1,r,L,R);
        pushup(x);
    }
    
    void dfs(int u,int f){
        dfn[u]=++dfn_clock; id[dfn_clock]=u;
        for(auto &e : v[u]){
            int to=e.first,w=e.second;
            if(to==f) continue;
            dep[to]=dep[u]+1; a[to]=(a[u]^w);
            dfs(to,u);
        }
        out[u]=dfn_clock;
    }
    void init(){
        dep[rt]=0; dfs(rt,-1);
        build(1,1,n);
    }
    void change(int x,int y){
        if(dep[x]>dep[y]) swap(x,y);
        update(1,1,n,dfn[y],out[y]);
    }
}T1,T2;


int main()
{
    n=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read(),z=read(); E[i]=mk(x,y);
        v[x].push_back(mk(y,z)); v[y].push_back(mk(x,z));
    }
    mxdep=-1;
    dfs1(1,-1); T1.rt=mxid; 
    d[mxid]=0; mxdep=-1; 
    dfs1(mxid,-1); T2.rt=mxid;
    T1.init(); T2.init(); 
    m=read();
    while(m--){
        int x=read();
        T1.change(E[x].first,E[x].second);
        T2.change(E[x].first,E[x].second);
        int ans=max(T1.mx0[1],T2.mx0[1]);
        printf("%d\n",ans);
    }
    return 0;
}