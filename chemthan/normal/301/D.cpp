#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

const int maxn = 200000 + 5;
int n, q;
int a[maxn];
int p[maxn];
int l[maxn];
int r[maxn];
vector<pair<pi, pi> > event;

void upd(int fen[], int n, int p, int val) {
    for (; p <= n; p += p & -p) {
        fen[p] += val;
    }
}
int query(int fen[], int n, int p) {
    int res = 0;
    for (; p > 0; p -= p & -p) {
        res += fen[p];
    }
    return res;
}

void solve() {
    cin >> n >> q;
    FOR(i, 1, n + 1) {
        cin >> a[i];
        p[a[i]] = i;
    }
    FOR(i, 0, q) {
        cin >> l[i] >> r[i];
        event.pb(mp(mp(l[i] - 1, l[i] - 1), mp(+1, i)));
        event.pb(mp(mp(l[i] - 1, r[i]), mp(-1, i)));
        event.pb(mp(mp(r[i], r[i]), mp(+1, i)));
        event.pb(mp(mp(r[i], l[i] - 1), mp(-1, i)));
    }
    sort(all(event));
    static int fen[maxn] = {};
    static long long ans[maxn] = {};
    int ptr = 1;
    FOR(i, 0, sz(event)) {
        int x = event[i].fi.fi;
        int y = event[i].fi.se;
        int s = event[i].se.fi;
        int ix = event[i].se.se;
        while (ptr <= x) {
            for (int j = a[ptr]; j <= n; j += a[ptr]) {
                upd(fen, n, p[j], 1);
            }
            ptr++;
        }
        ans[ix] += s * query(fen, n, y);
    }
    FOR(i, 0, q) cout << ans[i] << "\n";
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    solve();
#ifdef _LOCAL_
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}