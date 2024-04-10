#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=7e1+10,LN=30,SQ=550,M=1e9+10;
const ll INF=1e16;
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
ll n,dp[N][N][N][2];
string s;
vector<ll> c[3];
int main(){
    fast_io;
    cin >> n >> s;
    for(ll i=0; i<n; i++){
        if(s[i]=='V') c[0].push_back(i+1);
        else if(s[i]=='K') c[1].push_back(i+1);
        else c[2].push_back(i+1);
    }
    memset(dp,63,sizeof dp);
    dp[0][0][0][0]=0;
    for(ll i=0; i<=c[0].size(); i++){
        for(ll j=0; j<=c[1].size(); j++){
            for(ll k=0; k<=c[2].size(); k++){
                for(ll t=0; t<2; t++){
                    if(i+1<=c[0].size()){
                        ll x=max(lower_bound(c[0].begin(),c[0].end(),c[0][i])-c[0].begin()-i,0ll);
                        ll y=max(lower_bound(c[1].begin(),c[1].end(),c[0][i])-c[1].begin()-j,0ll);
                        ll z=max(lower_bound(c[2].begin(),c[2].end(),c[0][i])-c[2].begin()-k,0ll);
                        dp[i+1][j][k][1]=min(dp[i+1][j][k][1],dp[i][j][k][t]+x+y+z);
                    }
                    if (j+1<=c[1].size() && !t) {
                        ll x=max(lower_bound(c[0].begin(),c[0].end(),c[1][j])-c[0].begin()-i,0ll);
                        ll y=max(lower_bound(c[1].begin(),c[1].end(),c[1][j])-c[1].begin()-j,0ll);
                        ll z=max(lower_bound(c[2].begin(),c[2].end(),c[1][j])-c[2].begin()-k,0ll);
                        dp[i][j+1][k][0]=min(dp[i][j+1][k][0],dp[i][j][k][t]+x+y+z);
                    }
                    if (k+1<=c[2].size()) {
                        ll x=max(lower_bound(c[0].begin(),c[0].end(),c[2][k])-c[0].begin()-i,0ll);
                        ll y=max(lower_bound(c[1].begin(),c[1].end(),c[2][k])-c[1].begin()-j,0ll);
                        ll z=max(lower_bound(c[2].begin(),c[2].end(),c[2][k])-c[2].begin()-k,0ll);
                        dp[i][j][k+1][0]=min(dp[i][j][k+1][0],dp[i][j][k][t]+x+y+z);
                    }
                }
            }
        }
    }
    cout << min(dp[c[0].size()][c[1].size()][c[2].size()][0],dp[c[0].size()][c[1].size()][c[2].size()][1]) << '\n';
    return 0;
}