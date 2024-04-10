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

const int maxn = 5e5 + 5;
const int logn = 20;
int n, k, m;
pi edges[maxn];
pi medges[maxn];
int w[maxn];
vii adj[maxn];
int dj[maxn];
int from[maxn];
int lev[maxn];
int par[logn][maxn];
int mn[logn][maxn];

int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
int join(int u, int v) {
    int p = find(u);
    int q = find(v);
    if (p != q) {
        dj[p] = q;
        return 1;
    }
    return 0;
}

vi ver;
void dfs(int u, int p) {
    FOR(i, 1, logn) par[i][u] = par[i - 1][par[i - 1][u]];
    for (pi e : adj[u]) {
        int v = e.fi;
        int ix = e.se;
        if (v != p) {
            from[v] = ix;
            lev[v] = lev[u] + 1;
            par[0][v] = u;
            dfs(v, u);
        }
    }
    ver.pb(u);
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

void chemthan() {
    scanf("%d%d%d", &n, &k, &m);
    FOR(i, 0, k) {
        int u, v; scanf("%d%d", &u, &v); u--, v--;
        edges[i] = mp(u, v);
    }
    FOR(i, 0, m) {
        int u, v; scanf("%d%d%d", &u, &v, w + i); u--, v--;
        medges[i] = mp(u, v);
    }
    FOR(i, 0, n) dj[i] = i;
    FOR(i, 0, k) {
        int u = edges[i].fi;
        int v = edges[i].se;
        adj[u].pb(mp(v, i));
        adj[v].pb(mp(u, i));
        join(u, v);
    }
    static int used[maxn];
    FOR(i, 0, m) {
        int u = medges[i].fi;
        int v = medges[i].se;
        if (join(u, v)) {
            adj[u].pb(mp(v, k + i));
            adj[v].pb(mp(u, k + i));
            used[i] = 1;
        }
    }
    dfs(0, -1);
    FOR(i, 0, logn) FOR(u, 0, n) mn[i][u] = INF;
    FOR(i, 0, m) if (!used[i]) {
        int u = medges[i].fi;
        int v = medges[i].se;
        int a = lca(u, v);
        for (int t : {u, v}) {
            FORd(j, logn, 0) if (t != a) {
                if (lev[par[j][t]] >= lev[a]) {
                    chkmin(mn[j][t], w[i]);
                    t = par[j][t];
                }
            }
        }
    }
    static int res[maxn];
    for (int u : ver) {
        FORd(i, logn, 1) {
            chkmin(mn[i - 1][u], mn[i][u]);
            chkmin(mn[i - 1][par[i - 1][u]], mn[i][u]);
        }
        if (u) {
            int ix = from[u];
            if (ix < k) {
                res[ix] = mn[0][u];
            }
        }
    }
    FOR(i, 0, k) if (res[i] == INF) {
        cout << -1 << "\n";
        return;
    }
    cout << accumulate(res, res + k, 0LL) << "\n";
}

int main(int argc, char* argv[]) {
    //ios_base::sync_with_stdio(0), cin.tie(0);
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