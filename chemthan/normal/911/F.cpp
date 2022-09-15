#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 2e5 + 5;
const int logn = 20;
int n;
vi adj[maxn];
int lev[maxn];
int par[logn][maxn];
int from[maxn];
int f[maxn];
vi path;

pi best;
void dfs(int u, int p, int lev) {
    chkmax(best, mp(lev, u));
    for (int v : adj[u]) {
        if (v != p) {
            from[v] = u;
            dfs(v, u, lev + 1);
        }
    }
}

vi getdiameter() {
    dfs(0, -1, 0);
    int st = best.se;
    best = mp(0, 0);
    dfs(st, -1, 0);
    int ed = best.se;
    vi res;
    while (ed != st) {
        res.pb(ed);
        ed = from[ed];
    }
    res.pb(ed);
    return res;
}

void dfs(int u, int p) {
    FOR(i, 1, logn) {
        par[i][u] = par[i - 1][par[i - 1][u]];
    }
    for (int v : adj[u]) {
        if (v != p) {
            lev[v] = lev[u] + 1;
            par[0][v] = u;
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (lev[u] < lev[v]) swap(u, v);
    FORd(i, logn, 0) {
        if (lev[par[i][u]] >= lev[v]) {
            u = par[i][u];
        }
    }
    if (u == v) return u;
    FORd(i, logn, 0) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}
int dist(int u, int v) {
    int a = lca(u, v);
    return lev[u] + lev[v] - lev[a] - lev[a];
}

long long res;
vii vals;
void trace(int u, int p) {
    int st = path[0];
    int ed = path.back();
    for (int v : adj[u]) {
        if (v != p) {
            trace(v, u);
        }
    }
    if (!f[u]) {
        if (dist(u, st) > dist(u, ed)) {
            vals.pb(mp(u, st));
            res += dist(u, st);
        }
        else {
            vals.pb(mp(u, ed));
            res += dist(u, ed);
        }
    }
}

void solve() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    path = getdiameter();
    for (int x : path) {
        f[x] = 1;
    }
    dfs(0, -1), trace(path[0], -1);
    while (sz(path) > 1) {
        int st = path[0];
        int ed = path.back();
        path.pop_back();
        vals.pb(mp(ed, st));
        res += dist(st, ed);
    }
    cout << res << "\n";
    for (pi it : vals) {
        cout << it.fi + 1 << " " << it.se + 1 << " " << it.fi + 1 << "\n";
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