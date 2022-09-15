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

int inside(int u, int v) {
    if (!(0 <= u && u < 8)) return 0;
    if (!(0 <= v && v < 8)) return 0;
    return 1;
}

int a[8][8];
int b[8][8];

void chemthan() {
    int n; cin >> n;
    int flip = 0;
    if (n + n >= 64) {
        flip = 1;
        FOR(i, 0, 8) FOR(j, 0, 8) a[i][j] = 1;
    }
    FOR(i, 0, n) {
        string s; cin >> s;
        if (!flip) {
            a[s[0] - 'a'][s[1] - '1'] = 1;
        }
        else {
            a[7 - (s[0] - 'a')][7 - (s[1] - '1')] = 0;
        }
    }
    vector<string> res;
    FOR(j, 0, 8) FOR(i, 0, 8) {
        static int vis[8][8];
        static int fromx[8][8];
        static int fromy[8][8];
        queue<int> que;
        ms(vis, 0);
        vis[i][j] = 1, que.push(i), que.push(j);
        pi ed = mp(-1, -1);
        while (sz(que)) {
            int u = que.front(); que.pop();
            int v = que.front(); que.pop();
            if (a[u][v]) {
                ed = mp(u, v);
                break;
            }
            for (int du : {-1, 1, -2, 2}) {
                for (int dv : {-1, 1, -2, 2}) if (abs(du) != abs(dv)) {
                    int nu = u + du;
                    int nv = v + dv;
                    if (inside(nu, nv) && !b[nu][nv] && !vis[nu][nv]) {
                        fromx[nu][nv] = u;
                        fromy[nu][nv] = v;
                        vis[nu][nv] = 1, que.push(nu), que.push(nv);
                    }
                }
            }
        }
        if (ed == mp(-1, -1)) {
            break;
        }
        int u = ed.fi, v = ed.se;
        a[u][v] = 0;
        while (u != i || v != j) {
            int nu = fromx[u][v];
            int nv = fromy[u][v];
            string step;
            if (!flip) {
                step += char('a' + u);
                step += char('1' + v);
                step += "-";
                step += char('a' + nu);
                step += char('1' + nv);
            }
            else {
                step += char('a' + 7 - nu);
                step += char('1' + 7 - nv);
                step += "-";
                step += char('a' + 7 - u);
                step += char('1' + 7 - v);
            }
            res.pb(step);
            u = nu, v = nv;
        }
        a[i][j] = b[i][j] = 1;
    }
    cout << sz(res) << "\n";
    for (string step : res) {
        cout << step << "\n";
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