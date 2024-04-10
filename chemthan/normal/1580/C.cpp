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
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n"; 

const int magic = 500;
struct RangeQuery {
    static const int maxn = 2e5 + 5;
    int a[maxn];
    int b[maxn];
    int block[magic];
    vector<int> his;

    void clear() {
        while (his.size()) {
            int k = his.back();
            a[k] = b[k] = block[k / magic] = 0;
            his.pop_back();
        }
    }
    void upd(int n, int val) {
        if (!(b[n]++)) {
            his.push_back(n);
        }
        a[n] += val;
        block[n / magic] += val;
    }
    int query(int l, int r) {
        int res = 0;
        int u = l / magic;
        int v = r / magic;
        for (int i = u + 1; i < v; i++) {
            res += block[i];
        }
        for (int i = l; i <= min(r, (u + 1) * magic - 1); i++) {
            res += a[i];
        }
        if (u < v) {
            for (int i = max(l, v * magic); i <= r; i++) {
                res += a[i];
            }
        }
        return res;
    }
} rq;

void chemthan() {
    int n, m; cin >> n >> m;
    vii a(n);
    FOR(i, 0, n) cin >> a[i].fi >> a[i].se;
    vector<vi> f(magic, vi(magic));
    auto upd = [&] (int t, int u, int s) {
        int x = a[u].fi;
        int y = a[u].se;
        if (magic <= x + y) {
            for (int st = t + x; st <= m; st += x + y) {
                int ed = min(m + 1, st + y);
                rq.upd(st, +s);
                rq.upd(ed, -s);
            }
        }
        else {
            FOR(i, 0, y) {
                int r = (t + x + i) % (x + y);
                f[x + y][r] += s;
            }
        }
    };
    auto query = [&] (int t) {
        int res = rq.query(0, t);
        FOR(i, 1, magic) {
            res += f[i][t % i];
        }
        return res;
    };
    vi d(m + 1);
    FOR(i, 1, m + 1) {
        int op, k; cin >> op >> k; k--;
        if (op == 1) {
            upd(d[k] = i, k, 1);
        }
        else {
            upd(d[k], k, -1);
        }
        cout << query(i) << "\n";
    }
}

int32_t main(int32_t argc, char* argv[]) {
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