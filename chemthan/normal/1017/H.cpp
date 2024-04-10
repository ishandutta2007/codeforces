#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
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

const int maxn = 2e5 + 5;
int iv[maxn];
int fac[maxn];
int ifac[maxn];
int n, m, q;
int a[maxn];
vector<pair<pi, int> > que[maxn];
int f[maxn];
int g[maxn];
int res[maxn];

int num;
int den;
int cnt[maxn];

inline void add(int x) {
    num = (long long) num * (cnt[x]--) % MOD;
}

inline void rem(int x) {
    den = (long long) den * (++cnt[x]) % MOD;
}

inline long long gilbertOrder(int x, int y, int pow, int rotate) {
    if (!pow) return 0;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    long long subSquareSize = 1LL << (2 * pow - 2);
    long long res = seg * subSquareSize;
    long long add = gilbertOrder(nx, ny, pow - 1, nrot);
    res += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return res;
}

void work(int k) {
    if (!sz(que[k])) return;
    FOR(i, 0, m) g[i] = f[i] + k;
    long long s = 0;
    FOR(i, 0, m) s += g[i];
    static int x[maxn];
    x[0] = 1; FOR(i, 0, maxn - 1) x[i + 1] = mult(x[i], (s - i) % MOD);
    int magic = n / sqrt(sz(que[k])) + 1;
    sort(all(que[k]), [&] (pair<pi, int> a, pair<pi, int> b) {
            return gilbertOrder(a.fi.fi, a.fi.se, 17, 0) < gilbertOrder(b.fi.fi, b.fi.se, 17, 0);
            }
        );
    num = den = 1;
    fill_n(cnt, maxn, 0);
    FOR(i, 0, m) cnt[i] = g[i];
    int l = 0, r = -1;
    for (auto e : que[k]) {
        int u = e.fi.fi;
        int v = e.fi.se;
        int ix = e.se;
        int d = v - u + 1;
        while (l > u) add(a[--l]);
        while (r < v) add(a[++r]);
        while (l < u) rem(a[l++]);
        while (r > v) rem(a[r--]);
        res[ix] = mult(num, inv(den));
        res[ix] = mult(res[ix], x[n]);
        res[ix] = mult(res[ix], inv(x[d]));
    }
}

void chemthan() {
    FOR(i, 1, maxn) iv[i] = inv(i);
    fac[0] = 1; FOR(i, 1, maxn) fac[i] = mult(fac[i - 1], i);
    FOR(i, 0, maxn) ifac[i] = inv(fac[i]);
    cin >> n >> m >> q;
    FOR(i, 0, n) cin >> a[i], a[i]--, f[a[i]]++;
    FOR(i, 0, q) {
        int l, r, k; cin >> l >> r >> k; l--, r--;
        que[k].pb(mp(mp(l, r), i));
    }
    FOR(k, 0, maxn) work(k);
    FOR(i, 0, q) cout << res[i] << "\n";
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