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
    int n, len;
    num_t* mem;

    BitSet() {
        n = 0;
    }
    BitSet(int _len) {
        n = _len + MS >> WS;
        len = n << WS;
        mem = (num_t*) calloc(n, sizeof(num_t));
    }
    BitSet(const BitSet& rhs) {
        n = rhs.n;
        len = rhs.len;
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
        len = rhs.len;
        mem = (num_t*) malloc(sizeof(num_t) * n);
        memcpy(mem, rhs.mem, sizeof(num_t) * n);
        return *this;
    }
    BitSet operator >> (const int k) {
        BitSet res(len);
        int d = k >> WS;
        int r = k & MS;
        num_t msk = (unit << r) - 1;
        int shift = MS - r + 1;
        for (int i = 0; i < n - d - 1; i++) {
            res.mem[i] = ((mem[i + d + 1] & msk) << shift) | (mem[i + d] >> r);
        }
        if (d < n) {
            res.mem[n - d - 1] = mem[n - 1] >> r;
        }
        return res;
    }
    BitSet& operator >>= (const int k) {
        int d = k >> WS;
        int r = k & MS;
        num_t msk = (unit << r) - 1;
        int shift = MS - r + 1;
        for (int i = 0; i < n - d - 1; i++) {
            mem[i] = ((mem[i + d + 1] & msk) << shift) | (mem[i + d] >> r);
        }
        if (d < n) {
            mem[n - d - 1] = mem[n - 1] >> r;
        }
        memset(mem + n - d, 0, sizeof(num_t) * d);
        return *this;
    }
    BitSet operator << (const int k) {
        BitSet res(len);
        int d = k >> WS;
        int r = k & MS;
        num_t msk = ((unit << r) - 1) << MS - r + 1;
        int shift = MS - r + 1;
        for (int i = d + 1; i < n; i++) {
            res.mem[i] = (mem[i - d] << r) | ((mem[i - d - 1] & msk) >> shift);
        }
        if (d < n) {
            res.mem[d] = mem[0] << r;
        }
        return res;
    }
    BitSet& operator <<= (const int k) {
        int d = k >> WS;
        int r = k & MS;
        num_t msk = ((unit << r) - 1) << MS - r + 1;
        int shift = MS - r + 1;
        for (int i = n; i > d; i--) {
            mem[i] = (mem[i - d] << r) | ((mem[i - d - 1] & msk) >> shift);
        }
        if (d < n) {
            mem[d] = mem[0] << r;
        }
        memset(mem, 0, sizeof(num_t) * d);
        return *this;
    }
    BitSet gets(int l, int r) {
        BitSet res(len);
        int x = l + MS >> WS;
        int y = r >> WS;
        if (x <= y) {
            memcpy(res.mem + x, mem + x, sizeof(num_t) * (y - x));
        }
        for (int i = l; i < min(x << WS, r + 1); i++) {
            res.set(i, get(i));
        }
        if (x <= y) {
            for (int i = (y << WS); i <= r; i++) {
                res.set(i, get(i));
            }
        }
        return res;
    }
    void resize(int _len) {
        int nn = _len + MS >> WS;
        if (n ^ nn) {
            int nlen = nn << WS;
            num_t* nmem = (num_t*) calloc(nn, sizeof(num_t));
            memcpy(nmem, mem, sizeof(num_t) * min(n, nn));
            if (n) {
                free(mem);
            }
            n = nn, len = nlen, mem = nmem;
        }
    }
    inline int get(int k) {
        if (len <= k) return 0;
        return (mem[k >> WS] >> (k & MS)) & 1;
    }
    inline void set(int k, int v) {
        if (len <= k) return;
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
    inline int firstBit() {
        for (int i = 0; i < n; i++) {
            if (mem[i]) {
                return (i << WS) + __lg(mem[i] & -mem[i]);
            }
        }
        return len;
    }
    inline int lastBit() {
        for (int i = n - 1; i >= 0; i--) {
            if (mem[i]) {
                return (i << WS) + __lg(mem[i]);
            }
        }
        return -1;
    }
    inline int nextBit(int k) {
        k++;
        if (k < 0) k = 0;
        if (len <= k) return len;
        int d = k >> WS;
        int r = k & MS;
        num_t t = (mem[d] >> r) << r;
        if (t) {
            return (d << WS) + __lg(t & -t);
        }
        for (int i = d + 1; i < n; i++) {
            if (mem[i]) {
                return (i << WS) + __lg(mem[i] & -mem[i]);
            }
        }
        return len;
    }
    inline int prevBit(int k) {
        k--;
        if (k < 0) return -1;
        if (len <= k) k = len - 1;
        int d = k >> WS;
        int r = k & MS;
        num_t t = (mem[d] << MS - r) >> MS - r;
        if (t) {
            return (d << WS) + __lg(t);
        }
        for (int i = d - 1; i >= 0; i--) {
            if (mem[i]) {
                return (i << WS) + __lg(mem[i]);
            }
        }
        return -1;
    }
    friend ostream& operator << (ostream& os, const BitSet& bs) {
        for (int i = 0; i < bs.len; i++) {
            os << bs.mem[i];
        }
        return os;
    }
#define MAKE(OP)\
    BitSet operator OP (const BitSet& rhs) const {\
        int mx = max(len, rhs.len);\
        BitSet res(mx);\
        memcpy(res.mem, mem, sizeof(num_t) * n);\
        for (int i = 0; i < rhs.n % 4; i++) {\
            res.mem[i] = res.mem[i] OP rhs.mem[i];\
        }\
        for (int i = rhs.n % 4; i < rhs.n; i += 4) {\
            res.mem[i] = res.mem[i] OP rhs.mem[i];\
            res.mem[i + 1] = res.mem[i + 1] OP rhs.mem[i + 1];\
            res.mem[i + 2] = res.mem[i + 2] OP rhs.mem[i + 2];\
            res.mem[i + 3] = res.mem[i + 3] OP rhs.mem[i + 3];\
        }\
        return res;\
    }
#define MAKE2(OP)\
    BitSet& operator OP (const BitSet& rhs) {\
        int mx = max(len, rhs.len);\
        resize(mx);\
        for (int i = 0; i < rhs.n % 4; i++) {\
            mem[i] OP rhs.mem[i];\
        }\
        for (int i = rhs.n % 4; i < rhs.n; i += 4) {\
            mem[i] OP rhs.mem[i];\
            mem[i + 1] OP rhs.mem[i + 1];\
            mem[i + 2] OP rhs.mem[i + 2];\
            mem[i + 3] OP rhs.mem[i + 3];\
        }\
        return *this;\
    }
    MAKE(&) MAKE(|) MAKE(^) MAKE2(&=) MAKE2(|=) MAKE2(^=)
};

const int maxn = 1e4 + 5;
int n, q;
BS f(maxn);

void divide(int l, int r, BS can, vector<pair<pi, int> > events) {
    int m = l + r >> 1;
    vector<pair<pi, int> > levents, revents;
    for (auto it : events) {
        int u = it.fi.fi;
        int v = it.fi.se;
        int x = it.se;
        if (u <= l && r <= v) {
            can |= can << x;
        }
        else {
            if (u <= m) {
                levents.pb(it);
            }
            if (m + 1 <= v) {
                revents.pb(it);
            }
        }
    }
    if (l == r) {
        f |= can;
        return;
    }
    divide(l, m, can, levents);
    divide(m + 1, r, can, revents);
}

void chemthan() {
    cin >> n >> q;
    vector<pair<pi, int> > events;
    FOR(i, 0, q) {
        int l, r, x; cin >> l >> r >> x; l--, r--;
        events.pb(mp(mp(l, r), x));
    }
    BS can(maxn); can.set(0, 1);
    divide(0, n - 1, can, events);
    vi res;
    FOR(i, 1, n + 1) if (f.get(i)) res.pb(i);
    cout << sz(res) << "\n";
    FOR(i, 0, sz(res)) cout << res[i] << " \n"[i == sz(res) - 1];
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