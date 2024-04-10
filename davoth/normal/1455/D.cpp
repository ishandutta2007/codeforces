#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e2+10,LN=20,SQ=550,M=5e4+10;
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
ll t,x,a[N],b[N],n;
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n >> x;
        ll ans=0,k=n;
        for(ll i=0; i<n; i++){
            cin >> a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        for(ll i=n-1; i>=0; i--){
            if(a[i]!=b[i]) break;
            k--;
        }
        for(ll i=0; i<n; i++){
            if(a[i]>x && i<k){
                swap(a[i],x);
                ans++;
            }
            b[i]=a[i];
        }
        sort(b,b+n);
        for(ll i=0; i<n; i++) if(a[i]!=b[i]) ans=-1;
        cout << ans << '\n';
    }
    return 0;
}