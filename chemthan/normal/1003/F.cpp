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
//const int MOD = (int) 1e9 + 7;
const int MOD = 998244353;
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

const int maxn = 1e5 + 5;
const int maxc = 300 + 5;
int n;
string s[maxn];
int a[maxn];
map<string, int> hs;
int f[maxc][maxc];
int g[maxc][maxc];

int query(string s) {
    if (hs.count(s)) return hs[s];
    int res = sz(hs);
    return hs[s] = res;
}

int ptr;
int nxt[maxn][maxc];
int val[maxn * maxc];

void add(int l, int r) {
    int rt = 0;
    FOR(i, l, r + 1) {
        if (!nxt[rt][a[i]]) nxt[rt][a[i]] = ++ptr;
        rt = nxt[rt][a[i]];
        chkmax(val[rt], l);
    }
}

void reset() {
    FOR(i, 0, ptr + 1) fill_n(nxt[i], maxc, 0), val[i] = -1;
    ptr = 0;
}

void chemthan() {
    ms(f, -1);
    ms(val, -1);
    cin >> n;
    FOR(i, 0, n) cin >> s[i], a[i] = query(s[i]);
    int sum = 0;
    FOR(i, 0, n) sum += sz(s[i]);
    sum += n - 1;
    int res = sum;
    FOR(i, 1, n) {
        reset();
        FOR(j, 0, i) add(j, i - 1);
        int rt = 0, mx = 0;
        FOR(j, i, n) {
            if (nxt[rt][a[j]]) {
                mx++;
                rt = nxt[rt][a[j]];
            }
            else {
                break;
            }
            f[i][j] = val[rt];
        }
    }
    FOR(i, 0, n) FOR(j, i, n) {
        FOR(k, i, j + 1) {
            g[i][j] += sz(s[k]) - 1;
        }
        g[i][j] += j - i;
    }
    static int dp[maxc][maxc];
    FOR(i, 0, n) FOR(j, i, n) {
        int pv = f[i][j];
        dp[i][j] = 1;
        if (pv != -1) {
            dp[i][j] = dp[pv][pv + j - i] + 1;
        }
        if (dp[i][j] > 1) {
            chkmin(res, sum - g[i][j] * dp[i][j]);
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