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
template<class T> inline void addmod(T& a, T val, T p = MOD) {if ((a = (a + val)) >= p) a -= p;}
template<class T> inline void submod(T& a, T val, T p = MOD) {if ((a = (a - val)) < 0) a += p;}
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
vii adj[maxn];
int a[maxn];
long long d[maxn];
int par[maxn];
vi events;
int st[maxn];
int tin[maxn];
int idx[maxn];
int tms;
int ispr[maxn];
int mylog[maxn << 1];

int f[logn][maxn << 1];
void build() {
    for (int i = 0; i < events.size(); i++) {
        f[0][i] = events[i];
    }
    for (int i = 1; i < logn; i++) {
        for (int j = 0; j + (1 << i - 1) < events.size(); j++) {
            f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
        }
    }
    FOR(i, 0, maxn << 1) mylog[i] = __lg(i);
}
int query(int u, int v) {
    int l = u == v ? 0 : mylog[v - u];
    return min(f[l][u], f[l][v - (1 << l) + 1]);
}
void dfs(int u, int p) {
    idx[tin[u] = tms++] = u;
    st[u] = events.size();
    events.pb(tin[u]);
    for (auto it : adj[u]) {
        int v = it.fi;
        int w = it.se;
        if (v != p) {
            d[v] = d[u] + w;
            par[v] = u;
            dfs(v, u);
            events.pb(tin[u]);
        }
    }
}
int lca(int u, int v) {
    if (st[u] > st[v]) swap(u, v);
    return idx[query(st[u], st[v])];
}
long long dist(int u, int v) {
    int a = lca(u, v);
    return d[u] + d[v] - d[a] - d[a];
}

int dj[maxn];
int da[maxn];
int db[maxn];
int dd[maxn];

void init() {
    FOR(i, 0, n) dj[i] = da[i] = db[i] = i, dd[i] = 0;
}
int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v, int w, int dx[], int dy[]) {
    int p = find(u);
    int q = find(v);
    if (p != q) {
        dj[p] = q;
        int ax[] = {da[p], db[p]};
        int ay[] = {da[q], db[q]};
        if (chkmax(dd[q], dd[p])) {
            da[q] = da[p];
            db[q] = db[p];
        }
        FOR(i, 0, 2) FOR(j, 0, 2) {
            int nd = dx[i] + w + dy[j];
            if (chkmax(dd[q], nd)) {
                da[q] = ax[i];
                db[q] = ay[j];
            }
        }
    }
}

void chemthan() {
    fill_n(ispr + 2, maxn - 2, 1);
    FOR(i, 2, maxn) if (ispr[i]) {
        for (int j = i + i; j < maxn; j += i) {
            ispr[j] = 0;
        }
    }
    cin >> n;
    FOR(i, 0, n) {
        cin >> a[i];
    }
    init();
    FOR(i, 0, n - 1) {
        int u, v, w = 1; cin >> u >> v; u--, v--;
        adj[u].pb(mp(v, w)), adj[v].pb(mp(u, w));
        dj[find(u)] = find(v);
    }
    dfs(0, -1);
    build();
    init();
    vi ver; FOR(i, 0, n) ver.pb(i);
    sort(all(ver), [] (int i, int j) {
            if (a[i] != a[j]) return a[i] < a[j];
            return i < j;
            }
        );
    static int f[maxn];
    FOR(i, 0, n) f[ver[i]] = i;
    static vi gr[maxn];
    for (int u : ver) {
        for (int d = 1; d * d <= a[u]; d++) if (a[u] % d == 0) {
            gr[d].pb(u);
            if (d * d < a[u]) {
                gr[a[u] / d].pb(u);
            }
        }
    }
    int res = -1;
    FORd(d, maxn, 2) if (ispr[d] && sz(gr[d])) {
        FORd(it, sz(gr[d]), 0) {
            int u = gr[d][it];
            for (auto it : adj[u]) {
                int v = it.fi;
                int w = it.se;
                if (a[v] % d == 0 && f[u] < f[v]) {
                    int pu = find(u);
                    int pv = find(v);
                    int ax[] = {da[pu], db[pu]};
                    int ay[] = {da[pv], db[pv]};
                    static int dx[2];
                    static int dy[2];
                    dx[0] = dist(u, da[pu]), dx[1] = dist(u, db[pu]);
                    dy[0] = dist(v, da[pv]), dy[1] = dist(v, db[pv]);
                    int mxd = 0;
                    FOR(i, 0, 2) FOR(j, 0, 2) {
                        chkmax(mxd, dx[i] + w + dy[j]);
                    }
                    chkmax(res, mxd);
                    join(u, v, w, dx, dy);
                }
            }
        }
        while (sz(gr[d])) {
            int u = gr[d].back(); gr[d].pop_back();
            dj[u] = da[u] = db[u] = u, dd[u] = 0;
        }
    }
    FOR(u, 0, n) if (a[u] > 1) chkmax(res, 0);
    cout << res + 1 << "\n";
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