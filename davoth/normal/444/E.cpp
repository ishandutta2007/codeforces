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
const int N=1e5+10,LN=20,M=1e6+10,SQ=350,B=737,inf=1e9;
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
ll n,s,x[N],sz[N],p[N],t,ans;
vector<pair<ll,pll>> ed;
ll gp(ll x){
    return p[x]?p[x]=gp(p[x]):x;
}
void uni(ll v, ll u){
    v=gp(v);
    u=gp(u);
    sz[v]+=sz[u];
    x[v]+=x[u];
    p[u]=v;
    if(s-x[v]<sz[v]) t=1;
}
int main(){
    fast_io;
    cin >> n;
    for(int i=0; i<n-1; i++){
        ll v,u,w;
        cin >> v >> u >> w;
        ed.pb({w,{v,u}});
    }
    for(int i=1; i<=n; i++){
        cin >> x[i];
        s+=x[i];
        sz[i]=1;
    }
    sort(ed.begin(),ed.end());
    for(int i=0; i<ed.size() && !t; i++){
        ans=ed[i].F;
        uni(ed[i].S.F,ed[i].S.S);
    }
    cout << ans << '\n';
    return 0;
}