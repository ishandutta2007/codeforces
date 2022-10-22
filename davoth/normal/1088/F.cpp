#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=20,M=1e5+10,SQ=450,inf=1e9;
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
ll n,a[N],r=1,p[LN][N],h[N],ans;
vector<ll> adj[N];
void dfs(ll v, ll t){
    p[0][v]=t;
    h[v]=h[t]+1;
    for(ll u : adj[v]) if(u!=t) dfs(u,v);
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        if(a[r]>a[i]) r=i;
    }
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(r,0);
    for(ll i=1; i<LN; i++){
        for(ll j=1; j<=n; j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
    for(ll i=1; i<=n; i++){
        if(i==r) continue;
        ll j=0,x=INF;
        for(;p[j][i];j++){
            x=min(x,a[p[j][i]]*(j+1)+a[i]);
        }
        x=min(x,a[r]*(j+1)+a[i]);
        ans+=x;
    }
    cout << ans << '\n';
    return 0;
}