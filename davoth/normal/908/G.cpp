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
const int N=7e2+10,LN=24,M=1e7+10,SQ=500,B=737,inf=1e9;
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
string s;
ll n,dp[N][N][2],ans;
int main(){
    fast_io;
    /*cout << "done!\n";
    return 0;*/
    cin >> s;
    n=s.size();
    s=s;
    for(ll t=1; t<10; t++){
        memset(dp,0,sizeof dp);
        dp[0][0][1]=1;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<=i; j++){
                dp[i][j][0]%=MOD;
                dp[i][j][1]%=MOD;
                for(ll k=0; k<10; k++){
                    dp[i+1][j+(k>=t)][0]+=dp[i][j][0];
                }
                for(ll k=0; k<s[i]-'0'; k++){
                    dp[i+1][j+(k>=t)][0]+=dp[i][j][1];
                }
                dp[i+1][j+(s[i]-'0'>=t)][1]+=dp[i][j][1];
            }
        }
        for(ll i=1,j=1; i<=n; i++,j=(j*10+1)%MOD) ans=(ans+(dp[n][i][0]+dp[n][i][1])%MOD*j%MOD)%MOD;
    }
    cout << ans << '\n';
    return 0;
}