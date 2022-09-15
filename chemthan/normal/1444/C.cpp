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
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

#define int long long
struct Data {
    int time, u, par;
};

struct DSU {
    vector<int> par;
    vector<Data> change;

    void init(int n) {
        par = vector<int> (n + 5, -1);
        change.clear();
    }

    int getRoot(int x) {
        while (par[x] >= 0) {
            x = par[x];
        }
        return x;
    }

    void join(int x, int y, int t) {
        x = getRoot(x);
        y = getRoot(y);
        if (x == y) {
            return;
        }
        if (par[x] < par[y]) swap(x, y);
        change.push_back({t, y, par[y]});
        par[y] += par[x];
        change.push_back({t, x, par[x]});
        par[x] = y;
    }

    void rollback(int t) {
        while (!change.empty() && change.back().time > t) {
            par[change.back().u] = change.back().par;
            change.pop_back();
        }
    }
};

void chemthan() {
    int n, m, k; cin >> n >> m >> k;
    vi c(n);
    vector<vi> g(k);
    FOR(i, 0, n) cin >> c[i], c[i]--, g[c[i]].pb(i);
    vector<vi> adj(n);
    DSU dsu;
    dsu.init(n + n);
    vi flag(k);
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        if (c[u] == c[v]) {
            if (dsu.getRoot(u * 2) == dsu.getRoot(v * 2)) {
                flag[c[u]] = 1;
            }
            dsu.join(u * 2, v * 2 + 1, 0);
            dsu.join(u * 2 + 1, v * 2, 0);
        }
        else {
            adj[u].pb(v), adj[v].pb(u);
        }
    }
    int sum = accumulate(all(flag), 0);
    long long res = 0;
    FOR(i, 0, k) if (!flag[i]) {
        map<int, vii> hs;
        for (int u : g[i]) {
            for (int v : adj[u]) {
                hs[c[v]].pb({u, v});
            }
        }
        int num = sum;
        for (auto [t, vals] : hs) if (!flag[t]) {
            int found = 0;
            for (auto [u, v] : vals) {
                if (dsu.getRoot(u * 2) == dsu.getRoot(v * 2)) {
                    found = 1;
                }
                dsu.join(u * 2, v * 2 + 1, 1);
                dsu.join(u * 2 + 1, v * 2, 1);
            }
            num += found;
            dsu.rollback(0);
        }
        res += k - 1 - num;
    }
    assert(res % 2 == 0);
    cout << res / 2 << "\n";
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