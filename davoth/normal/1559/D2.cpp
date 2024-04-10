#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
/*#pragma comment(linker, "/stack:200000000")
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
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=5e6,SQ=350,B=737,inf=1e9+10;
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
ll n,m[2],p[2][N],f[N];
vector<pll> ans;
vector<ll> cp[2][N];
ll gp(ll c, ll x){
    return p[c][x]?p[c][x]=gp(c,p[c][x]):x;
}
void uni(ll c, ll v, ll u){
    v=gp(c,v);
    u=gp(c,u);
    if(v==u) return;
    if(cp[c][v].size()<cp[c][u].size()) swap(v,u);
    p[c][u]=v;
    for(ll i : cp[c][u]) cp[c][v].pb(i);
}
void unit(ll v, ll u){
    v=gp(0,v);
    u=gp(1,u);
    for(ll i : cp[0][v]) f[i]=-1;
    for(ll i : cp[1][u]) f[i]=-1;
    uni(0,v,u);
    uni(1,v,u);
}
int main(){
    fast_io;
    cin >> n >> m[0] >> m[1];
    for(ll i=1; i<=n; i++){
        cp[0][i].pb(i);
        cp[1][i].pb(i);
    }
    for(ll t=0; t<2; t++){
        for(ll i=1; i<=m[t]; i++){
            ll v,u;
            cin >> v >> u;
            uni(t,v,u);
        }
    }
    for(ll i=1; i<=1; i++){
        for(ll j=i+1; j<=n; j++){
            if(gp(0,i)!=gp(0,j) && gp(1,i)!=gp(1,j)){
                uni(0,i,j);
                uni(1,i,j);
                ans.pb({i,j});
            }
        }
    }
    for(ll i=1; i<=n; i++){
        if(gp(0,i)==gp(0,1) && gp(1,i)!=gp(1,1)) f[i]=1;
        else if(gp(0,i)!=gp(0,1)) f[i]=0;
        else f[i]=-1;
    }
    ll p1=1,p2=1;
    while(true){
        while(p1<=n && f[p1]!=0) p1++;
        while(p2<=n && f[p2]!=1) p2++;
        if(p1>n || p2>n) break;
        unit(p1,p2);
        ans.pb({p1,p2});
    }
    cout << ans.size() << '\n';
    for(auto [i,j] : ans) cout << i << ' ' << j << '\n';
    return 0;
}