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

#define HK HopcroftKarp
namespace HopcroftKarp {
    const int maxv = 1e4 + 5;
    const int maxe = 1e6 + 5;
    int nx, ny, E, nmatches;
    int adj[maxe], nxt[maxe];
    int lst[maxv], ptr[maxv], lev[maxv], que[maxv], matx[maxv], maty[maxv];
    void init(int _nx, int _ny) {
        nx = _nx, ny = _ny;
        E = nmatches = 0, fill_n(lst, nx, -1);
        fill_n(matx, nx, -1), fill_n(maty, ny, -1);
    }
    void add(int x, int y) {
        adj[E] = y, nxt[E] = lst[x], lst[x] = E++;
    }
    int bfs() {
        int qh = 0, qe = 0;
        for (int x = 0; x < nx; x++) {
            if (~matx[x]) {
                lev[x] = 0;
            }
            else {
                lev[x] = 1;
                que[qe++] = x;
            }
        }
        int res = 0;
        while (qh < qe) {
            int x = que[qh++];
            for (int e = lst[x]; ~e; e = nxt[e]) {
                int y = adj[e];
                if (!~maty[y]) {
                    res = 1;
                }
                else if (!lev[maty[y]]) {
                    lev[maty[y]] = lev[x] + 1;
                    que[qe++] = maty[y];
                }
            }
        }
        return res;
    }
    int dfs(int x) {
        for (int& e = ptr[x]; ~e; e = nxt[e]) {
            int y = adj[e];
            if (!~maty[y] || (lev[maty[y]] == lev[x] + 1 && dfs(maty[y]))) {
                matx[x] = y;
                maty[y] = x;
                return 1;
            }
        }
        return 0;
    }
    int maxmat() {
        while (bfs()) {
            for (int x = 0; x < nx; x++) {
                ptr[x] = lst[x];
            }
            for (int x = 0; x < nx; x++) {
                if (!~matx[x]) {
                    nmatches += dfs(x);
                }
            }
        }
        return nmatches;
    }
    int vis[2][maxv];
    void dfs(int u, int r) {
        vis[r][u] = 1;
        if (!r) {
            for (int e = lst[u]; ~e; e = nxt[e]) {
                int v = adj[e];
                if (matx[u] != v && !vis[!r][v]) {
                    dfs(v, !r);
                }
            }
        }
        else {
            int v = maty[u];
            if (~v && !vis[!r][v]) {
                dfs(v, !r);
            }
        }
    }
    vector<int> mincover() {
        maxmat();
        vector<int> res;
        fill_n(vis[0], nx, 0), fill_n(vis[1], ny, 0);
        for (int x = 0; x < nx; x++) {
            if (!~matx[x] && !vis[0][x]) {
                dfs(x, 0);
            }
        }
        for (int x = 0; x < nx; x++) {
            if (!vis[0][x]) {
                res.push_back(x);
            }
        }
        for (int y = 0; y < ny; y++) {
            if (vis[1][y]) {
                res.push_back(nx + y);
            }
        }
        return res;
    }
    vector<int> maxind() {
        maxmat();
        vector<int> res;
        fill_n(vis[0], nx, 0), fill_n(vis[1], ny, 0);
        for (int x = 0; x < nx; x++) {
            if (!~matx[x] && !vis[0][x]) {
                dfs(x, 0);
            }
        }
        for (int x = 0; x < nx; x++) {
            if (vis[0][x]) {
                res.push_back(x);
            }
        }
        for (int y = 0; y < ny; y++) {
            if (!vis[1][y]) {
                res.push_back(nx + y);
            }
        }
        return res;
    }
}

void chemthan() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    FOR(i, 0, m) {
        int u, v, d; cin >> u >> v >> d; u--, v--;
        edges.pb({u, v, d});
    }
    int lo = 0, hi = INF;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        HK::init(n, n);
        for (auto& [u, v, d] : edges) if (d <= mi) {
            HK::add(u, v);
        }
        if (HK::maxmat() < n) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    int res = (lo + hi >> 1);
    if (res == INF) res = -1;
    cout << res << "\n";
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