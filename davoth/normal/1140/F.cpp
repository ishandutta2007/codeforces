#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
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
const int N=3e5+10,LN=24,M=1e7+10,SQ=500,B=737,inf=1e9;
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
ll q,p[N*2],sz[2][N*2],ans;
vector<ll> st;
vector<pll> f[N*4];
set<pair<pll,ll>> ed;
ll gp(ll x){
    return p[x]?gp(p[x]):x;
}
void uni(ll v, ll u){
    v=gp(v);
    u=gp(u);
    if(v==u) st.pb(0);
    else{
        if(sz[0][v]+sz[1][v]<sz[0][u]+sz[1][u]) swap(v,u);
        st.pb(u);
        p[u]=v;
        ans+=sz[1][v]*sz[0][u]+sz[0][v]*sz[1][u];
        sz[0][v]+=sz[0][u];
        sz[1][v]+=sz[1][u];
    }
}
void und(){
    ll v=st.back();
    st.pop_back();
    sz[0][p[v]]-=sz[0][v];
    sz[1][p[v]]-=sz[1][v];
    ans-=sz[0][p[v]]*sz[1][v]+sz[1][p[v]]*sz[0][v];
    p[v]=0;
}
void upd(ll v, ll l, ll r, ll tl, ll tr, pll p){
    if(l>=tr || tl>=r) return;
    if(l>=tl && r<=tr){
        f[v].pb(p);
        return;
    }
    ll m=(l+r)>>1;
    upd(lc,l,m,tl,tr,p);
    upd(rc,m,r,tl,tr,p);
}
void build(ll v, ll l, ll r){
    for(pll p : f[v]){
        uni(p.F,p.S);
    }
    if(r-l==1){
        cout << ans << ' ';
    }else{
        ll m=(l+r)>>1;
        build(lc,l,m);
        build(rc,m,r);
    }
    for(pll p : f[v]){
        und();
    }
}
int main(){
    fast_io;
    cin >> q;
    for(ll i=1; i<N; i++){
        sz[0][i]=1;
        sz[1][i+N]=1;
    }
    for(ll i=1; i<=q; i++){
        ll v,u;
        cin >> v >> u;
        u+=N;
        auto it=ed.lower_bound({{v,u},0});
        if(it==ed.end() || it->F.F!=v || it->F.S!=u){
            ed.insert({{v,u},i});
        }else{
            upd(1,1,q+1,it->S,i,{v,u});
            ed.erase(it);
        }
    }
    for(pair<pll,ll> p : ed){
        upd(1,1,q+1,p.S,q+1,p.F);
    }
    build(1,1,q+1);
    cout << '\n';
    return 0;
}