#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,SQ=550,M=1e9+10;
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
ll q,n,w;
pll a[N];
int main(){
    fast_io;
    cin >> q;
    while(q--){
        cin >> n >> w;
        for(ll i=0; i<n; i++){
            cin >> a[i].F;
            a[i].S=i+1;
        }
        sort(a,a+n);
        ll s=0,t=n;
        vector<ll> ans;
        while(--t>=0){
            if(a[t].F+s<=w) ans.push_back(a[t].S),s+=a[t].F;
        }
        if(s*2<w) cout << -1 << '\n';
        else{
            cout << ans.size() << '\n';
            for(ll i : ans) cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}