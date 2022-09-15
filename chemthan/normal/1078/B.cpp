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
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 100 + 5;
int pr;
int n;
int f[maxn];
int dp[maxn][maxn * maxn];
int c[maxn][maxn];

int ispr(int k) {
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            return 0;
        }
    }
    return 1;
}

void chemthan() {
    pr = INF - myrand() % (INF / 100);
    while (!ispr(pr)) pr++;
    FOR(i, 0, maxn) c[0][i] = 1;
    FOR(i, 1, maxn) FOR(j, 1, maxn) c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % pr;
    cin >> n;
    vi vals;
    int sum = 0;
    FOR(i, 0, n) {
        int x; cin >> x;
        f[x]++;
        vals.pb(x);
        sum += x;
    }
    dp[0][0] = 1;
    for (int x : vals) {
        FORd(i, maxn - 1, 0) {
            FORd(j, maxn * maxn - x, 0) {
                addmod(dp[i + 1][j + x], dp[i][j], pr);
            }
        }
    }
    int res = 0;
    FOR(i, 1, maxn) if (f[i]) {
        FOR(j, 1, f[i] + 1) {
            if (dp[j][j * i] == c[j][f[i]]) {
                chkmax(res, j);
                if (j == f[i]) {
                    int num = 0;
                    FOR(k, 0, maxn) num += f[k] > 0;
                    if (num == 2) {
                        chkmax(res, n);
                    }
                }
            }
            if (dp[n - j][sum - j * i] == c[j][f[i]]) {
                chkmax(res, j);
                if (j == f[i]) {
                    int num = 0;
                    FOR(k, 0, maxn) num += f[k] > 0;
                    if (num == 2) {
                        chkmax(res, n);
                    }
                }
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