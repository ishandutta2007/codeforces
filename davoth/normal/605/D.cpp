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
const int N=2e5+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
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
ll n,a[N],b[N],x[N],y[N],d[N],m,pr[N];
pll f[N*4];
queue<ll> q;
vector<ll> cp={0},ans;
vector<pll> nx[N];
void upd(ll v, ll l, ll r, ll p, pll x){
    if(r-l==1){
        f[v]=x;
        return;
    }
    ll m=(l+r)>>1;
    if(p<m) upd(lc,l,m,p,x);
    else upd(rc,m,r,p,x);
    f[v]=min(f[lc],f[rc]);
}
pll get(ll v, ll l, ll r, ll tl, ll tr){
    if(tl>=r || l>=tr) return mp(INF,-1ll);
    if(l>=tl && r<=tr) return f[v];
    ll m=(l+r)>>1;
    return min(get(lc,l,m,tl,tr),get(rc,m,r,tl,tr));
}
void nxt(ll i){
    pll p;
    if(nx[i].empty()) p={INF,-1ll};
    else{
        p=nx[i].back();
        nx[i].pop_back();
    }
    upd(1,0,m,i,p);
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i] >> b[i] >> x[i] >> y[i];
        cp.pb(a[i]);
        cp.pb(x[i]);
    }
    sort(cp.begin(),cp.end());
    cp.resize(unique(cp.begin(),cp.end())-cp.begin());
    m=cp.size();
    for(ll i=1; i<=n; i++){
        a[i]=lower_bound(cp.begin(),cp.end(),a[i])-cp.begin();
        x[i]=lower_bound(cp.begin(),cp.end(),x[i])-cp.begin();
    }
    cp={0};
    for(ll i=1; i<=n; i++){
        cp.pb(b[i]);
        cp.pb(y[i]);
    }
    sort(cp.begin(),cp.end());
    cp.resize(unique(cp.begin(),cp.end())-cp.begin());
    for(ll i=1; i<=n; i++){
        b[i]=lower_bound(cp.begin(),cp.end(),b[i])-cp.begin();
        y[i]=lower_bound(cp.begin(),cp.end(),y[i])-cp.begin();
    }
    for(ll i=1; i<=n; i++){
        nx[a[i]].pb({b[i],i});
    }
    for(ll i=0; i<m; i++){
        sort(nx[i].begin(),nx[i].end(),greater<>());
        nxt(i);
    }
    q.push(0);
    memset(d,63,sizeof d);
    d[0]=0;
    while(!q.empty()){
        ll v=q.front(),t=x[v],w=y[v];
        q.pop();
        pll p;
        while((p=get(1,0,m,0,t+1)).F<=w){
            ll u=p.S;
            pr[u]=v;
            d[u]=d[v]+1;
            q.push(u);
            nxt(a[u]);
        }
    }
    if(d[n]>n){
        cout << -1 << '\n';
        return 0;
    }
    ll v=n;
    while(v){
        ans.pb(v);
        v=pr[v];
    }
    reverse(ans.begin(),ans.end());
    cout << d[n] << '\n';
    for(ll i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}