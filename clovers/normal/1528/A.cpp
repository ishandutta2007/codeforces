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
int T,n,l[N],r[N]; vector<int> v[N];
ll dp[N][2];

void dfs(int u,int f){
    for(auto &to : v[u]){
        if(to==f) continue;
        dfs(to,u);
    }
    dp[u][0]=0,dp[u][1]=0;
    for(auto &to : v[u]) if(to!=f){
        dp[u][0]+=max(dp[to][0]+_abs(l[to]-l[u]),dp[to][1]+_abs(r[to]-l[u]));
        dp[u][1]+=max(dp[to][0]+_abs(l[to]-r[u]),dp[to][1]+_abs(r[to]-r[u]));
    }
}

void solve(){
    n=read(); for(int i=1;i<=n;i++) v[i].clear();
    for(int i=1;i<=n;i++) l[i]=read(),r[i]=read();
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    dfs(1,-1);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
}

int main()
{
    T=read();
    while(T--){solve();}
    return 0;
}