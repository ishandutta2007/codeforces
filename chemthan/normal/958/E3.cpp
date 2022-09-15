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

struct PT {
    int x, y, ix;
    PT(int x = 0, int y = 0, int ix = 0) : x(x), y(y), ix(ix) {}
    int operator < (const PT& rhs) {
        return make_tuple(x, y, ix) < make_tuple(rhs.x, rhs.y, rhs.ix);
    }
    PT operator - (const PT& rhs) {
        return PT(x - rhs.x, y - rhs.y, ix);
    }
};

int cross(PT a, PT b) {
    return a.x * b.y - a.y * b.x;
}

const int maxn = 1e4 + 5;
int n;
int res[maxn];

void divide(vector<PT> pts, queue<vector<PT> >& que) {
    if (sz(pts) == 2) {
        int ix1 = pts[0].ix;
        int ix2 = pts[1].ix;
        if (ix1 > ix2) swap(ix1, ix2);
        res[ix1] = ix2 - n;
        return;
    }
    sort(all(pts));
    FOR(i, 1, sz(pts)) {
        pts[i] = pts[i] - pts[0];
    }
    pts[0] = pts[0] - pts[0];
    sort(pts.begin() + 1, pts.end(), [&] (PT a, PT b) {
            return cross(a, b) > 0;
            }
        );
    int sum0 = 0, sum1 = 0;
    if (pts[0].ix < n) sum0++;
    else sum0--;
    FOR(i, 1, sz(pts)) {
        if (pts[i].ix < n) {
            sum0++;
            sum1++;
        }
        else {
            sum0--;
            sum1--;
        }
        if (!sum0) {
            vector<PT> u, v;
            FOR(j, 0, i + 1) u.pb(pts[j]);
            FOR(j, i + 1, sz(pts)) v.pb(pts[j]);
            que.push(u); que.push(v);
            return;
        }
        if (!sum1) {
            vector<PT> u, v;
            FOR(j, 1, i + 1) u.pb(pts[j]);
            v.pb(pts[0]);
            FOR(j, i + 1, sz(pts)) v.pb(pts[j]);
            que.push(u), que.push(v);
            return;
        }
    }
}

void chemthan() {
    cin >> n;
    vector<PT> p(n + n);
    FOR(i, 0, n + n) {
        cin >> p[i].x >> p[i].y;
        p[i].ix = i;
    }
    queue<vector<PT> > que;
    que.push(p);
    while (sz(que)) {
        vector<PT> pts = que.front(); que.pop();
        divide(pts, que);
    }
    FOR(i, 0, n) cout << res[i] + 1 << "\n";
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