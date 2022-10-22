#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m,p;
int main(){
    fast_io;
    cin >> n >> m >> p;
    if(n>m){
        cout << 0 << '\n';
        return 0;
    }
    ll dp[m+1][n+1][n+1];
    memset(dp,0,sizeof dp);
    dp[0][0][0]=1;
    for(int i=1; i<=m; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<=j; k++){
                if(i==p){
                    if(j) dp[i][j][k]=dp[i-1][j-1][k];
                    if(k) dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k-1])%MOD;
                    continue;
                }
                dp[i][j][k]=dp[i-1][j][k];
                if(j) dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k])%MOD;
                if(k){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k-1]+dp[i-1][j-1][k-1])%MOD;
                }
            }
        }
    }
    for(int i=1; i<=n; i++) dp[m][n][n]=dp[m][n][n]*i%MOD;
    cout << dp[m][n][n] << '\n';
    return 0;
}