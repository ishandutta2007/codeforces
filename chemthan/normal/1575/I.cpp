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
        //upd(num[u] + 1, num[v]) for edge path
        res.push_back(make_pair(num[u], num[v]));
        return res;
    }
}

void chemthan() {
    int n, q; cin >> n >> q;
    vi a(n);
    FOR(i, 0, n) cin >> a[i], a[i] = abs(a[i]);
    vector<vi> adj(n);
    map<pi, int> hs;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
        hs[mp(u, v)] = hs[mp(v, u)] = 1;
    }
    HLD::build(adj);
    vector<long long> fen(n + 1);
    auto upd = [&] (int p, int v) {
        p++;
        for (; p < sz(fen); p += p & -p) {
            fen[p] += v;
        }
    };
    auto query = [&] (int p) {
        p++;
        long long res = 0;
        for (; 0 < p; p -= p & -p) {
            res += fen[p];
        }
        return res;
    };
    FOR(i, 0, n) {
        upd(HLD::num[i], a[i]);
    }
    while (q--) {
        int op, u, v; cin >> op >> u >> v;
        if (op == 1) {
            u--, v = abs(v);
            upd(HLD::num[u], -a[u]);
            a[u] = v;
            upd(HLD::num[u], a[u]);
        }
        else {
            u--, v--;
            if (u == v) {
                cout << 0 << "\n";
                continue;
            }
            long long res = 0;
            for (auto [l, r] : HLD::getsegs(u, v)) {
                res += query(r);
                res -= query(l - 1);
            }
            if (!hs[mp(u, v)]) {
                res *= 2;
                res -= a[u];
                res -= a[v];
            }
            cout << res << "\n";
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