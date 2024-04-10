#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e6+10,LN=19,M=5e6,SQ=350,B=737,inf=1e9+10;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=1000000007,MOD=998244353;
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
ll n,f[N],s[2];
pll p[N];
vector<ll> adj[N],c[2];
void dfs(ll v, ll t=0){
    f[v]=1;
    s[t]+=v;
    c[t].pb(v);
    for(ll u : adj[v]) if(!f[u]) dfs(u,t^1);
}
int main(){
    fast_io;
    cin >> n;
    if(n%2==0){
        cout << "First" << endl;
        for(ll i=1; i<=n; i++) cout << i << ' ';
        for(ll i=1; i<=n; i++) cout << i << ' ';
        cout << endl;
        return 0;
    }
    cout << "Second" << endl;
    for(ll i=1; i<=2*n; i++){
        ll x;
        cin >> x;
        if(!p[x].F) p[x].F=i;
        else p[x].S=i;
    }
    for(ll i=1; i<=n; i++){
        adj[i].pb(n+i);
        adj[n+i].pb(i);
        adj[p[i].F].pb(p[i].S);
        adj[p[i].S].pb(p[i].F);
    }
    for(ll i=1; i<=n; i++) if(!f[i]) dfs(i);
    if(s[0]%2*n==0) for(ll i : c[0]) cout << i << ' ';
    else for(ll i : c[1]) cout << i << ' ';
    cout << endl;
    return 0;
}