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

template<class TE, class TS> struct OrderedTree {
    static const int MAXN = 1e6 + 5;
    static const int LOGN = 20;
    int tr[LOGN + 1][MAXN];
    TS sm[LOGN + 1][MAXN];
    void insert(int x, TE t) {
        for (int i = 0; i < LOGN; i++) {
            tr[i][x]++;
            sm[i][x] += t;
            x >>= 1;
        }
    }
    void erase(int x, TE t) {
        for (int i = 0; i < LOGN; i++) {
            tr[i][x]--;
            sm[i][x] -= t;
            x >>= 1;
        }
    }
    TE kthelm(int k) {
        TE res = 0;
        int a = 0, b = LOGN;
        while (b--) {
            a <<= 1;
            k -= tr[b][a] < k ? tr[b][a++] : 0;
            res = sm[b][a] / tr[b][a];
        }
        return res;
    }
    TS kthsum(int k) {
        if (!k) return 0;
        TS res = 0;
        int a = 0, b = LOGN;
        while (b--) {
            a <<= 1;
            if (tr[b][a] < k) {
                res += sm[b][a];
            }
            k -= tr[b][a] < k ? tr[b][a++] : 0;
            if (!b) res += sm[b][a] / tr[b][a] * k;
        }
        return res;
    }
};
OrderedTree<long long, long long> odtree;

const int maxn = 2e5 + 5;
int n, m;
long long t;
int p[maxn];

void chemthan() {
    int test; cin >> test;
    while (test--) {
        cin >> n >> m >> t;
        vii vals;
        FOR(i, 0, n) cin >> p[i], vals.pb(mp(p[i], i));
        sort(all(vals));
        pi res;
        int ptr = 0;
        FOR(i, 0, sz(vals)) {
            while (ptr < sz(vals) && vals[ptr].fi <= vals[i].fi) {
                odtree.insert(vals[ptr].se, vals[ptr].fi);
                ptr++;
            }
            int lo = 0, hi = ptr;
            while (lo < hi) {
                int mi = lo + hi + 1 >> 1;
                long long sum = odtree.kthsum(mi);
                long long sum2 = odtree.kthsum((mi - 1) / m * m);
                if (sum2 * 2 + sum - sum2 <= t) {
                    lo = mi;
                }
                else {
                    hi = mi - 1;
                }
            }
            chkmax(res, mp(lo + hi >> 1, vals[i].fi));
        }
        FOR(i, 0, n) odtree.erase(i, p[i]);
        if (res.se > t) res.se = t;
        cout << res.fi << " " << res.se << "\n";
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