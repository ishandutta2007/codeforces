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
 
void chemthan() {
    int n; cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];
    if (n == 1) {
        if (a[0] != b[0]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        else {
            cout << "SMALL\n";
            cout << 0 << "\n";
            return;
        }
    }
    long long sa = accumulate(all(a), 0LL);
    vector<long long> res;
    while (sa < accumulate(all(b), 0LL)) {
        int fa = 0;
        FOR(i, 0, n - 1) {
            if (b[i] < b[i + 1]) {
                fa |= 1;
            }
            else if (b[i + 1] < b[i]) {
                fa |= 2;
            }
            else {
                fa |= 4;
            }
        }
        if (bit(fa, 2) || (bit(fa, 0) && bit(fa, 1))) {
            break;
        }
        if (fa == 2) {
            reverse(all(b));
            res.pb(1);
        }
        if (!b[0]) {
            break;
        }
        if (n == 2) {
            long long lo = 0, hi = b[1] / b[0];
            while (lo < hi) {
                long long mi = lo + hi >> 1;
                if (sa < b[0] + b[1] - b[0] * mi) {
                    lo = mi + 1;
                }
                else {
                    hi = mi;
                }
            }
            long long mi = lo + hi >> 1;
            b[1] -= mi * b[0];
            if (mi) {
                res.pb(-mi);
            }
        }
        else {
            FORd(i, n, 1) b[i] -= b[i - 1];
            res.pb(-1);
        }
    }
    int found = 0;
    FOR(i, 0, n) {
        if (a[i] != b[i]) {
            found = 1;
        }
    }
    if (found) {
        reverse(all(b));
        res.pb(1);
    }
    found = 0;
    FOR(i, 0, n) {
        if (a[i] != b[i]) {
            found = 1;
        }
    }
    if (found) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    long long total = 0;
    for (auto e : res) {
        if (e < 0) {
            total += -e;
            chkmin(total, LINF);
        }
    }
    if (2e5 < total) {
        cout << "BIG\n";
        cout << total << "\n";
        return;
    }
    reverse(all(res));
    string sres;
    for (auto x : res) {
        if (x < 0) {
            FOR(j, 0, -x) {
                sres += "P";
            }
        }
        else {
            sres += "R";
        }
    }
    cout << "SMALL\n";
    cout << sz(sres) << "\n";
    cout << sres << "\n";
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