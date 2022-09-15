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
    vector<vi> f(256, vi(256));
    f['w']['y'] = f['y']['w'] = 1;
    f['g']['b'] = f['b']['g'] = 1;
    f['r']['o'] = f['o']['r'] = 1;
    int k; cin >> k;
    vector<vi> dps;
    {
        vi dp(6);
        FOR(i, 0, 6) dp[i] = 1;
        dps.pb(dp);
        FOR(i, 0, k - 1) {
            vi ndp(6);
            FOR(x, 0, 6) {
                FOR(y, 0, 6) FOR(z, 0, 6) {
                    if (x != y && (x + 3) % 6 != y &&
                            x != z && (x + 3) % 6 != z
                       ) {
                        addmod(ndp[x], mult(dp[y], dp[z]));
                    }
                }
            }
            dp = ndp;
            dps.pb(dp);
        }
    }
    int n; cin >> n;
    map<long long, char> hs;
    map<long long, int> mem;
    FOR(i, 0, n) {
        long long u; string c; cin >> u >> c;
        hs[u] = c[0];
        FOR(i, 0, 60) {
            mem[u >> i] = 1;
        }
    }
    function<map<int, int> (long long, int)> calc = [&] (long long p, int lev) {
        if (lev == -1) return map<int, int>();
        if (!mem[p]) {
            map<int, int> res;
            for (char c : {'w', 'y', 'g', 'b', 'r', 'o'}) {
                res[c] = dps[lev][0];
            }
            return res;
        }
        auto left = calc(p << 1, lev - 1);
        auto right = calc(p << 1 | 1, lev - 1);
        vi vv;
        if (hs.count(p)) {
            vv.pb(hs[p]);
        }
        else {
            for (char c : {'w', 'y', 'g', 'b', 'r', 'o'}) {
                vv.pb(c);
            }
        }
        map<int, int> res;
        for (char c : vv) {
            if (lev == 0) {
                addmod(res[c], 1);
                continue;
            }
            int x = 0;
            int y = 0;
            for (char c1 : {'w', 'y', 'g', 'b', 'r', 'o'}) {
                if (c == c1 || f[c][c1]) continue;
                addmod(x, left[c1]);
                addmod(y, right[c1]);
            }
            addmod(res[c], mult(x, y));
        }
        return res;
    };
    int res = 0;
    for (auto [x, v] : calc(1, k - 1)) {
        addmod(res, v);
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