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

void chemthan() {
    int test; cin >> test;
    while (test--) {
        int l, r; cin >> l >> r;
        vi a, b;
        FOR(i, 0, 40) {
            a.pb(l & 1);
            b.pb(r & 1);
            l >>= 1, r >>= 1;
        }
        reverse(all(a)), reverse(all(b));
        vector<vector<vector<vector<long long>>>> dp;
        dp.resize(40);
        for (auto& r1 : dp) {
            r1.resize(4);
            for (auto& r2 : r1) {
                r2.resize(4);
                for (auto& r3 : r2) {
                    r3.resize(2, -1);
                }
            }
        }
        function<long long(int, int, int, int)> calc = [&] (int pos, int fa, int fb, int c) {
            if (pos == 40) return (long long) !c;
            long long& res = dp[pos][fa][fb][c];
            if (~res) return res;
            res = 0;
            int lox = 0, loy = 0;
            int hix = 1, hiy = 1;
            if (!bit(fa, 0)) chkmax(lox, a[pos]);
            if (!bit(fa, 1)) chkmin(hix, b[pos]);
            if (!bit(fb, 0)) chkmax(loy, a[pos]);
            if (!bit(fb, 1)) chkmin(hiy, b[pos]);
            FOR(i, lox, hix + 1) FOR(j, loy, hiy + 1) FOR(nc, 0, 2) {
                int nfa = fa | (a[pos] < i) | ((i < b[pos]) << 1);
                int nfb = fb | (a[pos] < j) | ((j < b[pos]) << 1);
                if ((i ^ j) == (nc + i + j & 1) && c == (nc + i + j >> 1)) {
                    res += calc(pos + 1, nfa, nfb, nc);
                }
            }
            return res;
        };
        cout << calc(0, 0, 0, 0) << "\n";
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