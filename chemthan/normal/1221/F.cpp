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

template<class num_t> struct SegmentTree {
    int n;
    vector<pair<num_t, int>> st;
    vector<num_t> lz;
    void init(int n_) {
        n = n_;
        st.resize(n << 2);
        lz.resize(n << 2);
        init(1, 0, n - 1);
    }
    void init(int p, int L, int R) {
        if (L == R) {
            st[p] = mp(0LL, L);
            return;
        }
        init(p << 1, L, L + R >> 1);
        init(p << 1 | 1, (L + R >> 1) + 1, R);
        st[p] = max(st[p << 1], st[p << 1 | 1]);
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
        st[p] = max(st[p << 1], st[p << 1 | 1]);
    }
    pair<num_t, int> query(int p, int l, int r, int L, int R) {
        pushdown(p, L, R);
        if (r < L || R < l) return mp(-1e18, 0);
        if (l <= L && R <= r) return st[p];
        return max(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
    void upd(int l, int r, num_t val) {
        upd(1, l, r, 0, n - 1, val);
    }
    pair<num_t, int> query(int l, int r) {
        return query(1, l, r, 0, n - 1);
    }
};

SegmentTree<long long> seg;

void chemthan() {
    int n; cin >> n;
    vi x(n);
    vi y(n);
    vi c(n);
    vi dc;
    FOR(i, 0, n) {
        cin >> x[i] >> y[i] >> c[i];
        dc.pb(x[i]);
        dc.pb(y[i]);
    }
    sort(all(dc)), uni(dc);
    seg.init(sz(dc));
    FOR(i, 0, sz(dc)) {
        seg.upd(i, i, -dc[i]);
    }
    vi xx(n);
    vi yy(n);
    FOR(i, 0, n) {
        int u = lower_bound(all(dc), x[i]) - dc.begin();
        int v = lower_bound(all(dc), y[i]) - dc.begin();
        int w = max(u, v);
        seg.upd(w, sz(dc) - 1, c[i]);
        xx[i] = u, yy[i] = v;
    }
    tuple<long long, int, int> res;
    get<0>(res) = 0;
    get<1>(res) = get<2>(res) = INF;
    auto rem = [&] (int u) {
        int w = max(xx[u], yy[u]);
        seg.upd(w, sz(dc) - 1, -c[u]);
    };
    vi f(n);
    vii vx;
    vii vy;
    FOR(i, 0, n) vx.pb({x[i], i});
    FOR(i, 0, n) vy.pb({y[i], i});
    sort(all(vx)), sort(all(vy));
    int px = 0, py = 0;
    FOR(i, 0, sz(dc)) {
        while (px < n && vx[px].fi < dc[i]) {
            int id = vx[px].se;
            if (!f[id]) {
                f[id] = 1;
                rem(id);
            }
            px++;
        }
        while (py < n && vy[py].fi < dc[i]) {
            int id = vy[py].se;
            if (!f[id]) {
                f[id] = 1;
                rem(id);
            }
            py++;
        }
        auto mx = seg.query(i, sz(dc) - 1);
        mx.fi += dc[i];
        chkmax(res, make_tuple(mx.fi, dc[i], dc[mx.se]));
    }
    cout << get<0>(res) << "\n";
    cout << get<1>(res) << " " << get<1>(res) << " " << get<2>(res) << " " << get<2>(res) << "\n";
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