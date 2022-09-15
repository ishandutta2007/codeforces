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

const int maxn = 300 + 5;
int n;
int a[maxn];
int f[maxn];
int g[maxn][maxn];
int dp[2][maxn][maxn][2][2];

void solve() {
    cin >> n;
    vi dc;
    FOR(i, 0, n) {
        cin >> a[i];
        map<int, int> hs;
        for (int k = 2; k * k <= a[i]; k++) {
            while (a[i] % k == 0) hs[k]++, a[i] /= k;
        }
        if (a[i] > 1) {
            hs[a[i]]++;
        }
        a[i] = 1;
        FORall(it, hs) if (it->se & 1) {
            a[i] *= it->fi;
        }
        dc.pb(a[i]);
    }
    sort(all(dc)), uni(dc);
    FOR(i, 0, n) a[i] = lower_bound(all(dc), a[i]) - dc.begin();
    sort(a, a + n);
    int prv = 0, cur = 1;
    dp[prv][0][0][1][1] = 1;
    int lst = 0;
    FOR(i, 1, n) {
        ms(dp[cur], 0);
        if (a[i] != a[i - 1]) {
            lst = i;
        }
        FOR(j, 0, i + 1) FOR(k, 0, i + 1) FOR(x, 0, 2) FOR(y, 0, 2) if (dp[prv][j][k][x][y]) {
            int t = dp[prv][j][k][x][y];
            if (a[i] == a[i - 1]) {
                if (j) {
                    addmod(dp[cur][j - 1][k][x][y], mult(t, j));
                }
                addmod(dp[cur][j][k + 1][x][y], mult(t, k));
                int rm = (i - lst) * 2 - k - k;
                if (rm > 0) {
                    addmod(dp[cur][j][k + 1][x][y], mult(t, rm));
                }
                rm = i + 1 - j - k - rm;
                if (!x) rm--;
                if (!y) rm--;
                if (rm > 0) {
                    addmod(dp[cur][j][k][x][y], mult(t, rm));
                }
                if (!x) {
                    addmod(dp[cur][j][k][1][y], t);
                }
                if (!y) {
                    addmod(dp[cur][j][k][x][1], t);
                }
            }
            else {
                int nj = j + k, nk = 0, nx = 0, ny = 0;
                swap(j, nj), swap(k, nk), swap(x, nx), swap(y, ny);
                
                if (j) {
                    addmod(dp[cur][j - 1][k][x][y], mult(t, j));
                }
                addmod(dp[cur][j][k + 1][x][y], mult(t, k));
                int rm = (i - lst) * 2 - k - k;
                if (rm > 0) {
                    addmod(dp[cur][j][k + 1][x][y], mult(t, rm));
                }
                rm = i + 1 - j - k - rm;
                if (!x) rm--;
                if (!y) rm--;
                if (rm > 0) {
                    addmod(dp[cur][j][k][x][y], mult(t, rm));
                }
                if (!x) {
                    addmod(dp[cur][j][k][1][y], t);
                }
                if (!y) {
                    addmod(dp[cur][j][k][x][1], t);
                }
                
                swap(j, nj), swap(k, nk), swap(x, nx), swap(y, ny);
            }
        }
        swap(prv, cur);
    }
    int ans = 0;
    FOR(x, 0, 2) FOR(y, 0, 2) {
        addmod(ans, dp[prv][0][0][x][y]);
    }
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