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
int n;
int a[maxn];

int ispr(int k) {
    FOR(i, 2, k) if (k % i == 0) return 0;
    return 1;
}

void solve() {
    vi pr; FOR(i, 2, 70) if (ispr(i)) pr.pb(i);
    cin >> n;
    map<int, int> hs;
    FOR(i, 0, n) {
        int x; cin >> x;
        FOR(j, 0, sz(pr)) if (x % pr[j] == 0) {
            while (x % pr[j] == 0) a[i] ^= 1 << j, x /= pr[j];
        }
        hs[a[i]]++;
    }
    vii vals;
    for (auto it : hs) {
        vals.pb(it);
    }
    int m = sz(vals) / 2, m2 = sz(vals) - m;
    int t1 = 1, t2 = 1;
    FOR(i, 0, m) {
        t1 = mult(t1, fpow(2, vals[i].se - 1));
    }
    FOR(i, m, sz(vals)) {
        t2 = mult(t2, fpow(2, vals[i].se - 1));
    }
    static int f[1 << 22];
    static int c[1 << 22];
    FOR(msk, 0, 1 << m) {
        if (msk) {
            int k = __lg(msk);
            f[msk] = f[msk ^ (1 << k)] ^ vals[k].fi;
        }
        addmod(c[f[msk]], t1);
    }
    int res = 0;
    FOR(msk, 0, 1 << m2) {
        if (msk) {
            int k = __lg(msk);
            f[msk] = f[msk ^ (1 << k)] ^ vals[k + m].fi;
        }
        addmod(res, mult(t2, c[f[msk]]));
    }
    submod(res, 1);
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
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}