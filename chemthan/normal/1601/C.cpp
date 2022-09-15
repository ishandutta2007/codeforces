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
    int n;
    vector<num_t> st;
    vector<num_t> lz;
    void init(int n_) {
        n = n_;
        st.clear();
        lz.clear();
        st.resize(n << 2);
        lz.resize(n << 2);
    }
    void pushdown(int p, int L, int R) {
        if (lz[p]) {
            st[p] += lz[p];
            if (L < R) {
                lz[p << 1] += lz[p];
                lz[p << 1 | 1] += lz[p];
            }
            lz[p] = 0;
        }
    }
    void upd(int p, int l, int r, int L, int R, num_t val) {
        pushdown(p, L, R);
        if (r < L || R < l) return;
        if (l <= L && R <= r) {
            lz[p] = val;
            pushdown(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        st[p] = min(st[p << 1], st[p << 1 | 1]);
    }
    num_t query(int p, int l, int r, int L, int R) {
        pushdown(p, L, R);
        if (r < L || R < l) return INF;
        if (l <= L && R <= r) return st[p];
        return min(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
    void upd(int l, int r, num_t val) {
        upd(1, l, r, 0, n - 1, val);
    }
    num_t query(int l, int r) {
        return query(1, l, r, 0, n - 1);
    }
};

void chemthan() {
    int test; cin >> test;
    while (test--) {
        SegmentTree<int> seg;
        int n, m; cin >> n >> m;
        vi a(n);
        vi b(m);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, m) cin >> b[i];
        sort(all(b));
        vi dc = a;
        dc.insert(dc.end(), all(b));
        sort(all(dc)), uni(dc);
        FOR(i, 0, n) a[i] = lower_bound(all(dc), a[i]) - dc.begin();
        FOR(i, 0, m) b[i] = lower_bound(all(dc), b[i]) - dc.begin();
        seg.init(n + 1);
        FOR(i, 0, n + 1) {
            seg.upd(i, i, i);
        }
        vii v1;
        FOR(i, 0, n) {
            v1.pb({a[i], i});
        }
        sort(all(v1));
        int ptr = 0;
        int ptr2 = 0;
        long long res = 0;
        FOR(i, 0, m) {
            while (ptr < sz(v1) && v1[ptr].fi <= b[i]) {
                int ix = v1[ptr].se;
                seg.upd(ix + 1, n, -1);
                ptr++;
            }
            while (ptr2 < sz(v1) && v1[ptr2].fi < b[i]) {
                int ix = v1[ptr2].se;
                seg.upd(0, ix, 1);
                ptr2++;
            }
            res += seg.query(0, n);
        }
        vi fen(sz(dc) + 1);
        auto upd = [&] (int p, int v) {
            p++;
            for (; 0 < p; p -= p & -p) {
                fen[p] += v;
            }
        };
        auto query = [&] (int p) {
            p++;
            int res = 0;
            for (; p < sz(fen); p += p & -p) {
                res += fen[p];
            }
            return res;
        };
        FOR(i, 0, n) {
            res += query(a[i] + 1);
            upd(a[i], 1);
        }
        cout << res << "\n";
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