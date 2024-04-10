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

void chemthan() {
    int n; cin >> n;
    vi a(n);
    vi b(n);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];
    long long sum = 0;
    FOR(i, 0, n) sum += abs(a[i] - b[i]);
    auto func = [&] (int sa, int sb) {
        long long res = sum;
        vi dc;
        FOR(i, 0, n) dc.pb(sb * a[i]), dc.pb(sb * b[i]);
        sort(all(dc)), uni(dc);
        vector<long long> fen(sz(dc) + 1, LINF);
        auto upd = [&] (int p, long long v) {
            p++;
            for (; p < sz(fen); p += p & -p) {
                chkmin(fen[p], v);
            }
        };
        auto query = [&] (int p) {
            p++;
            long long res = LINF;
            for (; 0 < p; p -= p & -p) {
                chkmin(res, fen[p]);
            }
            return res;
        };
        vector<tuple<int, int, int>> v;
        FOR(i, 0, n) {
            v.pb({sa * a[i], sb * b[i], 1});
            v.pb({sa * b[i], sb * a[i], 0});
        }
        sort(all(v));
        for (auto [x, y, t] : v) {
            int k = lower_bound(all(dc), y) - dc.begin();
            if (!t) {
                upd(k, (long long) - x - y - abs(sa * x - sb * y));
            }
            else {
                chkmin(res, sum + x + y + query(k) - abs(sa * x - sb * y));
            }
        }
        return res;
    };
    long long res = sum;
    for (int sa : {-1, 1}) {
        for (int sb : {-1, 1}) {
            chkmin(res, func(sa, sb));
        }
    }
    cout << res << "\n";
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