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
using point=complex<ld>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!\n")
const int N=3e5+10,LN=19,M=1e8+10,SQ=256,B=737,inf=1e9;
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
ll n,q,P[LN][N],h[N],st[N],fn[N],f[N],T,ans;
vector<ll> adj[N],ed[N];
map<ll,ll> mk[N];
ll kp(ll v, ll t){
    for(ll i=0; i<LN; i++) if((t>>i)&1) v=P[i][v];
    return v;
}
void dfs(ll v, ll p=0){
    P[0][v]=p;
    st[v]=++T;
    for(ll i=1; i<LN; i++) P[i][v]=P[i-1][P[i-1][v]];
    h[v]=h[p]+1;
    for(ll u : adj[v]) if(u!=p) dfs(u,v);
    fn[v]=T;
}
void upd(ll t, ll x){
    while(t<N) f[t]+=x,t+=t&-t;
}
ll get(ll t, ll x=0){
    while(t) x+=f[t],t-=t&-t;
    return x;
}
ll gt(ll l, ll r){
    return get(r)-get(l-1);
}
void sfd(ll v, ll p=0){
    for(ll u : adj[v]) if(u!=p) sfd(u,v);
    for(ll u : ed[v]){
        if(st[u]<st[v] || st[u]>fn[v]) continue;
        ll w=kp(u,h[u]-h[v]-1);
        if(gt(st[w],fn[w])-gt(st[u],fn[u])==0){
            ans++;
            upd(st[w],1);
        }
    }
}

int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=2; i<=n; i++){
        ll v;
        cin >> v;
        adj[v].pb(i);
        mk[v][i]=mk[i][v]=1;
    }
    dfs(1);
    for(ll i=1; i<=q; i++){
        ll v,u;
        cin >> v >> u;
        if(h[v]>h[u]) swap(v,u);
        ed[v].pb(u);
        if(mk[v][u]){
            kill("-1\n");
        }
    }
    sfd(1);
    for(ll i=1; i<=n; i++){
        for(ll j : ed[i]){
            if(st[j]>=st[i] && st[j]<=fn[i]) continue;
            if(gt(1,n)-gt(st[i],fn[i])-gt(st[j],fn[j])==0){
                cout << ans+1 << '\n';
                return 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}