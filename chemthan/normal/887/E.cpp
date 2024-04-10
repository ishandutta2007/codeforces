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

#define RL long double
#define EPS 1e-9
struct PT {
    RL x, y;
    PT() : x(0), y(0) {}
    PT(RL x, RL y) : x(x), y(y) {}
    PT(const PT& p) : x(p.x), y(p.y) {}
    int operator < (const PT& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
    int operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
    PT operator + (const PT& p) const {return PT(x + p.x, y + p.y);}
    PT operator - (const PT& p) const {return PT(x - p.x, y - p.y);}
    PT operator * (RL c) const {return PT(x * c, y * c);}
    PT operator / (RL c) const {return PT(x / c, y / c);}
};
RL cross(PT p, PT q) {return p.x * q.y - p.y * q.x;}
RL area(PT a, PT b, PT c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
RL area2(PT a, PT b, PT c) {return cross(a, b) + cross(b, c) + cross(c, a);}
RL dot(PT p, PT q) {return p.x * q.x + p.y * q.y;}
RL dist(PT p, PT q) {return sqrt(dot(p - q, p - q));}
RL dist2(PT p, PT q) {return dot(p - q, p - q);}
PT RotateCCW90(PT p) {return PT(-p.y, p.x);}
PT RotateCW90(PT p) {return PT(p.y, -p.x);}
PT RotateCCW(PT p, RL t) {return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}
ostream& operator << (ostream& os, const PT& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

pair<RL, RL> solve(RL a, RL b, RL c) {
    RL delta = b * b - 4 * a * c;
    if (delta < 0) delta = 0;
    RL x1 = (-b - sqrt(delta)) / 2 / a;
    RL x2 = (-b + sqrt(delta)) / 2 / a;
    return mp(x1, x2);
}

inline RL sqr(RL x) {return x * x;}

const int maxn = 1e5 + 5;
int n;
PT a, b;
PT cen[maxn];
RL rad[maxn];

RL ff(int u) {
    RL lo = -1e12, hi = 1e12;
    int sign = 1;
    if (cen[u].x > 0) cen[u].x *= -1, sign = -1;
    FOR(it, 0, 100) {
        RL mi = (lo + hi) / 2;
        PT p = PT(mi, 0);
        int sign = 1;
        if (dist(p, cen[u]) <= dist(p, b) + rad[u]) {
            lo = mi;
        }
        else {
            hi = mi;
        }
    }
    cen[u].x *= sign;
    return sign * (lo + hi) / 2;
}
RL gg(int u) {
    RL lo = -1e12, hi = 1e12;
    int sign = 1;
    if (cen[u].x > 0) cen[u].x *= -1, sign = -1;
    FOR(it, 0, 100) {
        RL mi = (lo + hi) / 2;
        PT p = PT(mi, 0);
        int sign = 1;
        if (dist(p, cen[u]) <= dist(p, b) - rad[u]) {
            lo = mi;
        }
        else {
            hi = mi;
        }
    }
    cen[u].x *= sign;
    return sign * (lo + hi) / 2;
}

void solve() {
    cin >> a.x >> a.y >> b.x >> b.y;
    b = b - a;
    cin >> n;
    FOR(i, 0, n) cin >> cen[i].x >> cen[i].y >> rad[i], cen[i] = cen[i] - a;
    RL al = atan2(b.y, b.x);
    b = RotateCCW(b, PI / 2 - al);
    FOR(i, 0, n) {
        cen[i] = RotateCCW(cen[i], PI / 2 - al);
        cen[i].y -= b.y / 2;
    }
    b.y /= 2;
    vector<pair<RL, int> > events;
    events.pb(mp(0, 2));
    FOR(i, 0, n) {
        double l = gg(i);
        double r = ff(i);
        if (l > r) swap(l, r);
        events.pb(mp(l, 0));
        events.pb(mp(r, 1));
    }
    sort(all(events));
    int ptr = 0, cnt = 0;
    RL ans = 1e100;
    FOR(i, 0, sz(events)) {
        int add = 0;
        while (ptr < sz(events) && !sign(events[ptr].fi, events[i].fi)) {
            if (!events[ptr].se) {
                add++;
            }
            else if (events[ptr].se == 1) {
                cnt--;
            }
            ptr++;
        }
        if (!cnt) {
            chkmin(ans, dist(PT(events[i].fi, 0), b));
        }
        cnt += add;
    }
    cout << prec(9) << ans << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int JUDGE_ONLINE = 1;
    if (argc > 1) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[2], "wb", stdout));
    }
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}