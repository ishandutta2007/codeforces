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

//#define LOCAL
void chemthan() {
#ifdef LOCAL
    int n = 10, k = 3;
    vi c(n);
    FOR(i, 0, n) c[i] = mrand() % INF;
#else
    int n, k; cin >> n >> k;
#endif
    auto ask = [&] (int u, int v) {
        cout << "and " << u + 1 << " " << v + 1 << "\n";
        cout.flush();
#ifdef LOCAL
        int x = c[u] & c[v];
#else
        int x; cin >> x;
#endif
        cout << "or " << u + 1 << " " << v + 1 << "\n";
        cout.flush();
#ifdef LOCAL
        int y = c[u] | c[v];
#else
        int y; cin >> y;
#endif
        return mp(x, y);
    };
    vii v(n);
    FOR(i, 0, n) {
        v[i] = ask(i, (i + 1) % n);
    }
    vi a(n);
    FOR(t, 0, 30) {
        vii v2(n);
        FOR(i, 0, n) v2[i] = mp(bit(v[i].fi, t), bit(v[i].se, t));
        vi b(n);
        auto check = [&] (int k) {
            b[0] = k;
            FOR(i, 0, n - 1) {
                int found = 0;
                FOR(j, 0, 2) {
                    if (mp(b[i] & j, b[i] | j) == v2[i]) {
                        b[i + 1] = j;
                        found = 1;
                        break;
                    }
                }
                if (!found) return false;
            }
            return mp(b[n - 1] & b[0], b[n - 1] | b[0]) == v2[n - 1];
        };
        FOR(k, 0, 2) if (check(k)) {
            FOR(i, 0, n) {
                a[i] += (1 << t) * b[i];
            }
        }
    }
#ifdef LOCAL
    FOR(i, 0, n) assert(a[i] == c[i]);
#endif
    sort(all(a));
    cout << "finish " << a[k - 1] << "\n";
    cout.flush();
}

int32_t main(int32_t argc, char* argv[]) {
    //ios_base::sync_with_stdio(0), cin.tie(0);
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