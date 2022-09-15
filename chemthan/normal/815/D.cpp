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
const int MOD2 = (int) 1e8 + 7;
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

const int maxn = 5e5 + 5;
int n, p, q, r;
int a[maxn];
int b[maxn];
int c[maxn];

int st[maxn << 2];
long long sum[maxn << 2];
int lz[maxn << 2];

void pushdown(int p, int L, int R) {
    if (lz[p]) {
        st[p] = lz[p];
        sum[p] = (long long) lz[p] * (R - L + 1);
        if (L < R) {
            lz[p << 1] = lz[p];
            lz[p << 1 | 1] = lz[p];
        }
        lz[p] = 0;
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
    st[p] = max(st[p << 1], st[p << 1 | 1]);
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}
int query(int p, int L, int R, int mxc) {
    pushdown(p, L, R);
    if (L == R) return L;
    pushdown(p << 1, L, L + R >> 1);
    pushdown(p << 1 | 1, (L + R >> 1) + 1, R);
    if (st[p << 1 | 1] < mxc) return query(p << 1, L, L + R >> 1, mxc);
    return query(p << 1 | 1, (L + R >> 1) + 1, R, mxc);
}
long long query(int p, int l, int r, int L, int R) {
    pushdown(p, L, R);
    if (l > R || r < L) return 0;
    if (l <= L && r >= R) return sum[p];
    return query(p << 1, l, r, L, L + R >> 1) + query(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
}

int compare(int i, int j) {
    if (a[i] != a[j]) return a[i] < a[j];
    return i < j;
}

void upd(int st[], int p, int val) {
    for (st[p += maxn] = val; p > 1; ) p >>= 1, st[p] = max(st[p << 1], st[p << 1 | 1]);
}
int query(int st[], int l, int r) {
    int res = 0;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmax(res, st[l++]);
        if (r & 1) chkmax(res, st[--r]);
    }
    return res;
}

void solve() {
    cin >> n >> p >> q >> r;
    FOR(i, 0, n) cin >> a[i] >> b[i] >> c[i];
    vi ver; FOR(i, 0, n) ver.pb(i);
    sort(all(ver), compare);
    long long ans = 0;
    static int heapb[maxn << 1];
    static int heapc[maxn << 1];
    FOR(i, 0, n) upd(heapb, i, b[i]);
    FOR(i, 0, n) upd(heapc, i, c[i]);
    FOR(i, 1, p + 1) {
        static int ptr = 0;
        while (ptr < n && a[ver[ptr]] < i) {
            int ix = ver[ptr];
            upd(heapb, ix, 0);
            upd(heapc, ix, 0);
            int x = query(1, 0, maxn - 1, c[ix]);
            upd(1, x + 1, b[ix], 0, maxn - 1, c[ix]);
            ptr++;
        }
        int mxb = query(heapb, 0, maxn - 1);
        int mxc = query(heapc, 0, maxn - 1);
        int x = query(1, 0, maxn - 1, mxc);
        chkmin(x, q);
        if (x > mxb) {
            ans += (long long) (x - mxb) * r - query(1, mxb + 1, x, 0, maxn - 1);
        }
        ans += (long long) (q - max(x, mxb)) * (r - mxc);
    }
    cout << ans << "\n";
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