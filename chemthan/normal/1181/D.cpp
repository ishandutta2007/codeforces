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

template<class num_t>
struct OrderedTree {
    int n;
    vector<num_t> a;
    num_t tot;
    vector<num_t> x;
    vector<num_t> y;

    void init(int _n) {
        n = _n;
        a.resize(n);
        for (int i = 0; i < n; i++) a[i] = 0;
        tot = 0;
        x.resize(n + 1);
        y.resize(n + 1);
        for (int i = 0; i <= n; i++) x[i] = y[i] = 0;
    }

    void upd(int p, num_t val, num_t cnt) {
        assert(0 <= p && p < n);
        a[p] = val, tot += cnt;
        for (p++; p <= n; p += p & -p) {
            x[p] += cnt;
            y[p] += cnt * val;
        }
    }

    num_t find_by_order(num_t k) {
        assert(0 <= k && k <= tot);
        if (!k) return -1;
        int p = 0;
        for (int i = __lg(n); i >= 0; i--) {
            if (p + (1 << i) <= n && x[p + (1 << i)] < k) {
                k -= x[p + (1 << i)];
                p += 1 << i;
            }
        }
        return a[p];
    }
    num_t find_sum_by_order(num_t k) {
        assert(0 <= k && k <= tot);
        if (!k) return 0;
        num_t res = 0;
        int p = 0;
        for (int i = __lg(n); i >= 0; i--) {
            if (p + (1 << i) <= n && x[p + (1 << i)] < k) {
                k -= x[p + (1 << i)];
                res += y[p + (1 << i)];
                p += 1 << i;
            }
        }
        return res + k * a[p];
    }
};
OrderedTree<long long> odtree;

void chemthan() {
    int n, m, q; cin >> m >> n >> q;
    vii f(n);
    FOR(i, 0, n) f[i].se = i;
    FOR(i, 0, m) {
        int x; cin >> x; x--;
        f[x].fi++;
    }
    sort(all(f));
    vector<pair<long long, int>> events;
    vector<long long> sum(n);
    FOR(i, 0, n) {
        if (i) sum[i] = sum[i - 1];
        sum[i] += f[i].fi;
    }
    FOR(i, 0, n) {
        if (i == n - 1 || f[i].fi < f[i + 1].fi) {
            long long timer = i + 1 < n ? (long long) f[i + 1].fi * (i + 1) - sum[i] + 1 : LINF;
            events.pb(mp(timer, i));
        }
    }
    vector<pair<long long, int>> qs;
    FOR(i, 0, q) {
        long long x; cin >> x;
        qs.pb(mp(x, i));
    }
    odtree.init(1e6);
    sort(all(qs));
    int st = 0;
    vi res(q);
    FOR(i, 0, q) {
        long long x = qs[i].fi; 
        int k = upper_bound(all(events), mp(x - m, INF)) - events.begin();
        int ix = events[k].se;
        while (st <= ix) {
            odtree.upd(f[st].se, f[st].se, 1);
            st++;
        }
        int u = (x - m + sum[ix] - 1) % (ix + 1);
        res[qs[i].se] = odtree.find_by_order(u + 1);
    }
    FOR(i, 0, q) {
        cout << res[i] + 1 << "\n";
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
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}