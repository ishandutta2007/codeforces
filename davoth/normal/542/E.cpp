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
const int N=5e3+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
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
ll n,m,cl[N],t,d[N],ans,s;
vector<ll> adj[N],cp[N];
void dfs(ll v){
    cp[t].pb(v);
    for(ll u : adj[v]){
        if(cl[u]==cl[v]){
            cout << -1 << '\n';
            exit(0);
        }
        if(!cl[u]){
            cl[u]=3-cl[v];
            dfs(u);
        }
    }
}
ll bfs(ll v){
    memset(d,63,sizeof d);
    d[v]=0;
    ll ans=0;
    queue<ll> q;
    q.push(v);
    while(!q.empty()){
        ll v=q.front();
        q.pop();
        for(ll u : adj[v]){
            if(d[u]>d[v]+1){
                d[u]=d[v]+1;
                q.push(u);
            }
        }
    }
    for(ll i=1; i<=n; i++) if(d[i]<=n) ans=max(d[i],ans);
    return ans;
}
int main(){
    fast_io;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    for(int i=1; i<=n; i++){
        if(!cl[i]){
            cl[i]=1;
            dfs(i);
            t++;
        }
    }
    for(int i=0; i<t; i++){
        ans=0;
        for(ll v : cp[i]) ans=max(ans,bfs(v));
        s+=ans;
    }
    cout << s << '\n';
    return 0;
}