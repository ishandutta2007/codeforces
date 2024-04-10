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
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

struct point_t {
    int x, y, ix;
    bool operator<(const point_t& oth) {
        if (y != oth.y) {
            return y < oth.y;
        }
        return x < oth.x;
    }
    point_t operator-(point_t p) { return {x - p.x, y - p.y, ix}; }
    long long cross(point_t a) {
        return (long long)x * a.y - (long long)y * a.x;
    }
    friend ostream& operator<<(ostream& out, point_t p) {
        return out << "(" << p.x << ", " << p.y << ", " << p.ix << ")";
    }
};

long long dist(point_t a, point_t b) {
    return (long long)(a.x - b.x) * (a.x - b.x) +
        (long long)(a.y - b.y) * (a.y - b.y);
}

void chemthan() {
    int n, r; cin >> n >> r;
    vector<point_t> pts(n);
    FOR(i, 0, n) {
        int x, y; cin >> x >> y;
        pts[i] = {x, y, 0};
    }
    sort(all(pts));
    FOR(i, 0, n) {
        pts[i].ix = i;
    }
    vector<pair<short, short>> dirs;
    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            dirs.pb({i, j});
        }
    }
    sort(all(dirs), [&](pair<short, short> a, pair<short, short> b) {
            return 0 < (pts[a.se] - pts[a.fi]).cross(pts[b.se] - pts[b.fi]);
            });
    vi pos(n);
    FOR(i, 0, n) pos[pts[i].ix] = i;
    vector<vector<bool>> f(n, vector<bool>(n));
    for (auto [u, v] : dirs) {
        auto x = abs((pts[pos[u]] - pts[pos[v]]).cross(pts[0] - pts[pos[v]]));
        auto y = abs((pts[pos[u]] - pts[pos[v]]).cross(pts[n - 1] - pts[pos[v]]));
        auto z = max(x, y);
        auto d = dist(pts[pos[u]], pts[pos[v]]);
        if ((long double) z * z / d <= (long long) r * r) {
            f[u][v] = 1;
        }
        swap(pts[pos[u]], pts[pos[v]]);
        swap(pos[u], pos[v]);
    }
    sort(all(pts), [&] (point_t a, point_t b) {
            return a.ix < b.ix;
            }
        );
    FOR(t, 0, n) {
        vector<point_t> pts2;
        FOR(i, 0, n) if (i ^ t) {
            pts2.push_back(pts[i] - pts[t]);
        }
        pts2.push_back({0, 1, -1});
        pts2.push_back({0, -1, -1});
        pts2.push_back({1, 0, -1});
        pts2.push_back({-1, 0, -1});
        sort(pts2.begin(), pts2.end(), [&](point_t a, point_t b) {
                int sa = a.y < 0 || (!a.y && a.x < 0);
                int sb = b.y < 0 || (!b.y && b.x < 0);
                if (sa != sb) return (int)sb;
                return (int)(0 < a.cross(b));
                });
        int k = pts2.size();
        for (int i = 0; i < k; i++) {
            pts2.push_back(pts2[i]);
        }
        int ptr1 = 0;
        int ptr2 = 0;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            auto q = pts2[i];
            while (ptr1 < k + k) {
                auto q2 = pts2[ptr1];
                swap(q2.x, q2.y), q2.x *= -1;
                if (ptr1 < i || 0 <= q.cross(q2)) {
                    if ((long long) r * r < (long long) q2.x * q2.x + (long long) q2.y * q2.y) {
                        cnt--;
                    }
                    ptr1++;
                } else {
                    break;
                }
            }
            while (ptr2 < k + k) {
                auto q2 = pts2[ptr2];
                swap(q2.x, q2.y), q2.x *= -1;
                if (ptr2 < ptr1 || 0 <= q2.cross(q)) {
                    if ((long long) r * r < (long long) q2.x * q2.x + (long long) q2.y * q2.y) {
                        cnt++;
                    }
                    ptr2++;
                } else {
                    break;
                }
            }
            if (0 < cnt && 0 <= q.ix) {
                f[t][q.ix] = f[q.ix][t] = 0;
            }
        }
    }
    int res = 0;
    FOR(i, 0, n) FOR(j, i + 1, n) res += f[i][j];
    cout << res << "\n";
}

int32_t main(int32_t argc, char* argv[]) {
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