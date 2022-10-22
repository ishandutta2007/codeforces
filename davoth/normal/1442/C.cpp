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
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=17,M=2e3+4,SQ=600,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=/*1000000007*/ 998244353;
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
ll n,m,d[N][30],ans=inf;
pll ds[N];
queue<pll> q1,q2;
vector<ll> adj[2][N];
priority_queue<pair<pll,ll>> pq;
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=0; i<m; i++){
        ll v,u;
        cin >> v >> u;
        adj[0][v].pb(u);
        adj[1][u].pb(v);
    }
    for(ll i=2; i<=n*2+2; i++) ds[i]={inf,inf};
    memset(d,63,sizeof d);
    ds[2]={0,0};
    pq.push({{0,0},2});
    while(!pq.empty()){
        auto [p,t]=pq.top();
        ll v=t/2;
        pq.pop();
        p.F*=-1;
        p.S*=-1;
        if(p!=ds[t]) continue;
        if(ds[t^1]>mp(p.F+1,p.S)){
            ds[t^1]=mp(p.F+1,p.S);
            pq.push({{-p.F-1,-p.S},t^1});
        }
        for(ll u : adj[t%2][v]){
            pll w={p.F,p.S+1};
            if(w<ds[u*2+t%2]){
                ds[u*2+t%2]=w;
                pq.push({{-w.F,-w.S},u*2+t%2});
            }
        }
    }
    d[1][0]=0;
    q1.push({1,0});
    while(!q1.empty()){
        auto [x,y]=q1.front();
        q1.pop();
        if(y<29 && d[x][y+1]>d[x][y]) q2.push({x,y+1}),d[x][y+1]=d[x][y];
        for(ll u : adj[y%2][x]){
            if(d[u][y]>d[x][y]+1){
                d[u][y]=d[x][y]+1;
                q1.push({u,y});
            }
        }
        while(!q2.empty()){
            auto [x,y]=q2.front();
            q2.pop();
            if(y<29 && d[x][y+1]>d[x][y]) q2.push({x,y+1}),d[x][y+1]=d[x][y];
            for(ll u : adj[y%2][x]){
                if(d[u][y]>d[x][y]+1){
                    d[u][y]=d[x][y]+1;
                    q1.push({u,y});
                }
            }
        }
    }
    for(ll i=0; i<30; i++) ans=min(ans,d[n][i]+(1ll<<i)-1);
    if(ans==inf){
        if(ds[n*2].F>ds[n*2+1].F) swap(ds[n*2],ds[n*2+1]);
        ans=pow(2,ds[n*2].F,MOD)-1+ds[n*2].S;
    }
    cout << ans%MOD << '\n';
    return 0;
}