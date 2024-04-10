#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20,SQ=550,M=1e9+10;
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
ll n,q,k,a[N],ans;
int main(){
    fast_io;
    cin >> q;
    while(q--){
        ans=0;
        cin >> n >> k;
        for(ll i=1; i<=n*k; i++) cin >> a[i];
        sort(a+1,a+n*k+1);
        ll l=n-n/2-1;
        for(ll i=n*k-n/2; i>=l; i-=n/2+1,l+=n-n/2-1) ans+=a[i];
        cout << ans << '\n';
    }
    return 0;
}