#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20,SQ=547,M=1e6+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,q,L[N],R[N],W[N],w,t,f[2][4*N][5],lz[4*N],ls,H[N],h[N];
vector<pll> adj[N];
void dfs(ll v, ll p){
    for(auto [u,i] : adj[v]){
        if(u==p) continue;
        L[i]=++t;
        H[u]=H[v]+1;
        h[t]=H[u];
        dfs(u,v);
        R[i]=++t;
        h[t]=H[v];
    }
}
void shift(ll v, ll l, ll r){
    if(!lz[v]) return;
    for(ll i=0; i<5; i++) swap(f[0][v][i],f[1][v][i]);
    if(r-l>1) lz[v*2]^=1,lz[v*2+1]^=1;
    lz[v]=0;
}
void merge(ll v, ll c){
    f[c][v][4]=max({f[c][v*2][0]+f[c][v*2+1][3],f[c][v*2][2]+f[c][v*2+1][0],f[c][v*2][4],f[c][v*2+1][4]});
    f[c][v][0]=max(f[c][v*2][0],f[c][v*2+1][0]);
    f[c][v][1]=min(f[c][v*2][1],f[c][v*2+1][1]);
    f[c][v][2]=max({f[c][v*2][2],f[c][v*2+1][2],f[c][v*2][0]-2*f[c][v*2+1][1]});
    f[c][v][3]=max({f[c][v*2][3],f[c][v*2+1][3],f[c][v*2+1][0]-2*f[c][v*2][1]});
}
void build(ll v, ll l, ll r){
    if(r-l<=1){
        f[0][v][0]=h[l];
        f[0][v][1]=h[l];
        f[0][v][2]=-h[l];
        f[0][v][3]=-h[l];
        for(ll i=0; i<4; i++) f[1][v][i]=-INF;
        f[1][v][1]=h[l];
        return;
    }
    ll m=(l+r)/2;
    build(v*2,l,m);
    build(v*2+1,m,r);
    merge(v,0);
    merge(v,1);
}
void update(ll v, ll l, ll r, ll tl, ll tr){
    shift(v,l,r);
    if(tl>=tr) return;
    if(l==tl && r==tr){
        lz[v]^=1;
        return shift(v,l,r);
    }
    ll m=(l+r)/2;
    update(v*2,l,m,tl,min(tr,m));
    update(v*2+1,m,r,max(tl,m),tr);
    merge(v,0);
    merge(v,1);
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u >> W[i];
        adj[v].emplace_back(u,i);
        adj[u].emplace_back(v,i);
    }
    dfs(1,0);
    build(1,0,t);
    for(ll i=1; i<n; i++) if(W[i]) update(1,0,t,L[i],R[i]);
    cin >> q;
    while(q--){
        ll i;
        cin >> i;
        update(1,0,t,L[i],R[i]);
        cout << max(f[1][1][4],f[0][1][4]) << '\n';
    }
    return 0;
}