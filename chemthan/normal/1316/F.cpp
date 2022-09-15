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

vi p2;
vi ip2;
template<class num_t> struct SegmentTree {
    int n;
    vector<num_t> st;
    vector<num_t> c;
    vector<num_t> x;
    vector<num_t> y;
    SegmentTree(int n) : n(n) {
        st.resize(n << 2);
        c.resize(n << 2);
        x.resize(n << 2);
        y.resize(n << 2);
    }
    void upd(int p, int i, int L, int R, int val, int s) {
        if (i < L || R < i) return;
        if (L == R) {
            if (s == 1) {
                x[p] = y[p] = val;
                c[p] = 1;
            }
            else {
                x[p] = y[p] = c[p] = 0;
            }
            return;
        }
        upd(p << 1, i, L, L + R >> 1, val, s);
        upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val, s);
        st[p] = (st[p << 1] + st[p << 1 | 1]) % MOD;
        c[p] = (c[p << 1] + c[p << 1 | 1]);
        x[p] = x[p << 1];
        addmod(x[p], mult(p2[c[p << 1]], x[p << 1 | 1]));
        y[p] = y[p << 1];
        addmod(y[p], mult(ip2[c[p << 1]], y[p << 1 | 1]));
        addmod(st[p], mult(x[p << 1], mult(ip2[c[p << 1]], y[p << 1 | 1])));
    }
};

void chemthan() {
    p2.resize(1234567);
    ip2.resize(1234567);
    FOR(i, 0, sz(p2)) p2[i] = fpow(2, i), ip2[i] = inv(p2[i]);
    int n; cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    int q; cin >> q;
    vii que;
    vii dc;
    FOR(i, 0, n) dc.pb(mp(a[i], i));
    FOR(i, 0, q) {
        int u, v; cin >> u >> v; u--;
        que.pb({u, v});
        dc.pb({v, u});
    }
    sort(all(dc)), uni(dc);
    SegmentTree<int> seg(sz(dc));
    FOR(i, 0, n) {
        int x = lower_bound(all(dc), mp(a[i], i)) - dc.begin();
        seg.upd(1, x, 0, sz(dc) - 1, a[i], 1);
    }
    cout << mult(inv(2), seg.st[1]) << "\n";
    FOR(i, 0, q) {
        int u, v; tie(u, v) = que[i];
        int x = lower_bound(all(dc), mp(a[u], u)) - dc.begin();
        seg.upd(1, x, 0, sz(dc) - 1, a[u], -1);
        x = lower_bound(all(dc), mp(a[u] = v, u)) - dc.begin();
        seg.upd(1, x, 0, sz(dc) - 1, a[u], 1);
        cout << mult(inv(2), seg.st[1]) << "\n";
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