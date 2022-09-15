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
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 2e5 + 5;
const int logn = 20;
int n;
vi adj[maxn];
int lev[maxn];
int par[logn][maxn];
int used[maxn];

void dfs(int u, int p) {
    FOR(i, 1, logn) par[i][u] = par[i - 1][par[i - 1][u]];
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

pi best;
int from[maxn];
void dfs(int u, int p, int lev) {
    chkmax(best, mp(lev, u));
    for (int v : adj[u]) {
        if (v != p && used[v]) {
            from[v] = u;
            dfs(v, u, lev + 1);
        }
    }
}
int center(int rt) {
    best = mp(0, 0);
    dfs(rt, -1, 0);
    int st = best.se;
    best = mp(0, 0);
    dfs(st, -1, 0);
    int ed = best.se;
    int len = best.fi;
    FOR(i, 0, len >> 1) ed = from[ed];
    return ed;
}

int isleaf[maxn];
int ff[maxn];
void dfs2(int u, int p, int seanc = -1) {
    ff[u] = seanc;
    int num = 0;
    for (int v : adj[u]) {
        if (used[v]) {
            num++;
        }
        if (v != p && used[v]) {
            lev[v] = lev[u] + 1;
            int nseanc = seanc;
            if (nseanc == -1) nseanc = v;
            dfs2(v, u, nseanc);
        }
    }
    if (num == 1) {
        isleaf[u] = 1;
    }
}

pi f[maxn];
pi g[maxn];
void dfs3(int u, int p) {
    vii vals;
    vals.pb(mp(0, u));
    for (int v : adj[u]) {
        if (v != p && !used[v]) {
            dfs3(v, u);
            vals.pb(mp(f[v].fi + 1, f[v].se));
        }
    }
    sort(all(vals), greater<pi>());
    f[u] = vals[0];
    if (sz(vals) > 1) {
        g[u] = vals[1];
    }
    else {
        g[u] = mp(-INF, -INF);
    }
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1);
    vi ver;
    FOR(u, 0, n) if (sz(adj[u]) >= 3) ver.pb(u);
    int rt = ver[0];
    for (int u : ver) rt = lca(rt, u);
    used[rt] = 1;
    FOR(i, 0, sz(ver)) {
        int u = ver[i];
        while (u != rt && !used[u]) {
            used[u] = 1;
            u = par[0][u];
        }
    }
    rt = center(rt);
    dfs2(rt, -1);
    map<int, pair<pi, pi> > hs;
    vector<pair<pi, pi> > vals;
    FOR(u, 0, n) if (isleaf[u]) {
        dfs3(u, -1);
        chkmax(hs[ff[u]], mp(mp(lev[u], f[u].fi + g[u].fi), mp(f[u].se, g[u].se)));
    }
    for (auto it : hs) {
        vals.pb(it.se);
    }
    sort(all(vals)), reverse(all(vals));
    cout << vals[0].se.fi + 1 << " " << vals[1].se.fi + 1 << "\n";
    cout << vals[0].se.se + 1 << " " << vals[1].se.se + 1 << "\n";
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