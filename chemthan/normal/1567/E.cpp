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

template<class num_t> struct SegmentTree {
    struct node_t {
        int num;
        int first;
        int last;
        num_t sum;
        int prf;
        int suf;
        node_t() {
            sum = 0;
        }
    };
    int n;
    vector<node_t> st;
    node_t join(node_t a, node_t b) {
        if (!a.sum) return b;
        if (!b.sum) return a;
        node_t c;
        c.first = a.first;
        c.last = b.last;
        c.num = a.num + b.num;
        c.sum = a.sum + b.sum;
        if (a.last <= b.first) {
            c.sum += (long long) a.suf * b.prf;
        }
        c.prf = a.prf;
        if (a.prf == a.num && a.last <= b.first) {
            c.prf += b.prf;
        }
        c.suf = b.suf;
        if (b.suf == b.num && a.last <= b.first) {
            c.suf += a.suf;
        }
        return c;
    }
    void init(int n_) {
        n = n_;
        st.resize(n << 2);
        init(1, 0, n - 1);
    }
    void init(int p, int L, int R) {
        st[p].num = R - L + 1;
        if (L == R) return;
        init(p << 1, L, L + R >> 1);
        init(p << 1 | 1, (L + R >> 1) + 1, R);
    }
    void upd(int p, int i, int L, int R, num_t val) {
        if (i < L || R < i) return;
        if (L == R) {
            st[p].sum = 1;
            st[p].first = val;
            st[p].last = val;
            st[p].prf = 1;
            st[p].suf = 1;
            return;
        }
        upd(p << 1, i, L, L + R >> 1, val);
        upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
        st[p] = join(st[p << 1], st[p << 1 | 1]);
    }
    node_t query(int p, int l, int r, int L, int R) {
        if (r < L || R < l) return node_t();
        if (l <= L && R <= r) return st[p];
        return join(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
    void upd(int i, num_t val) {
        upd(1, i, 0, n - 1, val);
    }
    node_t query(int l, int r) {
        return query(1, l, r, 0, n - 1);
    }
};

void chemthan() {
    int n, q; cin >> n >> q;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    SegmentTree<long long> seg;
    seg.init(n);
    FOR(i, 0, n) {
        seg.upd(i, a[i]);
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y; x--;
            seg.upd(x, a[x] = y);
        }
        else {
            int l, r; cin >> l >> r; l--, r--;
            auto res = seg.query(l, r);
            cout << res.sum << "\n";
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