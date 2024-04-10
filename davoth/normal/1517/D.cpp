#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e2+10,LN=32,M=1e5+4,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
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
ll n,m,k,dp[N][N][20];
vector<pll> adj[N*N*4];
priority_queue<pair<ll,pll>> pq;
int main(){
    fast_io;
    cin >> n >> m >> k;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m-1; j++){
            ll w;
            cin >> w;
            adj[i*m+j].pb({i*m+j+1,w});
            adj[i*m+j+1].pb({i*m+j,w});
        }
    }
    for(ll i=0; i<n-1; i++){
        for(ll j=0; j<m; j++){
            ll w;
            cin >> w;
            adj[i*m+j].pb({(i+1)*m+j,w});
            adj[(i+1)*m+j].pb({i*m+j,w});
        }
    }
    if(k&1){
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                cout << -1 << ' ';
            }
            cout << '\n';
        }
        return 0;
    }
    k/=2;
    memset(dp,63,sizeof dp);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            dp[i][j][0]=0;
        }
    }
    for(ll t=0; t<k; t++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                ll v=i*m+j;
                for(auto [u,w] : adj[v]){
                    ll ti=u/m,tj=u%m;
                    if(dp[ti][tj][t+1]>dp[i][j][t]+w){
                        dp[ti][tj][t+1]=dp[i][j][t]+w;
                    }
                }
            }
        }
    }
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            ll x=dp[i][j][k]*2;
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}