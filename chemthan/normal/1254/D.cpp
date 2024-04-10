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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
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

void solve() {
    int n, q; cin >> n >> q;
    vector<vi> adj(n);
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    vi fen(n + 1);
    auto upd = [&] (int p, int val) {
        p++;
        for (; p < sz(fen); p += p & -p) {
            addmod(fen[p], val);
        }
    };
    auto query = [&] (int p) {
        p++;
        int res = 0;
        for (; 0 < p; p -= p & -p) {
            addmod(res, fen[p]);
        }
        return res;
    };
    vi lev(n);
    vi szz(n);
    vector<vi> par(20, vi(n));
    vi tin(n), tou(n);
    int tms = 0;
    function<void(int, int)> dfs = [&] (int u, int p) {
        szz[u] = 1;
        tin[u] = tms++;
        FOR(i, 1, 20) par[i][u] = par[i - 1][par[i - 1][u]];
        for (int v : adj[u]) {
            if (v ^ p) {
                lev[v] = lev[u] + 1;
                par[0][v] = u;
                dfs(v, u);
                szz[u] += szz[v];
            }
        }
        tou[u] = tms - 1;
    };
    auto isanc = [&] (int u, int v) {
        return tin[u] <= tin[v] && tou[v] <= tou[u];
    };
    auto go = [&] (int u, int v) {
        FORd(i, 20, 0) {
            if (lev[par[i][u]] > lev[v]) {
                u = par[i][u];
            }
        }
        return u;
    };
    dfs(0, -1);
    int magic = 500;
    vi f(n);
    int tot = 0;
    vi ver;
    FOR(u, 0, n) if (magic <= sz(adj[u])) {
        ver.pb(u);
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int u, d; cin >> u >> d; u--;
            addmod(f[u], d);
            int k = szz[u];
            addmod(tot, mult(k, d));
            int t = mult(n - k, d);
            upd(tin[u] + 1, (MOD - t) % MOD);
            upd(tou[u] + 1, t);
            if (sz(adj[u]) < magic) {
                for (int v : adj[u]) {
                    if (isanc(u, v)) {
                        int l = tin[v];
                        int r = tou[v];
                        int x = mult(d, szz[v]);
                        upd(l, x);
                        upd(r + 1, (MOD - x) % MOD);
                    }
                }
            }
        }
        else {
            int u; cin >> u; u--;
            int res = tot;
            addmod(res, mult(f[u], n - szz[u]));
            submod(res, query(tin[u]));
            for (int v : ver) {
                if (isanc(v, u) && v != u) {
                    int w = go(u, v);
                    submod(res, mult(szz[w], f[v]));
                }
            }
            res = mult(res, inv(n));
            cout << res << "\n";
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
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}