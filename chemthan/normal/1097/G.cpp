#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
template<class T> inline void addmod(T& a, T val, T p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 1e5 + 5;
const int maxk = 200 + 5;
int n, k;
int size[maxn];
vi adj[maxn];
int dp[maxn][maxk][2];
int dp2[maxn][maxk][2];
int p2[maxn];
int fac[maxn];
int ifac[maxn];

void dfs(int u, int p) {
    size[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            size[u] += size[v];
            static long long f[maxk][2];
            ms(f, 0);
            static long long SQMOD = (long long) MOD * MOD;
            FOR(i, 1, k + 1) {
                addmod(f[i][0], (long long) dp[u][i][0], SQMOD);
                addmod(f[i][0], (long long) dp[v][i][0], SQMOD);
                
                addmod(f[i][1], (long long) dp[u][i][1] * p2[size[v]], SQMOD);
                addmod(f[i][1], (long long) dp[u][i][0] * (p2[size[v]] - 1 + MOD), SQMOD);
                addmod(f[i][1], (long long) dp[v][i][0] * (p2[size[u] - size[v] - 1] - 1 + MOD), SQMOD);
            }
            FOR(i, 1, k + 1) addmod(dp[u][i][0], dp[u][i][1]);
            FOR(i, 1, k + 1) {
                if (dp[v][i][0]) {
                    int hi = min(k - i, size[u] - size[v] - 1);
                    FOR(j, 1, hi + 1) {
                        addmod(f[i + j][1], (long long) dp[u][j][0] * dp[v][i][0], SQMOD);
                    }
                }
            }
            FOR(i, 0, k + 1) FOR(j, 0, 2) dp[u][i][j] = f[i][j] % MOD;
        }
    }
    FORd(i, k + 1, 1) {
        FOR(j, 0, 2) dp2[u][i][j] = dp[u][i][j];
        addmod(dp[u][i][0], dp[u][i][1]);
        addmod(dp[u][i][0], dp[u][i][0]);
        if (i == 1) {
            addmod(dp[u][i][0], (p2[size[u]] - 1 + MOD) % MOD);
        }
        else {
            addmod(dp[u][i][0], dp[u][i - 1][0]);
            addmod(dp[u][i][0], dp[u][i - 1][0]);
            addmod(dp[u][i][0], dp[u][i - 1][1]);
            addmod(dp[u][i][0], dp[u][i - 1][1]);
        }
    }
}

int f[maxk][maxk];
int calc(int u, int v) {
    if (!v) return u == 0;
    int& res = f[u][v];
    if (~res) return res;
    res = 0;
    FOR(i, 1, u + 1) {
        addmod(res, mult(calc(u - i, v - 1), ifac[i]));
    }
    return res;
}

void chemthan() {
    FOR(i, 0, maxn) p2[i] = fpow(2, i);
    fac[0] = 1; FOR(i, 1, maxn) fac[i] = mult(fac[i - 1], i);
    FOR(i, 0, maxn) ifac[i] = inv(fac[i]);
    cin >> n >> k;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1);
    ms(f, -1);
    int res = 0;
    FOR(i, 1, k + 1) {
        int coef = mult(fac[k], calc(k, i));
        FOR(u, 0, n) {
            addmod(res, mult(dp2[u][i][0], coef));
            addmod(res, mult(2 * dp2[u][i][1], coef));
        }
    }
    cout << res << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}