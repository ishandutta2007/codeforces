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

typedef double T;
const int MAXN = 1 << 20;
struct cplex {
    T r, i;
    cplex() : r(0), i(0) {}
    cplex(T n) : r(n), i(0) {}
    cplex(T r, T i) : r(r), i(i) {}
    T real() {return r;}
    cplex operator + (cplex b) {return cplex (r + b.r, i + b.i);}
    cplex operator += (cplex b) {r += b.r, i += b.i; return *this;}
    cplex operator - (cplex b) {return cplex(r - b.r, i - b.i);}
    cplex operator * (cplex b) {return cplex(r * b.r - i * b.i, r * b.i + i * b.r);}
    cplex operator *= (cplex b) {T r2 = r * b.r - i * b.i, i2 = r * b.i + i * b.r; r = r2, i = i2; return *this;}
    cplex operator /= (T n) {r /= n, i /= n; return *this;}
};
void fft(cplex a[], int n, int invert) {
    static T PI = 2 * acos((T) 0);
    for (int i = 1, j = 0; i < n; i++) {
        for (int s = n; j ^= s >>= 1, ~j & s;);
        if (i < j) swap(a[i], a[j]);
    }
    for (int m = 1; m < n; m <<= 1) {
        T p = PI / m * (invert ? -1 : 1);
        cplex w = cplex(cos(p), sin(p));
        for (int i = 0; i < n; i += m << 1) {
            cplex unit = 1;
            for (int j = 0; j < m; j++) {
                cplex& x = a[i + j + m], &y = a[i + j], t = unit * x;
                x = y - t;
                y = y + t;
                unit *= w;
            }
        }
    }
    if (invert) for (int i = 0; i < n; i++) a[i] /= n;
}
void multiply(int a[], int b[], long long c[], int na, int nb) {
    static cplex fa[MAXN << 1], fb[MAXN << 1];
    int n = 1; while (n < na + nb - 1) n <<= 1;
    for (int i = 0; i < n; i++) fa[i] = fb[i] = cplex(0);
    for (int i = 0; i < na; i++) fa[i] = cplex(a[i]);
    for (int i = 0; i < nb; i++) fb[i] = cplex(b[i]);
    fft(fa, n, 0); fft(fb, n, 0);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, n, 1);
    for (int i = 0; i < n; i++) c[i] = (long long) (fa[i].real() + 0.5);
}

const int maxn = 1 << 20;
int n;
int a[maxn];
int b[maxn];
long long c[maxn << 1];
int f[maxn];

void solve() {
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        string s; cin >> s;
        FOR(i, 0, n) a[i] = s[i] == 'V';
        b[0] = 0;
        FOR(i, 0, n) b[i + 1] = s[n - i - 1] == 'K';
        multiply(a, b, c, n, n + 1);
        FOR(i, 1, n + 1) f[i] = 0;
        FOR(i, 0, n + n) if (c[i]) {
            int x = abs(i - n);
            f[x] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j += i) if (f[j]) {
                f[i] = 1;
                break;
            }
        }
        vi res;
        FOR(i, 1, n + 1) if (!f[i]) res.pb(i);
        cout << sz(res) << "\n";
        FOR(i, 0, sz(res)) cout << res[i] << " \n"[i == sz(res) - 1];
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