#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,SQ=550,M=5e4+10;
const ll INF=1e18;
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
ll n,q,a[N],b[N];
int main(){
    fast_io;
    cin >> q;
    while(q--){
        cin >> n;
        ll mx=0,s=0;
        for(ll i=0; i<n; i++) cin >> a[i];
        for(ll i=0; i<n-1; i++){
            b[i]=a[i]-a[i+1];
            s+=abs(b[i]);
        }
        mx=max({mx,abs(b[0]),abs(b[n-2])});
        for(ll i=1; i<n-1; i++){
            if(b[i-1]>0 && b[i]<0) mx=max(mx,2*min(-b[i],b[i-1]));
            if(b[i-1]<0 && b[i]>0) mx=max(mx,2*min(b[i],-b[i-1]));
        }
        cout << s-mx << '\n';
    }
    return 0;
}