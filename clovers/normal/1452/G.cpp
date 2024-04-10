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
const int N=200005;
int n,k,a[N],dis[N],dp[N];
vector<int> v[N];
int vis[N],bl[N];
int rt,mi=inf,mxdep,sz[N],dep[N],Tmpmx;
namespace BIT{
    int a[N];
    void init(){for(int i=1;i<=mxdep;i++) a[i]=0;}
    int lowbit(int x){return x&(-x);}
    void update(int x,int val){
        for(int i=x;i;i-=lowbit(i)) checkmax(a[i],val);
    }
    int query(int x){
        int ret=0;
        for(int i=x;i<=mxdep;i+=lowbit(i)) checkmax(ret,a[i]);
        return ret;
    }
}
void findroot(int u,int f,int S){
    sz[u]=1; int mx=0;
    for(auto &to : v[u]){
        if(to==f||vis[to]) continue;
        findroot(to,u,S); sz[u]+=sz[to];
        checkmax(mx,sz[to]);
    }
    int tmp=max(mx,S-sz[u]);
    if(tmp<mi) mi=tmp,rt=u;
}
void dfs1(int u,int f){
    sz[u]=1; checkmax(mxdep,dep[u]);
    if(dep[u]<dis[u]) checkmax(Tmpmx,dis[u]);
    for(auto &to : v[u]){
        if(to==f||vis[to]) continue;
        dep[to]=dep[u]+1; dfs1(to,u);
        sz[u]+=sz[to];
    }
}
void dfs2(int u,int f){
    checkmax(dp[u],BIT::query(dep[u]));
    for(auto &to : v[u]) if(!vis[to]&&to!=f) dfs2(to,u);
}
void dfs3(int u,int f){
    if(dis[u]-dep[u]-1>0) BIT::update(min(mxdep,dis[u]-dep[u]-1),dis[u]);
    for(auto &to : v[u]) if(!vis[to]&&to!=f) dfs3(to,u);
}

void solve(int x,int S){
    if(S==1) return;
    mi=inf,mxdep=0; Tmpmx=0;
    findroot(x,-1,S); dep[rt]=0; dfs1(rt,-1);
    BIT::init(); checkmax(dp[rt],Tmpmx); 
    if(dis[rt]>1) BIT::update(min(mxdep,dis[rt]-1),dis[rt]);
    for(int i=0;i<sz(v[rt]);i++){
        int to=v[rt][i]; if(vis[to]) continue;
        dfs2(to,rt); dfs3(to,rt);
    }
    BIT::init(); 
    if(dis[rt]>1) BIT::update(min(mxdep,dis[rt]-1),dis[rt]);
    for(int i=sz(v[rt])-1;i>=0;i--){
        int to=v[rt][i]; if(vis[to]) continue;
        dfs2(to,rt); dfs3(to,rt);
    }
    vis[rt]=1;
    for(auto &to : v[rt]) if(!vis[to]) solve(to,sz[to]);
}

int main()
{
    n=read(); 
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    k=read(); for(int i=1;i<=k;i++) a[i]=read(),bl[a[i]]=1;
    queue<int> q;
    for(int i=1;i<=n;i++) if(bl[i]) vis[i]=1,q.push(i);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto &to : v[u]) if(!vis[to]) 
            vis[to]=1,dis[to]=dis[u]+1,q.push(to);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) dp[i]=dis[i];
    solve(1,n);
    for(int i=1;i<=n;i++){
        if(bl[i]) printf("0 ");
        else printf("%d ",dp[i]);
    }
    return 0;
}