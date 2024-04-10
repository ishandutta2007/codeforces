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
    int n, m; cin >> n >> m;
    vector<vii> adj(n);
    FOR(i, 0, m) {
        int u, v, c; cin >> u >> v >> c; u--, v--;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    vector<double> res(n);
    vii dp(n);
    vi vis(n);
    FOR(u, 0, n) if (!vis[u]) {
        vi ver;
        function<void(int)> dfs = [&] (int u) {
            ver.pb(u);
            vis[u] = 1;
            for (auto e : adj[u]) {
                int v, c; tie(v, c) = e;
                if (!vis[v]) {
                    dp[v] = dp[u];
                    dp[v].fi *= -1;
                    dp[v].se *= -1;
                    dp[v].se += c;
                    dfs(v);
                }
            }
        };
        dp[u] = mp(1, 0);
        dfs(u);
        vii vals;
        for (int u : ver) {
            for (auto e : adj[u]) {
                int v, c; tie(v, c) = e;
                int a = dp[u].fi + dp[v].fi;
                int b = c - (dp[u].se + dp[v].se);
                if (!a && b) {
                    cout << "NO\n";
                    return;
                }
                if (a) {
                    if (a < 0) {
                        a = -a, b = -b;
                    }
                    int g = __gcd(abs(a), abs(b));
                    a /= g, b /= g;
                    vals.pb({a, b});
                }
            }
        }
        sort(all(vals)), uni(vals);
        if (1 < sz(vals)) {
            cout << "NO\n";
            return;
        }
        if (sz(vals)) {
            double x = (double) vals[0].se / vals[0].fi;
            for (int u : ver) {
                res[u] = dp[u].fi * x + dp[u].se;
            }
        }
        else {
            vector<pair<double, int>> vals;
            long long suma = 0;
            for (int u : ver) {
                int a = dp[u].fi;
                int b = dp[u].se;
                if (a) {
                    if (a < 0) {
                        vals.pb({(double) -b / a, -a});
                    }
                    else {
                        vals.pb({(double) -b / a, a});
                    }
                    suma += abs(a);
                }
            }
            sort(all(vals));
            long long tmp = 0;
            double x = 0;
            FOR(i, 0, sz(vals)) {
                tmp += vals[i].se;
                if (suma <= tmp + tmp) {
                    x = vals[i].fi;
                    break;
                }
            }
            for (int u : ver) {
                res[u] = dp[u].fi * x + dp[u].se;
            }
        }
    }
    cout << "YES\n";
    FOR(i, 0, n) cout << prec(9) << res[i] << " \n"[i == n - 1];
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