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

template<class T> struct SegmenTree {
    static const int MAXN = 2e6 + 5;
    T st[MAXN << 2];
    T lz[MAXN << 2];
    void pushdown(int node, int L, int R) {
        if (lz[node]) {
            st[node] += lz[node];
            if (L < R) {
                lz[node << 1] += lz[node];
                lz[node << 1 | 1] += lz[node];
            }
            lz[node] = 0;
        }
    }
    void upd(int node, int l, int r, int L, int R, T val) {
        pushdown(node, L, R);
        if (l > R || r < L) return;
        if (l <= L && r >= R) {
            lz[node] = val;
            pushdown(node, L, R);
            return;
        }
        upd(node << 1, l, r, L, L + R >> 1, val);
        upd(node << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        st[node] = min(st[node << 1], st[node << 1 | 1]);
    }
    T query(int node, int l, int r, int L, int R) {
        pushdown(node, L, R);
        if (l > R || r < L) return INF;
        if (l <= L && r >= R) return st[node];
        return min(query(node << 1, l, r, L, L + R >> 1), query(node << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
};
SegmenTree<int> seg;

const int maxn = 2e6 + 5;
int n;
int l[maxn];
int r[maxn];

void solve() {
    cin >> n;
    vi dc;
    FOR(i, 0, n) {
        cin >> l[i] >> r[i];
        FOR(d, -1, 1 + 1) {
            dc.pb(l[i] + d), dc.pb(r[i] + d);
        }
    }
    sort(all(dc)), uni(dc);
    FOR(i, 0, n) {
        l[i] = lower_bound(all(dc), l[i]) - dc.begin();
        r[i] = lower_bound(all(dc), r[i]) - dc.begin();
        seg.upd(1, l[i], r[i], 0, sz(dc) - 1, 1);
    }
    FOR(i, 0, n) {
        seg.upd(1, l[i], r[i], 0, sz(dc) - 1, -1);
        if (seg.query(1, l[i], r[i], 0, sz(dc) - 1)) {
            cout << i + 1 << "\n";
            return;
        }
        seg.upd(1, l[i], r[i], 0, sz(dc) - 1, 1);
    }
    cout << -1 << "\n";
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