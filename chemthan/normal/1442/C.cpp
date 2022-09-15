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

struct data_t {
    int d, k;
    data_t(int d = 0, int k = 0) : d(d), k(k) {}
    int toint() {
        int res = d;
        addmod(res, fpow(2, k));
        submod(res, 1);
        return res;
    }
};

int operator < (data_t a, data_t b) {
    if (a.k != b.k && 50 < max(a.k, b.k)) return a.k > b.k;
    if (a.k == b.k) return a.d > b.d;
    return a.d + (1LL << a.k) > b.d + (1LL << b.k);
}

int operator != (data_t a, data_t b) {
    return a < b || b < a;
}

void chemthan() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n);
    vector<vi> radj(n);
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);
        radj[v].pb(u);
    }
    vector<vector<vector<data_t>>> d(n, vector<vector<data_t>>(2, vector<data_t>(30 + 1, data_t(0, INF))));
    priority_queue<tuple<data_t, int, int, int>> heap;
    d[0][0][0] = data_t(), heap.push({d[0][0][0], 0, 0, 0});
    while (sz(heap)) {
        auto [t, u, f, dep] = heap.top();
        heap.pop();
        if (d[u][f][dep] != t) continue;
        for (int v : adj[u]) {
            if (!f) {
                int ndep = dep;
                auto nt = t;
                nt.d++;
                if (chkmax(d[v][f][ndep], nt)) {
                    heap.push({d[v][f][ndep], v, f, ndep});
                }
            }
            else {
                int ndep = min(dep + 1, 30);
                auto nt = t;
                nt.d++;
                nt.k++;
                if (chkmax(d[v][!f][ndep], nt)) {
                    heap.push({d[v][!f][ndep], v, !f, ndep});
                }
            }
        }
        for (int v : radj[u]) {
            if (f) {
                int ndep = dep;
                auto nt = t;
                nt.d++;
                if (chkmax(d[v][f][ndep], nt)) {
                    heap.push({d[v][f][ndep], v, f, ndep});
                }
            }
            else {
                int ndep = min(dep + 1, 30);
                auto nt = t;
                nt.d++;
                nt.k++;
                if (chkmax(d[v][!f][ndep], nt)) {
                    heap.push({d[v][!f][ndep], v, !f, ndep});
                }
            }
        }
    }
    data_t res(INF, INF);
    FOR(i, 0, 2) FOR(j, 0, 30 + 1) {
        chkmax(res, d[n - 1][i][j]);
    }
    cout << res.toint() << "\n";
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