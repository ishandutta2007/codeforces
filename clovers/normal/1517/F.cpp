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
const int N=305;
int n,k,Base[N]; vector<int> v[N];
int f1[N],g1[N],f[N][N],g[N][N],sumf[N][N],sumg[N][N];
void dfs(int u,int fa){
    memset(f[u],0,sizeof(f[u])); memset(g[u],0,sizeof(g[u]));
    f[u][0]=1; g[u][0]=1;
    for(int i=0;i<=n;i++) sumf[u][i]=1,sumg[u][i]=1;
    for(auto &to : v[u]) if(to!=fa){
        dfs(to,u);
        memset(f1,0,sizeof(f1)); memset(g1,0,sizeof(g1));
        for(int i=0;i<=k;i++){
            if(i) f1[i]=add(mul(f[u][i],f[to][i-1]),mul(f[to][i-1],sumf[u][i-1]));
            if(i>=2) Add(f1[i],mul(f[u][i],sumf[to][i-2]));
            if(i!=k) Add(f1[i],mul(f[u][i],sub(sumg[to][n],sumg[to][k-i-1])));
            else Add(f1[i],mul(f[u][i],sumg[to][n]));
            if(i) Add(f1[i],mul(f[to][i-1],sub(sumg[u][n],sumg[u][k-i])));
            
            if(i) g1[i]=add(mul(g[u][i],g[to][i-1]),mul(g[to][i-1],sub(sumg[u][n],sumg[u][i])));
            if(i) Add(g1[i],mul(g[u][i],sub(sumg[to][n],sumg[to][i-1])));
            else Add(g1[i],mul(g[u][i],sumg[to][n]));
            Add(g1[i],mul(g[u][i],sumf[to][k-i-1]));
            if(i) Add(g1[i],mul(g[to][i-1],sumf[u][k-i]));
        }
        for(int i=0;i<=n;i++) f[u][i]=f1[i],g[u][i]=g1[i];
        sumf[u][0]=f[u][0]; for(int i=1;i<=n;i++) sumf[u][i]=add(sumf[u][i-1],f[u][i]);
        sumg[u][0]=g[u][0]; for(int i=1;i<=n;i++) sumg[u][i]=add(sumg[u][i-1],g[u][i]);
    }
}

int main()
{
    n=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    Base[0]=1;
    for(int i=1;i<=n;i++) Base[i]=mul(Base[i-1],2);
    int ans=mul(n,Base[n]);
    for(k=n;k>=1;k--){
        dfs(1,-1);
        for(int j=0;j<=k;j++) Sub(ans,g[1][j]);
    }
    Sub(ans,1);
    cout<<mul(ans,qpow(Base[n],MOD-2))<<endl;
    return 0;
}