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

void chemthan() {
    vector<long long> vals;
    vals.pb(0);
    FOR(i1, 0, 32) FOR(i2, i1, 32) FOR(i3, i2, 32) FOR(i4, i3, 32) FOR(i5, i4, 32) {
        int ar[] = {i1, i2, i3, i4, i5};
        FOR(k, 1, 5 + 1) {
            long long r = 0;
            FOR(msk, 1, 1 << k) {
                int t = 0;
                FOR(i, 0, k) if (bit(msk, i)) {
                    t ^= ar[i];
                }
                r |= 1LL << t;
            }
            vals.pb(r);
        }
    }
    vals.pb((1LL << 32) - 1);
    sort(all(vals)), uni(vals);
    vector<vi> g(sz(vals), vi(sz(vals)));
    FOR(i, 0, sz(vals)) FOR(j, 0, sz(vals)) {
        long long x = vals[i];
        long long y = vals[j];
        long long z = x | y;
        FOR(u, 0, 32) if (bit(x, u)) {
            FOR(v, 0, 32) if (bit(y, v)) {
                z |= 1LL << (u ^ v);
            }
        }
        g[i][j] = lower_bound(all(vals), z) - vals.begin();
        assert(g[i][j] < sz(vals) && vals[g[i][j]] == z);
    }
    auto find_ix = [&] (long long x) {
        int k = lower_bound(all(vals), x) - vals.begin();
        assert(k < sz(vals) && vals[k] == x);
        return k;
    };
    auto merge = [&] (long long x, long long y) {
        int ix = find_ix(x);
        int iy = find_ix(y);
        return vals[g[ix][iy]];
    };

    int n, m; cin >> n >> m;
    vector<vii> adj(n);
    vi a(n), dj(n);
    vector<long long> b(n);
    FOR(i, 0, n) dj[i] = i;
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    auto join = [&] (int u, int v) {
        u = find(u);
        v = find(v);
        if (u ^ v) {
            dj[u] = v;
            b[v] = merge(b[v], b[u]);
        }
    };
    map<pi, int> hs;
    FOR(i, 0, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        hs[mp(u, v)] = hs[mp(v, u)] = w;
    }
    map<pi, int> mem;
    vi vis(n);
    function<void(int, int)> dfs = [&] (int u, int p) {
        vis[u] = 1;
        for (auto e : adj[u]) {
            int v = e.fi;
            int w = e.se;
            if (!v) continue;
            if (!vis[v]) {
                a[v] = a[u] ^ w;
                join(u, v);
                dfs(v, u);
            }
            else if (v != p) {
                auto& bb = b[find(u)];
                if (!mem.count(mp(u, v))) {
                    bb = merge(bb, 1LL << (a[u] ^ a[v] ^ w));
                    mem[mp(u, v)] = mem[mp(v, u)] = 1;
                }
            }
        }
    };
    FOR(u, 1, n) if (!vis[u]) {
        dfs(u, -1);
    }
    map<int, long long> hs2;
    for (auto e : adj[0]) {
        int v = e.fi;
        int w = e.se;
        for (auto e2 : adj[v]) {
            int v2 = e2.fi;
            int w2 = e2.se;
            if (v < v2 && hs.count(mp(v2, 0))) {
                hs2[find(v)] = 1LL << (w ^ w2 ^ hs[mp(v2, 0)]);
            }
        }
    }
    vi dp(sz(vals));
    dp[0] = 1;
    FOR(i, 1, n) if (dj[i] == i) {
        long long x = b[i];
        long long y = hs2.count(i) ? hs2[i] : -1LL;
        int cx = 1;
        if (y != -1) {
            y = merge(x, y);
            cx = 2;
        }
        vi ndp = dp;
        int xx = find_ix(x);
        int yy = y != -1 ? find_ix(y) : -1;
        FOR(j, 0, sz(vals)) if (dp[j]) {
            int ix = g[xx][j];
            addmod(ndp[ix], mult(dp[j], cx));
            if (y != -1) {
                int iy = g[yy][j];
                addmod(ndp[iy], dp[j]);
            }
        }
        dp = ndp;
    }
    int res = 0;
    FOR(i, 0, sz(vals)) if (!bit(vals[i], 0)) {
        addmod(res, dp[i]);
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