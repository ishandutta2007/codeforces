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
const int N=2e5+10,LN=19,M=1e5+10,SQ=450,BS=737,inf=1e9,NSQ=N/SQ+1;
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
ll n,k=1,st[N],sz[N],T,a[N],lz[N*4],hd[N],p[N];
vector<ll> adj[N];
pll ed[N];
struct node{
    ll a,b,o;
} f[N*4];
node operator+(node x, node y){
    node z;
    z.o=x.o+y.o;
    z.a=x.a+y.a;
    z.b=x.b+y.b;
    return z;
}
void build(ll v, ll l, ll r){
    if(r-l==1){
        f[v].a=f[v].o=0;
        f[v].b=a[l];
        return;
    }
    ll m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    f[v]=f[lc]+f[rc];
}
void shift(ll v, ll l, ll r){
    if(!lz[v]) return;
    swap(f[v].a,f[v].b);
    f[v].o=r-l-f[v].o;
    if(r-l>1){
        lz[lc]^=1;
        lz[rc]^=1;
    }
    lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=r || l>=tr || tl>=tr) return;
    if(l>=tl && r<=tr){
        lz[v]=1;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,tr);
    upd(rc,m,r,tl,tr);
    f[v]=f[lc]+f[rc];
}
ll get(ll v, ll l, ll r, ll p){
    shift(v,l,r);
    if(r-l==1) return f[v].o;
    ll m=(l+r)>>1;
    if(p<m) return get(lc,l,m,p);
    return get(rc,m,r,p);
}
void predfs(ll v){
    sz[v]=1;
    for(ll u : adj[v]){
        if(u==p[v]) continue;
        p[u]=v;
        predfs(u);
        sz[v]+=sz[u];
    }
}
void dfs(ll v){
    sort(adj[v].begin(),adj[v].end(),[&](ll x, ll y){return sz[x]<sz[y];});
    if(adj[v].back()==p[v]) adj[v].pop_back();
    st[v]=++T;
    if(adj[v].empty()) return;
    hd[adj[v].back()]=hd[v];
    dfs(adj[v].back());
    for(ll i=0; i<(ll)adj[v].size()-1; i++){
        hd[adj[v][i]]=adj[v][i];
        dfs(adj[v][i]);
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
        ed[i]={v,u};
    }
    predfs(1);
    hd[1]=1;
    dfs(1);
    for(ll i=1; i<n; i++){
        if(st[ed[i].F]>st[ed[i].S]) swap(ed[i].F,ed[i].S);
        a[st[ed[i].S]]=i;
    }
    build(1,1,n+1);
    upd(1,1,n+1,1,2);
    while(true){
        ll t,v;
        cin >> t;
        if(t==3) return 0;
        if(t==2){
            if(f[1].o*2>k){
                cout << 0 << endl;
                continue;
            }
            vector<ll> ans;
            for(ll i=1; i<n; i++){
                if(get(1,1,n+1,st[ed[i].S])) ans.pb(i);
            }
            cout << ans.size();
            for(ll i : ans) cout << ' ' << i;
            cout << endl;
            continue;
        }
        cin >> v;
        k++;
        while(v){
            upd(1,1,n+1,st[hd[v]],st[v]+1);
            v=p[hd[v]];
        }
        if(f[1].o*2>k) cout << 0 << endl;
        else cout << f[1].a << endl;
    }
    return 0;
}