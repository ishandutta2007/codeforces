#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
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
const int N=2e5+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e18;
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
ll n,e,q,an[N],p[N],sz[N],c[N],ans;
pll ed[N];
vector<ll> st;
pll gp(ll x){
    if(!p[x]) return {x,0};
    else{
        pll t=gp(p[x]);
        t.S^=c[x];
        return t;
    }
}
void uni(ll i){
    auto [v,u]=ed[i];
    pll a=gp(v),b=gp(u);
    if(a.F==b.F){
        if(a.S==b.S) ans++,st.pb(-1);
        else st.pb(0);
        return;
    }
    if(sz[a.F]<sz[b.F]) swap(a,b);
    p[b.F]=a.F;
    st.pb(b.F);
    sz[a.F]+=sz[b.F];
    c[b.F]=a.S^b.S^1;
}
void und(){
    ll v=st.back();
    st.pop_back();
    if(!v) return;
    if(v==-1){
        ans--;
        return;
    }
    pll t=gp(v);
    sz[t.F]-=sz[v];
    p[v]=c[v]=0;
}
void solve(ll l, ll r, ll tl, ll tr){
    if(l>r) return;
    ll m=(l+r)>>1;
    for(ll i=l; i<m; i++) uni(i);
    ll i=min(e,tr);
    while(!ans && i>=m) uni(i--);
    an[m]=i;
    while(i<min(e,tr)) und(),i++;
    uni(m);
    solve(m+1,r,an[m],tr);
    for(ll i=l; i<=m; i++) und();
    while(i>an[m]) uni(i--);
    solve(l,m-1,tl,an[m]);
    while(i<min(e,tr)) und(),i++;
}
int main(){
    fast_io;
    cin >> n >> e >> q;
    for(ll i=1; i<=e; i++) cin >> ed[i].F >> ed[i].S;
    for(ll i=1; i<=n; i++) sz[i]=1;
    solve(1,e,1,e+1);
    //for(ll i=1; i<=e; i++) cout << an[i] << ' ';
    while(q--){
        ll l,r;
        cin >> l >> r;
        if(r>an[l]) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}