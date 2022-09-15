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

template<class TE, class TS> struct OrderedTree {
    static const int MAXN = 2e5 + 5;
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
OrderedTree<int, long long> odtree;

const int maxn = 2e5 + 5;
int n, T;
pi a[maxn];
int t[maxn];

void chemthan() {
    cin >> n >> T;
    vector<pair<pi, int> > vals;
    FOR(i, 0, n) cin >> a[i].fi >> t[i], a[i].se = i, vals.pb(mp(a[i], t[i]));
    sort(all(vals), greater<pair<pi, int> >());
    int res = 0, sum = 0, ptr = 0;
    FORd(i, n + 1, 1) {
        while (ptr < n && vals[ptr].fi.fi >= i) {
            odtree.insert(vals[ptr].se, vals[ptr].se);
            sum++;
            ptr++;
        }
        int lo = 0, hi = min(i, sum);
        while (lo < hi) {
            int mi = lo + hi + 1 >> 1;
            if (odtree.kthsum(mi) <= T) {
                lo = mi;
            }
            else {
                hi = mi - 1;
            }
        }
        int mi = lo + hi >> 1;
        chkmax(res, mi);
    }
    cout << res << "\n";
    vi vs;
    FOR(i, 0, n) odtree.erase(t[i], t[i]);
    sum = 0, ptr = 0;
    FORd(i, n + 1, 1) {
        while (ptr < n && vals[ptr].fi.fi >= i) {
            odtree.insert(vals[ptr].se, vals[ptr].se);
            sum++;
            ptr++;
        }
        int lo = 0, hi = min(i, sum);
        while (lo < hi) {
            int mi = lo + hi + 1 >> 1;
            if (odtree.kthsum(mi) <= T) {
                lo = mi;
            }
            else {
                hi = mi - 1;
            }
        }
        int mi = lo + hi >> 1;
        if (res == mi) {
            FOR(j, 0, ptr) {
                vs.pb(vals[j].fi.se);
            }
            sort(all(vs), [&] (int i, int j) {
                    return t[i] < t[j];
                    }
                );
            while (sz(vs) > res) vs.pop_back();
            break;
        }
    }
    sort(all(vs));
    cout << sz(vs) << "\n";
    FOR(i, 0, sz(vs)) cout << vs[i] + 1 << " \n"[i == sz(vs) - 1];
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