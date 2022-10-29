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
const int N=4005;
const int M=77;
int k,n1,n2;
int ans=0,fac[M],ifac[M];
int C(int n,int m){return mul(fac[n],mul(ifac[m],ifac[n-m]));}
struct Tree{
    int f[N][M],g[N][M],n,sum[M];
    vector<int> v[N];
    int Rt,sz[N],vis[N],mi=inf;
    vector<int> A;
    void init(){
        memset(vis,0,sizeof(vis));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<n;i++){
            int x=read(),y=read();
            v[x].push_back(y); v[y].push_back(x);
        }
    }
    void findroot(int u,int F,int S){
        sz[u]=1; int maxsz=0; A.push_back(u);
        for(auto &to : v[u]){
            if(to==F||vis[to]) continue;
            findroot(to,u,S);
            sz[u]+=sz[to]; checkmax(maxsz,sz[to]);
        }
        if(mi>max(S-sz[u],maxsz)) mi=max(S-sz[u],maxsz),Rt=u;
    }
    void treedp(){
        for(auto &u : A){
            for(int j=0;j<=k;j++) f[u][j]=g[u][j]=0;
        }
        f[Rt][0]=g[Rt][0]=1;
        for(int j=1;j<=k;j++){
            for(auto &u : A){
                for(auto &to : v[u]) if(!vis[to]){
                    if(to!=Rt||j==1) Add(f[u][j],f[to][j-1]);
                    Add(g[u][j],g[to][j-1]);
                }
            }
        }
        for(auto &u : A){
            if(u==Rt){
                for(int i=0;i<=k;i++) Add(sum[i],g[u][i]);
                continue;
            }
            for(int i=0;i<=k;i++){
                for(int j=0;j+i<=k;j++){
                    Add(sum[i+j],mul(f[u][i],g[u][j]));
                }
            }
        }
    }
    void print(){
        for(int i=0;i<=k;i++) cout<<sum[i]<<" "; cout<<endl;
    }
    void dfs(int u,int f){
        sz[u]=1;
        for(auto &to : v[u]){
            if(to==f||vis[to]) continue;
            dfs(to,u); sz[u]+=sz[to];
        }
    }
    void solve(int x,int Sz){
        if(Sz==1){Add(sum[0],1); return;}
        mi=inf; A.clear(); findroot(x,-1,Sz);
        dfs(Rt,-1); treedp(); vis[Rt]=1;
        for(auto &to : v[Rt]){
            if(!vis[to]) solve(to,sz[to]);
        }
    }
}tree1,tree2;

int main()
{
    n1=read(); n2=read(); k=read();
    fac[0]=1; for(int i=1;i<=k;i++) fac[i]=mul(fac[i-1],i);
    ifac[k]=qpow(fac[k],MOD-2);
    for(int i=k-1;i>=0;i--) ifac[i]=mul(ifac[i+1],i+1);
    tree1.n=n1; tree2.n=n2;
    tree1.init(); tree2.init();
    tree2.solve(1,n2);
    tree1.solve(1,n1); 
    for(int i=0;i<=k;i++){
        Add(ans,mul(C(k,i),mul(tree1.sum[i],tree2.sum[k-i])));
    }
    cout<<ans<<endl;
    return 0;
}