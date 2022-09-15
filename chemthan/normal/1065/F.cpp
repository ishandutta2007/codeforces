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
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}

const int maxn = 1e6 + 5;
const int logn = 20;
int n, k;
vi adj[maxn];
vi radj[maxn];
vi adj2[maxn];
int f[maxn];
int g[maxn];
int par[logn][maxn];

void dfs(int u, int p) {
    FOR(i, 1, logn) par[i][u] = par[i - 1][par[i - 1][u]];
    for (int v : adj[u]) {
        if (v != p) {
            par[0][v] = u;
            dfs(v, u);
        }
    }
}

int go(int u, int k) {
    FORd(i, logn, 0) {
        if (k >= (1 << i)) {
            k -= (1 << i);
            u = par[i][u];
        }
    }
    return u;
}

int vis[maxn];
vi ver;
void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    ver.pb(u);
}

int id;
int fid[maxn];
void rdfs(int u) {
    vis[u] = 1;
    g[fid[u] = id] += f[u];
    for (int v : radj[u]) {
        if (!vis[v]) {
            rdfs(v);
        }
    }
}

int dp[maxn];
int calc(int u) {
    int& res = dp[u];
    if (~res) return res;
    res = g[u];
    for (int v : adj2[u]) {
        chkmax(res, calc(v) + g[u]);
    }
    return res;
}

void chemthan() {
    cin >> n >> k;
    FOR(i, 1, n) {
        int p; cin >> p; p--;
        adj[p].pb(i);
        radj[i].pb(p);
    }
    dfs(0, -1);
    FOR(u, 0, n) {
        f[u] = !sz(adj[u]);
        if (f[u]) {
            int v = go(u, k);
            if (u != v) {
                adj[u].pb(v);
                radj[v].pb(u);
            }
        }
    }
    FOR(u, 0, n) if (!vis[u]) dfs(u);
    reverse(all(ver));
    fill_n(vis, n, 0);
    for (int u : ver) if (!vis[u]) {
        rdfs(u);
        id++;
    }
    map<pi, int> hs;
    FOR(u, 0, n) {
        for (int v : adj[u]) {
            int uu = fid[u];
            int vv = fid[v];
            if (uu != vv && !hs[mp(uu, vv)]) {
                hs[mp(uu, vv)] = 1;
                adj2[uu].pb(vv);
            }
        }
    }
    ms(dp, -1);
    int res = 0;
    FOR(u, 0, id) if (g[u]) chkmax(res, calc(u));
    cout << res << "\n";
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