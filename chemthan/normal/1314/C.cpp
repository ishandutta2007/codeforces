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
    int n, m;
    long long k;
    cin >> n >> m >> k;
    string s; cin >> s;
    vector<vi> lcp(n + 1, vi(n + 1));
    FORd(i, n, 0) FORd(j, n, 0) {
        if (s[i] == s[j]) {
            chkmax(lcp[i][j], lcp[i + 1][j + 1] + 1);
        }
    }
    vii vals;
    FOR(i, 0, n) FOR(j, i, n) vals.pb({i, j});
    auto cmp = [&] (int i1, int i2, int j1, int j2) {
        int k = min(i2 - i1 + 1, min(j2 - j1 + 1, lcp[i1][j1]));
        if (k == j2 - j1 + 1) return false;
        if (k == i2 - i1 + 1) return true;
        return s[i1 + k] < s[j1 + k];
    };
    sort(all(vals), [&] (pi a, pi b) {
            int i1 = a.fi, i2 = a.se;
            int j1 = b.fi, j2 = b.se;
            return cmp(i1, i2, j1, j2);
            }
        );
    vector<vector<long long>> dp(n + 2, vector<long long>(m + 1));
    auto upd = [&] (long long& x, long long v) {
        if (LINF < (x += v)) {
            x = LINF;
        }
    };
    int lo = 0, hi = sz(vals) - 1;
    while (lo < hi) {
        int mi = lo + hi + 1 >> 1;
        int p = vals[mi].fi;
        int q = vals[mi].se;
        for (auto& row : dp) {
            for (auto& e : row) {
                e = 0;
            }
        }
        dp[n][0] = 1;
        FORd(i, n, 0) {
            FOR(j, 0, m + 1) {
                upd(dp[i + 1][j], dp[i + 2][j]);
            }
            int x = i, y = n;
            while (x < y) {
                int z = x + y >> 1;
                if (cmp(i, z, p, q)) {
                    x = z + 1;
                }
                else {
                    y = z;
                }
            }
            int z = x + y >> 1;
            if (z < n) {
                FOR(j, 0, m) {
                    upd(dp[i][j + 1], dp[z + 1][j]);
                }
            }
        }
        if (dp[0][m] < k) {
            hi = mi - 1;
        }
        else {
            lo = mi;
        }
    }
    int mi = lo + hi >> 1;
    int p = vals[mi].fi;
    int q = vals[mi].se;
    cout << s.substr(p, q - p + 1) << "\n";
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