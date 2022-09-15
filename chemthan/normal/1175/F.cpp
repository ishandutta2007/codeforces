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

template<class num_t, class cmp = less<num_t> >
struct RMQ {
    int n;
    vector<num_t> a;
    vector<vector<num_t> > f;

    inline num_t best(const num_t& a, const num_t& b) {
        if (cmp()(a, b)) return a;
        return b;
    }
    void init(int _n) {
        n = _n;
        int p = 1; while ((1 << p) < n) p++;
        a.resize(n), f.resize(p + 1);
        a.shrink_to_fit(), f.shrink_to_fit();
        for (int i = 0; i < (int) f.size(); i++) {
            f[i].resize(n);
        }
    }
    num_t& operator [] (int u) {
        assert(u < (int) a.size());
        return a[u];
    }
    void build() {
        for (int i = 0; i < n; i++) f[0][i] = a[i];
        for (int l = 0, k; (k = 1 << l) < n; l++) {
            for (int i = 0; i + k < n; i++) {
                f[l + 1][i] = best(f[l][i], f[l][i + k]);
            }
        }
    }
    num_t query(int a, int b) {
        assert(a <= b);
        int l = a == b ? 0 : __lg(b - a);
        return best(f[l][a], f[l][b - (1 << l) + 1]);
    }
};
RMQ<int, greater<int>> rmq;

void chemthan() {
    int n; cin >> n;
    vi a(n);
    rmq.init(n);
    FOR(i, 0, n) cin >> a[i], a[i]--, rmq[i] = a[i];
    rmq.build();
    vi f(n, -1);
    FOR(i, 0, n) {
        int lo = -1, hi = i - 1;
        while (lo < hi) {
            int mi = lo + hi + 1 >> 1;
            if (a[i] < rmq.query(mi, i - 1)) {
                lo = mi;
            }
            else {
                hi = mi - 1;
            }
        }
        f[i] = lo + hi >> 1;
    }
    rmq.build();
    vi mn(n << 2), cn(n << 2), lz(n << 2);
    auto push = [&] (int p, int L, int R) {
        if (lz[p]) {
            mn[p] += lz[p];
            if (L < R) {
                FOR(i, p << 1, p + 1 << 1) {
                    lz[i] += lz[p];
                }
            }
            lz[p] = 0;
        }
    };
    function<void(int, int, int, int, int, int)> upd = [&] (int p, int l, int r, int L, int R, int val) {
        push(p, L, R);
        if (R < l || r < L) return;
        if (l <= L && R <= r) {
            lz[p] = val;
            push(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        mn[p] = mn[p << 1], cn[p] = cn[p << 1];
        if (chkmin(mn[p], mn[p << 1 | 1])) {
            cn[p] = cn[p << 1 | 1];
        }
        else if (mn[p] == mn[p << 1 | 1]) {
            cn[p] += cn[p << 1 | 1];
        }
    };
    function<void(int, int, int)> build = [&] (int p, int L, int R) {
        if (L == R) {
            cn[p] = 1;
            return;
        }
        build(p << 1, L, L + R >> 1);
        build(p << 1 | 1, (L + R >> 1) + 1, R);
        cn[p] = cn[p << 1] + cn[p << 1 | 1];
    };
    function<pi(int, int, int, int, int)> query = [&] (int p, int l, int r, int L, int R) {
        push(p, L, R);
        if (R < l || r < L) return mp(INF, 0);
        if (l <= L && R <= r) return mp(mn[p], cn[p]);
        pi x = query(p << 1, l, r, L, L + R >> 1);
        pi y = query(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
        if (chkmin(x.fi, y.fi)) {
            x.se = y.se;
        }
        else if (x.fi == y.fi) {
            x.se += y.se;
        }
        return x;
    };
    vi fen(n + 1);
    auto updfen = [&] (int p, int val) {
        p++;
        for (; p < sz(fen); p += p & -p) {
            fen[p] += val;
        }
    };
    auto queryfen = [&] (int p) {
        p++;
        int res = 0;
        for (; 0 < p; p -= p & -p) {
            res += fen[p];
        }
        return res;
    };
    build(1, 0, n - 1);
    long long res = 0;
    vi cnt(n);
    int ptr = 0;
    vector<vi> g(n);
    FOR(i, 0, n) {
        if (i) {
            cnt[a[i - 1]]--;
            updfen(a[i - 1], -1);
            for (int j : g[i - 1]) {
                upd(1, a[j], a[f[j]] - 1, 0, n - 1, -1);
            }
        }
        while (ptr < n && !cnt[a[ptr]]) {
            cnt[a[ptr]]++;
            updfen(a[ptr], 1);
            if (i <= f[ptr]) {
                upd(1, a[ptr], a[f[ptr]] - 1, 0, n - 1, 1);
                g[f[ptr]].pb(ptr);
            }
            ptr++;
        }
        int lo = -1, hi = n - 1;
        while (lo < hi) {
            int mi = lo + hi + 1 >> 1;
            if (queryfen(mi) == mi + 1) {
                lo = mi;
            }
            else {
                hi = mi - 1;
            }
        }
        int mi = lo + hi >> 1;
        if (0 <= mi) {
            auto e = query(1, 0, mi, 0, n - 1);
            if (!e.fi) {
                res += e.se;
            }
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