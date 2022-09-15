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

struct Tree_t {
    vector<int> events;
    vector<int> sta;
    vector<int> lev;
    vector<int> tin;
    vector<int> tou;
    vector<int> idx;
    vector<vector<int>> par;
    int timer;
    vector<vector<int>> f;
    vector<int> mlg;

    void dfs(int u, int p, const vector<vector<int>>& adj) {
        idx[tin[u] = timer++] = u;
        sta[u] = events.size();
        events.push_back(tin[u]);
        for (int i = 1; i < (int) par.size(); i++) {
            par[i][u] = par[i - 1][par[i - 1][u]];
        }
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (v != p) {
                lev[v] = lev[u] + 1;
                par[0][v] = u;
                dfs(v, u, adj);
                events.push_back(tin[u]);
            }
        }
        tou[u] = timer - 1;
    }
    void build(const vector<vector<int>>& adj, int rt = 0) {
        events.clear();
        sta.resize(adj.size());
        lev.resize(adj.size());
        tin.resize(adj.size());
        tou.resize(adj.size());
        idx.resize(adj.size());
        par.resize(__lg(adj.size()) + 1, vector<int>(adj.size()));
        for (int i = 0; i < (int) par.size(); i++) {
            par[i][rt] = rt;
        }
        timer = lev[rt] = 0, dfs(rt, -1, adj);
        int logn = __lg(events.size()) + 1;
        f.resize(logn);
        for (int i = 0; i < logn; i++) {
            f[i].resize(events.size());
        }
        for (int i = 0; i < events.size(); i++) {
            f[0][i] = events[i];
        }
        for (int i = 1; i < logn; i++) {
            for (int j = 0; j + (1 << i - 1) < events.size(); j++) {
                f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
            }
        }
        mlg.resize(events.size());
        for (int i = 1; i < mlg.size(); i++) {
            mlg[i] = __lg(i);
        }
    }
    int rmq(int u, int v) {
        int l = u == v ? 0 : mlg[v - u];
        return min(f[l][u], f[l][v - (1 << l) + 1]);
    }
    int lca(int u, int v) {
        if (sta[u] > sta[v]) swap(u, v);
        return idx[rmq(sta[u], sta[v])];
    }
    int dist(int u, int v) {
        int a = lca(u, v);
        return lev[u] + lev[v] - lev[a] - lev[a];
    }
    int isanc(int p, int u) {
        return tin[p] <= tin[u] && tou[u] <= tou[p];
    }
    int go_up(int u, int k) {
        for (int i = (int) par.size() - 1; 0 <= i; i--) {
            if ((1 << i) <= k) {
                k -= 1 << i;
                u = par[i][u];
            }
        }
        return u;
    }
    int go_to(int u, int v, int k) {
        int a = lca(u, v);
        if (k <= lev[u] - lev[a]) {
            return go_up(u, k);
        }
        k -= lev[u] - lev[a];
        k = lev[v] - lev[a] - k;
        return go_up(v, k);
    }
} tree;

