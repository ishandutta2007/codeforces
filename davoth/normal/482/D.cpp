/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=1e5+10,LN=22,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,dp[N][2];
vector<ll> adj[N];
void dfs(ll v){
    ll a=1,b=1,c=0;
    dp[v][1]=1;
    for(ll u : adj[v]){
        dfs(u);
        ll x=dp[v][0],y=dp[v][1];
        dp[v][0]=(x*(dp[u][0]+1)+y*dp[u][1])%MOD;
        dp[v][1]=(x*dp[u][1]+y*(dp[u][0]+1))%MOD;
        a=a*(dp[u][0]+1)%MOD;
        ll bb=b,cc=c;
        b=(bb+cc*dp[u][1])%MOD;
        c=(cc+bb*dp[u][1])%MOD;
    }
    dp[v][0]=(dp[v][0]*2+MOD-c)%MOD;
    dp[v][1]=(dp[v][1]*2+MOD-a)%MOD;
}
int main(){
    fast_io;
    cin >> n;
    for(ll i=2; i<=n; i++){
        ll p;
        cin >> p;
        adj[p].pb(i);
    }
    dfs(1);
    cout << (dp[1][0]+dp[1][1])%MOD << '\n';
    return 0;
}