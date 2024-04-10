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

void chemthan() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    vi dj(n), size(n);
    FOR(i, 0, n) dj[i] = i, size[i] = 1;
    function<int(int)> find = [&] (int u) {
        return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
    };
    vector<vi> d(n, vi(n, INF));
    vector<vi> e(n, vi(n, INF));
    FOR(i, 0, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        if (w == a) {
            int p = find(u);
            int q = find(v);
            if (p ^ q) {
                dj[p] = q;
                size[q] += size[p];
            }
            chkmin(d[u][v], a);
            chkmin(d[v][u], a);
        }
        else {
            chkmin(e[u][v], b);
            chkmin(e[v][u], b);
        }
    }
    vi vals, vals2;
    FOR(i, 0, n) if (dj[i] == i) {
        if (3 < size[i]) {
            vals.pb(i);
        }
        else {
            vals2.pb(i);
        }
    }
    vi f(n, -1);
    auto comp = [&] (int u) {
        int& res = f[u];
        if (~res) return res;
        res = lower_bound(all(vals), find(u)) - vals.begin();
        if (res < sz(vals) && vals[res] == find(u)) return res;
        return res = sz(vals) + (int) (lower_bound(all(vals2), find(u)) - vals2.begin());
    };
    vector<vi> dp(1 << sz(vals), vi(n, INF));
    priority_queue<tuple<int, int, int>> heap;
    int c0 = comp(0);
    int msk0 = c0 < sz(vals) ? (1 << c0) : 0;
    dp[msk0][0] = 0, heap.push(make_tuple(-dp[msk0][0], msk0, 0));
    vi res(n, INF);
    while (sz(heap)) {
        int t, msk, lst; tie(t, msk, lst) = heap.top();
        heap.pop();
        t = -t;
        if (dp[msk][lst] ^ t) continue;
        chkmin(res[lst], t);
        int clst = comp(lst);
        FOR(u, 0, n) {
            int cu = comp(u);
            if (sz(vals) <= cu ||!bit(msk, cu) || cu == clst) {
                int nmsk = msk;
                if (cu < sz(vals)) {
                    nmsk |= 1 << cu;
                }
                int cost = 0;
                if (cu == clst) {
                    cost = d[lst][u];
                }
                else {
                    cost = e[lst][u];
                }
                if (chkmin(dp[nmsk][u], dp[msk][lst] + cost)) {
                    heap.push(make_tuple(-dp[nmsk][u], nmsk, u));
                }
            }
        }
    }
    FOR(i, 0, n) cout << res[i] << " \n"[i == n - 1];
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