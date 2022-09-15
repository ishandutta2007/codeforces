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

void transform(int a[], int n, int p, int invert) {
    int k = __lg(n);
    FOR(i, 0, k) {
        FOR(msk, 0, n) if (bit(msk, i)) {
            int pmsk = msk ^ (1 << i);
            if (!invert) {
                addmod(a[msk], a[pmsk], p);
            }
            else {
                submod(a[msk], a[pmsk], p);
            }
        }
    }
}

vector<int> pow_convol(vector<int> a, int k, int p) {
    int n = a.size();
    if (k == 1) {
        return a;
    }
    else if (k & 1) {
        vector<int> r = pow_convol(a, k - 1, p);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                res[i + j] = (res[i + j] + (long long) r[i] * a[j]) % p;
            }
        }
        return res;
    }
    else {
        vector<int> r = pow_convol(a, k >> 1, p);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                res[i + j] = (res[i + j] + (long long) r[i] * r[j]) % p;
            }
        }
        return res;
    }
}

vector<int> subset_pow_convol(vector<int> a, int k, int p) {
    static const int logn = 19;
    static int fa[logn][1 << logn];
    static int fb[logn][1 << logn];
    static int fc[logn][1 << logn];
    int n = a.size();
    while (n != (n & -n)) n += n & -n; 
    vector<int> res(n, 0);
    for (int i = 0; i < logn; i++) {
        for (int j = 0; j < n; j++) {
            if (bitcount(j) == i) {
                fa[i][j] = j < sz(a) ? a[j] : 0;
            }
            else {
                fa[i][j] = 0;
            }
            fc[i][j] = 0;
        }
        transform(fa[i], n, p, 0);
    }
    FOR(i, 0, n) {
        vi va(logn);
        FOR(j, 0, logn) {
            va[j] = fa[j][i];
        }
        va = pow_convol(va, k, p);
        FOR(j, 0, logn) {
            fc[j][i] = va[j];
        }
    }
    for (int i = 0; i < logn; i++) {
        transform(fc[i], n, p, 1);
        for (int j = 0; j < n; j++) if (bitcount(j) == i) {
            res[j] = fc[i][j];
        }
    }
    return res;
}

const int maxn = 1e6 + 5;
int n, k, p;
int fac[maxn];
int ifac[maxn];
int dp[2][maxn];
int f[maxn];

void solve() {
    cin >> n >> k >> p;
    int nn = n;
    FOR(i, 0, n + 1) if ((n & i) == i) {
        int t = 0;
        FOR(j, 0, 20) if (bit(n, j)) {
            t <<= 1;
            t |= bit(i, j);
        }
        f[t] = i;
        nn = t;
    }
    if (n & 1) {
        cout << fpow(k, n, p) << "\n";
        return;
    }
    fac[0] = 1; FOR(i, 1, maxn) fac[i] = mult(fac[i - 1], i, p);
    FOR(i, 0, maxn) ifac[i] = inv(fac[i], p);
    vi a(nn + 1, 0);
    FOR(i, 0, nn + 1) a[i] = ifac[f[i]];
    int res = fpow(k, n, p);
    a = subset_pow_convol(a, k, p);
    submod(res, mult(a[nn], fac[n], p), p);
    cout << res << "\n";
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