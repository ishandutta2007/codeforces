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
const int N=1e6+10,LN=39,M=5e6,SQ=350,B=737,inf=1e9+10;
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
ll n,q,p[N],a[N];
vector<ll> pr[N],ed[N];
ll gp(ll x){
    return p[x]?p[x]=gp(p[x]):x;
}
void uni(ll v, ll u){
    v=gp(v);
    u=gp(u);
    if(v==u) return;
    p[u]=v;
}
int main(){
    fast_io;
    for(ll i=2; i<N; i++){
        if(pr[i].empty()){
            for(ll j=i; j<N; j+=i) pr[j].pb(i);
        }
    }
    cin >> n >> q;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        for(ll j=1; j<pr[a[i]].size(); j++){
            for(ll k=0; k<j; k++){
                uni(pr[a[i]][j],pr[a[i]][k]);
            }
        }
    }
    for(ll i=1; i<=n; i++){
        ll v=gp(pr[a[i]][0]);
        for(ll j=0; j<pr[a[i]+1].size(); j++){
            ll x=gp(pr[a[i]+1][j]);
            ed[x].pb(v);
            for(ll k=0; k<j; k++){
                ed[x].pb(gp(pr[a[i]+1][k]));
            }
        }
    }
    for(ll i=1; i<N; i++){
        ed[i].pb(inf);
        sort(ed[i].begin(),ed[i].end());
    }
    while(q--){
        ll x,y,ans=2;
        cin >> x >> y;
        x=gp(pr[a[x]][0]);
        y=gp(pr[a[y]][0]);
        if(x==y) ans=0;
        else if(*lower_bound(ed[x].begin(),ed[x].end(),y)==y || *lower_bound(ed[y].begin(),ed[y].end(),x)==x) ans=1;
        cout << ans << '\n';
    }
    return 0;
}