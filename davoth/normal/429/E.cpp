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
#define kill(x) cout << x << '\n';exit(0);
const int N=2e5+10,LN=24,M=1e7+10,SQ=500,B=737,inf=1e9;
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
ll n,m,ans[N],l[N],r[N],t,ls=-1,fl[N];
vector<ll> vec={0,inf};
vector<pll> adj[N];
void dfs(ll v){
    while(!adj[v].empty()){
        auto [u,i]=adj[v].back();
        adj[v].pop_back();
        if(fl[i]) continue;
        fl[i]=1;
        ans[i]=v<u;
        dfs(u);
    }
}
int main(){
    fast_io;
    cin >> m;
    for(ll i=1; i<=m; i++){
        cin >> l[i] >> r[i];
        r[i]++;
        vec.pb(l[i]);
        vec.pb(r[i]);
    }
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    n=vec.size();
    for(ll i=1; i<=m; i++){
        l[i]=lower_bound(vec.begin(),vec.end(),l[i])-vec.begin();
        r[i]=lower_bound(vec.begin(),vec.end(),r[i])-vec.begin();
        adj[l[i]].pb({r[i],i});
        adj[r[i]].pb({l[i],i});
    }
    for(ll i=0; i<n; i++){
        if(adj[i].size()&1){
            if(~ls){
                ++t;
                adj[i].pb({ls,m+t});
                adj[ls].pb({i,m+t});
                ls=-1;
            }else ls=i;
        }
    }
    for(ll i=0; i<n; i++) if(!adj[i].empty()) dfs(i);
    for(ll i=1; i<=m; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}