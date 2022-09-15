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

typedef vector<int> ROW;
typedef vector<ROW> MATRIX;
int iv[5];

void gauss(MATRIX& a, int d) {
    int i, j, k, n = a.size(), m = a[0].size();
    for (i = 0; i < min(n, d); i++) {
        if (!a[i][i]) {
            for (j = i + 1; j < n; j++) {
                if (a[j][i]) {
                    for (k = 0; k < m; k++) {
                        a[i][k] += a[j][k];
                        if (a[i][k] >= 5) {
                            a[i][k] -= 5;
                        }
                    }
                    break;
                }
            }
        }
        if (!a[i][i]) continue;
        int t = a[i][i];
        for (k = 0; k < m; k++) a[i][k] = mult(a[i][k], iv[t], 5);
        for (j = 0; j < n; j++) {
            if (j == i) continue;
            t = a[j][i];
            for (k = 0; k < m; k++) {
                a[j][k] -= a[i][k] * t % 5;
                if (a[j][k] < 0) {
                    a[j][k] += 5;
                }
            }
        }
    }
}

const int maxn = 1000 + 5;
int n, m, q;
int a[maxn][maxn];
int b[maxn][maxn];

void solve() {
    FOR(i, 1, 5) iv[i] = inv(i, 5);
    cin >> n >> m;
    FOR(i, 0, n) {
        string s; cin >> s;
        FOR(j, 0, m) a[j][i] = s[j] - 'a';
    }
    cin >> q;
    FOR(i, 0, q) {
        string s; cin >> s;
        FOR(j, 0, m) b[i][j] = s[j] - 'a';
    }
    MATRIX mat(m, ROW(n + q));
    FOR(i, 0, m) {
        FOR(j, 0, n) mat[i][j] = a[i][j];
        FOR(j, 0, q) mat[i][n + j] = b[j][i];
    }
    gauss(mat, n);
    FOR(k, 0, q) {
        int found = 0, rk = 0;
        FOR(i, 0, m) {
            int tot = 0;
            FOR(j, 0, n) tot += mat[i][j];
            if (!tot && mat[i][n + k]) {
                found = 1;
                break;
            }
            if (tot) rk++;
        }
        if (found) {
            cout << 0 << "\n";
            continue;
        }
        cout << fpow(5, n - rk) << "\n";
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