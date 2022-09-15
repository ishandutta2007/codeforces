#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stdio.h>
#include <string.h>
#include <vector>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return (int) fpow(a, p - 2, p);}

const int maxn = 64;
long long m, k;
int a[maxn];
long long dp[maxn][maxn][2];

long long calc(int pos, int cnt, int fa) {
    if (pos == maxn) return cnt == k;
    long long& res = dp[pos][cnt][fa];
    if (~res) return res;
    res = 0;
    if (cnt > k) return res;
    int lo = 0, hi = 1;
    if (!fa) chkmin(hi, a[pos]);
    FOR(i, lo, hi + 1) {
        res += calc(pos + 1, cnt + i, fa | (i < a[pos]));
    }
    return res;
}

long long ff(long long n, int k) {
    ms(a, 0);
    int ptr = maxn - 1;
    while (n) {
        a[ptr--] = n & 1;
        n >>= 1;
    }
    ms(dp, -1);
    return calc(0, 0, 0);
}

void solve() {
    cin >> m >> k;
    FOR(i, 0, 100) {
        long long l = i > 0 ? 0 : 1, r = LINF / 100;
        while (l < r) {
            long long mid = (l + r) >> 1;
            long long n = mid * 100 + i;
            if (ff(n + n, k) - ff(n, k) < m) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        long long n = l * 100 + i;
        if (n <= LINF && ff(n + n, k) - ff(n, k) == m) {
            cout << n << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    solve();
    cerr << "\n" << 1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}