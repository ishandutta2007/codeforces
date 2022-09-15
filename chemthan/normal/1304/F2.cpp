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

template<class T> struct SegmenTree {
    static const int maxn = 1e5 + 5;
    T st[maxn << 2];
    T lz[maxn << 2];
    void init(int n) {
        for (int p = 0; p < (n << 2); p++) {
            st[p] = 0, lz[p] = 0;
        }
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
    void upd(int p, int l, int r, int L, int R, T val) {
        pushdown(p, L, R);
        if (l > R || r < L) return;
        if (l <= L && r >= R) {
            lz[p] = val;
            pushdown(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        st[p] = max(st[p << 1], st[p << 1 | 1]);
    }
    T query(int p, int l, int r, int L, int R) {
        pushdown(p, L, R);
        if (l > R || r < L) return -LINF;
        if (l <= L && r >= R) return st[p];
        return max(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
};
SegmenTree<long long> seg;

void chemthan() {
    int n, m, k; cin >> n >> m >> k;
    vector<vi> a(n + 5, vi(m));
    FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];
    auto upd = [&] (vector<long long>& dp, vi& a, vi& b) {
        int n = sz(a);
        vector<long long> ndp(n - k + 1, -LINF);
        FOR(it, 0, 2) {
            auto sa = a;
            FOR(i, 1, sz(sa)) sa[i] += sa[i - 1];
            seg.init(n);
            FOR(i, 0, n - k + 1) seg.upd(1, i, i, 0, n - 1, dp[i]);
            FOR(i, 0, k) {
                long long cost = sa[k - 1];
                if (i) cost -= sa[i - 1];
                seg.upd(1, i, i, 0, n - 1, -cost);
            }
            FOR(i, 0, n - k + 1) {
                chkmax(ndp[i], seg.query(1, i, n - k, 0, n - 1));
                if (i + k < n) {
                    seg.upd(1, i + 1, i + k, 0, n - 1, -a[i + k]);
                }
            }
            reverse(all(dp)), reverse(all(ndp));
            reverse(all(a)), reverse(all(b));
        }
        auto sa = a;
        FOR(i, 1, sz(sa)) sa[i] += sa[i - 1];
        auto sb = b;
        FOR(i, 1, sz(sb)) sb[i] += sb[i - 1];
        dp = ndp;
        FOR(i, 0, n - k + 1) {
            long long cost = sa[i + k - 1] + sb[i + k - 1];
            if (i) cost -= sa[i - 1] + sb[i - 1];
            dp[i] += cost;
        }
    };
    auto sa = a[0];
    FOR(i, 1, m) sa[i] += sa[i - 1];
    auto sb = a[1];
    FOR(i, 1, m) sb[i] += sb[i - 1];
    vector<long long> dp(m - k + 1);
    FOR(i, 0, m - k + 1) {
        dp[i] = sa[i + k - 1];
        dp[i] += sb[i + k - 1];
        if (i) dp[i] -= sa[i - 1];
        if (i) dp[i] -= sb[i - 1];
    }
    FOR(i, 1, n) {
        upd(dp, a[i], a[i + 1]);
    }
    cout << *max_element(all(dp)) << "\n";
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