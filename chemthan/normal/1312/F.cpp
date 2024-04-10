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
    vector<map<pi, int>> dp(12345);
    vi used(1234567);
    function<int(int, int, int, int, int)> calc = [&] (int t, int k, int x, int y, int z) {
        if (!t) return 0;
        int w = (x - 1) * 5 * 5 + (y - 1) * 5 + z - 1;
        auto key = mp(t, k);
        if (dp[w].count(key)) return dp[w][key];
        int& res = dp[w][key];
        vi vals;
        vals.pb(calc(max(0, t - x), 0, x, y, z));
        if (!k) {
            int ptr = 0;
            for (int e : {y, z}) {
                ptr++;
                vals.pb(calc(max(0, t - e), ptr, x, y, z));
            }
        }
        else if (k == 1) {
            vals.pb(calc(max(0, t - z), 2, x, y, z));
        }
        else {
            vals.pb(calc(max(0, t - y), 1, x, y, z));
        }
        for (int x : vals) used[x] = 1;
        while (used[res]) res++;
        for (int x : vals) used[x] = 0;
        return res;
    };
    vector<vector<vector<vi>>> cycle(6, vector<vector<vi>>(6, vector<vi>(6, vi(3))));
    FOR(x, 1, 5 + 1) FOR(y, 1, 5 + 1) FOR(z, 1, 5 + 1) FOR(k, 0, 3) {
        vi f;
        FOR(i, 0, 2000) {
            f.pb(calc(i, k, x, y, z));
        }
        FOR(d, 1, 2000) {
            int found = 0;
            FOR(i, 1000, sz(f) - d) {
                if (f[i] ^ f[i + d]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                cycle[x][y][z][k] = d;
                break;
            }
        }
        assert(cycle[x][y][z][k]);
    }
    int test; cin >> test;
    while (test--) {
        int n, x, y, z; cin >> n >> x >> y >> z;
        int res = 0;
        vector<long long> vt;
        auto func = [&] (long long t, int k) {
            if (1000 < t) {
                t %= cycle[x][y][z][k];
                t += 1000 / cycle[x][y][z][k] * cycle[x][y][z][k];
            }
            return calc(t, k, x, y, z);
        };
        FOR(i, 0, n) {
            long long t; cin >> t;
            vt.pb(t);
            res ^= func(t, 0);
        }
        int cnt = 0;
        for (auto t : vt) {
            res ^= func(t, 0);
            int ptr = 0;
            for (int e : {x, y, z}) {
                res ^= func(max(0LL, t - e), ptr);
                if (!res) {
                    cnt++;
                }
                res ^= func(max(0LL, t - e), ptr);
                ptr++;
            }
            res ^= func(t, 0);
        }
        cout << cnt << "\n";
    }
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