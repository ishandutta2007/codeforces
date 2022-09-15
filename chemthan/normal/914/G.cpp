#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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

void XORFFT(int a[], int n, int p, int invert) {
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
/*
* Matrix:
* +1 +1
* +1 +0
*/
void ORFFT(int a[], int n, int p, int invert) {
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                int u = a[j + k], v = a[i + j + k];
                if (!invert) {
                    a[j + k] = u + v;
                    a[i + j + k] = u;
                    if (a[j + k] >= p) a[j + k] -= p;
                }
                else {
                    a[j + k] = v;
                    a[i + j + k] = u - v;
                    if (a[i + j + k] < 0) a[i + j + k] += p;
                }
            }
        }
    }
}
/*
* matrix:
* +0 +1
* +1 +1
*/
void ANDFFT(int a[], int n, int p, int invert) {
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                int u = a[j + k], v = a[i + j + k];
                if (!invert) {
                    a[j + k] = v;
                    a[i + j + k] = u + v;
                    if (a[i + j + k] >= p) a[i + j + k] -= p;
                }
                else {
                    a[j + k] = v - u;
                    if (a[j + k] < 0) a[j + k] += p;
                    a[i + j + k] = u;
                }
            }
        }
    }
}

void transform(int a[], int n, int p, int invert) {
    int k = __lg(n);
    FOR(i, 0, k) {
        FOR(msk, 0, n) if (bit(msk, i)) {
            int pmsk = msk ^ (1 << i);
            if (!invert) {
                addmod(a[msk], a[pmsk], p);
            }
            else {
                submod(a[msk], a[pmsk], p);
            }
        }
    }
}

vector<int> pow_convol(vector<int> a, int k, int p) {
    int n = a.size();
    if (k == 1) {
        return a;
    }
    else if (k & 1) {
        vector<int> r = pow_convol(a, k - 1, p);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                res[i + j] = (res[i + j] + (long long) r[i] * a[j]) % p;
            }
        }
        return res;
    }
    else {
        vector<int> r = pow_convol(a, k >> 1, p);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                res[i + j] = (res[i + j] + (long long) r[i] * r[j]) % p;
            }
        }
        return res;
    }
}

vector<int> subset_pow_convol(vector<int> a, int k, int p) {
    static const int logn = 19;
    static int fa[logn][1 << logn];
    static int fb[logn][1 << logn];
    static int fc[logn][1 << logn];
    int n = a.size();
    while (n != (n & -n)) n += n & -n;
    vector<int> res(n, 0);
    for (int i = 0; i < logn; i++) {
        for (int j = 0; j < n; j++) {
            if (bitcount(j) == i) {
                fa[i][j] = j < sz(a) ? a[j] : 0;
            }
            else {
                fa[i][j] = 0;
            }
            fc[i][j] = 0;
        }
        transform(fa[i], n, p, 0);
    }
    FOR(i, 0, n) {
        vi va(logn);
        FOR(j, 0, logn) {
            va[j] = fa[j][i];
        }
        va = pow_convol(va, k, p);
        FOR(j, 0, logn) {
            fc[j][i] = va[j];
        }
    }
    for (int i = 0; i < logn; i++) {
        transform(fc[i], n, p, 1);
        for (int j = 0; j < n; j++) if (bitcount(j) == i) {
            res[j] = fc[i][j];
        }
    }
    return res;
}

const int maxn = 1 << 17;
int n;
int a[maxn];
int b[maxn];
int c[maxn];
int fib[maxn];

void testOR() {
    vi va; FOR(i, 0, maxn) va.pb(a[i]);
    va = subset_pow_convol(va, 2, MOD);
    FOR(i, 0, maxn) b[i] = va[i];
}
void testXOR() {
    static int fa[maxn];
    FOR(i, 0, maxn) fa[i] = a[i];
    XORFFT(fa, maxn, MOD, 0);
    for (int i = 0; i < maxn; i++) fa[i] = (long long) fa[i] * fa[i] % MOD;
    XORFFT(fa, maxn, MOD, 1);
    FOR(i, 0, maxn) c[i] = fa[i];
}
void testAND() {
    FOR(i, 0, maxn) {
        a[i] = mult(a[i], fib[i]);
        b[i] = mult(b[i], fib[i]);
        c[i] = mult(c[i], fib[i]);
    }
    ANDFFT(a, maxn, MOD, 0);
    ANDFFT(b, maxn, MOD, 0);
    ANDFFT(c, maxn, MOD, 0);
    FOR(i, 0, maxn) a[i] = mult(a[i], mult(b[i], c[i]));
    ANDFFT(a, maxn, MOD, 1);
}

void chemthan() {
    fib[0] = 0, fib[1] = 1;
    FOR(i, 2, maxn) fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    cin >> n;
    FOR(i, 0, n) {
        int x; cin >> x;
        a[x]++;
    }
    testOR(), testXOR(), testAND();
    int res = 0;
    FOR(i, 0, maxn) if (bitcount(i) == 1) {
        addmod(res, a[i]);
    }
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
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}