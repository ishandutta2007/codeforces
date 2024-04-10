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

const int maxn = 5e5 + 5;
int n, q;
int a[maxn];
int lst[maxn];
int l[maxn];
int r[maxn];

vector<pair<pi, int> > st[maxn << 2];
void upd(int p, int i, int L, int R, pair<pi, int> val) {
    if (i < L || R < i) return;
    st[p].pb(val);
    if (L < R) {
        upd(p << 1, i, L, L + R >> 1, val);
        upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
    }
}
void build(int p, int L, int R) {
    int mx = -1, ix = -1;
    for (pair<pi, int>& e : st[p]) {
        if (chkmax(e.fi.se, mx)) {
            e.se = ix;
        }
        if (chkmax(mx, e.fi.se)) {
            ix = e.se;
        }
    }
    if (L < R) {
        build(p << 1, L, L + R >> 1);
        build(p << 1 | 1, (L + R >> 1) + 1, R);
    }
}
int query(int p, int l, int r, int L, int R, pi val) {
    if (l > R || r < L) return -1;
    if (l <= L && R <= r) {
        int k = lower_bound(all(st[p]), mp(mp(val.fi, -INF), -INF)) - st[p].begin() - 1;
        if (k >= 0 && st[p][k].fi.se > val.se) {
            return st[p][k].se;
        }
        return -1;
    }
    return max(query(p << 1, l, r, L, L + R >> 1, val), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val));
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    fill_n(lst, maxn, -1);
    FOR(i, 0, n) {
        l[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    fill_n(lst, maxn, n);
    FORd(i, n, 0) {
        r[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    vector<pair<pi, int> > vals;
    FOR(i, 0, n) {
        vals.pb(mp(mp(l[i], r[i]), i));
    }
    sort(all(vals));
    for (auto it : vals) {
        upd(1, it.se, 0, n - 1, it);
    }
    build(1, 0, n - 1);
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        int ix = query(1, l, r, 0, n - 1, mp(l, r));
        if (ix == -1) {
            cout << 0 << "\n";
        }
        else {
            cout << a[ix] << "\n";
        }
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