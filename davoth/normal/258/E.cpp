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
const int N=1e5+10,LN=20,M=2e4+10,SQ=350,B=737,inf=1e9;
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
ll n,lz[N*4],st[N],fn[N],q,t,ans[N];
vector<ll> adj[N],vec[N];
struct node{
    ll mn,c;
} f[N*4];
node operator+(node a, node b){
    node c;
    if(a.mn<b.mn) c=a;
    else if(a.mn>b.mn) c=b;
    else{
        c=a;
        c.c+=b.c;
    }
    return c;
}
void dfs(ll v, ll p){
    st[v]=++t;
    for(ll u : adj[v]) if(u!=p) dfs(u,v);
    fn[v]=t;
}
void build(ll v, ll l, ll r){
    if(r-l==1){
        f[v].c=1;
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=f[lc]+f[rc];
}
void shift(ll v, ll l, ll r){
    f[v].mn+=lz[v];
    if(r-l>1){
        lz[lc]+=lz[v];
        lz[rc]+=lz[v];
    }
    lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(l>=tr || tl>=r) return;
    if(l>=tl && r<=tr){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,tr,x);
    upd(rc,m,r,tl,tr,x);
    f[v]=f[lc]+f[rc];
}
void sfd(ll v, ll p){
    for(ll u : vec[v]){
        upd(1,1,n+1,st[u],fn[u]+1,1);
    }
    ans[v]=max(0ll,n-f[1].c-1);
    if(f[1].mn) ans[v]=n-1;
    for(ll u : adj[v]) if(u!=p) sfd(u,v);
    for(ll u : vec[v]){
        upd(1,1,n+1,st[u],fn[u]+1,-1);
    }
}
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    build(1,1,n+1);
    dfs(1,0);
    while(q--){
        ll v,u;
        cin >> v >> u;
        vec[v].pb(u);
        vec[v].pb(v);
        vec[u].pb(v);
        vec[u].pb(u);
    }
    sfd(1,0);
    for(ll i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}