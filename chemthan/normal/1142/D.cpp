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

void chemthan() {
    vector<long long> vals;
    FOR(i, 1, 10) vals.pb(i);
    long long st = 0;
    FOR(it, 0, 1000) {
        int k = lower_bound(all(vals), st) - vals.begin();
        if (k < sz(vals) && vals[k] == st) {
            k++;
            FOR(x, 0, k % 11) {
                if (vals.back() < st * 10 + x) {
                    vals.pb(st * 10 + x);
                }
            }
        }
        st++;
    }
    auto find = [&] (long long x) {
        int k = lower_bound(all(vals), x) - vals.begin();
        return k < sz(vals) && vals[k] == x;
    };
    auto func = [&] (long long x) {
        return upper_bound(all(vals), x) - vals.begin();
    };
    vector<vi> nxt(11, vi(11, -1));
    FOR(x, 0, 1000) if (find(x)) {
        int t = func(x);
        FOR(d, 0, t % 11) {
            int u = func(x * 10 + d);
            int p = t % 11, q = u % 11;
            nxt[p][d] = q;
        }
    }
    FOR(i, 0, 11) FOR(j, 0, i) assert(nxt[i][j] != -1);
    string s; cin >> s;
    vector<long long> dp(11);
    long long res = 0;
    FOR(i, 0, sz(s)) {
        vector<long long> ndp(11);
        int c = s[i] - '0';
        if (c) {
            res++;
            ndp[c]++;
        }
        FOR(i, 0, 11) {
            if (c < i) {
                ndp[nxt[i][c]] += dp[i];
                res += dp[i];
            }
        }
        dp = ndp;
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