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

namespace HLD {
    int n;
    vector<vector<int>> adj;
    vector<int> size;
    vector<int> lev;
    vector<int> p;
    vector<int> heavy;

    vector<int> num;
    vector<int> head;
    int cnt;

    void firstdfs(int u, int dad) {
        size[u] = 1, heavy[u] = -1;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (v != dad) {
                p[v] = u, lev[v] = lev[u] + 1;
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
            int v = adj[u][i];
            if (v != p && v != heavy[u]) {
                dfs(v, v, u);
            }
        }
    }
    void build(const vector<vector<int>>& _adj) {
        n = (int) _adj.size();
        adj = _adj;
        size.resize(n);
        lev.resize(n);
        p.resize(n);
        heavy.resize(n);

        num.resize(n);
        head.resize(n);
        cnt = 0;
        firstdfs(0, -1), dfs(0, 0, -1);
    }
}

void chemthan() {
    int n, q; cin >> n >> q;
    vector<vi> adj(n);
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    HLD::build(adj);
    int logn = __lg(n) + 1;
    vi lev(n), mx(n);
    vector<vi> par(logn, vi(n));
    function<void(int, int)> dfs = [&] (int u, int p) {
        FOR(i, 1, logn) par[i][u] = par[i - 1][par[i - 1][u]];
        mx[u] = u;
        for (int v : adj[u]) {
            if (v != p) {
                lev[v] = lev[u] + 1;
                par[0][v] = u;
                dfs(v, u);
                chkmax(mx[u], mx[v]);
            }
        }
    };
    auto lca = [&] (int u, int v) {
        if (lev[u] < lev[v]) swap(u, v);
        FORd(i, logn, 0) {
            if (lev[par[i][u]] >= lev[v]) {
                u = par[i][u];
            }
        }
        if (u == v) return u;
        FORd(i, logn, 0) {
            if (par[i][u] ^ par[i][v]) {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    };
    auto dist = [&] (int u, int v) {
        int a = lca(u, v);
        return lev[u] + lev[v] - lev[a] - lev[a];
    };
    dfs(par[0][n - 1] = n - 1, -1);
    vi ver; FOR(u, 0, n) ver.pb(u);
    sort(all(ver), [&] (int i, int j) {
            if (mx[i] ^ mx[j]) return mx[i] < mx[j];
            return lev[i] > lev[j];
            }
        );
    vi od(n);
    FOR(i, 0, n) od[ver[i]] = i;
    vector<vi> st(n << 2, vi(2));
    vi lz(n << 2);
    auto push = [&] (int p, int L, int R) {
        if (lz[p]) {
            st[p][0] = lz[p], st[p][1] = -lz[p];
            if (L < R) {
                FOR(i, p << 1, p + 1 << 1) {
                    lz[i] = lz[p];
                }
            }
            lz[p] = 0;
        }
    };
    function<void(int, int, int, int, int, int)> upd = [&] (int p, int l, int r, int L, int R, int val) {
        push(p, L, R);
        if (R < l || r < L) return;
        if (l <= L && R <= r) {
            lz[p] = val;
            push(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        FOR(i, 0, 2) {
            st[p][i] = min(st[p << 1][i], st[p << 1 | 1][i]);
        }
    };
    function<pi(int, int, int, int, int, pi&)> query = [&] (int p, int l, int r, int L, int R, pi& e) {
        push(p, L, R);
        if (R < l || r < L) return mp(-1, -1);
        if (l <= L && R <= r) {
            auto check = [&] (pi a, pi b) {
                chkmin(a.fi, b.fi);
                chkmin(a.se, b.se);
                return a.fi == -a.se;
            };
            pi ne = mp(st[p][0], st[p][1]);
            if (!check(e, ne)) {
                while (L < R) {
                    push(p << 1, L, L + R >> 1);
                    push(p << 1 | 1, (L + R >> 1) + 1, R);
                    if (check(e, {st[p << 1][0], st[p << 1][1]})) {
                        chkmin(e.fi, st[p << 1][0]);
                        chkmin(e.se, st[p << 1][1]);
                        L = (L + R >> 1) + 1;
                        p = p << 1 | 1;
                    }
                    else {
                        R = L + R >> 1;
                        p = p << 1;
                    }
                }
                return mp((L + R >> 1) - 1, e.fi);
            }
            chkmin(e.fi, ne.fi);
            chkmin(e.se, ne.se);
            return mp(-1, -1);
        }
        pi x = query(p << 1, l, r, L, L + R >> 1, e);
        if (x != mp(-1, -1)) return x;
        return query(p << 1 | 1, l, r, (L + R >> 1) + 1, R, e);
    };
    function<int(int, int, int, int)> querye = [&] (int p, int i, int L, int R) {
        push(p, L, R);
        if (R < i || i < L) return 0;
        if (L == R) return st[p][0];
        return querye(p << 1, i, L, L + R >> 1) + querye(p << 1 | 1, i, (L + R >> 1) + 1, R);
    };
    auto querys = [&] (int l, int r) {
        pi e = mp(INF, INF);
        pi res = query(1, l, r, 0, n - 1, e);
        if (res != mp(-1, -1)) return res;
        return mp(r, e.fi);
    };
    vi fen(n + q + 5);
    auto updf = [&] (int p, int val) {
        p++;
        for (; p < sz(fen); p += p & -p) {
            fen[p] += val;
        }
    };
    auto queryf = [&] (int p) {
        p++;
        int res = 0;
        for (; p > 0; p -= p & -p) {
            res += fen[p];
        }
        return res;
    };
    FOR(u, 0, n) {
        updf(od[u], 1);
        upd(1, HLD::num[u], HLD::num[u], 0, n - 1, od[u]);
    }
    vi vals(1, n - 1);
    auto getstep = [&] (int u) {
        int x = querye(1, HLD::num[u], 0, n - 1);
        return queryf(x - 1) + (n <= x ? dist(vals[x - n], u) : 0) + 1;
    };
    FOR(it, 1, q + 1) {
        string op; cin >> op;
        if (op == "up") {
            int v; cin >> v; v--;
            int lst = vals.back();
            auto upd3 = [&] (int l, int r) {
                int tl = l, tr = r;
                while (l <= r) {
                    pi p = querys(l, r);
                    updf(p.se, -(p.fi - l + 1));
                    l = p.fi + 1;
                }
                updf(n + sz(vals) - 1, tr - tl + 1);
                upd(1, tl, tr, 0, n - 1, n + sz(vals) - 1);
            };
            auto upd2 = [&] (int u, int v) {
                int hu = HLD::head[u], hv = HLD::head[v];
                while (hu != hv) {
                    if (HLD::lev[hu] < HLD::lev[hv]) swap(u, v), swap(hu, hv);
                    upd3(HLD::num[hu], HLD::num[u]);
                    u = HLD::p[hu], hu = HLD::head[u];
                }
                if (HLD::lev[u] > HLD::lev[v]) swap(u, v);
                upd3(HLD::num[u], HLD::num[v]);
            };
            upd2(v, lst);
            vals.pb(v);
        }
        else if (op == "when") {
            int v; cin >> v; v--;
            cout << getstep(v) << "\n";
        }
        else {
            int u, v; cin >> u >> v; u--, v--;
            if (getstep(u) < getstep(v)) {
                cout << u + 1 << "\n";
            }
            else {
                cout << v + 1 << "\n";
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