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
#define chkpt cerr << "-----\n";

const int maxn = 2500 + 5;
int n, m, k;
int a[maxn][maxn];
int b[maxn][maxn];

long long divide(int n, int m, int px, int py, int t) {
    if (!n || !m) return 0;
    if (n == 1 && m == 1) {
        return (!t && a[px][py] == k) || (t && b[px][py] == k);
    }
    long long res = 0;
    int mid = n - 1 >> 1;
    static int up[maxn][maxn];
    static int dn[maxn][maxn];
    static int nup[maxn];
    static int ndn[maxn];
    fill_n(nup, m, 0), fill_n(ndn, m, 0);
    FOR(i, 0, n) FOR(j, 0, m) if ((!t && a[px + i][py + j]) || (t && b[px + i][py + j])) {
        if (i <= mid) {
            up[j][nup[j]++] = i;
        }
        else {
            dn[j][ndn[j]++] = i;
        }
    }
    FOR(i, 0, m) reverse(up[i], up[i] + nup[i]);
    FOR(i, 0, m) {
        static int vup[maxn];
        static int vdn[maxn];
        int nvup = 0;
        int nvdn = 0;
        FOR(j, i, m) {
            for (int l = 0; l < nup[j] && l < k + 1; l++) {
                int x = up[j][l];
                vup[nvup++] = x;
                FORd(p, nvup - 1, 0) {
                    if (vup[p] < vup[p + 1]) {
                        swap(vup[p], vup[p + 1]);
                    }
                }
                chkmin(nvup, k + 1);
            }
            for (int l = 0; l < ndn[j] && l < k + 1; l++) {
                int x = dn[j][l];
                vdn[nvdn++] = x;
                FORd(p, nvdn - 1, 0) {
                    if (vdn[p] > vdn[p + 1]) {
                        swap(vdn[p], vdn[p + 1]);
                    }
                }
                chkmin(nvdn, k + 1);
            }
            FOR(l, 0, min(nvup, k - 1)) {
                int x = l == nvup - 1 ? vup[l] + 1 : vup[l] - vup[l + 1];
                int p = k - l - 2;
                if (p >= nvdn) continue;
                int y = p == nvdn - 1 ? n - vdn[p] : vdn[p + 1] - vdn[p];
                res += x * y;
            }
            if (k) {
                if (nvup >= k) {
                    int x = k - 1 == nvup - 1 ? vup[k - 1] + 1 : vup[k - 1] - vup[k];
                    int y = nvdn ? vdn[0] - mid - 1 : n - mid - 1;
                    res += x * y;
                }
                if (nvdn >= k) {
                    int x = k - 1 == nvdn - 1 ? n - vdn[k - 1] : vdn[k] - vdn[k - 1];
                    int y = nvup ? mid - vup[0] : mid + 1;
                    res += x * y;
                }
            }
            else {
                int x = nvup ? mid - vup[0] : mid + 1;
                int y = nvdn ? vdn[0] - mid - 1 : n - mid - 1;
                res += x * y;
            }
        }
    }
    int n1 = mid + 1;
    int n2 = n - n1;
    res += divide(m, n1, py, px, !t);
    res += divide(m, n2, py, px + n1, !t);
    return res;
}

void solve() {
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 0, n) {
        static char s[maxn];
        scanf("%s", s);
        FOR(j, 0, m) a[i][j] = b[j][i] = s[j] == '1';
    }
    printf("%I64d\n", divide(n, m, 0, 0, 0));
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        //ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}