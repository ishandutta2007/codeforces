#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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
    int x, y;
    PT(int x = 0, int y = 0) : x(x), y(y) {}
    PT operator - (const PT& rhs) {return PT(x - rhs.x, y - rhs.y);}
    PT operator + (const PT& rhs) {return PT(x + rhs.x, y + rhs.y);}
    int operator == (const PT& rhs) const {return x == rhs.x && y == rhs.y;}
    int operator != (const PT& rhs) const {return !(x == rhs.x && y == rhs.y);}
    int operator < (const PT& rhs) const {return mp(x, y) < mp(rhs.x, rhs.y);}
};

inline long long cross(PT a, PT b) {
    return (long long) a.x * b.y - (long long) a.y * b.x;
}

const int maxn = 4000 + 5;
int n;

int dj[maxn];
int size[maxn];
int odds;
int ncache;
pair<int*, int> cache[maxn * maxn / 2];

void init(int k) {
    FOR(i, 0, k) dj[i] = i, size[i] = 1;
    odds = k;
}
void reset() {
    while (ncache > 0) {
        *cache[ncache - 1].fi = cache[ncache - 1].se;
        ncache--;
    }
}
int find(int u) {
    if (dj[u] == u) return dj[u];
    cache[ncache++] = mp(&dj[u], dj[u]);
    return dj[u] = find(dj[u]);
}
void join(int u, int v) {
    int p = find(u);
    int q = find(v);
    if (p != q) {
        cache[ncache++] = mp(&dj[p], dj[p]);
        dj[p] = q;
        cache[ncache++] = mp(&odds, odds);
        if (size[p] & 1) {
            odds--;
        }
        if (size[q] & 1) {
            odds--;
        }
        cache[ncache++] = mp(&size[q], size[q]);
        size[q] += size[p];
        if (size[q] & 1) {
            odds++;
        }
    }
}

void solve() {
    srand(time(NULL));
    cin >> n;
    vector<PT> p(n);
    PT cen;
    map<PT, int> hs, tmp;
    for (PT& q : p) {
        cin >> q.x >> q.y;
        cen = cen + q;
        q.x *= n, q.y *= n;
        hs[q] ^= 1;
        tmp[q] = 1;
    }
    FOR(i, 0, n) {
        PT q = cen + cen - p[i];
        hs[q] ^= 1;
    }
    p.clear();
    for (auto it : hs) {
        if (it.fi != cen && it.se) {
            p.pb(it.fi);
        }
    }
    if (!sz(p)) {
        cout << -1 << "\n";
        return;
    }
    unordered_map<long long, vii> hs2;
    map<long long, int> can;
    FOR(i, 0, sz(p)) FOR(j, i + 1, sz(p)) if (tmp.count(p[i]) + tmp.count(p[j]) == 1) {
        PT q = p[i] - p[j];
        if (q.y < 0 || (!q.y && q.x < 0)) q.x *= -1, q.y *= -1;
        int g = __gcd(abs(q.x), abs(q.y));
        q.x /= g, q.y /= g;
        long long t = (long long) (q.x + INF) * (INF + INF) + (q.y + INF);
        if (!i) {
            can[t] = 1;
            hs2[t].pb(mp(i, j));
        }
        else if (can.count(t)) {
            hs2[t].pb(mp(i, j));
        }
    }
    int k = sz(p);
    init(k);
    int res = 0;
    for (auto it : hs2) if (can[it.fi]) {
        reset();
        for (auto x : it.se) {
            join(x.fi, x.se);
        }
        if (!odds) {
            res++;
        }
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
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}