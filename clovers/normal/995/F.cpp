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
const int N=3005;
int n,D,fac[N],ifac[N],CD[N];
vector<int> v[N];
int C(int n,int m){
    return mul(fac[n],mul(ifac[n-m],ifac[m]));
}
void init(){
    n=read(); D=read();
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
    ifac[n]=qpow(fac[n],MOD-2);
    for(int i=n-1;i>=0;i--) ifac[i]=mul(ifac[i+1],i+1);
    CD[0]=1;
    for(int i=1;i<=n;i++) CD[i]=mul(CD[i-1],mul(D-i+1,qpow(i,MOD-2)));
    for(int i=2;i<=n;i++){
        int fa=read();
        v[fa].push_back(i);
    }
}

int dp[N][N],sum[N][N];
void dfs(int u){
    for(auto &to : v[u]) dfs(to);
    for(int i=1;i<=n;i++){
        dp[u][i]=1;
        for(auto &to : v[u]) Mul(dp[u][i],sum[to][i]);
    }
    for(int i=1;i<=n;i++) sum[u][i]=add(sum[u][i-1],dp[u][i]);
}

int f[N];
void solve(){
    dfs(1);
    //cout<<dp[1][1]<<" "<<dp[1][2]<<endl;
    for(int i=1;i<=n;i++){
        f[i]=dp[1][i];
        for(int j=1;j<i;j++) Sub(f[i],mul(f[j],C(i-1,j-1)));
    }
    //cout<<f[1]<<" "<<f[2]<<endl;
    int ans=0;
    for(int i=1;i<=min(n,D);i++) Add(ans,mul(CD[i],f[i]));
    cout<<ans<<endl;
}

int main()
{
    init(); solve();
    return 0;
}