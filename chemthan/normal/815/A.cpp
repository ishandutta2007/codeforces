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
const int MOD2 = (int) 1e8 + 7;
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
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";

const int maxn = 100 + 5;
int n, m;
int a[maxn][maxn];
int r[maxn];
int c[maxn];

void solve() {
    cin >> n >> m;
    FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];
    int mn = INF;
    FOR(x, 0, 500 + 1) {
        r[0] = x;
        FOR(i, 0, m) {
            c[i] = a[0][i] - x;
        }
        FOR(i, 1, n) {
            r[i] = a[i][0] - c[0];
        }
        int ok = 1;
        FOR(i, 0, n) if (r[i] < 0) {
            ok = 0;
            break;
        }
        FOR(i, 0, m) if (c[i] < 0) {
            ok = 0;
            break;
        }
        FOR(i, 0, n) FOR(j, 0, m) if (r[i] + c[j] != a[i][j]) {
            ok = 0;
            break;
        }
        if (!ok) continue;
        int tot = 0;
        FOR(i, 0, n) {
            tot += r[i];
        }
        FOR(i, 0, m) {
            tot += c[i];
        }
        chkmin(mn, tot);
    }
    if (mn == INF) {
        cout << -1 << "\n";
        return;
    }
    FOR(x, 0, 500 + 1) {
        r[0] = x;
        FOR(i, 0, m) {
            c[i] = a[0][i] - x;
        }
        FOR(i, 1, n) {
            r[i] = a[i][0] - c[0];
        }
        int ok = 1;
        FOR(i, 0, n) if (r[i] < 0) {
            ok = 0;
            break;
        }
        FOR(i, 0, m) if (c[i] < 0) {
            ok = 0;
            break;
        }
        FOR(i, 0, n) FOR(j, 0, m) if (r[i] + c[j] != a[i][j]) {
            ok = 0;
            break;
        }
        if (!ok) continue;
        int tot = 0;
        FOR(i, 0, n) {
            tot += r[i];
        }
        FOR(i, 0, m) {
            tot += c[i];
        }
        if (mn - tot) continue;
        cout << tot << "\n";
        FOR(i, 0, n) {
            FOR(j, 0, r[i]) {
                cout << "row " << i + 1 << "\n";
            }
        }
        FOR(i, 0, m) {
            FOR(j, 0, c[i]) {
                cout << "col " << i + 1 << "\n";
            }
        }
        return;
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