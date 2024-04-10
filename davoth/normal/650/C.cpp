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
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=1e6+10,LN=20,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
const ll INF=1e18;
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
ll n,m,t,f[N],dp[N];
vector<ll> adj[N];
inline ll id(ll x, ll y){
    return (x-1)*m+y;
}
inline pll nid(ll x){
    return {(x-1)/m+1,(x-1)%m+1};
}
void dfs(ll v){
    f[v]=t;
    for(ll u : adj[v]) if(!f[u]) dfs(u);
}
void sfd(ll v){
    f[v]=1;
    dp[v]=1;
    for(ll u : adj[v]){
        if(!f[u]) sfd(u);
        dp[v]=max(dp[v],dp[u]+1);
    }
}
int main(){
    fast_io;
    cin >> n >> m;
    ll a[n+1][m+1],b[n+1][m+1];
    for(ll i=1; i<=n; i++){
        vector<pll> vec;
        for(ll j=1; j<=m; j++){
            cin >> a[i][j];
            vec.pb({a[i][j],id(i,j)});
        }
        sort(vec.begin(),vec.end());
        for(ll j=1; j<m; j++){
            if(vec[j].F==vec[j-1].F){
                adj[vec[j].S].pb(vec[j-1].S);
                adj[vec[j-1].S].pb(vec[j].S);
            }
        }
    }
    for(ll j=1; j<=m; j++){
        vector<pll> vec;
        for(ll i=1; i<=n; i++){
            vec.pb({a[i][j],id(i,j)});
        }
        sort(vec.begin(),vec.end());
        for(ll i=1; i<n; i++){
            if(vec[i].F==vec[i-1].F){
                adj[vec[i].S].pb(vec[i-1].S);
                adj[vec[i-1].S].pb(vec[i].S);
            }
        }
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            if(!f[id(i,j)]){
                t++;
                dfs(id(i,j));
            }
            b[i][j]=f[id(i,j)];
        }
    }
    for(ll i=1; i<=n; i++) for(ll j=1; j<=m; j++) adj[id(i,j)].clear();
    for(ll i=1; i<=n; i++){
        vector<pll> vec;
        for(ll j=1; j<=m; j++){
            vec.pb({a[i][j],b[i][j]});
        }
        sort(vec.begin(),vec.end());
        vec.resize(unique(vec.begin(),vec.end())-vec.begin());
        for(ll j=1; j<(int)vec.size(); j++){
            adj[vec[j].S].pb(vec[j-1].S);
        }
    }
    for(ll j=1; j<=m; j++){
        vector<pll> vec;
        for(ll i=1; i<=n; i++){
            vec.pb({a[i][j],b[i][j]});
        }
        sort(vec.begin(),vec.end());
        vec.resize(unique(vec.begin(),vec.end())-vec.begin());
        for(ll i=1; i<(int)vec.size(); i++){
            adj[vec[i].S].pb(vec[i-1].S);
        }
    }
    memset(f,0,sizeof f);
    for(ll i=1; i<=t; i++) if(!f[i]) sfd(i);
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            cout << dp[b[i][j]] << ' ';
        }
        cout << '\n';
    }
    return 0;
}