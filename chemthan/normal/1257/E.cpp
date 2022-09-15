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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
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
    static const int maxn = 1e6 + 5;
    T st[maxn << 2];
    T lz[maxn << 2];
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
        st[p] = min(st[p << 1], st[p << 1 | 1]);
    }
    T query(int p, int l, int r, int L, int R) {
        pushdown(p, L, R);
        if (l > R || r < L) return INF;
        if (l <= L && r >= R) return st[p];
        return min(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
};
SegmenTree<int> seg;

void solve() {
    int k1, k2, k3; cin >> k1 >> k2 >> k3;
    int n = k1 + k2 + k3;
    vi f(n);
    vi a1(k1), a2(k2), a3(k3);
    FOR(i, 0, k1) cin >> a1[i], a1[i]--, f[a1[i]] = 0;
    FOR(i, 0, k2) cin >> a2[i], a2[i]--, f[a2[i]] = 1;
    FOR(i, 0, k3) cin >> a3[i], a3[i]--, f[a3[i]] = 2;
    FOR(i, 0, k3) {
        int x = a3[i];
        seg.upd(1, 0, n - x - 1, 0, n, 1);
    }
    FOR(i, 0, n) {
        if (f[i] != 2) {
            seg.upd(1, n - i, n, 0, n, 1);
        }
    }
    FOR(i, 0, k1) {
        int x = a1[i];
        seg.upd(1, n - x, n, 0, n, -1);
    }
    int res = INF, num = 0, t = 0;
    FOR(i, 0, n + 1) {
        if (i) {
            if (!f[i - 1]) {
                num++;
            }
            else if (f[i - 1] == 1) {
                t++;
            }
        }
        chkmin(res, sz(a1) - num + t + seg.query(1, 0, n - i, 0, n));
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
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}