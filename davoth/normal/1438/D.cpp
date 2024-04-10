#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,SQ=547,M=1e6+10;
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
int n,a[N];
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++) cin >> a[i];
    if(n%2==1){
        cout << "YES\n" << n/2*2-1 << '\n';
        for(ll i=1; i+2<=n; i+=2) cout << i << ' ' << i+1 << ' ' << i+2 << '\n';
        for(ll i=n-4; i>=1; i-=2) cout << i << ' ' << i+1 << ' ' << i+2 << '\n';
    }else{
        ll t=0;
        for(ll i=1; i<=n; i++) t^=a[i];
        if(t){
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n" << n-3 << '\n';
        for(ll i=1; i+2<=n; i+=2) cout << i << ' ' << i+1 << ' ' << i+2 << '\n';
        for(ll i=n-5; i>=1; i-=2) cout << i << ' ' << i+1 << ' ' << i+2 << '\n';
    }
    return 0;
}