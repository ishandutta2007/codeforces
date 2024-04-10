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

struct LCA {
    vector<int> events;
    vector<int> sta;
    vector<int> tin;
    vector<int> idx;
    vector<int> lev;
    int timer;
    vector<vector<int>> f;
    vector<int> mlg;

    void dfs(int u, int p, const vector<vector<int>>& adj) {
        idx[tin[u] = timer++] = u;
        sta[u] = events.size();
        events.push_back(tin[u]);
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (v != p) {
                lev[v] = lev[u] + 1;
                dfs(v, u, adj);
                events.push_back(tin[u]);
            }
        }
    }
    int query(int u, int v) {
        int l = u == v ? 0 : mlg[v - u];
        return min(f[l][u], f[l][v - (1 << l) + 1]);
    }
    int lca(int u, int v) {
        if (sta[u] > sta[v]) swap(u, v);
        return idx[query(sta[u], sta[v])];
    }
    int dist(int u, int v) {
        int a = lca(u, v);
        return lev[u] + lev[v] - lev[a] - lev[a];
    }
    void build(const vector<vector<int>>& adj, int rt = 0) {
        events.clear();
        sta.resize(adj.size());
        tin.resize(adj.size());
        idx.resize(adj.size());
        lev.resize(adj.size());
        timer = 0, dfs(rt, -1, adj);
        int logn = __lg(events.size()) + 1;
        f.resize(logn);
        for (int i = 0; i < logn; i++) {
            f[i].resize(events.size());
        }
        for (int i = 0; i < events.size(); i++) {
            f[0][i] = events[i];
        }
        for (int i = 1; i < logn; i++) {
            for (int j = 0; j + (1 << i - 1) < events.size(); j++) {
                f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
            }
        }
        mlg.resize(events.size());
        for (int i = 1; i < mlg.size(); i++) {
            mlg[i] = __lg(i);
        }
    }
} lca;

void chemthan() {
    int n; cin >> n;
    vector<vi> adj(n);
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    lca.build(adj);
    int q; cin >> q;
    while (q--) {
        auto solve = [&] () {
            int x, y, u, v, k; cin >> x >> y >> u >> v >> k; x--, y--, u--, v--;
            int d = lca.dist(x, y) + 1;
            if (lca.dist(u, v) % 2 == k % 2 && lca.dist(u, v) <= k) {
                cout << "YES\n";
                return;
            }
            FOR(it, 0, 4) {
                int dux = lca.dist(u, x);
                int dvy = lca.dist(v, y);
                int r1 = k - dux - dvy - 1;
                int r2 = k - dux - dux - lca.dist(u, v);
                int r3 = k - dvy - dvy - lca.dist(u, v);
                for (int r : {r1, r2, r3}) {
                    if (r < 0) {
                        continue;
                    }
                    if (r % 2 == 0 ||
                            (d % 2 == 1 && d <= r)) {
                        cout << "YES\n";
                        return;
                    }
                }
                swap(x, y);
            }
            cout << "NO\n";
        };
        solve();
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
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}