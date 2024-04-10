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

const int maxn = 3e5 + 5;
const int logn = 20;
int n, q;
int a[maxn];
vii adj[maxn];
int ww[maxn];
long long f[maxn];
long long g[maxn];
long long h[maxn];
int lev[maxn];
int par[logn][maxn];
long long ch[maxn];

long long sa[maxn];
long long sb[maxn];

long long dfs(int u, int p) {
    for (pi e : adj[u]) {
        int v = e.fi;
        int w = e.se;
        if (v != p) {
            f[u] += max(0LL, dfs(v, u) + a[v] - w - w);
            ww[v] = w;
        }
    }
    return f[u];
}

void upd_dfs(int u, int p, long long val) {
    int pw = 0;
    long long t = 0;
    for (pi e : adj[u]) {
        int v = e.fi;
        int w = e.se;
        if (v == p) {
            pw = w;
            t += max(0LL, val + a[p] - pw - pw);
        }
        else {
            t += max(0LL, f[v] + a[v] - w - w);
        }
    }
    if (pw) {
        g[u] = max(0LL, val + a[p] - pw - pw);
    }
    if (pw) {
        h[u] = f[p] - max(0LL, f[u] + a[u] - pw - pw);
    }
    for (pi e : adj[u]) {
        int v = e.fi;
        int w = e.se;
        if (v != p) {
            upd_dfs(v, u, t - max(0LL, f[v] + a[v] - w - w));
        }
    }
}

void build_dfs(int u, int p) {
    FOR(i, 1, logn) par[i][u] = par[i - 1][par[i - 1][u]];
    for (pi e : adj[u]) {
        int v = e.fi;
        int w = e.se;
        if (v != p) {
            lev[v] = lev[u] + 1;
            par[0][v] = u;
            sa[v] = sa[u] + a[v];
            sb[v] = sb[u] + w;
            ch[v] = ch[u] + h[v];
            build_dfs(v, u);
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
int jump(int u, int p) {
    FORd(i, logn, 0) {
        if (lev[par[i][u]] > lev[p]) {
            u = par[i][u];
        }
    }
    return u;
}

long long query(int u, int v) {
    if (u == v) {
        return a[u] + f[u] + g[u];
    }
    int p = lca(u, v);
    long long res = sa[u] + sa[v] - sa[p];
    if (p) res -= sa[par[0][p]];
    res -= sb[u] + sb[v] - sb[p] - sb[p];
    int uu, vv;
    if (u != p) {
        uu = jump(u, p);
        res += ch[u];
        if (uu) res -= ch[par[0][uu]];
    }
    if (v != p) {
        vv = jump(v, p);
        res += ch[v];
        if (vv) res -= ch[par[0][vv]];
    }
    if (u != p && v != p) {
        res -= f[p];
        res += f[u] + f[v];
    }
    if (u == p) {
        res += f[v];
    }
    if (v == p) {
        res += f[u];
    }
    res += g[p];
    return res;
}

void chemthan() {
    cin >> n >> q;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n - 1) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    dfs(0, -1), upd_dfs(0, -1, 0);
    sa[0] = a[0], ch[0] = h[0], build_dfs(0, -1);
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
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}