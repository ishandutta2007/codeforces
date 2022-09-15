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
    int n, t; cin >> n >> t;
    vi a(n), b(n);
    vi c(3);
    FOR(i, 0, n) cin >> a[i] >> b[i], b[i]--, c[b[i]]++;
    vector<vector<vector<vi>>> dp;
    dp.resize(t + 1);
    for (auto& dp1 : dp) {
        dp1.resize(c[0] + 1);
        for (auto& dp2 : dp1) {
            dp2.resize(c[1] + 1);
            for (auto& dp3 : dp2) {
                dp3.resize(c[2] + 1);
            }
        }
    }
    vector<vector<vector<vi>>> ndp = dp;
    dp[0][0][0][0] = 1;
    FOR(k, 0, n) {
        FORd(i, t + 1, 0) FOR(u, 0, c[0] + 1) FOR(v, 0, c[1] + 1) FOR(w, 0, c[2] + 1) {
            if (dp[i][u][v][w]) {
                ndp[i][u][v][w] = dp[i][u][v][w];
                if (i + a[k] <= t) {
                    int ar[] = {u, v, w};
                    ar[b[k]]++;
                    addmod(ndp[i + a[k]][ar[0]][ar[1]][ar[2]], dp[i][u][v][w]);
                }
            }
        }
        dp = ndp;
    }
    vector<vector<vector<vi>>> f(n + 1, vector<vector<vi>>(n + 1, vector<vi>(n + 1, vi(4, -1))));
    function<int(int, int, int, int)> calc = [&] (int u, int v, int w, int lst) {
        if (!(u + v + w)) return 1;
        int& res = f[u][v][w][lst];
        if (~res) return res;
        res = 0;
        int ar[] = {u, v, w};
        FOR(i, 0, 3) if (ar[i] && i != lst) {
            ar[i]--;
            addmod(res, mult(ar[i] + 1, calc(ar[0], ar[1], ar[2], i)));
            ar[i]++;
        }
        return res;
    };
    int res = 0;
    FOR(u, 0, c[0] + 1) FOR(v, 0, c[1] + 1) FOR(w, 0, c[2] + 1) {
        addmod(res, mult(dp[t][u][v][w], calc(u, v, w, 3)));
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