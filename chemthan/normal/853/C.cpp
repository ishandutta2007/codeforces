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
const int MOD2 = 1007681537;
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

struct Rec {
    int x0, x1, y0, y1;
    Rec(int x0 = 0, int x1 = 0, int y0 = 0, int y1 = 0) : x0(x0), x1(x1), y0(y0), y1(y1) {}
};

const int maxn = 4e6 + 5;
int n, q;
int a[maxn];
int x[maxn][2];
int y[maxn][2];
int f[maxn];
long long g[maxn];
vector<pair<Rec, pi> > events;
vector<pair<int, pi> > event2[maxn];

int fen[maxn];

void upd(int p, int val) {
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p] += val;
    }
}
int query(int p) {
    p++;
    int res = 0;
    for (; p > 0; p -= p & -p) {
        res += fen[p];
    }
    return res;
}

void solve() {
    cin >> n >> q;
    FOR(i, 0, n) cin >> a[i], a[i]--;
    FOR(i, 0, q) {
        cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1], x[i][0]--, x[i][1]--, y[i][0]--, y[i][1]--;
        if (x[i][0] > x[i][1]) swap(x[i][0], x[i][1]);
        if (y[i][0] > y[i][1]) swap(y[i][0], y[i][1]);
        if (x[i][0] > 0) {
            events.pb(mp(Rec(0, x[i][0] - 1, 0, n - 1), mp(1, i)));
        }
        if (x[i][1] < n - 1) {
            events.pb(mp(Rec(x[i][1] + 1, n - 1, 0, n - 1), mp(1, i)));
        }
        if (y[i][0] > 0) {
            events.pb(mp(Rec(0, n - 1, 0, y[i][0] - 1), mp(1, i)));
        }
        if (y[i][1] < n - 1) {
            events.pb(mp(Rec(0, n - 1, y[i][1] + 1, n - 1), mp(1, i)));
        }
        if (x[i][0] > 0 && y[i][0] > 0) {
            events.pb(mp(Rec(0, x[i][0] - 1, 0, y[i][0] - 1), mp(-1, i)));
        }
        if (x[i][0] > 0 && y[i][1] < n - 1) {
            events.pb(mp(Rec(0, x[i][0] - 1, y[i][1] + 1, n - 1), mp(-1, i)));
        }
        if (x[i][1] < n - 1 && y[i][0] > 0) {
            events.pb(mp(Rec(x[i][1] + 1, n - 1, 0, y[i][0] - 1), mp(-1, i)));
        }
        if (x[i][1] < n - 1 && y[i][1] < n - 1) {
            events.pb(mp(Rec(x[i][1] + 1, n - 1, y[i][1] + 1, n - 1), mp(-1, i)));
        }
    }
    FOR(i, 0, sz(events)) {
        Rec rc = events[i].fi;
        int x0 = rc.x0, x1 = rc.x1, y0 = rc.y0, y1 = rc.y1;
        event2[x1].pb(mp(y1, mp(1, i)));
        if (x0) {
            event2[x0 - 1].pb(mp(y1, mp(-1, i)));
        }
        if (y0) {
            event2[x1].pb(mp(y0 - 1, mp(-1, i)));
        }
        if (x0 && y0) {
            event2[x0 - 1].pb(mp(y0 - 1, mp(1, i)));
        }
    }
    FOR(i, 0, n) {
        upd(a[i], 1);
        FOR(j, 0, sz(event2[i])) {
            int y = event2[i][j].fi;
            int sign = event2[i][j].se.fi;
            int ix = event2[i][j].se.se;
            f[ix] += sign * query(y);
        }
    }
    FOR(i, 0, sz(events)) {
        Rec rc = events[i].fi;
        int x0 = rc.x0, x1 = rc.x1, y0 = rc.y0, y1 = rc.y1;
        int sign = events[i].se.fi;
        int ix = events[i].se.se;
        g[ix] += sign * (long long) f[i] * (f[i] - 1) / 2;
    }
    FOR(i, 0, q) {
        g[i] = (long long) n * (n - 1) / 2 - g[i];
        cout << g[i] << "\n";
    }
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}