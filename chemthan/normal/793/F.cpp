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
    static const int maxn = 1e5 + 5;
    int st[maxn << 2];
    int lz[maxn << 2];
    
    void init() {
        fill_n(st, maxn << 2, INF);
        fill_n(lz, maxn << 2, INF);
    }
    void pushdown(int p, int L, int R) {
        if (lz[p] != INF) {
            chkmin(st[p], lz[p]);
            if (L < R) {
                chkmin(lz[p << 1], lz[p]);
                chkmin(lz[p << 1 | 1], lz[p]);
            }
            lz[p] = INF;
        }
    }
    void upd(int p, int l, int r, int L, int R, int val) {
        pushdown(p, L, R);
        if (l > R || r < L) return;
        if (l <= L && r >= R) {
            chkmin(lz[p], val);
            pushdown(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        st[p] = max(st[p << 1], st[p << 1 | 1]);
    }
    int query(int p, int l, int r, int L, int R, int val) {
        pushdown(p, L, R);
        if (l > R || r < L) return -1;
        if (l <= L && r >= R) {
            if (st[p] <= val) return -1;
            if (L == R) return L;
        }
        int res = query(p << 1, l, r, L, L + R >> 1, val);
        if (res >= 0) return res;
        return query(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
    }
} seg;

const int maxn = 1e5 + 5;
int n, m, q;
int l[maxn];
int r[maxn];
vi g[maxn];
int ans[maxn];

void solve() {
    cin >> n >> m;
    FOR(i, 0, m) {
        cin >> l[i] >> r[i]; l[i]--, r[i]--;
        g[l[i]].pb(r[i]);
    }
    static vii que[maxn];
    cin >> q;
    FOR(i, 0, q) {
        int x, y; cin >> x >> y; x--, y--;
        que[x].pb(mp(y, i));
    }
    seg.init();
    FORd(i, n, 0) {
        FOR(j, 0, sz(g[i])) {
            int k = g[i][j];
            seg.upd(1, i, k - 1, 0, n - 1, k);
        }
        FOR(j, 0, sz(que[i])) {
            int x = i;
            int y = que[i][j].fi;
            int ix = que[i][j].se;
            ans[ix] = max(x, seg.query(1, x, y, 0, n - 1, y));
        }
    }
    FOR(i, 0, q) cout << ans[i] + 1 << "\n";
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