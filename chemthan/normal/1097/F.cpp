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
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

#define BS BitSet
#define num_t unsigned long long
#define WS 6
#define MS 63
const num_t unit = (num_t) 1;
struct BitSet {
    int n;
    num_t* mem;

    BitSet() {
        n = 0;
    }
    BitSet(int len) {
        n = len + MS >> WS;
        mem = (num_t*) calloc(n, sizeof(num_t));
    }
    BitSet(const BitSet& rhs) {
        if (n) {
            free(mem);
        }
        n = rhs.n;
        mem = (num_t*) malloc(sizeof(num_t) * n);
        memcpy(mem, rhs.mem, sizeof(num_t) * n);
    }
    ~BitSet() {
        if (n) {
            free(mem);
        }
    }
    BitSet& operator = (const BitSet& rhs) {
        if (n) {
            free(mem);
        }
        n = rhs.n;
        mem = (num_t*) malloc(sizeof(num_t) * n);
        memcpy(mem, rhs.mem, sizeof(num_t) * n);
        return *this;
    }
    void resize(int len) {
        int nn = len + MS >> WS;
        num_t* nmem = (num_t*) calloc(nn, sizeof(num_t));
        memcpy(nmem, mem, sizeof(num_t) * min(n, nn));
        if (n) {
            free(mem);
        }
        n = nn, mem = nmem;
    }
    inline int get(int k) {
        if (n <= (k >> WS)) return 0;
        return (mem[k >> WS] >> (k & MS)) & 1;
    }
    inline void set(int k, int v) {
        if (n <= (k >> WS)) return;
        ((mem[k >> WS] |= unit << (k & MS)) ^= unit << (k & MS)) |= v * (unit << (k & MS));
    }
    inline void reset(int v = 0) {
        memset(mem, !v ? 0 : -1, sizeof(num_t) * n);
    }
    inline int count() {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += __builtin_popcountll(mem[i]);
        }
        return res;
    }
#define MAKE(OP)\
    BitSet operator OP (const BitSet& rhs) const {\
        int mx = max(n, rhs.n);\
        BitSet res(mx << WS);\
        memcpy(res.mem, mem, sizeof(num_t) * n);\
        for (int i = 0; i < rhs.n; i++) {\
            res.mem[i] = res.mem[i] OP rhs.mem[i];\
        }\
        return res;\
    }
    MAKE(&) MAKE(|) MAKE(^)
};

const int maxn = 7000 + 5;
int sp[maxn];
int mob[maxn];
BS g[maxn];
BS h[maxn];
BS f[100005];

void chemthan() {
    FOR(i, 0, maxn) {
        g[i].resize(maxn);
        h[i].resize(maxn);
    }
    FOR(i, 0, 100005) {
        f[i].resize(maxn);
    }
    FOR(i, 1, maxn) {
        sp[i] = i;
    }
    FOR(i, 2, maxn) if (sp[i] == i) {
        for (int j = i + i; j < maxn; j += i) {
            chkmin(sp[j], i);
        }
    }
    FOR(i, 1, maxn) {
        int t = i, pv = -1;
        mob[i] = 1;
        while (t > 1) {
            if (sp[t] == pv) {
                mob[i] = 0;
            }
            pv = sp[t];
            t /= pv;
        }
    }
    FOR(i, 1, maxn) {
        for (int j = i; j < maxn; j += i) {
            g[i].set(j, mob[j / i]);
            h[j].set(i, 1);
        }
    }
    int n, q; cin >> n >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, v; cin >> x >> v; x--;
            f[x] = h[v];
        }
        else if (op == 2) {
            int x, y, z; cin >> x >> y >> z; x--, y--, z--;
            f[x] = f[y] ^ f[z];
        }
        else if (op == 3) {
            int x, y, z; cin >> x >> y >> z; x--, y--, z--;
            f[x] = f[y] & f[z];
        }
        else {
            int x, v; cin >> x >> v; x--;
            int res = (f[x] & g[v]).count() & 1;
            cout << res;
        }
    }
    cout << "\n";
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