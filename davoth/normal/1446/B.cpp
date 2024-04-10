#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e3+10,LN=20,SQ=550,M=1e9+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
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
ll n,m,ans;
string s,t;
ll dp[N][N];
int main(){
    fast_io;
    cin >> n >> m >> s >> t;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(s[i-1]==t[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
            dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
            dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
            ans=max(ans,dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}