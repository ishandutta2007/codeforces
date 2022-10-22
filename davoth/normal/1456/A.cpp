#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,SQ=550,M=5e4+10;
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
ll q,n,p,k,x,y,dp[N],a[N];
string s;
int main(){
    fast_io;
    cin >> q;
    while(q--){
        cin >> n >> p >> k;
        cin >> s;
        for(ll i=0; i<n; i++) a[i]=s[i]-'0';
        cin >> x >> y;
        for(ll i=n-1; i>=n-k; i--) dp[i]=(1-a[i])*x;
        for(ll i=n-k-1; i>=0; i--) dp[i]=(1-a[i])*x+dp[i+k];
        ll ans=INF,t=0;
        for(ll i=p-1; i<n; i++) ans=min(ans,(i-p+1)*y+dp[i]);
        cout << ans << '\n';
    }
    return 0;
}