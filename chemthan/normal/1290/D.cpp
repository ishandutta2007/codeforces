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
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";
 
//#define LC
 
void chemthan() {
#ifdef LC
    int n = 512, k = 32;
    vi a(n);
    for (int& x : a) x = mrand() % 1000;
    vi que;
#else
    int n, k; cin >> n >> k;
#endif
    auto reset = [&] () {
        cout << "R\n";
        cout.flush();
#ifdef LC
        que.clear();
#endif
    };
    int total = 0;
    auto ask = [&] (int u) {
        cout << "? " << u + 1 << "\n";
        cout.flush();
#ifdef LC
        assert(++total <= 3 * n * n / 2 / k);
        int found = 0;
        for (int x : que) if (x == a[u]) {
            found = 1;
            break;
        }
        que.pb(a[u]);
        if (k < sz(que)) {
            que.erase(que.begin());
        }
        if (!found) {
            return 'N';
        }
        else {
            return 'Y';
        }
#else
        char res; cin >> res;
        return res;
#endif
    };
    vi vals;
    FOR(i, 0, n) vals.pb(i);
    int res = 0;
    while (sz(vals)) {
        reset();
        vi tmp, nvals;
        FOR(i, 0, sz(vals)) {
            int u = vals[i];
            if (ask(u) == 'N') {
                tmp.pb(u);
                res++;
            }
            if (i + 1 == k) {
                FOR(j, i + 1, sz(vals)) {
                    nvals.pb(vals[j]);
                }
                break;
            }
        }
        map<int, int> hs;
        vi nvals2;
        while (sz(nvals)) {
            int k = sz(tmp);
            if (k == 1) {
                ask(tmp[0]);
                int u = nvals.back();
                nvals.pop_back();
                if (ask(u) == 'N') {
                    nvals2.pb(u);
                }
            }
            else {
                reset();
                int kk = k >> 1;
                FOR(i, 0, kk) {
                    int u = tmp[i];
                    ask(u);
                }
                FOR(i, 0, kk) if (sz(nvals)) {
                    int u = nvals.back();
                    nvals.pop_back();
                    if (ask(u) == 'N') {
                        nvals2.pb(u);
                    }
                }
                FOR(i, kk, k) {
                    int u = tmp[i];
                    if (ask(u) == 'Y') {
                        if (!hs.count(u)) {
                            hs[u] = 1;
                            res--;
                        }
                    }
                }
            }
        }
        vals = nvals2;
    }
    cout << "! " << res << "\n";
    cout.flush();
#ifdef LC
    sort(all(a)), uni(a);
    cout << sz(a) << "\n";
#endif
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