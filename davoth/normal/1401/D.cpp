#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=1e3+10,SQ=600,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll t,sz[N];
vector<ll> adj[N];
void dfs(ll v, ll p){
    sz[v]=1;
    for(ll u : adj[v]){
        if(u!=p){
            dfs(u,v);
            sz[v]+=sz[u];
        }
    }
}
int main(){
    fast_io;
    cin >> t;
    while(t--){
        ll n,m,ans=0;
        cin >> n;
        pll ed[n];
        ll x[n];
        for(ll i=1; i<=n; i++) adj[i]={};
        for(ll i=1; i<n; i++){
            ll v,u;
            cin >> v >> u;
            adj[v].pb(u);
            adj[u].pb(v);
            ed[i]={v,u};
        }
        dfs(1,0);
        for(ll i=1; i<n; i++){
            auto [v,u]=ed[i];
            x[i]=(n-min(sz[v],sz[u]))*min(sz[v],sz[u]);
        }
        sort(x+1,x+n);
        cin >> m;
        vector<ll> p;
        for(ll i=0; i<m; i++){
            ll k;
            cin >> k;
            p.pb(k);
        }
        for(ll i=m; i<n-1; i++) p.pb(1);
        sort(p.begin(),p.end());
        while(p.size()>=n){
            p[p.size()-2]=p[p.size()-2]*p.back()%MOD;
            p.pop_back();
        }
        for(ll i=1; i<n; i++){
            ans=(ans+x[i]*p[i-1])%MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}