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
const int N=1e6+10,LN=20,SQ=550,M=5e4+10;
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
vector<pll> qu[N];
ll n,c[N],sz[N],m,an[N];
map<ll,ll> mp[N],ans[N];
void dfs(ll v, ll p=0){
    sz[v]=1;
    mp[v][c[v]]=1;
    ans[v][1]=1;
    for(ll u : adj[v]){
        if(u==p) continue;
        dfs(u,v);
        if(sz[v]<sz[u]) swap(mp[v],mp[u]),swap(ans[v],ans[u]);
        sz[v]+=sz[u];
        for(auto k : mp[u]){
            for(ll j=mp[v][k.F]+1; j<=mp[v][k.F]+k.S; j++) ans[v][j]++;
            mp[v][k.F]+=k.S;
        }
    }
    for(auto [q,i] : qu[v]) an[i]=ans[v][q];
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=n; i++) cin >> c[i];
    for(ll i=1; i<n; i++){
        ll a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(ll i=1; i<=m; i++){
        ll v,k;
        cin >> v >> k;
        qu[v].pb({k,i});
    }
    dfs(1);
    for(ll i=1; i<=m; i++) cout << an[i] << '\n';
}