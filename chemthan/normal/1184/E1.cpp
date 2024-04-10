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
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

void chemthan() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int, int>> edges;
    FOR(i, 0, m) {
        int u, v, w; cin >> u >> v >> w, u--, v--;
        if (!i) {
            w = (int) 1e9;
        }
        edges.pb(make_tuple(w, i, u, v));
    }
    sort(all(edges));
    vi dj(n);
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    FOR(u, 0, n) dj[u] = u;
    vector<vii> adj(n);
    vi use(m);
    for (auto e : edges) {
        int w, ix, u, v; tie(w, ix, u, v) = e;
        if (find(u) ^ find(v)) {
            dj[find(u)] = find(v);
            adj[u].pb(mp(v, w));
            adj[v].pb(mp(u, w));
            use[ix] = 1;
        }
    }
    int logn = 20;
    vi lev(n);
    vector<vi> par(logn, vi(n));
    vector<vi> f(logn, vi(n));
    function<void(int, int)> dfs = [&] (int u, int p) {
        FOR(i, 1, logn) {
            par[i][u] = par[i - 1][par[i - 1][u]];
            f[i][u] = max(f[i - 1][u], f[i - 1][par[i - 1][u]]);
        }
        for (auto e : adj[u]) {
            int v = e.fi;
            int w = e.se;
            if (v ^ p) {
                lev[v] = lev[u] + 1;
                par[0][v] = u;
                f[0][v] = w;
                dfs(v, u);
            }
        }
    };
    dfs(0, -1);
    auto query = [&] (int u, int v) {
        if (lev[u] < lev[v]) {
            swap(u, v);
        }
        int res = 0;
        FORd(i, logn, 0) {
            if (lev[v] <= lev[par[i][u]]) {
                chkmax(res, f[i][u]);
                u = par[i][u];
            }
        }
        if (u == v) return res;
        FORd(i, logn, 0) {
            if (par[i][u] ^ par[i][v]) {
                chkmax(res, f[i][u]);
                chkmax(res, f[i][v]);
                u = par[i][u];
                v = par[i][v];
            }
        }
        chkmax(res, f[0][u]);
        chkmax(res, f[0][v]);
        return res;
    };
    vi res(m);
    for (auto e : edges) {
        int w, ix, u, v; tie(w, ix, u, v) = e;
        res[ix] = query(u, v);
    }
    cout << res[0] << "\n";
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