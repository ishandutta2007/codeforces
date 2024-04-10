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

template<typename num_t>
struct RangeFenwick {
    int n;
    vector<num_t> fen[2];
    RangeFenwick(int n) {
        this->n = n;
        fen[0].resize(n + 1);
        fen[1].resize(n + 1);
    }
    void upd(int p, num_t val) {
        p++;
        assert(0 < p);
        for (int pp = p; pp <= n; pp += pp & -pp) {
            fen[0][pp] += val;
            fen[1][pp] += val * p;
        }
    }
    void upd(int l, int r, num_t val) {
        upd(l, +val), upd(r + 1, -val);
    }
    num_t query(int p) {
        p++;
        assert(p <= n);
        num_t res = 0;
        for (int pp = p; pp > 0; pp -= pp & -pp) {
            res += fen[0][pp] * (p + 1);
            res -= fen[1][pp];
        }
        return res;
    }
    num_t query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void chemthan() {
    int n, q; cin >> n >> q;
    vector<tuple<int, int, int>> qs;
    vi dj(n);
    FOR(u, 0, n) dj[u] = u;
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    auto join = [&] (int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            dj[u] = v;
            return 1;
        }
        return 0;
    };
    vector<vi> adj(n + 1);
    FOR(i, 0, q) {
        int u, v, x; cin >> u >> v >> x; u--, v--;
        qs.pb({u, v, x});
        if (join(u, v)) {
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    FOR(u, 0, n) if (dj[u] == u) {
        adj[n].pb(u);
        adj[u].pb(n);
    }
    HLD::build(adj);
    FOR(u, 0, n) dj[u] = u;
    RangeFenwick<int> fen(n + 1);
    RangeFenwick<int> fen2(n + 1);
    for (auto [u, v, x] : qs) {
        if (join(u, v)) {
            auto segs = HLD::getsegs(u, v);
            for (auto [l, r] : segs) {
                fen.upd(l, r, x);
            }
            cout << "YES\n";
        }
        else {
            auto segs = HLD::getsegs(u, v);
            int sum = 0;
            int sum2 = 0;
            for (auto [l, r] : segs) {
                sum += fen.query(l, r);
                sum2 += fen2.query(l, r);
            }
            if (sum2) {
                cout << "NO\n";
            }
            else {
                if (sum + x & 1) {
                    cout << "YES\n";
                    for (auto [l, r] : segs) {
                        fen2.upd(l, r, 1);
                    }
                }
                else {
                    cout << "NO\n";
                }
            }
        }
    }
}

int32_t main(int32_t argc, char* argv[]) {
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