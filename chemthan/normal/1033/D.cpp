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
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}

template<class T> T mulmod(T a, T b, T p) {
    a %= p; b %= p;
    T q = (T) ((long double) a * b / p);
    T r = a * b - q * p;
    while (r < 0) r += p;
    while (r >= p) r -= p;
    return r;
}
template<class T> T powmod(T n, T k, T p) {
    if (!n) return 0;
    T r = 1;
    for (; k; k >>= 1) {
        if (k & 1) r = mulmod(r, n, p);
        n = mulmod(n, n, p);
    }
    return r;
}
template<class T> int rabin(T n) {
    if (n == 2) return 1;
    if (n < 2 || !(n & 1)) return 0;
    const T p[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    T a, d = n - 1, mx = 9;
    int i, r, s = 0;
    while (!(d & 1)) {++s; d >>= 1;}
    for (i = 0; i < mx; i++) {
        if (n == p[i]) return 1;
        if (!(n % p[i])) return 0;
        a = powmod(p[i], d, n);
        if (a != 1) {
            for (r = 0; r < s && a != n - 1; r++) a = mulmod(a, a, n);
            if (r == s) return 0;
        }
    }
    return 1;
}

const int maxn = 500 +5;
const int mod = 998244353;
int n;
long long a[maxn];

int calc(long long x, int k) {
    long long xx = isqrt(x);
    long long xxx = icbrt(x);
    long long xxxx = isqrt(xx);
    if (xxxx * xxxx * xxxx * xxxx == x) {
        return 4 * k + 1;
    }
    if (xxx * xxx * xxx == x) {
        return 3 * k + 1;
    }
    if (xx * xx == x) {
        return 2 * k + 1;
    }
    if (rabin(x)) {
        return k + 1;
    }
    return (k + 1) * (k + 1);
}

void chemthan() {
    cin >> n;
    vector<long long> dvs;
    FOR(i, 0, n) {
        cin >> a[i];
        dvs.pb(a[i]);
    }
    while (1) {
        sort(all(dvs)), uni(dvs);
        int found = 0;
        FOR(i, 0, sz(dvs)) {
            FOR(j, i + 1, sz(dvs)) {
                long long g  = __gcd(dvs[i], dvs[j]);
                if (g > 1) {
                    dvs[i] /= g;
                    dvs[j] /= g;
                    dvs.pb(g);
                    found = 1;
                }
            }
        }
        if (!found) break;
    }
    dvs.pb(1);
    sort(all(dvs)), uni(dvs);
    reverse(all(dvs));
    dvs.pop_back();
    reverse(all(dvs));
    vector<long long> facs;
    FOR(i, 0, sz(dvs)) {
        int ok = 1;
        FOR(j, 0, i) {
            if (dvs[i] % dvs[j] == 0) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            facs.pb(dvs[i]);
        }
    }
    map<long long, int> hs;
    FOR(i, 0, n) {
        for (long long x : facs) {
            int cnt = 0;
            while (a[i] % x == 0) a[i] /= x, cnt++;
            if (cnt) hs[x] += cnt;
        }
    }
    int res = 1;
    for (auto it : hs) {
        res = mult(res, calc(it.fi, it.se), mod);
    }
    cout << res << "\n";
    cout.flush();
}

int main(int argc, char* argv[]) {
    //ios_base::sync_with_stdio(0), cin.tie(0);
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