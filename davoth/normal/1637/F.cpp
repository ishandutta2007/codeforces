/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=3e5+10,LN=19,M=1e5+10,SQ=300,BS=737,inf=1e9,NSQ=N/SQ+1;
const ll INF=1e16;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,a[N],d[N],ls,ans;
vector<ll> adj[N],cp;
set<pll> st;
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        cp.pb(a[i]);
    }
    sort(cp.begin(),cp.end());
    cp.resize(unique(cp.begin(),cp.end())-cp.begin());
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
        d[v]++;
        d[u]++;
    }
    for(ll i=1; i<=n; i++){
        if(d[i]==1) st.insert({a[i],i});
    }
    for(ll i : cp){
        while(st.begin()->F<i){
            ll v=st.begin()->S;
            st.erase(st.begin());
            for(ll u : adj[v]){
                d[u]--;
                if(d[u]==1){
                    st.insert({a[u],u});
                }
            }
        }
        ans+=max(2,(int)st.size())*(i-ls);
        ls=i;
    }
    cout << ans << '\n';
    return 0;
}