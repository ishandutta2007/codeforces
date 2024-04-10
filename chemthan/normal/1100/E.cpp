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

const int maxn = 1e5 + 5;
int n, m;
vii adj[maxn];
vii radj[maxn];
int w[maxn];
int f[maxn];
int vis[maxn];
int mi;

vi ver;
void dfs(int u) {
    vis[u] = 1;
    for (auto e : adj[u]) {
        int v = e.fi;
        int t = e.se;
        if (w[t] > mi) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    }
    ver.pb(u);
}

int cnt;
void rdfs(int u) {
    vis[u] = 1;
    cnt++;
    for (auto e : radj[u]) {
        int v = e.fi;
        int t = e.se;
        if (w[t] > mi) {
            if (!vis[v]) {
                rdfs(v);
            }
        }
    }
}

void chemthan() {
    cin >> n >> m;
    vii edges;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v >> w[i]; u--, v--;
        adj[u].pb(mp(v, i));
        radj[v].pb(mp(u, i));
        edges.pb(mp(u, v));
    }
    int lo = 0, hi = INF;
    while (lo < hi) {
        mi = lo + hi >> 1;
        ms(vis, 0), ver.clear();
        FOR(u, 0, n) if (!vis[u]) dfs(u);
        ms(vis, 0);
        int found = 0;
        FORd(i, n, 0) {
            int u = ver[i];
            if (!vis[u]) {
                cnt = 0;
                rdfs(u);
                if (cnt > 1) {
                    found = 1;
                }
            }
        }
        if (found) {
            lo = mi + 1;
        }
        else {
            hi = mi;;
        }
    }
    mi = lo + hi >> 1;
    ms(vis, 0), ver.clear();
    FOR(u, 0, n) if (!vis[u]) dfs(u);
    static int g[maxn];
    FOR(i, 0, n) g[ver[i]] = i;
    vi res;
    FOR(i, 0, m) if (w[i] <= mi) {
        int u = edges[i].fi;
        int v = edges[i].se;
        if (g[u] < g[v]) {
            res.pb(i);
        }
    }
    cout << mi << " " << sz(res) << "\n";
    FOR(i, 0, sz(res)) cout << res[i] + 1 << " \n"[i == sz(res) - 1];
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