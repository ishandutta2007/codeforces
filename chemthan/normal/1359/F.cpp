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
const ld EPS = 1e-8;
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
 
#define double double
struct point_t {
    double x, y;
    point_t() : x(0), y(0) {}
    point_t(double x, double y) : x(x), y(y) {}
    point_t(const point_t& p) : x(p.x), y(p.y) {}
    int operator == (const point_t& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
    point_t operator + (const point_t& p) const {return point_t(x + p.x, y + p.y);}
    point_t operator - (const point_t& p) const {return point_t(x - p.x, y - p.y);}
    point_t operator * (double c) const {return point_t(x * c, y * c);}
    point_t operator / (double c) const {return point_t(x / c, y / c);}
};
double cross(point_t p, point_t q) {return p.x * q.y - p.y * q.x;}
double area(point_t a, point_t b, point_t c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
double area2(point_t a, point_t b, point_t c) {return cross(a, b) + cross(b, c) + cross(c, a);}
double dot(point_t p, point_t q) {return p.x * q.x + p.y * q.y;}
double dist(point_t p, point_t q) {return sqrt(dot(p - q, p - q));}
double dist2(point_t p, point_t q) {return dot(p - q, p - q);}
point_t RotateCCW90(point_t p) {return point_t(-p.y, p.x);}
point_t RotateCW90(point_t p) {return point_t(p.y, -p.x);}
point_t RotateCCW(point_t p, double t) {return point_t(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}
ostream& operator << (ostream& os, const point_t& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
 
inline int operator < (point_t a, point_t b) {
    int fa = a.y < 0 || (!a.y && a.x < 0);
    int fb = b.y < 0 || (!b.y && b.x < 0);
    if (fa != fb) return !fa;
    return cross(a, b) > 0;
}
 
inline int LinesParallel(point_t a, point_t b, point_t c, point_t d) {
    return fabs(cross(b - a, c - d)) < EPS;
}
inline int LinesCollinear(point_t a, point_t b, point_t c, point_t d) {
    return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS && fabs(cross(c - d, c - a)) < EPS;
}
inline int insect(point_t a, point_t b, point_t c, point_t d, int flag = 0) {
    if (!flag) {
        if (LinesCollinear(a, b, c, d)) {
            if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) return 1;
            if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0) return 0;
            return 1;
        }
    }
    if (sign(cross(d - a, b - a)) * sign(cross(c - a, b - a)) > 0) return 0;
    if (sign(cross(a - c, d - c)) * sign(cross(b - c, d - c)) > 0) return 0;
    return 1;
}
 
struct Seg {
    point_t a, b;
    int ix;
    Seg(point_t a = point_t(), point_t b = point_t(), int ix = 0) : a(a), b(b), ix(ix) {}
};
 
inline int scross(point_t a, point_t b) {
    double cr = cross(a, b);
    return cr < 0 ? -1 : cr > 0;
}
 
int found;
int operator < (Seg s, Seg t) {
    if (!found && s.ix != t.ix) {
        found = insect(s.a, s.b, t.a, t.b);
    }
    point_t u = max(s.a, t.a);
    point_t v = min(s.b, t.b);
    if (s.a == t.a) {
        return sign(cross(s.b - s.a, t.b - t.a)) < 0;
    }
    if (s.b == t.b) {
        return sign(cross(s.a - s.b, t.a - t.b)) > 0;
    }
    point_t q = (u + v) / 2;
    if (u == s.a && v == s.b) {
        return !insect(point_t(), q, t.a, t.b, 1);
    }
    if (u == t.a && v == t.b) {
        return insect(point_t(), q, s.a, s.b, 1);
    }
    return insect(point_t(), q, s.a, s.b, 1);
}
 
struct cmpseg {
    int operator () (const Seg& a, const Seg& b) const {
        return a < b;
    }
};
 
void chemthan() {
    int n; cin >> n;
    vector<point_t> s(n);
    vector<point_t> t(n);
    vi v(n);
    FOR(i, 0, n) {
        cin >> s[i].x >> s[i].y >> t[i].x >> t[i].y;
        cin >> v[i];
    }
    int xx = mrand(1000) + 100;
    int yy = mrand(1000) + 100;
    double lo = 0, hi = 1e10;
    FOR(it, 0, 60) {
        double mi = (lo + hi) / 2;
        vector<tuple<point_t, int, Seg>> events;
        double mnx = 0, mny = 0;
        FOR(i, 0, n) {
            point_t ss = s[i];
            point_t tt = ss + t[i] / dist(point_t(), t[i]) * v[i] * mi;
            chkmin(mnx, ss.x);
            chkmin(mnx, tt.x);
            chkmin(mny, ss.y);
            chkmin(mny, tt.y);
        }
        FOR(i, 0, n) {
            point_t ss = s[i];
            point_t tt = ss + t[i] / dist(point_t(), t[i]) * v[i] * mi;
            ss = ss - point_t(mnx - xx, mny - yy);
            tt = tt - point_t(mnx - xx, mny - yy);
            if (tt < ss) swap(ss, tt);
            events.pb({ss, 1, Seg(ss, tt, i)});
            events.pb({tt, 0, Seg(ss, tt, i)});
        }
        sort(all(events));
        set<Seg, cmpseg> st;
        found = 0;
        for (auto e : events) {
            if (get<1>(e) == 0) {
                st.erase(get<2>(e));
            }
            else {
                st.insert(get<2>(e));
            }
            if (found) break;
        }
        if (!found) {
            lo = mi;
        }
        else {
            hi = mi;
        }
    }
    double res = (lo + hi) / 2;
    if (9e9 < res) {
        cout << "No show :(\n";
    }
    else {
        cout << prec(9) << res << "\n";
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