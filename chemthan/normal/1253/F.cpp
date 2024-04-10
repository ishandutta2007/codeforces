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

void solve() {
    int n, m, k, q; cin >> n >> m >> k >> q;
    vector<vii> adj(n);
    FOR(i, 0, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    vector<tuple<long long, int, int>> edges;
    map<pi, long long> d;
    vi ids(n, -1);
    priority_queue<tuple<long long, int, int>> heap;
    FOR(u, 0, k) {
        d[mp(u, u)] = 0, ids[u] = u, heap.push({-d[mp(u, u)], u, u});
    }
    while (sz(heap)) {
        long long t;
        int u, v; tie(t, u, v) = heap.top();
        t = -t;
        heap.pop();
        if (d[mp(u, v)] ^ t) continue;
        if (ids[u] != -1 && ids[u] != v) {
            edges.pb({d[mp(u, ids[u])] + t, ids[u], v});
        }
        else {
            ids[u] = v;
            for (auto e : adj[u]) {
                int nu = e.fi;
                int w = e.se;
                if (!d.count(mp(nu, v))) d[mp(nu, v)] = LINF;
                if (chkmin(d[mp(nu, v)], d[mp(u, v)] + w)) {
                    heap.push({-d[mp(nu, v)], nu, v});
                }
            }
        }
    }

    sort(all(edges));
    vi dj(n);
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    auto join = [&] (int u, int v) {
        u = find(u);
        v = find(v);
        if (u ^ v) {
            dj[u] = v;
            return 1;
        }
        return 0;
    };
    FOR(u, 0, n) dj[u] = u;
    vector<vector<pair<int, long long>>> adj2(k);
    for (auto e : edges) {
        int u, v; long long w; tie(w, u, v) = e;
        if (join(u, v)) {
            adj2[u].pb({v, w});
            adj2[v].pb({u, w});
        }
    }
    int logn = 20;
    vi lev(n);
    vector<vi> par(logn, vi(n));
    vector<vector<long long>> val(logn, vector<long long>(n));
    function<void(int, int)> dfs = [&] (int u, int p) {
        FOR(i, 1, logn) {
            par[i][u] = par[i - 1][par[i - 1][u]];
            val[i][u] = max(val[i - 1][u], val[i - 1][par[i - 1][u]]);
        }
        for (auto e : adj2[u]) {
            int v = e.fi;
            long long w = e.se;
            if (v ^ p) {
                lev[v] = lev[u] + 1;
                par[0][v] = u;
                val[0][v] = w;
                dfs(v, u);
            }
        }
    };
    auto query = [&] (int u, int v) {
        if (lev[u] < lev[v]) swap(u, v);
        long long res = 0;
        FORd(i, logn, 0) {
            if (lev[v] <= lev[par[i][u]]) {
                chkmax(res, val[i][u]);
                u = par[i][u];
            }
        }
        if (u == v) return res;
        FORd(i, logn, 0) {
            if (par[i][u] ^ par[i][v]) {
                chkmax(res, val[i][u]);
                chkmax(res, val[i][v]);
                u = par[i][u];
                v = par[i][v];
            }
        }
        chkmax(res, val[0][u]);
        chkmax(res, val[0][v]);
        return res;
    };
    dfs(0, -1);
    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        cout << query(u, v) << "\n";
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}