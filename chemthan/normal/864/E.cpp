#include <bits/stdc++.h>
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
const int MOD2 = 1007681537;
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

const int maxn = 100 + 5;
const int maxd = 2000 + 5;
int n;
int t[maxn];
int d[maxn];
int p[maxn];
vi ver;
int dp[maxn][maxd];
int rb[maxn][maxd];

int cmp(int i, int j) {
    if (d[i] != d[j]) return d[i] < d[j];
    if (p[i] != p[j]) return p[i] > p[j];
    return i < j;
}

int calc(int pos, int k) {
    if (pos < 0 || k < 0) return 0;
    int& res = dp[pos][k];
    if (~res) return res;
    res = calc(pos - 1, k);
    if (chkmax(res, calc(pos, k - 1))) {
        rb[pos][k] = 1;
    }
    int i = ver[pos];
    if (k < d[i] && t[i] <= k) {
        if (chkmax(res, calc(pos - 1, k - t[i]) + p[i])) {
            rb[pos][k] = 2;
        }
    }
    return res;
}

void solve() {
    cin >> n;
    FOR(i, 0, n) {
        cin >> t[i] >> d[i] >> p[i];
    }
    FOR(i, 0, n) ver.pb(i);
    sort(all(ver), cmp);
    ms(dp, -1);
    cout << calc(n - 1, maxd - 1) << "\n";
    int pos = n - 1, k = maxd - 1;
    vi res;
    while (pos >= 0 && k >= 0) {
        int z = rb[pos][k];
        if (!z) {
            pos--;
        }
        else if (z == 1) {
            k--;
        }
        else {
            int i = ver[pos];
            res.pb(i);
            pos--, k -= t[i];
        }
    }
    reverse(all(res));
    cout << sz(res) << "\n";
    FOR(i, 0, sz(res)) cout << res[i] + 1 << " \n"[i == sz(res) - 1];
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}