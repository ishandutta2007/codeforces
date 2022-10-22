#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=19,M=14348907,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=1000000007,MOD=998244353;
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
ll n,p[N],sz[N],t,c[N],s[N];
vector<pll> ans;
void sp(ll v, ll u){
    swap(p[v],p[u]);
    ans.pb({v,u});
}
void cyc(ll v, ll u, ll d=0){
    if(!d) sp(v,u);
    while(true){
        if(p[v]==u) swap(v,u);
        if(p[v]==u) break;
        sp(v,p[v]);
    }
    sp(v,u);
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> p[i];
    }
    for(ll i=1; i<=n; i++){
        if(p[i]!=i && !c[i]){
            s[++t]=i;
            sz[c[i]=t]++;
            for(ll v=p[i]; v!=i; v=p[v]) sz[c[v]=t]++;
        }
    }
    for(ll i=1; i<=t/2; i++) cyc(s[i*2-1],s[i*2]);
    if(t%2){
        if(sz[t]==n){
            ll v=1,u=p[1];
            sp(v,u);
            sp(u,p[v]);
            cyc(v,u,1);
        }else{
            for(ll i=1; i<=n; i++){
                if(c[i]!=t){
                    cyc(s[t],i);
                    break;
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto [x,y] : ans) cout << x << ' ' << y << '\n';
    return 0;
}