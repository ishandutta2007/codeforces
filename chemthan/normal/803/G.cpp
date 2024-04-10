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
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

struct SegTree {
    static const int maxn = 1e6 + 5;
    int st[maxn << 2];
    int lz[maxn << 2];
    
    void init() {
        fill_n(st, maxn << 2, +INF);
        fill_n(lz, maxn << 2, -1);
    }
    void pushdown(int p, int L, int R) {
        if (lz[p] != -1) {
            st[p] = lz[p];
            if (L < R) {
                lz[p << 1] = lz[p];
                lz[p << 1 | 1] = lz[p];
            }
            lz[p] = -1;
        }
    }
    void upd(int p, int l, int r, int L, int R, int val) {
        pushdown(p, L, R);
        if (l > R || r < L) return;
        if (l <= L && r >= R) {
            lz[p] = val;
            pushdown(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        st[p] = min(st[p << 1], st[p << 1 | 1]);
    }
    int query(int p, int l, int r, int L, int R) {
        pushdown(p, L, R);
        if (l > R || r < L) return INF;
        if (l <= L && r >= R) return st[p];
        return min(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
} seg;

const int maxn = 1e5 + 5;
int n, k, q;
int a[maxn];

int query(int l, int r) {
    if (r - l + 1 >= n) {
        return seg.query(1, 0, n - 1, 0, n - 1);
    }
    int x = (l / n + 1) * n;
    if (x > r) {
        return seg.query(1, l % n, r % n, 0, n - 1);
    }
    return min(seg.query(1, l % n, n - 1, 0, n - 1), seg.query(1, 0, r % n, 0, n - 1));
}

void solve() {
    cin >> n >> k;
    seg.init();
    FOR(i, 0, n) {
        cin >> a[i];
        seg.upd(1, i, i, 0, n - 1, a[i]);
    }
    cin >> q;
    vector<pair<pi, pi> > que;
    vi dc;
    FOR(i, 0, q) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, x; cin >> l >> r >> x; l--, r--;
            que.pb(mp(mp(op, x), mp(l + l, r + r)));
            dc.pb(l + l), dc.pb(r + r);
        }
        else {
            int l, r; cin >> l >> r; l--, r--;
            que.pb(mp(mp(op, 0), mp(l + l, r + r)));
            dc.pb(l + l), dc.pb(r + r);
        }
    }
    sort(all(dc)), uni(dc);
    vii pts;
    FOR(i, 0, sz(dc)) {
        int k = dc[i];
        pts.pb(mp(k, a[k / 2 % n]));
        if (i < sz(dc) - 1) {
            int l = dc[i + 1];
            k >>= 1, l >>= 1;
            if (k + 1 <= l - 1) {
                pts.pb(mp(k << 1 | 1, query(k + 1, l - 1)));
            }
        }
    }
    sort(all(pts));
    seg.init();
    dc.clear();
    FOR(i, 0, sz(pts)) {
        seg.upd(1, i, i, 0, sz(pts) - 1, pts[i].se);
        dc.pb(pts[i].fi);
    }
    FOR(i, 0, q) {
        int op = que[i].fi.fi;
        if (op == 1) {
            int l = lower_bound(all(dc), que[i].se.fi) - dc.begin();
            int r = lower_bound(all(dc), que[i].se.se) - dc.begin();
            int x = que[i].fi.se;
            seg.upd(1, l, r, 0, sz(pts) - 1, x);
        }
        else {
            int l = lower_bound(all(dc), que[i].se.fi) - dc.begin();
            int r = lower_bound(all(dc), que[i].se.se) - dc.begin();
            cout << seg.query(1, l, r, 0, sz(pts) - 1) << "\n";
        }
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