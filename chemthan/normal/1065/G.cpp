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
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}

const int maxn = 200 + 5;
string f[maxn];
int n, m;
long long k;
string s;

long long dp[maxn];
int dp2[maxn][maxn];

long long calc(int d) {
    if (d <= 1) return f[d] == s || !sz(s);
    long long& res  = dp[d];
    if (~res) return res;
    res = 0;
    res = calc(d - 2) + calc(d - 1);
    FOR(i, 1, sz(s)) {
        string u = s.substr(0, i);
        string v = s.substr(i);
        if (sz(f[d - 2]) >= sz(u) && sz(f[d - 1]) >= sz(v) && f[d - 2].substr(sz(f[d - 2]) - sz(u), sz(u)) == u && f[d - 1].substr(0, sz(v)) == v) {
            res++;
        }
    }
    chkmin(res, LINF);
    return res;
}

int calc2(int d, int len) {
    if (!len) return 0;
    if (d <= 1) return f[d] == s.substr(0, len);
    int& res = dp2[d][len];
    if (~res) return res;
    res = 0;
    if (d - 1 > 15 || sz(f[d - 1]) >= len) {
        return res = calc2(d - 1, len);
    }
    return res = (calc2(d - 2, len - sz(f[d - 1])) && f[d - 1] == s.substr(len - sz(f[d - 1]), sz(f[d - 1])));
}

void chemthan() {
    f[0] = "0", f[1] = "1";
    FOR(i, 2, 16) f[i] = f[i - 2] + f[i - 1];
    cin >> n >> k >> m;
    ms(dp, -1);
    long long sum = 0;
    FOR(i, 0, m) {
        ms(dp2, -1);
        int x = calc2(n, sz(s));
        s += "0";
        ms(dp, -1);
        long long y = calc(n);
        s.pop_back();
        if (sum + x == k) {
            break;
        }
        if (sum + x + y < k) {
            sum += x + y;
            s += "1";
        }
        else {
            sum += x;
            s += "0";
        }
    }
    cout << s << "\n";
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