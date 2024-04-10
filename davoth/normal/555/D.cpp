#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=30;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
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
map<ll,ll> mp;
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=0; i<n; i++){
        cin >> a[i];
        b[i]=a[i];
        mp[a[i]]=i+1;
    }
    sort(b,b+n);
    while(q--){
        ll i,x;
        cin >> i >> x;
        i=lower_bound(b,b+n,a[i-1])-b;
        while(true){
            ll r=upper_bound(b,b+n,b[i]+x)-b-1;
            x-=b[r]-b[i];
            ll l=lower_bound(b,b+n,b[r]-x)-b;
            x-=b[r]-b[l];
            if(l==r){
                cout << mp[b[l]] << '\n';
                break;
            }
            x%=2*(b[r]-b[l]);
            i=l;
        }
    }
    return 0;
}