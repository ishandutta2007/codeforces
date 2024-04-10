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
const int MOD = 119 << 23 | 1;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-6;
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

void XORFFT(vi& a, int n, int p, int invert) {
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                int u = a[j + k], v = a[i + j + k];
                a[j + k] = u + v;
                if (a[j + k] >= p) a[j + k] -= p;
                a[i + j + k] = u - v;
                if (a[i + j + k] < 0) a[i + j + k] += p;
            }
        }
    }
    if (invert) {
        long long inv = fpow(n, p - 2, p);
        for (int i = 0; i < n; i++) a[i] = a[i] * inv % p;
    }
}

inline void add(long long x, vector<long long>& v) {
    auto func = [&] (long long x) {
        return 1LL << __lg(x);
    };
    for (int i = 0; i < v.size(); i++) {
        if (func(v[i]) & x) x ^= v[i];
    }
    if (!x) return;
    for (int i = 0; i < v.size(); i++) {
        if (func(x) & v[i]) v[i] ^= x;
    }
    v.push_back(x);
}

void chemthan() {
    int n, m; cin >> n >> m;
    vector<long long> base;
    FOR(i, 0, n) {
        long long x; cin >> x;
        add(x, base);
    }
    int t = fpow(2, n - sz(base));
    sort(all(base)), reverse(all(base));
    if (sz(base) <= 23) {
        vector<long long> f(1 << sz(base));
        FOR(msk, 1, 1 << sz(base)) {
            int k = __lg(msk);
            int pmsk = msk ^ (1 << k);
            f[msk] = f[pmsk] ^ base[k];
        }
        vi res(m + 1);
        FOR(i, 0, sz(f)) {
            int k = bitcount(f[i]);
            addmod(res[k], t);
        }
        FOR(i, 0, m + 1) cout << res[i] << " \n"[i == m];
        return;
    }
    vi f(m);
    for (auto x : base) {
        int k = __lg(x);
        f[k] = 1;
    }
    vi dc;
    for (auto& x : base) {
        FOR(i, 0, m) if (f[i]) {
            if (bit(x, i)) {
                x -= 1LL << i;
            }
        }
        FOR(i, 0, m) if (bit(x, i)) {
            dc.pb(i);
        }
    }
    sort(all(dc)), uni(dc);
    int k = sz(dc);
    vector<vi> vals(sz(base) + 1, vi(1 << k));
    vals[0][0] = 1;
    XORFFT(vals[0], 1 << k, MOD, 0);
    for (auto& x : base) {
        long long y = 0;
        FOR(i, 0, m) if (bit(x, i)) {
            int ii = lower_bound(all(dc), i) - dc.begin();
            y |= 1 << ii;
        }
        vi tmp(1 << k);
        tmp[y] = 1;
        XORFFT(tmp, 1 << k, MOD, 0);
        FORd(j, sz(base), 0) {
            FOR(l, 0, 1 << k) {
                addmod(vals[j + 1][l], mult(vals[j][l], tmp[l]));
            }
        }
    }
    vi res(m + 1);
    FOR(i, 0, sz(base) + 1) {
        XORFFT(vals[i], 1 << k, MOD, 1);
        FOR(j, 0, 1 << k) {
            int d = bitcount(j) + i;
            if (vals[i][j]) {
                addmod(res[d], vals[i][j]);
            }
        }
    }
    FOR(i, 0, m + 1) {
        cout << mult(t, res[i]) << " \n"[i == m];
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