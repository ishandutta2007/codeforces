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

#define MCMF MincostMaxflow
#define flow_t int
#define cost_t long long
const flow_t foo = (flow_t) 1e9;
const cost_t coo = (cost_t) 1e18;
namespace MincostMaxflow {
    const int maxv = 1e5 + 5;
    const int maxe = 1e6 + 5;
    int n, s, t, E;
    int adj[maxe], nxt[maxe], lst[maxv], frm[maxv], vis[maxv];
    flow_t cap[maxe], flw[maxe], totalFlow;
    cost_t cst[maxe], dst[maxv], totalCost;

    void init(int nn, int ss, int tt) {
        n = nn, s = ss, t = tt;
        fill_n(lst, n, -1), E = 0;
    }
    void add(int u, int v, flow_t ca, cost_t co) {
        adj[E] = v, cap[E] = ca, flw[E] = 0, cst[E] = +co, nxt[E] = lst[u], lst[u] = E++;
        adj[E] = u, cap[E] =  0, flw[E] = 0, cst[E] = -co, nxt[E] = lst[v], lst[v] = E++;
    }
    int spfa() {
        fill_n(dst, n, coo), dst[s] = 0;
        queue<int> que; que.push(s);
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int e = lst[u]; e != -1; e = nxt[e]) if (flw[e] < cap[e]) {
                int v = adj[e];
                if (dst[v] > dst[u] + cst[e]) {
                    dst[v] = dst[u] + cst[e];
                    frm[v] = e;
                    if (!vis[v]) {
                        vis[v] = 1;
                        que.push(v);
                    }
                }
            }
            vis[u] = 0;
        }
        return dst[t] < coo;
    }
    cost_t mincost() {
        totalCost = 0, totalFlow = 0;
        while (1) {
            if (!spfa()) break;
            flow_t mn = foo;
            for (int v = t, e = frm[v]; v != s; v = adj[e ^ 1], e = frm[v]) mn = min(mn, cap[e] - flw[e]);
            for (int v = t, e = frm[v]; v != s; v = adj[e ^ 1], e = frm[v]) {
                flw[e] += mn;
                flw[e ^ 1] -= mn;
            }
            totalFlow += mn;
            totalCost += mn * dst[t];
        }
        return totalCost;
    }
}

const int maxn = 500 + 5;
int n, x, y;
int a[maxn];
vi adj1[maxn];
vi adj2[maxn];
int f1[maxn];
int f2[maxn];

vii ff;
void dfs(int u, int p, vi adj[], int cnt) {
    if (cnt == 1) {
        if (p != -1) {
            if (f1[u]) {
                ff.pb(mp(MCMF::E, f1[u]));
            }
            MCMF::add(p, u, f1[u] ? f1[u] : INF, f1[u] ? -INF : 0);
        }
    }
    else {
        if (p != -1) {
            if (f2[u]) {
                ff.pb(mp(MCMF::E, f2[u]));
            }
            MCMF::add(u + n, p + n, f2[u] ? f2[u] : INF, f2[u] ? -INF : 0);
        }
    }
    for(int v : adj[u]) {
        if (v != p) {
            dfs(v, u, adj, cnt);
        }
    }
}

void chemthan() {
    cin >> n >> x >> y; x--, y--;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj1[u].pb(v), adj1[v].pb(u);
    }
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj2[u].pb(v), adj2[v].pb(u);
    }
    int q1; cin >> q1;
    while (q1--) {
        int k, x; cin >> k >> x; k--;
        f1[k] = x;
    }
    int q2; cin >> q2;
    while (q2--) {
        int k, x; cin >> k >> x; k--;
        f2[k] = x;
    }
    int tot = n + n, s = tot++, t = tot++;
    MCMF::init(tot, s, t);
    MCMF::add(s, x, f1[x], 0);
    MCMF::add(n + y, t, f2[y], 0);
    FOR(u, 0, n) {
        MCMF::add(u, u + n, 1, -a[u]);
    }
    dfs(x, -1, adj1, 1);
    dfs(y, -1, adj2, 2);
    MCMF::mincost();
    if (MCMF::totalFlow != f1[x] || MCMF::totalFlow != f2[y]) {
        cout << -1 << "\n";
        return;
    }
    for (auto it : ff) {
        int e = it.fi;
        int v = it.se;
        if (MCMF::flw[e] != v) {
            cout << -1 << "\n";
            return;
        }
    }
    long long res = -MCMF::totalCost;
    FOR(u, 0, n) {
        if (u != x && f1[u]) res -= (long long) f1[u] * INF;
        if (u != y && f2[u]) res -= (long long) f2[u] * INF;
    }
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