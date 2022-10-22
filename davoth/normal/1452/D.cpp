#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,SQ=550,M=5e4+10;
//const ll INF=1e16;
const int MOD=/*1000000007*/ 998244353;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,dp[N],f,g;
int main(){
    fast_io;
    cin >> n;
    f=pow(2,MOD-2,MOD);
    g=f*f%MOD;
    dp[1]=f;
    dp[2]=g;
    for(ll i=3; i<=n; i++) dp[i]=(f*dp[i-1]+g*dp[i-2])%MOD;
    cout << dp[n] << '\n';
    return 0;
}