#include <bits/stdc++.h>
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=20,SQ=550,M=5e4+10;
const ll INF=2e18;
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
ll t;
int main(){
    fast_io;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll deg[n+1],w[n+1],ans[n];
        for(ll i=1; i<=n; i++) deg[i]=0;
        ans[n-1]=0;
        multiset<ll> st;
        for(ll i=1; i<=n; i++) cin >> w[i];
        for(ll i=1; i<n; i++){
            ll v,u;
            cin >> v >> u;
            deg[v]++;
            deg[u]++;
            ans[n-1]+=w[u]+w[v];
        }
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<deg[i]; j++) st.insert(w[i]);
        }
        for(ll i=n-2; i>0; i--){
            ans[i]=ans[i+1]-*st.begin();
            st.erase(st.begin());
        }
        for(ll i=1; i<n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}