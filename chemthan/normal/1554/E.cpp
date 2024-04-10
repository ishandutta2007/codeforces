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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
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
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

void chemthan() {
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<vi> adj(n);
        FOR(i, 0, n - 1) {
            int u, v; cin >> u >> v; u--, v--;
            adj[u].pb(v), adj[v].pb(u);
        }
        vi res(n + 1);
        res[1] = fpow(2, n - 1);
        FORd(d, n, 2) if ((n - 1) % d == 0) {
            auto solve = [&] () {
                vi layer;
                vi f(n);
                vi g(n);
                vi rem(n);
                int num = n;
                FOR(u, 0, n) if (sz(adj[u]) == 1) {
                    layer.pb(u);
                    f[u] = 1;
                    rem[u] = 1;
                }
                while (sz(layer)) {
                    if (num == 1) {
                        int u = layer[0];
                        return f[u] == 1 ? 1 : 0;
                    }
                    if (num == 2) {
                        int u = layer[0];
                        int v = layer[1];
                        if (f[u] == 0 && f[v] == 1) {
                            return 1;
                        }
                        if (f[u] == 1 && f[v] == 0) {
                            return 1;
                        }
                        return 0;
                    }
                    vi nlayer;
                    for (int u : layer) {
                        for (int v : adj[u]) if (!rem[v]) {
                            nlayer.pb(v);
                            g[v] += f[u];
                        }
                    }
                    num -= sz(layer);
                    sort(all(nlayer)), uni(nlayer);
                    layer = nlayer;
                    nlayer.clear();
                    for (int u : layer) {
                        int cnt = 0;
                        for (int v : adj[u]) {
                            cnt += rem[v];
                        }
                        if (sz(adj[u]) <= cnt + 1) {
                            nlayer.pb(u);
                        }
                    }
                    layer = nlayer;
                    for (int u : layer) {
                        rem[u] = 1;
                        if (g[u] % d == 0) {
                            f[u] = 1;
                        }
                        else if ((g[u] + 1) % d == 0) {
                            f[u] = 0;
                        }
                        else {
                            return 0;
                        }
                    }
                }
                return 1;
            };
            res[d] = solve();
        }
        FORd(i, n + 1, 2) if (res[i]) {
            for (int j = 2; j * j <= i; j++) if (i % j == 0) {
                res[j] = res[i / j] = 0;
            }
        }
        FOR(i, 2, n + 1) submod(res[1], res[i]);
        FOR(i, 1, n + 1) cout << res[i] << " \n"[i == n];
    }
}

int32_t main(int32_t argc, char* argv[]) {
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