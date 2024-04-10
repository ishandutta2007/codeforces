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
 
void chemthan() {
    int n; cin >> n;
    vector<long long> a(n);
    FOR(i, 0, n) cin >> a[i];
    vi vals; FOR(i, 0, n) vals.pb(i);
    vi pv_order(n), dp(n + 1);
    FOR(k, 1, 63) {
        sort(all(vals), [&] (int u, int v) {
                return mp(a[u] & (1LL << k) - 1, pv_order[u]) < mp(a[v] & (1LL << k) - 1, pv_order[v]);
                }
            );
        int x = 0, y = 0;
        FOR(i, 0, n) {
            if (!bit(a[i], k - 1)) {
                x++;
            }
        }
        vi st(n + 1 << 1);
        auto upd = [&] (int p, int val) {
            for (st[p += n + 1] = val; 1 < p; ) p >>= 1, st[p] = min(st[p << 1], st[p << 1 | 1]);
        };
        auto query = [&] (int l, int r) {
            int res = INF;
            for (l += n + 1, r += n + 2; l < r; l >>= 1, r >>= 1) {
                if (l & 1) chkmin(res, st[l++]);
                if (r & 1) chkmin(res, st[--r]);
            }
            return res;
        };
        FOR(i, 0, n + 1) upd(i, dp[i]);
        vi ndp(n + 1);
        int lo = 0;
        int hi = n;
        if (1 < k && !bit(a[vals[0]], k - 1)) {
            hi = pv_order[vals[0]] - 1;
        }
        ndp[0] = x + (1 < k ? query(lo, hi) : 0);
        FOR(i, 1, n + 1) {
            int lo = pv_order[vals[i - 1]];
            int hi = n;
            if (i < n && bit(a[vals[i - 1]], k - 1) == bit(a[vals[i]], k - 1)) {
                hi = pv_order[vals[i]] - 1;
            }
            if (!bit(a[vals[i - 1]], k - 1)) {
                x--;
                ndp[i] = x + (1 < k ? query(lo, hi) : 0);
                if (i == n || bit(a[vals[i]], k - 1)) {
                    chkmin(ndp[i], n - y + (1 < k ? query(0, hi) : 0));
                }
            }
            else {
                y++;
                ndp[i] = n - y + (1 < k ? query(lo, hi) : 0);
            }
        }
        FOR(i, 0, n) {
            pv_order[vals[i]] = i + 1;
        }
        dp = ndp;
    }
    cout << dp.back() << "\n";
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