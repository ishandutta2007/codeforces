#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
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
const int N=1.5e6+10,LN=18,M=1e7+10,SQ=500,B=737,inf=1e9;
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
ll n,f[N],p[N],P[N],fl[N],an[N],h[N],ans=1;
vector<ll> adj[N];
ll gp(ll x){
    return P[x]?P[x]=gp(P[x]):x;
}
void uni(ll v, ll u){
    v=gp(v);
    u=gp(u);
    if(v==u){
        cout << 0 << '\n';
        exit(0);
    }
    P[u]=v;
}
void dfs(ll v){
    for(ll u : adj[v]){
        if(p[v]==u) continue;
        h[u]=h[v]+1;
        p[u]=v;
        dfs(u);
    }
}
void tp(ll &v, ll &pv, ll c){
    if(fl[v]&c){
        cout << 0 << '\n';
        exit(0);
    }
    fl[v]|=c;
    an[v]--;
    uni(p[v],pv);
    pv=v;
    v=p[v];
}
void solve(ll s, ll t){
    ll ps=n+s,pt=n+n+t;
    while(h[s]>h[t]) tp(s,ps,1);
    while(h[t]>h[s]) tp(t,pt,2);
    while(s!=t) tp(s,ps,1),tp(t,pt,2);
    an[s]--;
    uni(ps,pt);
}
int main(){
    fast_io;
    f[0]=1;
    for(ll i=1; i<N; i++){
        f[i]=f[i-1]*i%MOD;
    }
    cin >> n;
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1);
    for(ll i=1; i<=n; i++) an[i]=adj[i].size();
    for(ll i=1; i<=n; i++){
        ll x;
        cin >> x;
        if(x) solve(x,i);
    }
    for(ll i=1; i<=n; i++){
        if(~an[i] && gp(i+n)==gp(i+n+n)){
            cout << 0 << '\n';
            exit(0);
        }
        ans=ans*f[max(0ll,an[i])]%MOD;
    }
    cout << ans << '\n';
    return 0;
}