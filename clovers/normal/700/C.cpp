/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)2e9+1;
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
const int N=1005;
const int M=30005;
map<pii,int> mp;
struct Edge{
    int x,y,w;
}E[M];
int n,m,S,T; 
vector<int> v[N],Edg;
int vis[N];
int To(int from,int e){
    return E[e].x==from ? E[e].y : E[e].x;
}
void bfs(){
    queue<int> q; q.push(S); vis[S]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto &e : v[u]){
            int to=To(u,e); if(vis[to]) continue;
            vis[to]=e; q.push(to);
        }
    }
    if(!vis[T]){puts("0\n0"); exit(0);}
    int x=T;
    while(x!=S){
        Edg.push_back(vis[x]);
        x=To(x,vis[x]);
    }
}

int low[N],dfn[N],tot=0,mi=inf,ans=inf,id,f[N];
vector<int> ret;
void dfs(int u,int lim,int fe){
    dfn[u]=++tot; low[u]=dfn[u];
    if(u==T) f[u]=1; 
    for(auto &e : v[u]) if(e!=lim&&e!=fe){
        int to=To(u,e);
        if(!dfn[to]){
            dfs(to,lim,e); 
            checkmin(low[u],low[to]);
            f[u]|=f[to];
        }
        else checkmin(low[u],dfn[to]);
    }
    if(low[u]==dfn[u]&&fe!=-1&&f[u]){
        if(mi>E[fe].w) mi=E[fe].w,id=fe;
    }
    //out(u); out(low[u]); outln(dfn[u]);
}

int main()
{
    n=read(); m=read(); S=read(); T=read();
    for(int i=1;i<=m;i++){
        E[i].x=read(),E[i].y=read(),E[i].w=read();
        v[E[i].x].push_back(i); v[E[i].y].push_back(i);
    }
    bfs();
    dfs(S,0,-1);
    if(mi<inf) ans=mi,ret.push_back(id);
    for(auto &e : Edg){
        memset(dfn,0,sizeof(dfn));
        memset(f,0,sizeof(f));
        tot=0; mi=inf;
        dfs(S,e,-1);
        if(mi<inf&&mi+E[e].w<ans){
            ans=mi+E[e].w;
            ret.clear(); 
            ret.push_back(id); ret.push_back(e);
        }
    }
    if(ans==inf){
        puts("-1");
        return 0;
    }
    printf("%d\n%d\n",ans,sz(ret));
    for(auto &u : ret) cout<<u<<" ";
    return 0;
}