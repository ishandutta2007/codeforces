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
    vector<pair<num_t, int>> st;
    vector<num_t> lz;
    void init(int n_) {
        n = n_;
        st.resize(n << 2);
        lz.resize(n << 2);
    }
    void build(int p, int L, int R, vi& a) {
        if (L == R) {
            st[p] = mp(a[L], L);
            return;
        }
        build(p << 1, L, L + R >> 1, a);
        build(p << 1 | 1, (L + R >> 1) + 1, R, a);
        st[p] = min(st[p << 1], st[p << 1 | 1]);
    }
    void pushdown(int p, int L, int R) {
        if (lz[p]) {
            st[p].fi += lz[p];
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
    void upd(int p, int i, int L, int R, num_t val) {
        pushdown(p, L, R);
        if (i < L || R < i) return;
        if (L == R) {
            st[p].fi = val;
            return;
        }
        upd(p << 1, i, L, L + R >> 1, val);
        upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
        st[p] = min(st[p << 1], st[p << 1 | 1]);
    }
    pair<num_t, int> query(int p, int l, int r, int L, int R) {
        pushdown(p, L, R);
        if (r < L || R < l) return mp(INF, INF);
        if (l <= L && R <= r) return st[p];
        return min(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
    void upd(int l, int r, num_t val) {
        upd(1, l, r, 0, n - 1, val);
    }
    void upd(int i, num_t val) {
        upd(1, i, 0, n - 1, val);
    }
    pair<num_t, int> query(int l, int r) {
        return query(1, l, r, 0, n - 1);
    }
};
SegmentTree<int> seg;

void chemthan() {
    int n, q; cin >> n >> q;
    vi a(n);
    FOR(i, 0, n) cin >> a[i], a[i]--;
    vector<vector<tuple<int, int>>> qs(n + 1);
    FOR(i, 0, q) {
        int x, y; cin >> x >> y;
        qs[x].pb({y, i});
    }
    vi b(n);
    FOR(i, 0, n) {
        b[i] = i - a[i];
    }
    vi fen(n + 1);
    auto upd = [&] (int p, int v) {
        p++;
        for (; p < sz(fen); p += p & -p) {
            fen[p] += v;
        }
    };
    auto query = [&] (int p) {
        p++;
        int res = 0;
        for (; 0 < p; p -= p & -p) {
            res += fen[p];
        }
        return res;
    };
    seg.init(n);
    seg.build(1, 0, n - 1, b);
    vi res(q);
    FORd(i, n + 1, 0) {
        while (1) {
            auto mn = seg.query(i, n - 1);
            if (0 < mn.fi) {
                break;
            }
            int u = mn.se;
            if (a[u] <= u) {
                upd(u, 1);
                seg.upd(u + 1, n - 1, -1);
            }
            seg.upd(u, INF);
        }
        for (auto e : qs[i]) {
            int y, ix; tie(y, ix) = e;
            res[ix] = query(n - y - 1);
        }
    }
    FOR(i, 0, q) cout << res[i] << "\n";
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