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

const int maxn = 30 + 5;
int n;
int a[maxn];
int dp[maxn][65 * maxn][65];
int rb[maxn][65 * maxn][65];
int z[65][65];
int f[maxn];

int calc(int pos, int u, int v) {
    if (pos == n) {
        if (u == v * (v - 1) / 2) {
            return v;
        }
        return INF;
    }
    int& res = dp[pos][u][v];
    if (~res) return res;
    res = INF;
    FOR(i, 1, 65 - v) {
        if (u + i * a[pos] < (v + i) * (v + i - 1) / 2) {
            break;
        }
        if (chkmin(res, calc(pos + 1, u + i * a[pos], v + i))) {
            rb[pos][u][v] = i;
        }
    }
    return res;
}

void solve() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    sort(a, a + n);
    ms(dp, -1);
    int k = calc(0, 0, 0);
    int pos = 0, u = 0, v = 0;
    vii vs;
    FOR(i, 0, n) {
        int npos = pos + 1;
        int t = rb[pos][u][v];
        FOR(i, 0, t) vs.pb(mp(a[pos], sz(vs)));
        int nu = u + t * a[pos];
        int nv = v + t;
        pos = npos, u = nu, v = nv;
    }
    FOR(i, 0, k) {
        sort(vs.begin() + i, vs.end());
        FOR(j, i + 1, i + vs[i].fi + 1) {
            z[vs[i].se][vs[j].se] = 1;
        }
        FOR(j, i + vs[i].fi + 1, k) {
            z[vs[j].se][vs[i].se] = 1;
            vs[j].fi--;
        }
    }
    cout << k << "\n";
    FOR(i, 0, k) {
        FOR(j, 0, k) cout << z[i][j];
        cout << "\n";
    }
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