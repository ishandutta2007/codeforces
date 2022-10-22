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
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=1e5+10,LN=60,M=4e6+10,SQ=500,BS=737,inf=1.05e9,NSQ=N/SQ+1;
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
ll n,r,sz[N],t,ans[N];
vector<ll> adj[N];
struct fenwick{
    vector<ll> f;
    ll n;
    fenwick(){
    }
    fenwick(ll n){
        n++;
        this->n=n;
        f.resize(n,0);
    }
    void upd(ll t, ll x){
        while(t<n) f[t]+=x,t+=t&-t;
    }
    ll get(ll t){
        ll x=0;
        t=min(t,n-1);
        while(t) x+=f[t],t-=t&-t;
        return x;
    }
    ll get(ll l, ll r){
        return get(r)-get(l-1);
    }
} f[N];
void predfs(ll v){
    sz[v]=1;
    for(ll u : adj[v]){
        predfs(u);
        sz[v]+=sz[u];
    }
    sort(adj[v].begin(),adj[v].end(),[&](ll &x, ll &y){return sz[x]>sz[y];});
}
void sfd(ll v, ll c){
    f[c].upd(sz[v],1);
    for(ll u : adj[v]){
        sfd(u,c);
    }
}
void dfs(ll v, ll c){
    if(adj[v].empty()){
        f[c].upd(1,1);
        ans[v]=n-1;
        return;
    }
    f[0].upd(sz[v],-1);
    ll k=adj[v][0];
    ll mn=n-sz[v],mx1=n-sz[v],mx2=0;
    if(v==r) mn=inf;
    for(ll u : adj[v]){
        f[n+1].upd(sz[v],1);
        mn=min(mn,sz[u]);
        if(sz[u]>mx2) mx2=sz[u];
        if(mx2>mx1) swap(mx1,mx2);
        if(u==k){
            dfs(u,c);
        }else{
            f[++t]=fenwick(sz[u]);
            dfs(u,t);
        }
        f[n+1].upd(sz[v],-1);
    }
    if(sz[k]>=n-sz[v]){
        ll l=mx2-1,r=n-1;
        while(r-l>1){
            ll m=(l+r)>>1,x=sz[k]-m,y=m-mn;
            if(x<=0 || (y>=x && f[c].get(x,y))) r=m;
            else l=m;
        }
        ans[v]=r;
    }
    f[c].upd(sz[v],1);
    for(ll u : adj[v]) if(u!=k) sfd(u,c);
    f[0].upd(sz[v],1);
    if(n-sz[v]>sz[k]){
        ll l=mx2-1,r=n-1;
        while(r-l>1){
            ll m=(l+r)>>1,x=n-sz[v]-m,y=m-mn;
            if(x<=0 || (y>=x && f[0].get(x,y)-f[c].get(x,y)+f[n+1].get(x+sz[v],y+sz[v])>0)) r=m;
            else l=m;
        }
        ans[v]=r;
    }
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        ll p,v;
        cin >> p >> v;
        if(p) adj[p].pb(v);
        else r=v;
    }
    predfs(r);
    f[0]=fenwick(n);
    f[1]=fenwick(n);
    f[n+1]=fenwick(n);
    for(ll i=1; i<=n; i++) f[0].upd(sz[i],1);
    dfs(r,++t);
    for(ll i=1; i<=n; i++) cout << ans[i] << '\n';
    return 0;
}