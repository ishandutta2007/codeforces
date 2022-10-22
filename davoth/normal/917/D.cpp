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
const int N=1e2+10,LN=60,M=1e6+10,SQ=700,BS=737,inf=1.05e9,NSQ=N/SQ+3;
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
ll n, dp[2][N][N][N], sz[N], iv[N], ans[N], f[N], fiv[N];
vector<ll> adj[N];
void dfs(ll v, ll p){
    dp[0][v][0][1] = sz[v] = 1;
    for(ll u : adj[v]){
        if(u == p) continue;
        dfs(u, v);
        for(ll i = 0; i < sz[v] + sz[u]; i++){
            for(ll j = 1; j <= sz[v] + sz[u]; j++){
                dp[1][v][i][j] = dp[0][v][i][j];
                dp[0][v][i][j] = 0;
            }
        }
        for(ll a = 0; a < sz[v]; a++){
            for(ll b = 1; b <= sz[v]; b++){
                for(ll x = 0; x < sz[u]; x++){
                    for(ll y = 1; y <= sz[u]; y++){
                        dp[0][v][a + x][b] = (dp[0][v][a + x][b] + dp[1][v][a][b] * dp[0][u][x][y]) % MOD;
                        dp[0][v][a + x + 1][b + y] = (dp[0][v][a + x + 1][b + y] + dp[1][v][a][b] * dp[0][u][x][y] % MOD * iv[b] % MOD * iv[y] % MOD * (b + y)) % MOD;
                    }
                }
            }
        }
        sz[v] += sz[u];
    }
}
ll C(ll n, ll k){
    if(k > n || k < 0) return 0;
    return f[n] * fiv[k] % MOD * fiv[n-k] % MOD;
}
int main(){
    fast_io;
    f[0] = fiv[0] = 1;
    for(ll i = 1; i < N; i++){
        iv[i] = pow(i, MOD-2, MOD);
        f[i] = i * f[i - 1] % MOD;
        fiv[i] = iv[i] * fiv[i - 1] % MOD;
    }
    cin >> n;
    for(ll i = 1; i < n; i++){
        ll v, u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1, 0);
    for(ll i = 0; i < n-1; i++){
        for(ll j = 1; j <= n; j++){
            ans[i] = (ans[i] + dp[0][1][i][j]) % MOD;
        }
        ans[i] = ans[i] * pow(n, n - i - 2, MOD) % MOD;
    }
    ans[n - 1] = 1;
    for(ll i = n - 1; i >= 0; i--){
        for(ll j = 0; j < i; j++) ans[j] = (ans[j] + MOD - C(i, j) * ans[i] % MOD) % MOD;
    }
    for(ll i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}