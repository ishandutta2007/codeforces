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

void chemthan() {
    int n, m, q; cin >> n >> m >> q;
    vi p(n);
    FOR(i, 0, n) cin >> p[i];
    vii edges;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        edges.pb({u, v});
    }
    vi dj(n);
    FOR(i, 0, n) dj[i] = i;
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    vii qs;
    vi flag(m);
    FOR(i, 0, q) {
        int u, v; cin >> u >> v, v--;
        qs.pb({u, v});
        if (u == 2) {
            flag[v] = 1;
        }
    }
    FOR(i, 0, m) if (!flag[i]) {
        int u, v; tie(u, v) = edges[i];
        dj[find(u)] = find(v);
    }
    vector<vi> g(n);
    FOR(i, 0, n) {
        g[find(i)].pb(i);
    }
    vi vv(q, -1);
    FORd(i, q, 0) {
        int u, v; tie(u, v) = qs[i];
        if (u == 2) {
            int x, y; tie(x, y) = edges[v];
            x = find(x), y = find(y);
            if (x != y) {
                if (sz(g[x]) < sz(g[y])) {
                    g[x].swap(g[y]);
                }
                vv[i] = g[y][0];
                for (auto e : g[y]) {
                    g[x].pb(e);
                }
                g[y].clear();
                g[y].shrink_to_fit();
            }
            dj[y] = x;
        }
    }
    set<int> st;
    vi od;
    int ptr = 0;
    FOR(i, 0, n) if (find(i) == i) {
        st.insert(ptr);
        ptr += sz(g[i]);
        for (auto e : g[i]) {
            od.pb(e);
        }
    }
    endln;
    vi iod(n);
    FOR(i, 0, n) iod[od[i]] = i;
    vi iod2(n + 1);
    FOR(i, 0, n) iod2[p[od[i]]] = i;
    vi ss(n << 1);
    auto upd = [&] (int p, int v) {
        for (ss[p += n] = v; 1 < p; ) p >>= 1, ss[p] = max(ss[p << 1], ss[p << 1 | 1]);
    };
    auto query = [&] (int l, int r) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) chkmax(res, ss[l++]);
            if (r & 1) chkmax(res, ss[--r]);
        }
        return res;
    };
    FOR(i, 0, n) {
        upd(i, p[od[i]]);
    }
    FOR(i, 0, q) {
        int u, v; tie(u, v) = qs[i];
        if (u == 1) {
            auto it = st.upper_bound(iod[v]);
            int r = it == st.end() ? n - 1 : *it - 1;
            it--;
            int l = *it;
            int x = query(l, r);
            cout << x << "\n";
            if (x) {
                int ix = iod2[x];
                upd(ix, 0);
            }
        }
        else if (vv[i] != -1) {
            st.insert(iod[vv[i]]);
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