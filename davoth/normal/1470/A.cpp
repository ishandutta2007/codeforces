#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=30;
const ll INF=1e18;
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
ll q;
int main() {
    cin >> q;
    while(q--){
        ll n,m,ans,s=0,k=0;
        cin >> n >> m;
        ll a[n],b[m],p[m];
        for(ll i=0; i<n; i++) cin >> a[i];
        for(ll i=0; i<m; i++) cin >> b[i];
        for(ll i=0; i<n; i++) s+=b[a[i]-1];
        sort(a,a+n);
        p[0]=b[0];
        for(ll i=1; i<m; i++) p[i]=b[i]+p[i-1];
        ans=s;
        for(ll i=0; i<n; i++){
            if(i>=a[n-i-1]) break;
            k+=b[a[n-i-1]-1];
            ans=min(ans,p[i]+s-k);
        }
        cout << ans << '\n';
    }
    return 0;
}