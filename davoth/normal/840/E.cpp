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
const int N=1e5+10,LN=24,M=1e8+10,SQ=256,B=737,inf=1e9;
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
ll n,q,a[N],f[N][SQ],p[N],h[N],k[N];
vector<ll> adj[N];
void dfs(ll v){
    h[v]=h[p[v]]+1;
    for(ll u : adj[v]) if(u!=p[v]){
        p[u]=v;
        dfs(u);
    }
    if(h[v]<SQ) return;
    ll x=v;
    for(ll i=0; i<SQ; i++){
        f[v][(a[x]>>8)^(SQ-1)]=max(f[v][(a[x]>>8)^(SQ-1)],((SQ-1)<<8)|(a[x]^i));
        x=p[x];
    }
    k[v]=x;
    for(ll i=0; i<8; i++) for(ll j=0; j<SQ; j++) f[v][j]=max(f[v][j],f[v][j^(1<<i)]-(SQ<<i));
}
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<=n; i++) cin >> a[i];
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1);
    while(q--){
        ll ans=0,v,u,sz,x;
        cin >> u >> v;
        sz=h[v]-h[u]+1;
        x=v;
        for(ll i=0; i<sz/SQ; i++){
            ans=max(ans,f[x][i]);
            x=k[x];
        }
        for(ll i=sz/SQ*SQ; i<sz; i++){
            ans=max(ans,a[x]^i);
            x=p[x];
        }
        cout << ans << '\n';
    }
    return 0;
}