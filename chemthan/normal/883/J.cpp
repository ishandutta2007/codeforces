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

struct SegTree {
    static const int maxn = 1e5 + 5;
    long long st[maxn << 2];
    long long lz[maxn << 2];
    
    void push(int p, int L, int R) {
        if (lz[p]) {
            st[p] += lz[p];
            if (L < R) {
                lz[p << 1] += lz[p];
                lz[p << 1 | 1] += lz[p];
            }
            lz[p] = 0;
        }
    }
    void pull(int p) {
        st[p] = max(st[p << 1], st[p << 1 | 1]);
    }
    void upd(int p, int l, int r, int L, int R, int val) {
        push(p, L, R);
        if (l > R || r < L) return;
        if (l <= L && r >= R) {
            lz[p] = val;
            push(p, L, R);
            return;
        }
        upd(p << 1, l, r, L, L + R >> 1, val);
        upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
        pull(p);
    }
    long long query(int p, int l, int r, int L, int R) {
        push(p, L, R);
        if (l > R || r < L) return -LINF;
        if (l <= L && r >= R) return st[p];
        return max(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
    }
} seg;

const int maxn = 1e5 + 5;
int n, m;
int a[maxn];
int b[maxn];
int p[maxn];
int f[maxn];

void solve() {
    cin >> n >> m;
    FOR(i, 0, n) {
        cin >> a[i];
        seg.upd(1, i, n - 1, 0, n - 1, -a[i]);
    }
    FOR(i, 0, m) cin >> b[i];
    FOR(i, 0, m) cin >> p[i];
    vector<pair<pi, int> > vals;
    FOR(i, 0, m) vals.pb(mp(mp(b[i], p[i]), i));
    sort(all(vals));
    fill_n(f, m, -1);
    int ptr = 0;
    FORd(i, n, 0) {
        while (ptr < m && vals[ptr].fi.fi <= a[i]) {
            f[vals[ptr].se] = i;
            ptr++;
        }
    }
    vals.clear();
    FOR(i, 0, m) vals.pb(mp(mp(p[i], b[i]), i));
    sort(all(vals));
    int ans = 0;
    FOR(ii, 0, m) {
        int i = vals[ii].se;
        if (~f[i]) {
            int x = vals[ii].fi.fi;
            if (seg.query(1, f[i], n - 1, 0, n - 1) + x <= 0) {
                ans++;
                seg.upd(1, f[i], n - 1, 0, n - 1, x);
            }
        }
    }
    cout << ans << "\n";
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
        assert(freopen(argv[2], "w", stdout));
    }
    solve();
    if (!JUDGE_ONLINE) {
        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}