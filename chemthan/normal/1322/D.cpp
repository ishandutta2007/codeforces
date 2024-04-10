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
    int n, m; cin >> n >> m;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    vi s(n);
    FOR(i, 0, n) cin >> s[i];
    vi c(n + m + 1);
    FOR(i, 1, n + m + 1) cin >> c[i];
    vector<vector<long long>> f(m + 1, vector<long long>(1 << 11, -LINF));
    auto calc = [&] (int st, int msk) {
        long long& res = f[st][msk];
        if (res != -LINF) return res;
        res = 0;
        FOR(i, 0, 11) {
            if (bit(msk, i)) {
                if (st + i + 1 <= n + m) {
                    res += c[st + i + 1];
                }
            }
            else {
                break;
            }
        }
        return res;
    };
    vector<long long> fen(m + 2, -LINF);
    auto upd = [&] (int p, long long v) {
        p++;
        for (; p < sz(fen); p += p & -p) {
            chkmax(fen[p], v);
        }
    };
    auto query = [&] (int p) {
        p++;
        long long res = -LINF;
        for (; 0 < p; p -= p & -p) {
            chkmax(res, fen[p]);
        }
        return res;
    };
    vector<vector<long long>> dp(m + 1, vector<long long>(1 << 11, -LINF));
    upd(0, dp[0][0] = 0);
    FORd(i, n, 0) {
        int x = a[i];
        int lo = max(0, x - 15);
        FORd(u, x + 1, lo) {
            FORd(msk, 1 << 11, 0) {
                int nmsk = (msk >> x - u) + 1;
                if (nmsk < (1 << 11)) {
                    chkmax(dp[x][nmsk], dp[u][msk] + calc(x, msk >> x - u) + c[x] - s[i]);
                }
            }
        }
        chkmax(dp[x][1], query(lo - 1) + c[x] - s[i]);
        long long mx = -LINF;
        FOR(msk, 0, 1 << 11) {
            chkmax(mx, dp[x][msk]);
        }
        upd(x, mx);
    }
    long long res = 0;
    FOR(i, 0, m + 1) FOR(msk, 0, 1 << 11) {
        chkmax(res, dp[i][msk]);
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