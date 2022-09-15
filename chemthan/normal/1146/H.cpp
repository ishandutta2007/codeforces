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
const ld EPS = 1e-12;
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

struct PT {
    int x, y, id;
    PT(int x = 0, int y = 0, int id = 0) : x(x), y(y), id(id) {}
    PT operator - (const PT& rhs) {
        return PT(x - rhs.x, y - rhs.y, id);
    }
};

inline long long cross(PT a, PT b) {
    return (long long) a.x * b.y - (long long) a.y * b.x;
}

inline long long area(PT a, PT b, PT c) {
    return abs(cross(a, b) + cross(b, c) + cross(c, a));
}

inline int scross(PT a, PT b) {
    long long sc = cross(a, b);
    return sc < 0 ? -1 : sc > 0;
}

inline int inside(PT a, PT b, PT c, PT p) {
    return area(a, b, c) == area(a, b, p) + area(b, c, p) + area(c, a, p);
}

const int maxn = 300 + 5;
const int maxk = 5 + 1;
int n, k;
PT p[maxn];

ull calc(int u) {
    ull res = 0;
    vector<PT> pts;
    FOR(i, 0, n) {
        if (p[i].y > p[u].y || (p[i].y == p[u].y && p[i].x > p[u].x)) {
            pts.pb(p[i] - p[u]);
        }
    }
    sort(all(pts), [&] (PT a, PT b) {
            return cross(a, b) > 0;
            }
        );
    static ull dp[maxn][maxn][maxk][2];
    ms(dp, 0);
    FOR(i, 0, sz(pts)) {
        vector<PT> tmp;
        FOR(j, 0, sz(pts)) if (j != i) {
            tmp.pb(pts[j] - pts[i]);
        }
        sort(all(tmp), [&] (PT a, PT b) {
                int fa = scross(a, PT() - pts[i]);
                int fb = scross(b, PT() - pts[i]);
                if (!fa) return 1;
                if (!fb) return 0;
                if (fa != fb) return fa > 0 ? 1 : 0;
                return cross(a, b) < 0 ? 1 : 0;
                }
            );
        static ull sum[maxk][2];
        ms(sum, 0);
        for (PT q : tmp) {
            FOR(j, 0, maxk) {
                sum[j][0] += dp[pts[i].id][q.id][j][0];
                sum[j][1] += dp[pts[i].id][q.id][j][1];
            }
        }
        sum[2][0]++;
        int ptr = 0;
        for (PT q : tmp) {
            while (ptr < sz(tmp) && scross(q, tmp[ptr]) <= 0) {
                FOR(j, 0, maxk) {
                    sum[j][0] -= dp[pts[i].id][tmp[ptr].id][j][0];
                    sum[j][1] -= dp[pts[i].id][tmp[ptr].id][j][1];
                }
                ptr++;
            }
            if (scross(PT() - pts[i], q) <= 0) {
                int z = 0;
                int w = q.id != u;
                FOR(j, 0, maxk - w) {
                    if (z <= 1) {
                        dp[q.id][pts[i].id][j + w][z] += sum[j][0];
                    }
                    if (!z) {
                        dp[q.id][pts[i].id][j + w][z + 1] += sum[j][1];
                    }
                }
                res += dp[q.id][pts[i].id][k][0];
            }
        }
    }
    return res;
}

void chemthan() {
    srand(2311);
    cin >> n;
    k = 5;
    FOR(i, 0, n) cin >> p[i].x >> p[i].y, p[i].id = i;
    while (1) {
        vii vals;
        int u = abs(rand()) % 1000000 + 1000005;
        int v = abs(rand()) % 1000000 + 1000005;
        FOR(i, 0, n) {
            int x = p[i].x + u;
            int y = p[i].y + v;
            int g = __gcd(x, y);
            x /= g, y /= g;
            vals.pb(mp(x, y));
        }
        sort(all(vals)), uni(vals);
        if (sz(vals) == n) {
            FOR(i, 0, n) {
                p[i].x += u;
                p[i].y += v;
            }
            break;
        }
    }
    ull res = 0;
    FOR(i, 0, n) {
        res += calc(i);
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