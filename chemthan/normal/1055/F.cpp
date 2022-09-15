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

const int maxn = 1e6 + 5;
int n;
long long k;
long long f[maxn];
int a[maxn];

int ptr;
int nxt[maxn * 2][2];
int val[maxn * 2];

inline int getnxt() {
    if (++ptr == maxn * 2) ptr = 0;
    nxt[ptr][0] = nxt[ptr][1] = -1, val[ptr] = 0;
    return ptr;
}

void chemthan() {
    ms(nxt, -1);
    cin >> n >> k;
    FOR(i, 1, n) {
        int p; long long w; cin >> p >> w; p--;
        f[i] = f[p] ^ w;
    }
    long long res = 0;
    vi v; v.pb(0), v.pb(0);
    FORd(it, 62, 0) {
        FOR(i, 0, n) {
            int x = a[i];
            int t = bit(f[i], it);
            if (nxt[x][t] == -1) {
                nxt[x][t] = getnxt();
            }
            x = nxt[x][t];
            val[x]++;
            a[i] = x;
        }
        long long tot = 0;
        for (int i = 0; i < sz(v); i += 2) {
            int x = v[i];
            int y = v[i + 1];
            FOR(j, 0, 2) {
                if (nxt[x][j] != -1 && nxt[y][j] != -1) {
                    tot += (long long) val[nxt[x][j]] * val[nxt[y][j]];
                }
            }
        }
        vi nv;
        if (tot < k) {
            k -= tot;
            res |= 1LL << it;
            for (int i = 0; i < sz(v); i += 2) {
                int x = v[i];
                int y = v[i + 1];
                FOR(j, 0, 2) {
                    if (nxt[x][j] != -1 && nxt[y][j ^ 1] != -1) {
                        nv.pb(nxt[x][j]);
                        nv.pb(nxt[y][j ^ 1]);
                    }
                }
            }
        }
        else {
            for (int i = 0; i < sz(v); i += 2) {
                int x = v[i];
                int y = v[i + 1];
                FOR(j, 0, 2) {
                    if (nxt[x][j] != -1 && nxt[y][j] != -1) {
                        nv.pb(nxt[x][j]);
                        nv.pb(nxt[y][j]);
                    }
                }
            }
        }
        v = nv;
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