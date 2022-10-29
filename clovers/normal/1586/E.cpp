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
const int N=300005;
int n,m,f[N][20],dep[N],dp[N],from[N],too[N],deg[N];
namespace DSU{
    int fa[N];
    void init(){for(int i=1;i<=n;i++) fa[i]=i;}
    int getfather(int x){return fa[x]==x ? x : fa[x]=getfather(fa[x]);}   
    void unite(int x,int y){fa[getfather(x)]=getfather(y);}
    bool same(int x,int y){return getfather(x)==getfather(y);}
}
vector<int> v[N];
void dfs1(int u,int fa){
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=1;i<20;i++) f[u][i]=f[f[u][i-1]][i-1];
    for(auto &to : v[u]) if(to!=fa) dfs1(to,u);
}
int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
void dfs(int u,int fa){
    for(auto &to : v[u]) if(to!=fa){
        dfs(to,u);
        dp[u]^=dp[to];
    }
}

int main()
{
    n=read(); m=read();
    DSU::init();
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        if(DSU::same(x,y)) continue;
        DSU::unite(x,y);
        v[x].push_back(y); v[y].push_back(x);
    }
    int q=read();
    for(int i=1;i<=q;i++) from[i]=read(),too[i]=read();
    for(int i=1;i<=q;i++){
        int x=from[i],y=too[i];
        dp[x]^=1,dp[y]^=1;
    }
    dfs1(1,0); dfs(1,0);
    int flag=0;
    for(int i=1;i<=n;i++) if(dp[i]) flag=1;
    if(flag){
        int num=0;
        for(int i=2;i<=n;i++) deg[i]+=dp[i];
        for(int i=2;i<=n;i++) deg[f[i][0]]+=dp[i];
        for(int i=1;i<=n;i++) num+=(deg[i]&1);
        puts("NO");
        printf("%d\n",num/2);
        return 0;
    }
    puts("YES");
    for(int i=1;i<=q;i++){
        int x=from[i],y=too[i],lca=LCA(x,y);
        int dis=dep[x]+dep[y]-dep[lca]*2;
        printf("%d\n",dis+1);
        while(x!=lca) printf("%d ",x),x=f[x][0];
        printf("%d ",lca); 
        vector<int> res;
        while(y!=lca) res.push_back(y),y=f[y][0];
        reverse(res.begin(),res.end());
        for(auto &u : res) printf("%d ",u);
        puts("");
    }
    return 0;
}