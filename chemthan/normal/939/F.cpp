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

const int maxn = 1e5 + 5;
const int maxk = 1e2 + 5;
int n, k;
int l[maxn];
int r[maxn];
int dp[2][2][maxn];

void chemthan() {
    cin >> n >> k;
    FOR(i, 0, k) cin >> l[i] >> r[i];
    l[k] = n + n;
    int pv = 0, nx = 1;
    FOR(i, 0, 2) FOR(j, 0, 2) FOR(k, 0, maxn) dp[i][j][k] = INF;
    dp[pv][0][l[0]] = 0;
    FOR(i, 0, k) {
        FOR(j, 0, 2) {
            if (!(j & 1)) {
                deque<pi> dq[2];
                FOR(u, 0, n + 1) {
                    if (u - (l[i + 1] - l[i]) >= 0) {
                        chkmin(dp[nx][j][u], dp[pv][j][u - (l[i + 1] - l[i])]);
                    }
                    //l[i + 1] - r[i] -> l[i + 1] - l[i]
                    while (sz(dq[j ^ 1]) && dq[j ^ 1].front().se < u - (l[i + 1] - l[i])) dq[j ^ 1].pop_front();
                    if (u - (l[i + 1] - r[i]) >= 0) {
                        while (sz(dq[j ^ 1]) && dq[j ^ 1].back().fi >= dp[pv][j ^ 1][u - (l[i + 1] - r[i])]) dq[j ^ 1].pop_back();
                        dq[j ^ 1].pb(mp(dp[pv][j ^ 1][u - (l[i + 1] - r[i])], u - (l[i + 1] - r[i])));
                        chkmin(dp[nx][j][u], dq[j ^ 1].front().fi + 1);
                    }
                    //l[i + 1] - r[i] -> l[i + 1] - l[i]
                    while (sz(dq[j]) && dq[j].front().se < u - (l[i + 1] - l[i])) dq[j].pop_front();
                    if (u - (l[i + 1] - r[i]) >= 0) {
                        while (sz(dq[j]) && dq[j].back().fi >= dp[pv][j][u - (l[i + 1] - r[i])]) dq[j].pop_back();
                        dq[j].pb(mp(dp[pv][j][u - (l[i + 1] - r[i])], u - (l[i + 1] - r[i])));
                        chkmin(dp[nx][j][u], dq[j].front().fi + 2);
                    }
                }
            }
            else {
                deque<pi> dq[2];
                FOR(u, 0, n + 1) {
                    chkmin(dp[nx][j][u], dp[pv][j][u]);
                    //0 -> r[i] - l[i]
                    while (sz(dq[j ^ 1]) && dq[j ^ 1].front().se < u - (r[i] - l[i])) dq[j ^ 1].pop_front();
                    while (sz(dq[j ^ 1]) && dq[j ^ 1].back().fi >= dp[pv][j ^ 1][u]) dq[j ^ 1].pop_back();
                    dq[j ^ 1].pb(mp(dp[pv][j ^ 1][u], u));
                    chkmin(dp[nx][j][u], dq[j ^ 1].front().fi + 1);
                    //0 -> r[i] - l[i]
                    while (sz(dq[j]) && dq[j].front().se < u - (r[i] - l[i])) dq[j].pop_front();
                    while (sz(dq[j]) && dq[j].back().fi >= dp[pv][j][u]) dq[j].pop_back();
                    dq[j].pb(mp(dp[pv][j][u], u));
                    chkmin(dp[nx][j][u], dq[j].front().fi + 2);
                }
            }
        }
        swap(pv, nx);
        FOR(j, 0, 2) FOR(u, 0, n + 1) dp[nx][j][u] = INF;
    }
    int res = min(dp[pv][0][n], dp[pv][1][n]);
    if (res == INF) {
        cout << "Hungry\n";
        return;
    }
    cout << "Full\n";
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