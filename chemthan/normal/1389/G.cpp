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

const int maxn = 1e6 + 5;
int n, m, k;
int s[maxn];
int c[maxn];
int w[maxn];
vi adj[maxn];
int num[maxn];
int low[maxn];
int cnt;
int art[maxn];
vector<vector<int>> comps;
vi stk;
vii nonbr;

void dfs(int u, int p) {
    num[u] = low[u] = ++cnt;
    stk.pb(u);
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (!num[v]) {
            dfs(v, u);
            if (low[v] <= num[u]) {
                nonbr.pb({u, v});
            }
            chkmin(low[u], low[v]);
            if (low[v] >= num[u]) {
                art[u] = num[u] > 1 || num[v] > 2;
                vi comp; comp.pb(u);
                comps.pb(comp);
                while (comps.back().back() != v) {
                    comps.back().pb(stk.back()), stk.pop_back();
                }
            }
        }
        else if (v != p) {
            chkmin(low[u], num[v]);
        }
    }
}

void chemthan() {
    cin >> n >> m >> k;
    FOR(i, 0, k) {
        int u; cin >> u, u--;
        s[u] = 1;
    }
    FOR(i, 0, n) cin >> c[i];
    FOR(i, 0, m) cin >> w[i];
    vii edges;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
        edges.pb({u, v});
    }
    dfs(0, -1);
    vi dj(n);
    FOR(u, 0, n) dj[u] = u;
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    auto join = [&] (int u, int v) {
        u = find(u), v = find(v);
        dj[u] = v;
    };
    for (auto comp : comps) if (2 < sz(comp)) {
        for (int u : comp) {
            join(u, comp[0]);
        }
    }
    vector<vi> adj2(n);
    map<pi, long long> hs;
    FOR(i, 0, sz(edges)) {
        int u, v; tie(u, v) = edges[i];
        int uu = find(u);
        int vv = find(v);
        if (uu ^ vv) {
            adj2[uu].pb(vv), adj2[vv].pb(uu);
            hs[mp(uu, vv)] += w[i];
            hs[mp(vv, uu)] += w[i];
        }
    }
    vector<long long> d(n);
    vi deg(n);
    queue<int> que;
    FOR(u, 0, n) {
        d[find(u)] += c[u];
        if (u != find(u)) {
            c[u] = -1;
        }
        s[find(u)] |= s[u];
        sort(all(adj2[u])), uni(adj2[u]);
        adj[u] = adj2[u];
        deg[u] = sz(adj[u]);
        if (deg[u] == 1 && !s[u]) {
            que.push(u);
        }
    }
    while (sz(que)) {
        int u = que.front(); que.pop();
        for (int v : adj[u]) if (d[v] != -1) {
            d[v] += d[u];
            d[u] = -1;
            deg[v]--;
            dj[find(u)] = v;
            if (deg[v] == 1 && !s[v]) {
                que.push(v);
            }
        }
    }
    int rt = -1;
    FOR(u, 0, n) if (d[u] != -1 && c[u] != -1) {
        if (rt == -1) {
            rt = u;
        }
        vi tmp;
        for (int v : adj[u]) if (d[v] != -1) {
            tmp.pb(v);
        }
        adj[u] = tmp;
    }
    assert(rt != -1);
    vector<long long> dp(n);
    function<void(int, int)> dfs = [&] (int u, int p) {
        dp[u] = d[u];
        for (int v : adj[u]) {
            if (v ^ p) {
                dfs(v, u);
                dp[u] += max(0LL, dp[v] - hs[mp(u, v)]);
            }
        }
    };
    vector<long long> dp2(n);
    function<void(int, int, long long)> upd_dfs = [&] (int u, int p, long long mx) {
        mx += d[u];
        for (int v : adj[u]) {
            if (v ^ p) {
                mx += max(0LL, dp[v] - hs[mp(u, v)]);
            }
        }
        dp2[u] = mx;
        for (int v : adj[u]) {
            if (v ^ p) {
                mx -= max(0LL, dp[v] - hs[mp(u, v)]);
                upd_dfs(v, u, max(0LL, mx - hs[mp(u, v)]));
                mx += max(0LL, dp[v] - hs[mp(u, v)]);
            }
        }
    };
    dfs(rt, -1);
    upd_dfs(rt, -1, 0);
    FOR(u, 0, n) {
        int v = find(u);
        cout << dp2[v] << " \n"[u == n - 1];
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