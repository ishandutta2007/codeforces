#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0);
const int N=1e5+10,LN=24,M=1e8+10,SQ=500,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,q,ans[N];
set<ll> qu[N],st[N];
vector<ll> adj[N];
void dfs(ll v, ll p=0){
    set<ll> l;
    for(ll u : adj[v]){
        if(u==p) continue;
        for(ll i : qu[u]) if(qu[v].count(i)) ans[i]=inf;
        dfs(u,v);
        if(st[v].size()<st[u].size()) swap(st[v],st[u]);
        for(ll i : st[u]){
            if(qu[v].count(i)) ans[i]++;
            else if(st[v].count(i)) l.insert(i);
            else st[v].insert(i);
        }
    }
    for(ll i : l) ans[i]++,st[v].erase(i);
    for(ll i : qu[v]){
        if(st[v].count(i)) ans[i]++;
        st[v].insert(i);
    }
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    cin >> q;
    for(ll i=1; i<=q; i++){
        ll k;
        cin >> k;
        while(k--){
            ll v;
            cin >> v;
            qu[v].insert(i);
        }
    }
    dfs(1);
    for(ll i=1; i<=q; i++) cout << (ans[i]<inf?ans[i]:-1) << '\n';
    return 0;
}