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
const ld EPS = 1e-6;
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

template<class T, class cmp = less<T> > struct RMQ {
    int n;
    vector<T> a;
    vector<vector<T> > f;

    T best(T a, T b) {
        return __gcd(a, b);
    }
    void init(int n) {
        this->n = n;
        int p = 1; while ((1 << p) < n) p++;
        a.resize(n), f.resize(p + 1);
        for (int i = 0; i < (int) f.size(); i++) {
            f[i].resize(n);
        }
    }
    void upd(int u, T x) {
        a[u] = x;
    }
    void build() {
        for (int i = 0; i < n; i++) f[0][i] = a[i];
        for (int l = 0, k; (k = 1 << l) < n; l++) {
            for (int i = 0; i + k < n; i++) {
                f[l + 1][i] = best(f[l][i], f[l][i + k]);
            }
        }
    }
    T query(int a, int b) {
        int l = a == b ? 0 : __lg(b - a);
        return best(f[l][a], f[l][b - (1 << l) + 1]);
    }
};
RMQ<int> rmq;

const int maxn = 2000 + 5;
int n;
int a[maxn];

void solve() {
    cin >> n;
    int g = 0;
    rmq.init(n);
    FOR(i, 0, n) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        rmq.upd(i, a[i]);
    }
    if (*min_element(a, a + n) == 1) {
        int res = 0;
        FOR(i, 0, n) if (a[i] != 1) {
            res++;
        }
        cout << res << "\n";
        return;
    }
    rmq.build();
    if (g != 1) {
        cout << -1 << "\n";
        return;
    }
    int mn = n;
    FOR(i, 0, n) {
        int lo = i, hi = n;
        while (lo < hi) {
            int mi = lo + hi >> 1;
            if (rmq.query(i, mi) > 1) {
                lo = mi + 1;
            }
            else {
                hi = mi;
            }
        }
        int mi = lo + hi >> 1;
        if (mi == n) continue;
        chkmin(mn, mi - i + 1);
    }
    cout << mn + n - 2 << "\n";
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