void chemthan() {
    int n, k, r; cin >> n >> k >> r;
    vector<vi> adj(n);
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    tree.build(adj);
    vi dj(n);
    FOR(i, 0, n) dj[i] = i;
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    vi vis(n);
    queue<int> que;
    vi f(n);
    FOR(i, 0, r) {
        int u; cin >> u; u--;
        f[u] = 1;
        vis[u] = 1, que.push(u), que.push(0);
    }
    vi d(n);
    while (sz(que)) {
        int u = que.front(); que.pop();
        int t = que.front(); que.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1, que.push(v), que.push(d[v] = t + 1);
                dj[find(v)] = find(u);
            }
            else if (d[u] + d[v] + 1 <= k) {
                dj[find(v)] = find(u);
            }
        }
    }
    map<int, vi> clus;
    FOR(u, 0, n) if (f[u]) {
        clus[find(u)].pb(u);
    }
    fill(all(vis), 0);
    vi id(n, -1);
    int num = 0;
    for (auto e : clus) {
        int w = -1;
        for (int u : e.se) {
            if (w == -1) {
                w = u;
            }
            else {
                w = tree.lca(w, u);
            }
        }
        id[w] = num;
        vis[w] = 1;
        for (int u : e.se) {
            int t = u;
            while (!vis[t]) {
                vis[t] = 1;
                id[t] = num;
                t = tree.par[0][t];
            }
        }
        num++;
    }
    vii x(n, mp(INF, -1));
    vector<vii> y(20, vii(n, mp(INF, -1)));
    vector<vii> z(20, vii(n, mp(INF, -1)));
    vii w(n);
    function<void(int, int)> dfs = [&] (int u, int p) {
        if (f[u]) {
            x[u] = mp(0, u);
        }
        for (int v : adj[u]) {
            if (v ^ p) {
                dfs(v, u);
                chkmin(x[u], mp(x[v].fi + 1, x[v].se));
            }
        }
        y[0][u] = z[0][u] = x[u];
        y[0][u].fi -= tree.lev[u];
        z[0][u].fi += tree.lev[u];
    };
    function<void(int, int, pi)> upd_dfs = [&] (int u, int p, pi mn) {
        if (f[u]) {
            mn = mp(0, u);
        }
        multiset<pi> st;
        st.insert(mn);
        for (int v : adj[u]) {
            if (v ^ p) {
                st.insert(x[v]);
            }
        }
        for (int v : adj[u]) {
            if (v ^ p) {
                st.erase(st.find(x[v]));
                auto nmn = *st.begin();
                nmn.fi++;
                upd_dfs(v, u, nmn);
                st.insert(x[v]);
            }
        }
        w[u] = mn;
    };
    vector<vi> par(20, vi(n));
    function<void(int, int)> build_dfs = [&] (int u, int p) {
        FOR(i, 1, 20) {
            par[i][u] = par[i - 1][par[i - 1][u]];
            y[i][u] = min(y[i - 1][u], y[i - 1][par[i - 1][u]]);
            z[i][u] = min(z[i - 1][u], z[i - 1][par[i - 1][u]]);
        }
        for (int v : adj[u]) {
            if (v ^ p) {
                par[0][v] = u;
                build_dfs(v, u);
            }
        }
    };
    dfs(0, -1);
    upd_dfs(0, -1, mp(INF, -1));
    build_dfs(0, -1);
    auto query = [&] (int u, int k, int t) {
        pi res = mp(INF, -1);
        FORd(i, 20, 0) {
            if ((1 << i) <= k) {
                if (!t) {
                    chkmin(res, y[i][u]);
                }
                else if (t == 1) {
                    chkmin(res, z[i][u]);
                }
                u = par[i][u];
                k -= 1 << i;
            }
        }
        return res;
    };
    auto query_path = [&] (int u, int v, int t) {
        if (tree.isanc(v, u)) swap(u, v);
        if (tree.isanc(u, v)) {
            return query(v, tree.lev[v] - tree.lev[u] + 1, t);
        }
        int w = tree.lca(u, v);
        return min(query(u, tree.lev[u] - tree.lev[w] + 1, t), query(v, tree.lev[v] - tree.lev[w] + 1, t));
    };
    auto check = [&] (int u, int v) {
        if (id[u] == id[v]) {
            return true;
        }
        int ou = u;
        if (tree.isanc(v, u)) {
            int d = tree.lev[u] - tree.lev[v];
            FORd(i, 20, 0) {
                if ((1 << i) <= d && id[par[i][u]] != id[v]) {
                    d -= 1 << i;
                    u = par[i][u];
                }
            }
            u = par[0][u];
        }
        else {
            int w = tree.lca(u, v);
            if (id[w] == id[v]) {
                int d = tree.lev[u] - tree.lev[w];
                FORd(i, 20, 0) {
                    if ((1 << i) <= d && id[par[i][u]] != id[v]) {
                        d -= 1 << i;
                        u = par[i][u];
                    }
                }
                u = par[0][u];
            }
            else {
                int d = tree.lev[v] - tree.lev[w];
                u = v;
                FORd(i, 20, 0) {
                    if ((1 << i) <= d && id[par[i][u]] == id[v]) {
                        u = par[i][u];
                        d -= 1 << i;
                    }
                }
            }
        }
        return tree.dist(ou, u) + d[u] <= k;
    };
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        auto solve = [&] () {
            int d = tree.dist(u, v);
            if (d <= k) {
                cout << "YES\n";
                return;
            }
            int uu = tree.go_to(u, v, d >> 1);
            int vv = tree.go_to(v, u, d >> 1);
            int a = tree.lca(u, v);
            FOR(t, 0, 2) {
                auto mnu = query_path(u, uu, t);
                auto mnv = query_path(v, vv, t);
                auto mnua = query_path(u, a, t);
                auto mnva = query_path(v, a, t);
                auto mnuua = query_path(uu, a, t);
                auto mnvva = query_path(vv, a, t);
                for (int w : {mnu.se, mnv.se, mnua.se, mnva.se, mnuua.se, mnvva.se}) {
                    if (w != -1) {
                        if (tree.dist(u, w) <= k && tree.dist(v, w) <= k) {
                            cout << "YES\n";
                            return;
                        }
                    }
                }
            }
            for (int w : {w[a].se}) {
                if (w != -1) {
                    if (tree.dist(u, w) <= k && tree.dist(v, w) <= k) {
                        cout << "YES\n";
                        return;
                    }
                }
            }
            if (id[uu] != -1 && id[uu] == id[vv]) {
                if (check(u, uu) && check(v, vv)) {
                    cout << "YES\n";
                    return;
                }
            }
            cout << "NO\n";
        };
        solve();
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