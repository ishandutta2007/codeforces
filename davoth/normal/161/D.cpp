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
const int N=1e5+10,LN=20,M=2e4+10,SQ=350,B=737,inf=1e9;
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
ll n,k,ans,sz[N],fl[N],t[N],c[N],mx,g;
vector<ll> adj[N];
void plant(ll v, ll p=0){
    sz[v]=1;
    for(ll u : adj[v]){
        if(u!=p && !fl[u]){
            plant(u,v);
            sz[v]+=sz[u];
        }
    }
}
ll find_centroid(ll v, ll n, ll p=0){
    bool f=1;
    while(f){
        f=0;
        for(ll u : adj[v]){
            if(u!=p && !fl[u] && sz[u]*2>n){
                p=v;
                v=u;
                f=1;
                break;
            }
        }
    }
    return v;
}
void dfs(ll v, ll p, ll h){
    mx=max(mx,h);
    c[h]++;
    for(ll u : adj[v]){
        if(u!=p && !fl[u]) dfs(u,v,h+1);
    }
}
void solve(ll v){
    g=ans;
    plant(v);
    ll x=sz[v];
    t[0]=1;
    v=find_centroid(v,x);
    fl[v]=1;
    for(ll u : adj[v]){
        if(fl[u]) continue;
        mx=0;
        dfs(u,v,1);
        for(ll i=1; i<=min(mx,k); i++) ans+=c[i]*t[k-i];
        for(ll i=1; i<=mx; i++){
            t[i]+=c[i];
            c[i]=0;
        }
    }
    for(ll i=0; i<=x; i++) t[i]=0;
    for(ll u : adj[v]){
        if(!fl[u]) solve(u);
    }
}
int main(){
    fast_io;
    cin >> n >> k;
    for(int i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    solve(1);
    cout << ans << '\n';
    return 0;
}