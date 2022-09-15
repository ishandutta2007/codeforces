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

#define double long double
typedef long long num_t;
const num_t oo = (num_t) 1e18;
struct LineHull {
    struct Line {
        num_t a, b;
        Line(num_t a, num_t b) : a(a), b(b) {}
    };
    double intersect(Line ln1, Line ln2) {
        return (double) (ln2.b - ln1.b) / (ln1.a - ln2.a);
    }
    int bad(Line ln1, Line ln2, Line ln3) {
        return (__int128) (ln1.a - ln2.a) * (ln2.b - ln3.b) >= (__int128) (ln2.a - ln3.a) * (ln1.b - ln2.b);
        //return intersect(ln1, ln2) >= intersect(ln2, ln3);
        //return (__int128) (ln1.a - ln2.a) * (ln2.b - ln3.b) <= (__int128) (ln2.a - ln3.a) * (ln1.b - ln2.b); //for adding in ascending order
        //return intersect(ln1, ln2) <= intersect(ln2, ln3); //for adding in ascending order
    }
    vector<Line> hull;
    vector<double> pos;
    LineHull() {
        pos.push_back(-oo);
        pos.push_back(+oo);
    }
    void add(num_t a, num_t b) {
        Line ln(a, b);
        pos.pop_back();
        while (hull.size() >= 2 && bad(hull[hull.size() - 2], hull[hull.size() - 1], ln)) {
            hull.pop_back();
            pos.pop_back();
        }
        hull.push_back(ln);
        //if (hull.size() >= 2) pos.push_back(intersect(hull[hull.size() - 2], hull[hull.size() - 1]));
        if (hull.size() >= 2) pos.push_back(-intersect(hull[hull.size() - 2], hull[hull.size() - 1])); //for adding in ascending order
        pos.push_back(+oo);
    }
    num_t query(num_t x) {
        if (!hull.size()) return +oo;
        int k = lower_bound(pos.begin(), pos.end(), x) - pos.begin() - 1;
        //int k = lower_bound(pos.begin(), pos.end(), -x) - pos.begin() - 1; //for adding in ascending order
        return hull[k].a * x + hull[k].b;
    }
};
#undef double

void chemthan() {
    int n, m, q; cin >> n >> m >> q;
    vector<vii> adj(n);
    FOR(i, 0, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        w = INF - w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    int magic = n * 2 + 5;
    vector<vector<long long>> dp(n, vector<long long>(magic, LINF));
    priority_queue<tuple<long long, int, int>> heap;
    dp[0][0] = 0;
    heap.push({-dp[0][0], 0, 0});
    while (sz(heap)) {
        long long t; int u, d; tie(t, u, d) = heap.top();
        heap.pop();
        t = -t;
        if (dp[u][d] != t) continue;
        if (d + 1 < magic) {
            for (auto e : adj[u]) {
                int v = e.fi;
                int w = e.se;
                if (chkmin(dp[v][d + 1], dp[u][d] + w)) {
                    heap.push({-dp[v][d + 1], v, d + 1});
                }
            }
        }
    }
    FOR(u, 0, n) {
        for (auto& e : adj[u]) {
            e.se = INF - e.se;
        }
    }
    int res = 0;
    FOR(k, 0, magic) {
        long long mx = 0;
        FOR(u, 0, n) {
            dp[u][k] = (long long) k * INF - dp[u][k];
            chkmax(mx, dp[u][k]);
        }
        if (k <= q) {
            addmod(res, mx % MOD);
        }
    }
    if (magic <= q) {
        vector<pair<long long, int>> vals;
        FOR(u, 0, n) {
            int mx = 0;
            for (auto e : adj[u]) {
                chkmax(mx, e.se);
            }
            vals.pb({dp[u][magic - 1], mx});
        }
        sort(all(vals)), reverse(all(vals));
        vector<pair<long long, int>> nvals;
        int mx = 0;
        for (auto e : vals) {
            if (mx < e.se) {
                nvals.pb(e);
                mx = e.se;
            }
        }
        vals = nvals;
        LineHull lh;
        for (auto e : vals) {
            lh.add(-e.se, -e.fi);
        }
        nvals.clear();
        for (auto e : lh.hull) {
            nvals.pb({-e.b, -e.a});
        }
        vals = nvals;
        auto calc = [&] (int d, int x, int l, int r) {
            int res = mult(d, r - l + 1);
            addmod(res, (long long) (r - l + 1) * (l + r) / 2 % MOD * x % MOD);
            return res;
        };
        long long pv = magic;
        FOR(i, 0, sz(vals) - 1) {
            long long d = (vals[i].fi - vals[i + 1].fi) / (vals[i + 1].se - vals[i].se);
            if (pv <= magic + d - 1) {
                long long npv = min(magic + d - 1, (long long) q);
                int l = pv - magic + 1;
                int r = npv - magic + 1;
                addmod(res, calc(vals[i].fi % MOD, vals[i].se, l, r));
                pv = npv + 1;
            }
        }
        if (pv <= q) {
            int l = pv - magic + 1;
            int r = q - magic + 1;
            addmod(res, calc(vals.back().fi % MOD, vals.back().se, l, r));
        }
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