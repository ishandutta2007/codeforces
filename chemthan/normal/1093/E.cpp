#include <bits/stdc++.h>
using namespace std; //#pragma GCC optimize("Ofast")
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
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 2e5 + 5;
const int magic = 500;
int n, m;
int a[maxn];
int b[maxn];
int f[maxn];
vi g[magic];

int query(int l, int r, int x, int y) {
    int res = 0;
    int il = (l + magic - 1) / magic;
    int ir = r / magic;
    FOR(i, il, ir) {
        res += upper_bound(all(g[i]), y) - lower_bound(all(g[i]), x);
    }
    FOR(i, l, min(il * magic, r + 1)) {
        if (x <= b[i] && b[i] <= y) {
            res++;
        }
    }
    if (il <= ir) {
        FOR(i, max(l, ir * magic), r + 1) {
            if (x <= b[i] && b[i] <= y) {
                res++;
            }
        }
    }
    return res;
}

void upd(int x, int y) {
    int ix = x / magic;
    int iy = y / magic;
    int k = lower_bound(all(g[ix]), b[x]) - g[ix].begin();
    assert(g[ix][k] == b[x]);
    swap(g[ix][k], g[ix].back());
    g[ix].pop_back();
    g[ix].pb(b[y]), sort(all(g[ix]));
    int l = lower_bound(all(g[iy]), b[y]) - g[iy].begin();
    assert(g[iy][l] == b[y]);
    swap(g[iy][l], g[iy].back());
    g[iy].pop_back();
    g[iy].pb(b[x]), sort(all(g[iy]));
    swap(b[x], b[y]);
}

void chemthan() {
    cin >> n >> m;
    FOR(i, 0, n) cin >> a[i], a[i]--, f[a[i]] = i;
    FOR(i, 0, n) {
        cin >> b[i], b[i]--, b[i] = f[b[i]];
        g[i / magic].pb(b[i]);
    }
    FOR(i, 0, magic) sort(all(g[i]));
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l[2], r[2];
            FOR(i, 0, 2) cin >> l[i] >> r[i], l[i]--, r[i]--;
            cout << query(l[1], r[1], l[0], r[0]) << "\n";
        }
        else {
            int u, v; cin >> u >> v; u--, v--;
            upd(u, v);
        }
    }
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