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
//const int MOD = (int) 1e9 + 7;
const int MOD = 998244353;
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

const int maxn = 5000 + 5;
const int mod = 998244353;
int c[maxn][maxn];
int fac[maxn];
int n;
vi a, b;
int cnt[11];

int ff(int x) {
    int res = 0;
    while (x) {
        res++, x /= 10;
    }
    return res;
}

void fft(int a[], int p, int r, int n) {
    for (int m = n, h; h = m / 2, m >= 2; r = (long long) r * r % p, m = h) {
        for (int i = 0, w = 1; i < h; i++, w = (long long) w * r % p) {
            for (int j = i; j < n; j += m) {
                int k = j + h;
                int x = a[j] - a[k];
                if (x < 0) x += p;
                a[j] += a[k];
                if (a[j] >= p) a[j] -= p;
                a[k] = (long long) w * x % p;
            }
        }
    }
    for (int i = 0, j = 1; j < n - 1; j++) {
        for (int k = n / 2; k > (i ^= k); k /= 2);
        if (j < i) swap(a[i], a[j]);
    }
}
void multiply(int a[], int b[], int c[], int na, int nb, int p, int prt) {
    static int fa[1 << 20], fb[1 << 20];
    int len = na + nb - 1;
    int k = 0; while ((1 << k) < na + nb - 1) k++;
    for (int i = 0; i < (1 << k); i++) fa[i] = fb[i] = 0;
    for (int i = 0; i < na; i++) fa[i] = a[i];
    for (int i = 0; i < nb; i++) fb[i] = b[i];
    int w = fpow(prt, (p - 1) / (1 << k), p);
    fft(fa, p, w, 1 << k);
    fft(fb, p, w, 1 << k);
    for (int i = 0; i < (1 << k); i++) c[i] = mult(fa[i], fb[i], p);
    fft(c, p, inv(w, p), 1 << k);
    int rem = inv(1 << k, p);
    for (int i = 0; i < (1 << k); i++) c[i] = mult(c[i], rem, p);
}
vi multiply(vi a, vi b) {
    static int fa[1 << 20], fb[1 << 20], fc[1 << 20];
    int na = sz(a), nb = sz(b);
    FOR(i, 0, na) fa[i] = a[i];
    FOR(i, 0, nb) fb[i] = b[i];
    multiply(fa, fb, fc, na, nb, mod, 3);
    vi res;
    FOR(i, 0, na + nb - 1) res.pb(fc[i]);
    return res;
}

vi sol(vi a) {
    fill_n(cnt, 11, 0);
    FOR(i, 0, sz(a)) {
        int x = a[i];
        cnt[x]++;
    }
    vi res;
    res.pb(1);
    FOR(i, 0, 11) {
        int k = cnt[i];
        vi poly((k + 1) * 121);
        FOR(j, 0, k + 1) {
            int d = j * 121 + i * j % 11;
            poly[d] = c[j][k];
        }
        res = multiply(res, poly);
    }
    return res;
}

void solve() {
    FOR(i, 0, maxn) c[0][i] = 1;
    FOR(i, 1, maxn) FOR(j, 1, maxn) c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % mod;
    fac[0] = 1; FOR(i, 1, maxn) fac[i] = mult(fac[i - 1], i, mod);
    int test; cin >> test;
    while (test--) {
        cin >> n;
        a.clear(), b.clear();
        int sum = 0, sum2 = 0, z = 0;
        FOR(i, 0, n) {
            int x; cin >> x;
            if (ff(x) & 1) {
                a.pb(x % 11);
                sum = (sum + x) % 11;
            }
            else {
                b.pb(x % 11);
                sum2 = (sum2 + x) % 11;
            }
        }
        vi va = sol(a);
        vi vb = sol(b);
        int k = sz(a) + 1 >> 1;
        int l = sz(a) + 0 >> 1;
        int p = sz(a) + 2 >> 1;
        int q = sz(a) + 1 >> 1;
        vi vc(11);
        FOR(i, 0, sz(vb)) if (vb[i]) {
            int x = i / 121;
            int y = sz(b) - x;
            int r = (2 * i - sum2 + 11) % 11;
            int t = 1;
            if (x) {
                t = mult(t, mult(c[x][p + x - 1], fac[x], mod), mod);
            }
            if (y) {
                t = mult(t, mult(c[y][q + y - 1], fac[y], mod), mod);
            }
            t = mult(t, vb[i], mod);
            addmod(vc[r], t, mod);
        }
        int res = 0;
        FOR(i, 0, sz(va)) {
            int kk = i / 121;
            int rr = (11 - (2 * i - sum) % 11 + 11) % 11;
            if (kk == k) {
                int t = mult(vc[rr], va[i], mod);
                t = mult(t, fac[k], mod);
                t = mult(t, fac[l], mod);
                addmod(res, t, mod);
            }
        }
        cout << res << "\n";
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