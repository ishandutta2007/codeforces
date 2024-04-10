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
const int N=4e3+10,LN=60,M=6.32e7+10,SQ=350,BS=737,inf=1.05e9,NSQ=N/SQ+1;
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
ll n,ans,wtf,k,hd[N],sz[N],dp[100][N],pd[100][N],an[2][100],F[N],IV[N];
vector<ll> adj[N];
void plant(ll v, ll p=0){
    sz[v]=1;
    for(ll u : adj[v]){
        if(!hd[u] && u!=p){
            plant(u,v);
            sz[v]+=sz[u];
        }
    }
}
ll find_centroid(ll v, ll n){
    ll p=0,f=1;
    while(f){
        f=0;
        for(ll u : adj[v]){
            if(!hd[u] && u!=p && sz[u]*2>n){
                p=v;
                v=u;
                f=1;
                break;
            }
        }
    }
    return v;
}
void dfs(ll v, ll k, ll r, ll p=0){
    for(ll u : adj[v]){
        if(hd[u]) continue;
        dp[k][v]=(dp[k][v]+dp[k-1][u])%MD;
        if(v!=r) pd[k][v]=(pd[k][v]+pd[k-1][u])%MD;
        if(u!=p) dfs(u,k,r,v);
    }
}
void sfd(ll v, ll p=0){
    for(ll i=0; i<=k; i++){
        for(ll j=0; i+j<=k; j++){
            an[0][i+j]=(an[0][i+j]+dp[i][v]*pd[j][v])%MD;
        }
    }
    for(ll u : adj[v]){
        if(!hd[u] && u!=p) sfd(u,v);
    }
}
void solve(ll v){
    plant(v);
    v=find_centroid(v,sz[v]);
    memset(dp,0,sizeof dp);
    memset(pd,0,sizeof pd);
    dp[0][v]=pd[0][v]=1;
    for(ll i=1; i<=k; i++) dfs(v,i,v);
    sfd(v);
    hd[v]=1;
    for(ll u : adj[v]) if(!hd[u]) solve(u);
}
int main(){
    fast_io;
    F[0]=IV[0]=1;
    for(ll i=1; i<N; i++){
        F[i]=i*F[i-1]%MD;
        IV[i]=pow(F[i],MD-2,MD);
    }
    cin >> n >> wtf >> k;
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    solve(1);
    n=wtf;
    for(ll i=0; i<=k; i++){
        an[1][i]=an[0][i];
        an[0][i]=0;
    }
    for(ll i=1; i<=n; i++) adj[i].clear();
    for(ll i=1; i<n; i++){
        ll v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    memset(hd,0,sizeof hd);
    solve(1);
    for(ll i=0; i<=k; i++){
        ans=(ans+an[0][i]*an[1][k-i]%MD*F[k]%MD*IV[i]%MD*IV[k-i])%MD;
    }
    cout << ans << '\n';
    return 0;
}