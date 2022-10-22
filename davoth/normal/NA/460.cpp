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
const int N=5e2+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
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
ll n,m,d[N][N][2];
pair<pll,ll> p[N][N][2];
vector<ll> adj[N],an[2];
queue<pair<pll,ll>> q;
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=m; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            for(ll t=0; t<2; t++){
                d[i][j][t]=INF;
                p[i][j][t]={{0,0},-1};
            }
        }
    }
    d[1][n][0]=0;
    q.push({{1,n},0});
    while(!q.empty()){
        ll v[]={q.front().F.F,q.front().F.S},t=q.front().S;
        q.pop();
        for(ll u : adj[v[t]]){
            if(t==1 && u==v[0]) continue;
            ll x=v[0],y=v[1];
            if(t) y=u;
            else x=u;
            if(d[x][y][1-t]<=d[v[0]][v[1]][t]+1) continue;
            d[x][y][1-t]=d[v[0]][v[1]][t]+1;
            p[x][y][1-t]={{v[0],v[1]},t};
            q.push({{x,y},1-t});
        }
    }
    if(d[n][1][0]==INF){
        cout << -1 << '\n';
        return 0;
    }
    cout << d[n][1][0]/2 << '\n';
    pair<pll,ll> t={{n,1},0};
    while(~t.S){
        ll v[]={t.F.F,t.F.S};
        an[1-t.S].pb(v[1-t.S]);
        t=p[v[0]][v[1]][t.S];
    }
    an[0].pb(1);
    reverse(an[0].begin(),an[0].end());
    reverse(an[1].begin(),an[1].end());
    for(ll i : an[0]) cout << i << ' ';
    cout << '\n';
    for(ll i : an[1]) cout << i << ' ';
    cout << '\n';
    return 0;
}