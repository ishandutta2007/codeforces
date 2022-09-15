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

const int maxn = 2e5 + 5;
int n;
vii g[2];
int prv[maxn];
int dp[maxn][305];

int calc(int n, int limit) {
    if (n == sz(g[0])) return 0;
    int& res = dp[n][limit];
    if (~res) return res;
    res = INF;
    int nlimit = limit;
    if (!nlimit) nlimit = INF;
    if (g[0][n].fi == 1) {
        if (g[0][n].se <= nlimit) {
            chkmin(res, calc(n + 1, limit));
        }
    }
    else if (g[0][n].fi == 3) {
        chkmin(res, calc(n + 1, limit) + 1);
        if (g[0][n].se >= prv[n]) {
            chkmin(res, calc(n + 1, g[0][n].se));
        }
    }
    else {
        chkmin(res, calc(n + 1, 0));
    }
    return res;
}

int calc2(int n, int alw) {
    if (n == sz(g[1])) return 0;
    int& res = dp[n][alw];
    if (~res) return res;
    res = INF;
    if (g[1][n].fi == 2) {
        if (alw) {
            chkmin(res, calc2(n + 1, alw));
        }
    }
    else if (g[1][n].fi == 4) {
        chkmin(res, calc2(n + 1, 1));
    }
    else if (g[1][n].fi == 6) {
        chkmin(res, calc2(n + 1, alw) + 1);
        chkmin(res, calc2(n + 1, 0));
    }
    return res;
}

void solve() {
    cin >> n;
    FOR(i, 0, n) {
        int op; cin >> op;
        if (op % 2 == 1) {
            if (op == 1 || op == 3) {
                int x; cin >> x;
                g[0].pb(mp(op, x));
            }
            else if (op == 5) {
                g[0].pb(mp(op, 0));
            }
        }
        else {
            g[1].pb(mp(op, 0));
        }
    }
    int cur;
    FOR(i, 0, sz(g[0])) {
        if (g[0][i].fi == 1) {
            cur = g[0][i].se;
        }
        prv[i] = cur;
    }
    ms(dp, -1);
    int ans = calc(1, 0);
    ms(dp, -1);
    ans += calc2(0, 1);
    cout << ans << "\n";
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