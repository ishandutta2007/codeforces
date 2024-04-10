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

#define MF Maxflow
#define flow_t int
const flow_t foo = (flow_t) 1e9;
namespace Maxflow {
    const int maxv = 1e5 + 5;
    const int maxe = 1e6 + 5;
    int n, s, t, E;
    int adj[maxe], nxt[maxe], lst[maxv], ptr[maxv], lev[maxv], que[maxv];
    flow_t flw[maxe], cap[maxe];
    void init(int nn, int ss, int tt) {
        n = nn, s = ss, t = tt, E = 0;
        fill_n(lst, n, -1);
    }
    void add(int u, int v, flow_t c1, flow_t c2) {
        adj[E] = v, flw[E] = 0, cap[E] = c1, nxt[E] = lst[u], lst[u] = E++;
        adj[E] = u, flw[E] = 0, cap[E] = c2, nxt[E] = lst[v], lst[v] = E++;
    }
    int bfs() {
        fill_n(lev, n, 0), lev[s] = 1;
        int qsize = 0;
        que[qsize++] = s;
        for (int i = 0; i < qsize; i++) {
            for (int u = que[i], e = lst[u]; ~e; e = nxt[e]) {
                int v = adj[e];
                if (flw[e] < cap[e] && !lev[v]) {
                    lev[v] = lev[u] + 1;
                    que[qsize++] = v;
                }
            }
        }
        return lev[t];
    }
    flow_t dfs(int u, flow_t bot) {
        if (u == t) return bot;
        for (int& e = ptr[u]; ~e; e = nxt[e]) {
            int v = adj[e];
            flow_t delta = 0;
            if (lev[v] == lev[u] + 1 && flw[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flw[e]))) > 0) {
                flw[e] += delta; flw[e ^ 1] -= delta;
                return delta;
            }
        }
        return 0;
    }
    flow_t maxflow(int ss = -1, int tt = -1) {
        if (~ss) s = ss;
        if (~tt) t = tt;
        fill_n(flw, E, 0);
        flow_t total = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) ptr[i] = lst[i];
            for (flow_t delta = dfs(s, foo); delta > 0; delta = dfs(s, foo)) total += delta;
        }
        return total;
    }
    vector<pair<pair<int, int>, flow_t> > gomory_hu() {
        vector<pair<pair<int, int>, flow_t> > tree;
        vector<int> p(n);
        for (int u = 1; u < n; u++) {
            tree.push_back(make_pair(make_pair(p[u], u), maxflow(u, p[u])));
            for (int v = u + 1; v < n; ++v) {
                if (lev[v] && p[v] == p[u]) {
                    p[v] = u;
                }
            }
        }
        return tree;
    }
    int dfs2(int u, int pu) {
        if (u == t) {
            return pu;
        }
        for (int e = lst[u]; ~e; e = nxt[e]) if (flw[e] > 0) {
            int v = adj[e];
            int r = dfs2(v, u);
            if (r) {
                flw[e]--;
                return r;
            }
        }
        return 0;
    }
    vii trace() {
        vii res;
        for (int e = lst[s]; ~e; e = nxt[e]) if (flw[e] > 0) {
            int v = adj[e];
            int r;
            while (flw[e] && (r = dfs2(v, s))) {
                flw[e]--;
                res.pb(mp(v, r));
            }
        }
        return res;
    }
}

int n, m;

void build(int p, int L, int R) {
    if (L == R) {
        MF::add(n + m + p, n + L, 1, 0);
        return;
    }
    build(p << 1, L, L + R >> 1);
    build(p << 1 | 1, (L + R >> 1) + 1, R);
    MF::add(n + m + p, n + m + (p << 1), R - L + 1, 0);
    MF::add(n + m + p, n + m + (p << 1 | 1), R - L + 1, 0);
}

void add(int id, int p, int l, int r, int L, int R) {
    if (r < L || R < l) return;
    if (l <= L && R <= r) {
        MF::add(id, n + m + p, 1, 0);
        return;
    }
    add(id, p << 1, l, r, L, L + R >> 1);
    add(id, p << 1 | 1, l, r, (L + R >> 1) + 1, R);
}

void chemthan() {
    cin >> n >> m;
    int tot = n + m + 65000, s = tot++, t = tot++;
    MF::init(tot, s, t);
    build(1, 0, m - 1);
    static int tp[5005];
    static vi g[5005];
    FOR(i, 0, n) {
        int t; cin >> t;
        tp[i] = t;
        if (t == 0) {
            MF::add(s, i, 1, 0);
            int k; cin >> k;
            while (k--) {
                int u; cin >> u; u--;
                MF::add(i, n + u, 1, 0);
            }
        }
        else if (t == 1) {
            MF::add(s, i, 1, 0);
            int l, r; cin >> l >> r; l--, r--;
            add(i, 1, l, r, 0, m - 1);
        }
        else if (t == 2) {
            MF::add(s, i, 2, 0);
            int a, b, c; cin >> a >> b >> c; a--, b--, c--;
            MF::add(i, n + a, 1, 0);
            MF::add(i, n + b, 1, 0);
            MF::add(i, n + c, 1, 0);
            g[i].pb(a);
            g[i].pb(b);
            g[i].pb(c);
        }
    }
    FOR(i, 0, m) MF::add(n + i, t, 1, 0);
    cout << MF::maxflow() << "\n";
    static int to[5005];
    static int from[5005];
    static int z[5005][5005];
    vii res = MF::trace();
    for (pi e : res) {
        z[e.fi][e.se - n] = 1;
    }
    ms(to, -1), ms(from, -1);
    FOR(i, 0, n) {
        if (tp[i] == 2) {
            vi vals;
            map<int, int> used;
            FOR(j, 0, m) {
                if (z[i][j] > 0) {
                    vals.pb(j);
                    used[j] = 1;
                }
            }
            if (sz(vals) && sz(vals) < 2) {
                for (int u : g[i]) {
                    if (!used[u]) {
                        from[u] = 0;
                        vals.pb(u);
                        break;
                    }
                }
            }
            for (int u : vals) {
                cout << i + 1 << " " << u + 1 << "\n";
            }
        }
    }
    FOR(i, 0, n) {
        if (tp[i] != 2) {
            FOR(j, 0, m) {
                if (z[i][j] > 0) {
                    if (from[j] == -1) {
                        cout << i + 1 << " " << j + 1 << "\n";
                    }
                }
            }
        }
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