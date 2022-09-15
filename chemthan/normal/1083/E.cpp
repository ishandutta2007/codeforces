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

vi dc;
template<class num_t, const num_t oo>
struct MagicTree {
    struct func_t {
        num_t a, b;
        func_t(num_t a = 0, num_t b = oo) : a(a), b(b) {}
        num_t query(num_t x) {return a * x + b;}
    };

    static const int maxn = 1e6 + 5;
    func_t st[maxn << 2];

    void init(int n = maxn) {
        fill_n(st, n << 2, func_t());
    }
    void upd(int p, int l, int r, int L, int R, func_t f) {
        int M = L + R >> 1;
        if (l > R || r < L) return;
        if (l <= L && r >= R) {
            int fl = f.query(dc[L]) >= st[p].query(dc[L]);
            int fr = f.query(dc[R]) >= st[p].query(dc[R]);
            if (fl && fr) return;
            if (!fl && !fr) {
                st[p] = f;
                return;
            }
            int fm1 = f.query(dc[M]) >= st[p].query(dc[M]);
            if (fl && fm1) {
                upd(p << 1 | 1, l, r, M + 1, R, f);
                return;
            }
            if (!fl && !fm1) {
                upd(p << 1 | 1, l, r, M + 1, R, st[p]);
                st[p] = f;
                return;
            }
            assert(M + 1 < sz(dc));
            int fm2 = f.query(dc[M + 1]) >= st[p].query(dc[M + 1]);
            if (fm2 && fr) {
                upd(p << 1, l, r, L, M, f);
                return;
            }
            if (!fm2 && !fr) {
                upd(p << 1, l, r, L, M, st[p]);
                st[p] = f;
                return;
            }
            assert(0);
        }
        else if (L < R) {
            upd(p << 1, l, r, L, L + R >> 1, f);
            upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, f);
        }
    }
    void upd(int p, int l, int r, int L, int R, num_t a, num_t b) {
        upd(p, l, r, L, R, func_t(a, b));
    }
    num_t query(int p, int i, int L, int R) {
        if (i < L || i > R) return oo;
        num_t res = st[p].query(dc[i]);
        if (L < R) {
            res = min(res, query(p << 1, i, L, L + R >> 1));
            res = min(res, query(p << 1 | 1, i, (L + R >> 1) + 1, R));
        }
        return res;
    }
};
MagicTree<long long, (long long) 4e18> mgtree;

const int maxn = 1e6 + 5;
int n;
int x[maxn];
int y[maxn];
long long a[maxn];

void chemthan() {
    cin >> n;
    vi vals;
    dc.pb(0);
    FOR(i, 0, n) {
        cin >> x[i] >> y[i] >> a[i];
        vals.pb(i);
        dc.pb(y[i]);
    }
    sort(all(dc)), uni(dc);
    sort(all(vals), [&] (int u, int v) {
            if (x[u] != x[v]) {
                return x[u] < x[v];
            }
            return y[u] > y[v];
            }
        );
    long long res = 0;
    mgtree.init();
    mgtree.upd(1, 0, sz(dc) - 1, 0, sz(dc) - 1, 0, 0);
    for (int i : vals) {
        int v = lower_bound(all(dc), y[i]) - dc.begin();
        long long mx = -mgtree.query(1, v, 0, sz(dc) - 1) + (long long) x[i] * y[i] - a[i];
        mgtree.upd(1, 0, sz(dc) - 1, 0, sz(dc) - 1, x[i], -mx);
        chkmax(res, mx);
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