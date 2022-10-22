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
const int N=5e5+10,LN=20,M=1.1e7+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007  /*998244353*/;
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
int n,a[N],b[N],k,f[N*4],ans[N];
bitset<M> fl;
vector<int> adj[M],tp;
void build(int v, int l, int r){
    if(r-l==1){
        f[v]=l;
        return;
    }
    f[v]=++k;
    int m=(l+r)>>1;
    build(lc,l,m);
    build(rc,m,r);
    adj[f[v]].pb(f[lc]);
    adj[f[v]].pb(f[rc]);
}
void add(int v, int l, int r, int tl, int tr, int x){
    if(tl>=tr) return;
    if(tl==l && tr==r){
        if(f[v]) adj[x].pb(f[v]);
        return;
    }
    int m=(l+r)>>1;
    add(lc,l,m,tl,min(m,tr),x);
    add(rc,m,r,max(m,tl),tr,x);
}
void rem(int v, int l, int r, int p){
    if(r-l==1){
        f[v]=0;
        return;
    }
    f[v]=++k;
    int m=(l+r)>>1;
    if(p<m) rem(lc,l,m,p);
    else rem(rc,m,r,p);
    if(f[lc]) adj[f[v]].pb(f[lc]);
    if(f[rc]) adj[f[v]].pb(f[rc]);
}
void dfs(int v){
    fl[v]=1;
    for(int u : adj[v]) if(!fl[u]) dfs(u);
    if(v<=n) tp.pb(v);
}
int main(){
    fast_io;
    cin >> n;
    k=n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(~a[i]) b[a[i]]=i;
    }
    for(int i=1; i<=n; i++){
        if(b[i]) adj[i].pb(b[i]);
    }
    build(1,1,n+1);
    for(int i=1; i<=n; i++){
        if(a[i]==-1) a[i]=n+1;
        if(a[i]<i) add(1,1,n+1,1,a[i],i);
        else{
            add(1,1,n+1,1,i,i);
            add(1,1,n+1,i+1,a[i],i);
        }
        if(a[i]<=n) rem(1,1,n+1,a[i]);
    }
    for(int i=1; i<=k; i++) if(!fl[i]) dfs(i);
    reverse(tp.begin(),tp.end());
    for(int i=0; i<n; i++){
        ans[tp[i]]=n-i;
    }
    for(int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}