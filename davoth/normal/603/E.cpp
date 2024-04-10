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
const int N=5e5+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
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
ll n,q,sz[N],ans,p[N],w[N],an[N],rv[N];
vector<ll> st;
vector<pll> s={{-1,-1}};
pll ed[N];
ll gp(ll x){
    return p[x]?gp(p[x]):x;
}
void uni(ll i){
    auto [v,u]=ed[i];
    v=gp(v);
    u=gp(u);
    if(v==u){
        st.pb(0);
        return;
    }
    if(sz[v]<sz[u]) swap(v,u);
    ans-=sz[v]%2+sz[u]%2;
    sz[v]+=sz[u];
    ans+=sz[v]%2;
    p[u]=v;
    st.pb(u);
}
void und(){
    ll v=st.back();
    st.pop_back();
    if(v){
        ans-=sz[p[v]]%2;
        sz[p[v]]-=sz[v];
        ans+=sz[p[v]]%2+sz[v]%2;
        p[v]=0;
    }
}
void solve(ll l, ll r, ll tl, ll tr){
    if(l>r) return;
    ll m=(l+r)>>1;
    for(ll i=l; i<=m; i++){
        if(rv[i]<tl) uni(i);
    }
    for(ll i=tl; i<=min(tr,q) && ans; i++){
        if(s[i].S<=m){
            an[m]=i;
            uni(s[i].S);
        }
    }
    if(ans) an[m]=q+1;
    for(ll i=tl; i<=min(an[m],q); i++){
        if(s[i].S<=m){
            und();
        }
    }
    solve(m+1,r,tl,an[m]);
    for(ll i=l; i<=m; i++){
        if(rv[i]<tl) und();
    }
    for(ll i=tl; i<an[m]; i++){
        if(s[i].S<l) uni(s[i].S);
    }
    solve(l,m-1,an[m],tr);
    for(ll i=tl; i<an[m]; i++){
        if(s[i].S<l) und();
    }
}
int main(){
    fast_io;
    cin >> n >> q;
    ans=n;
    for(ll i=1; i<=n; i++) sz[i]=1;
    for(ll i=1; i<=q; i++){
        cin >> ed[i].F >> ed[i].S >> w[i];
        s.pb({w[i],i});
    }
    sort(s.begin(),s.end());
    for(ll i=1; i<=q; i++) rv[s[i].S]=i;
    solve(1,q,1,q+1);
    for(ll i=1; i<=q; i++){
        if(an[i]==q+1) an[i]=-1;
        else an[i]=s[an[i]].F;
        cout << an[i] << '\n';
    }
    return 0;
}