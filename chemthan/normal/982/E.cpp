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

template<class T> struct ChineseRemainder {
    static const int MAXN = 1e5 + 5;
    int n;
    T p[MAXN], r[MAXN];
    T b[MAXN], x[MAXN];

    void init() {
        n = 0;
    }
    void add(T pr, T rm) {
        p[n] = pr, r[n++] = rm;
    }
    T mulmod(T a, T b, T p) {
    	a %= p, b %= p;
    	T q = (T) ((long double) a * b / p);
        T r = a * b - q * p;
        while (r < 0) r += p;
        while (r >= p) r -= p;
        return r;
    }
    pair<T, T> euclid(T a, T b) {
    	if (!b) return make_pair(1, 0);
    	pair<T, T> r = euclid(b, a % b);
    	return make_pair(r.second, r.first - a / b * r.second);
    }
    T calc() {
    	T M = 1;
    	for (int i = 0; i < n; i++) M *= p[i];
    	T N = 0;
    	for (int i = 0; i < n; i++) {
    		b[i] = M / p[i];
    		x[i] = (euclid(b[i], p[i]).first % p[i] + p[i]) % p[i];
    		N += mulmod(r[i] * b[i], x[i], M);
    		if (N >= M) N -= M;
    	}
    	return N;
    }
};
ChineseRemainder<long long> crt;


void chemthan() {
    int n, m, x, y, vx, vy; cin >> n >> m >> x >> y >> vx >> vy;
    if (vx == 0) {
        if (!x || x == n) {
            if (vy > 0) {
                cout << x << " " << m << "\n";
            }
            else {
                cout << x << " " << 0 << "\n";
            }
        }
        else {
            cout << -1 << "\n";
        }
        return;
    }
    if (vy == 0) {
        if (!y || y == m) {
            if (vx > 0) {
                cout << n << " " << y << "\n";
            }
            else {
                cout << 0 << " " << y << "\n";
            }
        }
        else {
            cout << -1 << "\n";
        }
        return;
    }
    int rn = (long long) (n - x % n) * (vx + n) % n;
    int rm = (long long) (m - y % m) * (vy + m) % m;
    assert((x + rn * vx) % n == 0);
    assert((y + rm * vy) % m == 0);
    int g = __gcd(n, m);
    if (rn % g != rm % g) {
        cout << -1 << "\n";
        return;
    }
    int N = n, M = m;
    map<int, int> dvsn, dvsm, com;
    for (int i = 2; i * i <= n; i++) {
        int num = 0;
        while (n % i == 0) {
            num++, n /= i;
        }
        if (num > 0) {
            dvsn[i] = num;
            com[i];
        }
    }
    if (n > 1) {
        dvsn[n] = 1;
        com[n];
    }
    for (int i = 2; i * i <= m; i++) {
        int num = 0;
        while (m % i == 0) {
            num++, m /= i;
        }
        if (num > 0) {
            dvsm[i] = num;
            com[i];
        }
    }
    if (m > 1) {
        dvsm[m] = 1;
        com[m];
    }
    long long prd = 1;
    for (auto it : com) {
        int p = it.fi;
        int nn = dvsn[p];
        int nm = dvsm[p];
        if (nn > nm) {
            crt.add(fpow(p, nn), rn % fpow(p, nn));
            prd *= fpow(p, nn);
        }
        else {
            crt.add(fpow(p, nm), rm % fpow(p, nm));
            prd *= fpow(p, nm);
        }
    }
    long long t = crt.calc();
    t = (t % prd + prd) % prd;
    long long u = x + t * vx;
    long long v = y + t * vy;
    n = N, m = M;
    assert(u % n == 0 && v % m == 0);
    u /= n, v /= m;
    int cx = 0, cy = 0;
    if (u % 2) cx = n;
    if (v % 2) cy = m;
    cout << cx << " " << cy << "\n";
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