#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 2e6 + 5;
int sp[maxn];
int n, k;
int dp[maxn];

void rec(pi pr[], int npr, int pos, int t, int isnew, int n, int& val) {
    if (isnew) {
        addmod(val, dp[n / t - 1]);
        submod(val, dp[n / t]);
    }
    if (pos == npr) return;
    rec(pr, npr, pos + 1, t, 0, n, val);
    FOR(i, 0, pr[pos].se) {
        t *= pr[pos].fi;
        rec(pr, npr, pos + 1, t, 1, n, val);
    }
}

void chemthan() {
    FOR(i, 1, maxn) sp[i] = i;
    FOR(i, 2, maxn) if (sp[i] == i) {
        for (int j = i; j < maxn; j += i) {
            chkmin(sp[j], i);
        }
    }
    cin >> n >> k;
    dp[0] = 0, dp[1] = 1;
    int res = 0;
    FOR(i, 0, 2) {
        addmod(res, dp[i] ^ i);
    }
    int tmp = 0;
    for (int i = 2; i <= k; i++) {
        static pi pr[100];
        int npr = 0;
        int t = i;
        while (t > 1) {
            if (npr && sp[t] == pr[npr - 1].fi) {
                pr[npr - 1].se++;
            }
            else {
                pr[npr++] = mp(sp[t], 1);
            }
            t /= sp[t];
        }
        rec(pr, npr, 0, 1, 0, i, tmp);
        dp[i] = tmp;
        addmod(dp[i], fpow(i, n));
        addmod(res, dp[i] ^ i);
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