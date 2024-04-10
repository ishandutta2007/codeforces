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

#define pos(v) ((v) << 1)
#define neg(v) (pos(v) ^ 1)
struct Twosat {
    static const int MAXV = 2e6 + 5;
    int n;
    vector<int> forward[MAXV], backward[MAXV];
    bool used[MAXV];
    int cnt, order[MAXV], comp[MAXV];
    void init(int _n) {
        n = _n;
        for (int i = 0; i < n; i++) {
            forward[i].clear();
            backward[i].clear();
        }
    }
    void add(int u, int v) {
        forward[u].push_back(v);
        backward[v].push_back(u);
    }
    void dfs1(int u) {
        used[u] = true;
        for (int i = 0; i < (int) forward[u].size(); i++) {
            int v = forward[u][i];
            if (!used[v]) dfs1(v);
        }
        order[cnt++] = u;
    }
    void dfs2(int u, int c) {
        comp[u] = c;
        for (int i = 0; i < (int) backward[u].size(); i++) {
            int v = backward[u][i];
            if (comp[v] == -1) dfs2(v, c);
        }
    }
    int solve(vector<int>& res) {
        cnt = 0;
        FOR(i, 0, n) used[i] = 0;
        for (int u = 0; u < n; u++) {
            if (!used[u]) dfs1(u);
        }
        FOR(i, 0, n) comp[i] = -1;
        int c = 0;
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            if (comp[u] == -1) dfs2(u, c++);
        }
        for (int u = 0; u < n; u += 2)
            if (comp[u] == comp[u ^ 1]) return 0;
        res.clear();
        for (int u = 0; u < n; u += 2) {
            int choose = (comp[u] > comp[u ^ 1]) ? u : u ^ 1;
            if (!(choose & 1)) res.push_back(choose >> 1);
        }
        return 1;
    }
} twosat;

void chemthan() {
    int test; cin >> test;
    while (test--) {
        int n, m; cin >> n >> m;
        twosat.init(2 * n);
        vi dj(n);
        FOR(i, 0, n) dj[i] = i;
        function<int(int)> find = [&] (int u) {
            return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
        };
        FOR(i, 0, m) {
            int u, v; string s; cin >> u >> v >> s; u--, v--;
            dj[find(u)] = find(v);
            if (s[0] == 'i') {
                twosat.add(pos(u), neg(v));
                twosat.add(neg(u), pos(v));

                twosat.add(neg(v), pos(u));
                twosat.add(pos(v), neg(u));
            }
            else {
                twosat.add(pos(u), pos(v));
                twosat.add(neg(u), neg(v));

                twosat.add(pos(v), pos(u));
                twosat.add(neg(v), neg(u));
            }
        }
        vi res;
        if (!twosat.solve(res)) {
            cout << -1 << "\n";
        }
        else {
            vi used(n);
            for (int x : res) used[x] = 1;
            map<int, vi> hs;
            FOR(i, 0, n) {
                hs[find(i)].pb(i);
            }
            int mx = 0;
            for (auto [x, v] : hs) {
                int sum = 0;
                for (int t : v) {
                    sum += used[t];
                }
                mx += max(sum, sz(v) - sum);
            }
            cout << mx << "\n";
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