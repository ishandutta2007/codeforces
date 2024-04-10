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

const int maxn = 1000 + 5;
int x[maxn];
int y[maxn];
int f[maxn][maxn];
int fx[maxn];
int fy[maxn];

int between(int u, int x, int y) {
    return min(x, y) <= u && u <= max(x, y);
}

void chemthan() {
    int sx, sy; cin >> sx >> sy;
    FOR(i, 1, 666 + 1) cin >> x[i] >> y[i], fx[x[i]]++, fy[y[i]]++;
    int cx = 500, cy = 500;
    while (sx != cx || sy != cy) {
        FOR(i, -1, 1 + 1) {
            if (1 <= sx + i && sx + i <= 999 && fx[sx + i]) {
                cout << sx + i << " " << sy << "\n";
                cout.flush();
                int a, b, c; cin >> a >> b >> c;
                assert(a == -1 && b == -1 && c == -1);
                return;
            }
            if (1 <= sy + i && sy + i <= 999 && fy[sy + i]) {
                cout << sx << " " << sy + i << "\n";
                cout.flush();
                int a, b, c; cin >> a >> b >> c;
                assert(a == -1 && b == -1 && c == -1);
                return;
            }
        }
        if (sx > cx) sx--;
        else if (sx < cx) sx++;
        if (sy > cy) sy--;
        else if (sy < cy) sy++;
        cout << sx << " " << sy << "\n";
        cout.flush();
        int a, b, c; cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            return;
        }
        fx[x[a]]--, fy[y[a]]--;
        x[a] = b, y[a] = c;
        fx[x[a]]++, fy[y[a]]++;
    }
    FOR(i, 1, 666 + 1) f[x[i]][y[i]] = 1;
    pair<int, pi> best;
    for (pi e : {mp(1, 1), mp(1, 999), mp(999, 1), mp(999, 999)}) {
        int u = e.fi;
        int v = e.se;
        if (u != sx && v != sy) {
            int num = 0;
            FOR(i, 0, maxn) FOR(j, 0, maxn) if (f[i][j] && (between(i, u, sx) || between(j, v, sy))) {
                num++;
            }
            chkmax(best, mp(num, e));
        }
    }
    assert(499 <= best.fi);
    int u = best.se.fi;
    int v = best.se.se;
    while (1) {
        FOR(i, -1, 1 + 1) {
            if (1 <= sx + i && sx + i <= 999 && fx[sx + i]) {
                cout << sx + i << " " << sy << "\n";
                cout.flush();
                int a, b, c; cin >> a >> b >> c;
                assert(a == -1 && b == -1 && c == -1);
                return;
            }
            if (1 <= sy + i && sy + i <= 999 && fy[sy + i]) {
                cout << sx << " " << sy + i << "\n";
                cout.flush();
                int a, b, c; cin >> a >> b >> c;
                assert(a == -1 && b == -1 && c == -1);
                return;
            }
        }
        if (sx > u) {
            sx--;
        }
        else if (sx < u) {
            sx++;
        }
        if (sy > v) {
            sy--;
        }
        else if (sy < v) {
            sy++;
        }
        cout << sx << " " << sy << "\n";
        cout.flush();
        int a, b, c; cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            return;
        }
        fx[x[a]]--, fy[y[a]]--;
        x[a] = b, y[a] = c;
        fx[x[a]]++, fy[y[a]]++;
    }
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