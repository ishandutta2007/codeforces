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
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=1e5+10,LN=18,M=5e3+10,SQ=350,BS=737,inf=1.05e9,NSQ=N/SQ+1;
//const ll INF=1e18;
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
ll n,q,a[LN][N],L[M],R[M],X[M],pp[M];
pll wtf[M];
ld dp[M][M],P[M],ans;
vector<ll> adj[M];
ll get(ll l, ll r){
    ll lg=64-__builtin_clzll(r-l+1)-1;
    return max(a[lg][l],a[lg][r-(1<<lg)+1]);
}
void dfs(ll v){
    for(ll u : adj[v]) dfs(u);
    ll x=X[v];
    dp[v][0]=1;
    ld p=0,lp;
    for(ll i=1; i<=q; i++){
        x++;
        lp=p;
        p=1;
        dp[v][i]+=(1-lp)*P[v];
        for(ll u : adj[v]){
            ll y=X[u];
            if(x-y<=q) p*=1-dp[u][x-y];
        }
        dp[v][i]+=(1-p)*(1-P[v]);
    }
}
int main(){
    fast_io;
    cin >> n >> q;
    for(ll i=1; i<=n; i++){
        cin >> a[0][i];
    }
    for(ll j=1; j<LN; j++){
        for(ll i=1; i<=n; i++){
            a[j][i]=a[j-1][i];
            if(i+(1<<(j-1))<=n) a[j][i]=max(a[j][i],a[j-1][i+(1<<(j-1))]);
        }
    }
    L[0]=1;
    R[0]=n;
    X[0]=a[LN-1][1];
    for(ll i=1; i<=q; i++){
        cin >> L[i] >> R[i] >> P[i];
        X[i]=get(L[i],R[i]);
        wtf[i]={R[i]-L[i]+1,-i};
    }
    wtf[0]={n,0};
    sort(wtf,wtf+q+1);
    for(ll i=0; i<=q; i++){
        ll x=-wtf[i].S;
        for(ll j=0; j<i; j++){
            ll y=-wtf[j].S;
            if(!pp[y] && L[x]<=L[y] && R[x]>=R[y]){
                pp[y]=1;
                adj[x].pb(y);
            }
        }
    }
    dfs(0);
    ans=X[0];
    for(ll i=1; i<=q; i++) ans+=dp[0][i];
    cout << setprecision(9) << fixed << ans << '\n';
    return 0;
}