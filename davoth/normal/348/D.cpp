/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=3e3+10,LN=18,M=1e6+10,SQ=350,BS=737,inf=1.05e9,NSQ=N/SQ+1;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m,a[N][N],dp[N][N];
ll calc(ll x1, ll y1, ll x2, ll y2){
    memset(dp,0,sizeof dp);
    dp[x1][y1]=a[x1][y1];
    for(ll i=x1; i<=x2; i++){
        for(ll j=y1; j<=y2; j++){
            if(!a[i][j]) continue;
            if(a[i-1][j]) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            if(a[i][j-1]) dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
        }
    }
    return dp[x2][y2];
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            char c;
            cin >> c;
            if(c=='.') a[i][j]=1;
        }
    }
    cout << (calc(1,2,n-1,m)*calc(2,1,n,m-1)%MOD+MOD-calc(1,2,n,m-1)*calc(2,1,n-1,m)%MOD)%MOD << '\n';
    return 0;
}