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
const int MOD=1e9+7;
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
const int N=205;
int n; vector<int> v[N];
int inv[N],sz[N],fac[N],ifac[N];
int ans=0;
int cnt=0,dfn[N],out[N],dep[N];
void dfs(int u,int f){
    sz[u]=1; dfn[u]=++cnt;
    for(auto &to : v[u]) if(to!=f){
        dep[to]=dep[u]+1;
        dfs(to,u);
        sz[u]+=sz[to]; 
    }
    out[u]=cnt;
}
int rt,dp[N][N];
bool isfa(int x,int y){return dfn[x]<=dfn[y]&&out[x]>=out[y];}
void dfs2(int u,int f,int d,int now){
    if(u>d){
        if(isfa(u,d)) Add(ans,1);
        else if(!isfa(d,u)){
            int x=dep[u]-now,y=dep[d]-now;
            //out(rt); out(d); out(u); out(x); out(y); outln(dp[x+y-1][x]);
            Add(ans,dp[x+y-1][x]);
        }
    }
    for(auto &to : v[u]) if(to!=f){
        if(isfa(u,d)&&!isfa(to,d)) dfs2(to,u,d,dep[u]);
        else dfs2(to,u,d,now);
    }
}

int main()
{
    n=read();
    inv[1]=1; for(int i=2;i<=n;i++) inv[i]=mul(MOD-MOD/i,inv[MOD%i]);
    fac[0]=1; for(int i=1;i<=n+n;i++) fac[i]=mul(fac[i-1],i);
    ifac[0]=1; for(int i=1;i<=n+n;i++) ifac[i]=mul(ifac[i-1],inv[i]);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j]=mul(inv[2],dp[i-1][j]);
            if(j) Add(dp[i][j],mul(inv[2],dp[i-1][j-1]));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0;j--) Add(dp[i][j],dp[i][j+1]);
    }
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    for(rt=1;rt<=n;rt++){
        dep[rt]=0; dfs(rt,-1);
        for(int i=1;i<=n;i++) dfs2(rt,-1,i,0);
        // out(rt); outln(ans);
    }
    cout<<mul(ans,inv[n])<<endl;
    return 0;
}