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
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

template<class T> struct SegmenTree {
    static const int MAXN = 1e5 + 5;
    T st[MAXN << 2];
    T lz[MAXN << 2];

    SegmenTree() {
        FOR(i, 0, MAXN << 2) st[i] = lz[i] = 1e9;
    }
    void pushdown(int p, int L, int R) {
        if (lz[p] < 1e9) {
            chkmin(st[p], lz[p]);
            if (L < R) {
                chkmin(lz[p << 1], lz[p]);
                chkmin(lz[p << 1 | 1], lz[p]);
            }
            lz[p] = 1e9;
        }
    }
    void upd(int p, int l, int r, int L, int R, T val) {
        pushdown(p, L, R);
        if (l > R || r < L) return;
        if (l <= L && r >= R) {
            lz[p] = val;
            pushdown(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        st[p] = min(st[p << 1], st[p << 1 | 1]);
    }
    T query(int p, int l, int r, int L, int R) {
        pushdown(p, L, R);
        if (l > R || r < L) return 1e9;
        if (l <= L && r >= R) return st[p];
        return min(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
};
SegmenTree<int> seg;

namespace HLD {
    int n;
    vector<vector<pair<int, int>>> adj;
    vector<int> size;
    vector<int> lev;
    vector<int> p;
    vector<int> heavy;

    vector<int> num;
    vector<int> head;
    int cnt;

    vector<int> mape;

    void firstdfs(int u, int dad) {
        size[u] = 1, heavy[u] = -1;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int ix = adj[u][i].second;
            if (v != dad) {
                p[v] = u, lev[v] = lev[u] + 1;
                mape[ix] = v;
                firstdfs(v, u);
                size[u] += size[v];
                if (heavy[u] == -1 || size[heavy[u]] < size[v]) {
                    heavy[u] = v;
                }
            }
        }
    }
    void dfs(int u, int h, int p) {
        num[u] = cnt++, head[u] = h;
        if (~heavy[u]) {
            dfs(heavy[u], h, u);
        }
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (v != p && v != heavy[u]) {
                dfs(v, v, u);
            }
        }
    }
    void build(const vector<vector<pair<int, int>>>& _adj, int m) {
        n = (int) _adj.size();
        adj = _adj;
        size.resize(n);
        lev.resize(n);
        p.resize(n);
        heavy.resize(n);

        num.resize(n);
        head.resize(n);
        cnt = 0;

        mape.resize(m);

        firstdfs(0, -1), dfs(0, 0, -1);
    }
    vector<pair<int, int>> getsegs(int u, int v) {
        vector<pair<int, int>> res;
        int hu = head[u], hv = head[v];
        while (hu != hv) {
            if (lev[hu] < lev[hv]) swap(u, v), swap(hu, hv);
            res.push_back(make_pair(num[hu], num[u]));
            u = p[hu], hu = head[u];
        }
        if (lev[u] > lev[v]) swap(u, v);
        res.push_back(make_pair(num[u] + 1, num[v]));
        return res;
    }
}

void chemthan() {
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int, int>> edges;
    vi ws(m);
    FOR(i, 0, m) {
        int u, v, w; cin >> u >> v >> w, u--, v--;
        edges.pb(make_tuple(w, i, u, v));
        ws[i] = w;
    }
    vi res(m);
    if (1) {
        sort(all(edges));
        vi dj(n);
        function<int(int)> find = [&] (int u) {
            return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
        };
        FOR(u, 0, n) dj[u] = u;
        vector<vii> adj(n);
        vi use(m);
        for (auto e : edges) {
            int w, ix, u, v; tie(w, ix, u, v) = e;
            if (find(u) ^ find(v)) {
                dj[find(u)] = find(v);
                adj[u].pb(mp(v, w));
                adj[v].pb(mp(u, w));
                use[ix] = 1;
            }
        }
        int logn = 20;
        vi lev(n);
        vector<vi> par(logn, vi(n));
        vector<vi> f(logn, vi(n));
        function<void(int, int)> dfs = [&] (int u, int p) {
            FOR(i, 1, logn) {
                par[i][u] = par[i - 1][par[i - 1][u]];
                f[i][u] = max(f[i - 1][u], f[i - 1][par[i - 1][u]]);
            }
            for (auto e : adj[u]) {
                int v = e.fi;
                int w = e.se;
                if (v ^ p) {
                    lev[v] = lev[u] + 1;
                    par[0][v] = u;
                    f[0][v] = w;
                    dfs(v, u);
                }
            }
        };
        dfs(0, -1);
        auto query = [&] (int u, int v) {
            if (lev[u] < lev[v]) {
                swap(u, v);
            }
            int res = 0;
            FORd(i, logn, 0) {
                if (lev[v] <= lev[par[i][u]]) {
                    chkmax(res, f[i][u]);
                    u = par[i][u];
                }
            }
            if (u == v) return res;
            FORd(i, logn, 0) {
                if (par[i][u] ^ par[i][v]) {
                    chkmax(res, f[i][u]);
                    chkmax(res, f[i][v]);
                    u = par[i][u];
                    v = par[i][v];
                }
            }
            chkmax(res, f[0][u]);
            chkmax(res, f[0][v]);
            return res;
        };
        for (auto e : edges) {
            int w, ix, u, v; tie(w, ix, u, v) = e;
            if (!use[ix]) {
                res[ix] = query(u, v);
            }
        }
    }
    if (2) {
        sort(all(edges));
        vi dj(n);
        function<int(int)> find = [&] (int u) {
            return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
        };
        FOR(u, 0, n) dj[u] = u;
        vector<vii> adj(n);
        vi use(m);
        for (auto e : edges) {
            int w, ix, u, v; tie(w, ix, u, v) = e;
            if (find(u) ^ find(v)) {
                dj[find(u)] = find(v);
                adj[u].pb(mp(v, ix));
                adj[v].pb(mp(u, ix));
                use[ix] = 1;
            }
        }
        HLD::build(adj, m);
        vii events;
        for (auto e : edges) {
            int w, ix, u, v; tie(w, ix, u, v) = e;
            if (!use[ix]) {
                auto segs = HLD::getsegs(u, v);
                for (auto s : segs) {
                    seg.upd(1, s.fi, s.se, 0, n - 1, w);
                }
            }
        }
        vi f(n);
        FOR(i, 0, n) f[i] = seg.query(1, i, i, 0, n - 1);
        FOR(i, 0, m) if (use[i]) {
            int j = HLD::mape[i];
            int k = HLD::num[j];
            res[i] = f[k];
        }
    }
    FOR(i, 0, m) cout << res[i] << "\n";
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