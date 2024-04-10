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
ll t,n,ans[N],f[N];
vector<ll> adj[N];
bool dfs(ll v, ll p, ll k){
    f[v]=0;
    ll x=0;
    for(ll u : adj[v]){
        if(u==p) continue;
        if(!dfs(u,v,k)) return false;
        if(!f[u]) x++;
    }
    if(x%k==k-1) f[v]=1,x++;
    return x%k==0;
}
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n;
        for(ll i=1; i<=n; i++){
            adj[i]={};
            ans[i]=0;
        }
        ans[1]=pow(2,n-1,MD);
        for(ll i=1; i<n; i++){
            ll v,u;
            cin >> v >> u;
            adj[v].pb(u);
            adj[u].pb(v);
        }
        for(ll i=2; i<n; i++){
            if((n-1)%i==0){
                ans[i]=dfs(1,0,i);
            }
        }
        for(ll i=n; i; i--){
            for(ll j=i+i; j<=n; j+=i) ans[i]-=ans[j];
        }
        ans[1]=(ans[1]+MD)%MD;
        for(ll i=1; i<=n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}