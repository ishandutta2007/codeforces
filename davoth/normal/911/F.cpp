#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
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
const int N=1e6+10,LN=20,M=1.1e7+10,SQ=350,B=737,inf=1e9;
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
ll n,P[LN][N],H[N],mh[N],ans,x,y;
vector<ll> adj[N],ip;
vector<pair<pll,ll>> an;
void dfs(ll v, ll p){
    P[0][v]=p;
    H[v]=H[p]+1;
    mh[v]=v;
    for(ll i=1; i<LN; i++) P[i][v]=P[i-1][P[i-1][v]];
    for(ll u : adj[v]){
        if(u!=p) dfs(u,v);
        if(H[mh[u]]>H[mh[v]]) mh[v]=mh[u];
    }
}
ll lca(ll v, ll u){
    if(H[v]>H[u]) swap(v,u);
    for(ll i=LN; i--;){
        if((1<<i)&(H[u]-H[v])) u=P[i][u];
    }
    if(v==u) return v;
    for(ll i=LN; i--;){
        if(P[i][v]!=P[i][u]) v=P[i][v],u=P[i][u];
    }
    return P[0][v];
}
ll dist(ll v, ll u){
    return H[v]+H[u]-2*H[lca(v,u)];
}
void sfd(ll v, ll p){
    ll a=dist(x,v),b=dist(y,v);
    for(ll u : adj[v]) if(u!=p) sfd(u,v);
    if(a+b!=H[y]-H[x]){
        ans+=max(a,b);
        if(a>b) an.pb({{x,v},v});
        else an.pb({{y,v},v});
    }else{
        ip.pb(v);
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
    dfs(1,0);
    x=mh[1];
    memset(H,0,sizeof H);
    memset(P,0,sizeof P);
    dfs(x,0);
    y=mh[x];
    sfd(x,0);
    ans+=H[y]*(H[y]-1)/2;
    for(ll v : ip){
        if(v==x) continue;
        an.pb({{v,x},v});
    }
    cout << ans << '\n';
    for(auto [p,q] : an) cout << p.F << ' ' << p.S << ' ' << q << '\n';
    return 0;
}