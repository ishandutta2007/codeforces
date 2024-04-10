#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=20,SQ=550,M=5e4+10;
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
vector<ll> adj[N];
bool hide[N];
ll res[N],sz[N],n;
void plant(ll v , ll p = -1){
    sz[v] = 1;
    for(auto u : adj[v])
        if(u != p && !hide[u]){
            plant(u , v);
            sz[v] += sz[u];
        }
}
ll find_centroid(ll v , ll n , ll p = 0){
    bool found = 1;
    while(found){
        found = 0;
        for(auto u : adj[v])
            if(u != p && !hide[u] && sz[u] * 2 > n){
                found = 1;
                p = v;
                v = u;
                break;
            }
    }
    return v;
}
void solve(ll v , ll h = 0){
    plant(v);
    v = find_centroid(v , sz[v]);
    hide[v] = 1;
    res[v] = h;
    for(auto u : adj[v])
        if(!hide[u])
            solve(u , h + 1);
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i < n; i++){
        ll a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    solve(1);
    for(ll i = 1; i <=n; i++)
        cout << (char)('A' + res[i]) << " ";
    cout << '\n';
}