#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const ld ep=1e-7;
const int MH=1000696969,MOD=1000000007,MD=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
ll n,f[N*4],lz[N*4],st[N],fn[N],p[N],sz[N],t,h[N],q,ans,fl[N];
vector<pll> adj[N],vec;
queue<pll> qe;
void dfs(ll v, ll p){
    st[v]=++t;
    for(auto [u,w] : adj[v]){
        if(u!=p) h[u]=h[v]+w,dfs(u,v);
    }
    fn[v]=t;
}
void shift(ll v, ll l, ll r){
    f[v]+=lz[v];
    if(r-l>1){
        lz[lc]+=lz[v];
        lz[rc]+=lz[v];
    }
    lz[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, ll x){
    shift(v,l,r);
    if(r<=tl || tr<=l) return;
    if(l>=tl && r<=tr){
        lz[v]+=x;
        return shift(v,l,r);
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,tr,x);
    upd(rc,m,r,tl,tr,x);
    f[v]=max(f[lc],f[rc]);
}
void sfd(ll v, ll p){
    vec.pb({f[1],v});
    for(auto [u,w] : adj[v]){
        if(u==p) continue;
        upd(1,1,n+1,1,n+1,w);
        upd(1,1,n+1,st[u],fn[u]+1,-2*w);
        sfd(u,v);
        upd(1,1,n+1,1,n+1,-w);
        upd(1,1,n+1,st[u],fn[u]+1,2*w);
    }
}
ll gp(ll x){
    return p[x]?p[x]=gp(p[x]):x;
}
void uni(ll v, ll u){
    v=gp(v);
    u=gp(u);
    if(v==u) return;
    sz[v]+=sz[u];
    p[u]=v;
    ans=max(ans,sz[v]);
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<n; i++){
        ll v,u,w;
        cin >> v >> u >> w;
        adj[v].pb({u,w});
        adj[u].pb({v,w});
    }
    cin >> q;
    dfs(1,0);
    for(ll i=1; i<=n; i++) upd(1,1,n+1,st[i],st[i]+1,h[i]);
    sfd(1,0);
    sort(vec.begin(),vec.end(),greater<>());
    while(q--){
        ll l;
        cin >> l;
        ans=1;
        memset(fl,0,sizeof fl);
        while(!qe.empty()) qe.pop();
        for(auto [d,v] : vec){
            while(!qe.empty() && qe.front().F>d+l){
                sz[gp(qe.front().S)]--;
                qe.pop();
            }
            p[v]=0;
            sz[v]=1;
            for(auto [u,w] : adj[v]){
                if(fl[u]) uni(v,u);
            }
            qe.push({d,v});
            fl[v]=1;
        }
        cout << ans << '\n';
    }
    return 0;
}