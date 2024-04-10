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

const int maxn = 5000 + 5;
int n, k, v;
int a[maxn];
int dp[maxn][maxn];
int rv[maxn][maxn];

void chemthan() {
    cin >> n >> k >> v;
    FOR(i, 0, n) cin >> a[i];
    if (v % k == 0) {
        int sum = accumulate(a, a + n, 0);
        if (sum < v) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        FOR(i, 1, n) {
            if (a[i]) {
                cout << (a[i] + k - 1) / k << " " << i + 1 << " " << 1 << "\n";
            }
        }
        if (v / k) {
            cout << v / k << " " << 1 << " " << 2 << "\n";
        }
        return;
    }
    ms(dp, -1);
    dp[0][0] = 0;
    FOR(pos, 0, n) FOR(r, 0, k) if (dp[pos][r] >= 0) {
        if (chkmax(dp[pos + 1][r], dp[pos][r] + a[pos])) {
            rv[pos + 1][r] = 0;
        }
        int nr = (r + a[pos]) % k;
        if (chkmax(dp[pos + 1][nr], dp[pos][r] + a[pos])) {
            rv[pos + 1][nr] = 1;
        }
    }
    if (dp[n][v % k] < v) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int st = -1;
    int pos = n, r = v % k;
    static int f[maxn];
    int sum = 0;
    FOR(i, 0, n) {
        if (!rv[pos][r]) {
            pos--;
        }
        else {
            pos--;
            r = (r - a[pos] % k + k) % k;
            f[pos] = 1;
            sum += a[pos];
            if (st == -1) {
                st = pos;
            }
            else {
                if (a[pos]) {
                    cout << (a[pos] + k - 1) / k << " " << pos + 1 << " " << st + 1 << "\n";
                }
            }
        }
    }
    int nst = -1;
    int nsum = 0;
    FOR(i, 0, n) if (!f[i]) {
        nsum += a[i];
        if (nst == -1) {
            nst = i;
        }
        else {
            if (a[i]) {
                cout << (a[i] + k - 1) / k << " " << i + 1 << " " << nst + 1 << "\n";
            }
        }
    }
    if (nsum >= k) {
        cout << nsum / k << " " << nst + 1 << " " << st + 1 << "\n";
        sum += nsum / k * k;
    }
    assert(sum >= v);
    nst = st ? (st - 1) : (st + 1);
    if (sum > v) {
        cout << (sum - v) / k << " " << st + 1 << " " << nst + 1 << "\n";
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