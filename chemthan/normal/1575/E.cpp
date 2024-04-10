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

namespace TCD {
    int k;
    vector<int> a;
    vector<int> rem;
    vector<int> size;

    void dfs(const vector<vector<pi>>& adj, int u, int p) {
        size[u] = 1;
        for (auto [v, t] : adj[u]) {
            if (v != p && !rem[v]) {
                dfs(adj, v, u);
                size[u] += size[v];
            }
        }
    }
    int findcentroid(const vector<vector<pi>>& adj, int u) {
        int p = -1;
        dfs(adj, u, -1);
        int cap = size[u] >> 1;
        while (1) {
            int found = 0;
            for (auto [v, t] : adj[u]) {
                if (v != p && !rem[v] && cap < size[v]) {
                    p = u, u = v;
                    found = 1;
                    break;
                }
            }
            if (!found) return u;
        }
        assert(0);
    }
    void workspace(const vector<vector<pi>>&, int);
    int res;
    vector<vector<int>> fen(2);
    vector<vector<int>> fen2(2);
    void divide(const vector<vector<pi>>& adj, int u = 0, int depth = 0) {
        if (!depth) {
            rem.resize(adj.size());
            fill(rem.begin(), rem.end(), 0);
            size.resize(adj.size());
            fen[0].resize(adj.size() + 1);
            fen[1].resize(adj.size() + 1);
            fen2[0].resize(adj.size() + 1);
            fen2[1].resize(adj.size() + 1);
        }
        u = findcentroid(adj, u);
        rem[u] = 1, workspace(adj, u);
        for (auto [v, t] : adj[u]) {
            if (!rem[v]) {
                divide(adj, v, depth + 1);
            }
        }
    }
    void workspace(const vector<vector<pi>>& adj, int rt) {
        auto upd = [&] (vi& fen, int p, int v) {
            p++;
            for (; p < sz(fen); p += p & -p) {
                addmod(fen[p], v);
            }
        };
        auto query = [&] (vi& fen, int p) {
            p++;
            int res = 0;
            for (; 0 < p; p -= p & -p) {
                addmod(res, fen[p]);
            }
            return res;
        };
        int c;
        function<void(int, int, int, int, int, int)> dfs1 = [&] (int u, int p, int d, int pt, int sum, int s) {
            addmod(sum, a[u]);
            upd(fen[c], d, mult(s + MOD, sum));
            upd(fen2[c], d, mult(s + MOD, 1));
            for (auto [v, t] : adj[u]) {
                if (v != p && !rem[v]) {
                    int nd = d;
                    if (t != pt) {
                        nd++;
                    }
                    dfs1(v, u, nd, t, sum, s);
                }
            }
        };
        function<void(int, int, int, int, int)> dfs2 = [&] (int u, int p, int d, int pt, int sum) {
            addmod(sum, a[u]);

            addmod(res, mult(sum, query(fen2[c], k - d)));
            addmod(res, mult(sum, query(fen2[c ^ 1], k - d - 1)));
            addmod(res, query(fen[c], k - d));
            addmod(res, query(fen[c ^ 1], k - d - 1));

            if (d <= k) {
                addmod(res, sum);
            }
            for (auto [v, t] : adj[u]) {
                if (v != p && !rem[v]) {
                    int nd = d;
                    if (t != pt) {
                        nd++;
                    }
                    dfs2(v, u, nd, t, sum);
                }
            }
        };
        for (auto [u, t] : adj[rt]) {
            if (!rem[u]) {
                c = t;
                dfs2(u, rt, 0, t, a[rt]);
                dfs1(u, rt, 0, t, 0, 1);
            }
        }
        for (auto [u, t] : adj[rt]) {
            if (!rem[u]) {
                c = t;
                dfs1(u, rt, 0, t, 0, -1);
            }
        }
        addmod(res, a[rt]);
    }
}

void chemthan() {
    int n, k; cin >> n >> k;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    vector<vii> adj(n);
    FOR(i, 0, n - 1) {
        int u, v, t; cin >> u >> v >> t; u--, v--;
        adj[u].pb({v, t});
        adj[v].pb({u, t});
    }
    TCD::k = k;
    TCD::a = a;
    TCD::divide(adj);
    cout << TCD::res << "\n";
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