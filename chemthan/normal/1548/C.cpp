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

struct Polynomial {
    //nirjhor's code
    static const int maxn = 1e7 + 5;
    static const int limit = 1e3;
    static const int mod = (int) 1e9 + 7;
    int deg;
    vector<int> cof;
    Polynomial(int deg = 0) : deg(deg){
        cof.resize(deg + 1, 0);
    }
    void init(int deg) {
        this->deg = deg;
        cof.resize(deg + 1, 0);
        for (int i = 0; i <= deg; i++) {
            cof[i] = 0;
        }
    }
    void shrink() {
        cof.resize(deg + 1);
    }
    friend Polynomial product(Polynomial f, Polynomial g) {
        Polynomial h(f.deg + g.deg);
        for (int i = 0; i <= f.deg; i++) {
            for (int j = 0; j <= g.deg; j++) {
                h.cof[i + j] = (h.cof[i + j] + (long long) f.cof[i] * g.cof[j]) % mod;
            }
        }
        return h;
    }
    //Assuming deg f >= deg g
    friend Polynomial quotient(Polynomial f, Polynomial g) {
        Polynomial q(f.deg - g.deg);
        for (int i = q.deg; i >= 0; i--) {
            q.cof[i] = (long long) f.cof[g.deg + i] * fpow(g.cof[g.deg], mod - 2, mod) % mod;
            for (int j = g.deg; j >= 0; j--) {
                f.cof[i + j] = (f.cof[i + j] - (long long) q.cof[i] * g.cof[j] % mod + mod) % mod;
            }
        }
        return q;
    }
    friend Polynomial remainder(Polynomial f, Polynomial g) {
        if (f.deg < g.deg) return f;
        for (int i = f.deg - g.deg; i >= 0; i--) {
            int c = (long long) f.cof[g.deg + i] * fpow(g.cof[g.deg], mod - 2, mod) % mod;
            for (int j = g.deg; j >= 0; j--) {
                f.cof[i + j] = (f.cof[i + j] - (long long) c * g.cof[j] % mod + mod) % mod;
            }
        }
        f.deg = g.deg - 1;
        while (!f.cof[f.deg]) f.deg--;
        f.deg = max(f.deg, 0);
        f.shrink();
        return f;
    }
    //Assuming deg f >= deg g
    friend Polynomial gcd(Polynomial f, Polynomial g) {
        if (!g.deg && !g.cof[0]) return f;
        return gcd(g, remainder(f, g));
    }
    //Cantor-Zassenhaus Algorithm
    friend vector<int> findroots(Polynomial f) {
        srand(time(NULL));
        vector<int> res;
        if (f.deg == 1) {
            int root = (mod - (long long) f.cof[0] * fpow(f.cof[1], mod - 2, mod) % mod) % mod;
            res.push_back(root);
            return res;
        }
        int it = 0;
        while (it++ < limit) {
            int d = rand() % mod;
            Polynomial a(1), r(0);
            a.cof[1] = 1, a.cof[0] = d;
            r.cof[0] = 1;
            int k = (mod - 1) >> 1;
            while (k) {
                if (k & 1) r = remainder(product(r, a), f);
                a = remainder(product(a, a), f);
                k >>= 1;
            }
            r.cof[0]--;
            a = gcd(f, r);
            if (a.deg > 0 && a.deg < f.deg) {
                r = quotient(f, a);
                res = findroots(a);
                vector<int> res2 = findroots(r);
                res.insert(res.end(), res2.begin(), res2.end());
                it = 0;
                return res;
            }
        }
        return res;
    }
};


void chemthan() {
    int n, q; cin >> n >> q;
    vi fac(3 * n + 555, 1);
    FOR(i, 1, sz(fac)) fac[i] = mult(fac[i - 1], i);
    vi inv_fac(sz(fac));
    FOR(i, 0, sz(fac)) inv_fac[i] = inv(fac[i]);
    auto binom = [&] (int n, int k) {
        return mult(fac[n], mult(inv_fac[k], inv_fac[n - k]));
    };
    Polynomial a;
    Polynomial b;
    a.init(3 * (n + 1));
    b.init(3);
    FOR(i, 0, sz(a.cof)) {
        a.cof[i] = binom(3 * (n + 1), i);
    }
    submod(a.cof[0], 1);
    FOR(i, 0, sz(b.cof)) {
        b.cof[i] = binom(3, i);
    }
    submod(b.cof[0], 1);
    Polynomial res = quotient(a, b);
    while (q--) {
        int x; cin >> x;
        cout << res.cof[x] << "\n";
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