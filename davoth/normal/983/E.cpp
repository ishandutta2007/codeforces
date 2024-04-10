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
const int N=2e5+10,LN=18,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
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
ll n,m,h[N],st[N],fn[N],t,q,P[LN][N],qu[N],ans[N],dp[LN][N];
vector<ll> adj[N],ed[N],f[N*4];
vector<pll> qq[N];
void predfs(ll v){
    st[v]=++t;
    for(ll i=1; i<LN; i++) P[i][v]=P[i-1][P[i-1][v]];
    for(ll u : adj[v]){
        h[u]=h[v]+1;
        P[0][u]=v;
        predfs(u);
    }
    fn[v]=t;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    if(l>=tr || tl>=r) return;
    if(l>=tl && r<=tr){
        f[v].pb(x);
        return;
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,tr,x);
    upd(rc,m,r,tl,tr,x);
}
void get(ll v, ll l, ll r, ll x){
    for(ll i : f[v]){
        if(!qu[i]) continue;
        ans[i]--;
        qu[i]=0;
    }
    f[v].clear();
    if(r-l>1){
        ll m=(l+r)>>1;
        if(x<m) get(lc,l,m,x);
        else get(rc,m,r,x);
    }
}
ll lca(ll v, ll u){
    if(h[v]>h[u]) swap(v,u);
    for(ll i=LN; i--; ) if(h[P[i][u]]>=h[v]) u=P[i][u];
    if(v==u) return v;
    for(ll i=LN; i--; ) if(P[i][v]!=P[i][u]) v=P[i][v],u=P[i][u];
    return P[0][v];
}
void sfd(ll v){
    for(ll u : adj[v]){
        sfd(u);
        if(h[dp[0][u]]<h[dp[0][v]]) dp[0][v]=dp[0][u];
    }
}
void dfs(ll v){
    for(auto [i,u] : qq[v]){
        upd(1,1,n+1,st[u],fn[u]+1,i);
        qu[i]=1;
    }
    for(ll u : ed[v]) get(1,1,n+1,st[u]);
    for(ll u : adj[v]) dfs(u);
    for(auto [i,u] : qq[v]) qu[i]=0;
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++) dp[0][i]=i;
    for(ll i=2; i<=n; i++){
        ll p;
        cin >> p;
        adj[p].pb(i);
    }
    h[1]=1;
    cin >> m;
    predfs(1);
    for(ll i=1; i<=m; i++){
        ll v,u,x;
        cin >> v >> u;
        if(h[v]>h[u]) swap(v,u);
        x=lca(v,u);
        if(h[x]<h[dp[0][u]]) dp[0][u]=x;
        if(h[x]<h[dp[0][v]]) dp[0][v]=x;
        if(x!=v){
            ed[v].pb(u);
            ed[u].pb(v);
        }
    }
    sfd(1);
    for(ll i=1; i<LN; i++){
        for(ll j=1; j<=n; j++){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    cin >> q;
    for(ll i=1; i<=q; i++){
        ll v,u,x;
        cin >> v >> u;
        if(h[v]>h[u]) swap(v,u);
        x=lca(v,u);
        for(ll j=LN; j--; ){
            if(h[dp[j][v]]>h[x]) ans[i]+=(1<<j),v=dp[j][v];
            if(h[dp[j][u]]>h[x]) ans[i]+=(1<<j),u=dp[j][u];
        }
        if(v!=x){
            qq[v].pb({i,u});
            ans[i]+=2;
        }else{
            ans[i]++;
        }
    }
    dfs(1);
    for(ll i=1; i<=q; i++){
        if(ans[i]>N) cout << -1 << '\n';
        else cout << ans[i] << '\n';
    }
    return 0;
}