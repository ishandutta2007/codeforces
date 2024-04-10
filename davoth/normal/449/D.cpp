#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20;
const int MOD=1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=1;
    if(y%2) b=x;
    return pow(x*x%mod,a,mod)*b%mod;
}
ll n,a[N],dp[LN+1][1<<LN],ans;
int main() {
    cin >> n;
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++){
        dp[0][a[i]]++;
    }
    for(ll i=1; i<=LN; i++){
        for(ll j=0; j<(1<<LN); j++){
            ll t=1<<(i-1);
            if((j&t)==t) dp[i][j]+=dp[i-1][j];
            else dp[i][j]+=dp[i-1][j]+dp[i-1][j+t];
        }
    }
    for(ll i=0; i<(1<<LN); i++){
        ans+=pow(2,dp[LN][i],MOD)*(__builtin_popcount(i)%2==0 ? 1 : -1);
        ans+=MOD;
        ans%=MOD;
    }
    cout << ans;
    return 0;
}