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

#define double long double
const int maxn = 1e5 + 5;
int n, m, r, k;

void chemthan() {
    cin >> n >> m >> r >> k;
    auto func = [&] (int x0, int y0) {
        int lox = max(1, x0 - r + 1);
        int hix = min(x0, n - r + 1);
        int loy = max(1, y0 - r + 1);
        int hiy = min(y0, m - r + 1);
        return (long long) (hix - lox + 1) * (hiy - loy + 1);
    };
    auto inside = [&] (int x, int y) {
        if (!(1 <= x && x <= n)) return 0;
        if (!(1 <= y && y <= m)) return 0;
        return 1;
    };
    map<pi, int> used;
    priority_queue<pair<long long, pi> > pq;
    int cenx = n + 1 >> 1, ceny = m + 1 >> 1;
    used[mp(cenx, ceny)] = 1;
    pq.push(mp(func(cenx, ceny), mp(cenx, ceny)));
    double res = 0.0;
    FOR(i, 0, k) {
        int x = pq.top().se.fi;
        int y = pq.top().se.se;
        pq.pop();
        res += (double) func(x, y) / (n - r + 1) / (m - r + 1);
        static int dx[] = {1, -1, 0, 0};
        static int dy[] = {0, 0, 1, -1};
        FOR(d, 0, 4) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (inside(nx, ny) && !used[mp(nx, ny)]) {
                used[mp(nx, ny)] = 1;
                pq.push(mp(func(nx, ny), mp(nx, ny)));
            }
        }
    }
    cout << prec(9) << res << "\n";
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