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

const int maxn = 3e5 + 5;
int n;
int a[maxn];
int b[maxn];
int h[maxn];
long long dp[maxn];
map<int, int> dc;

int compare(int i, int j) {
    if (b[i] != b[j]) return b[i] > b[j];
    if (a[i] != a[j]) return a[i] > a[j];
    return i < j;
}

long long st[maxn << 1];
void upd(int p, long long val) {
    for (chkmax(st[p += maxn], val); p > 1; ) p >>= 1, st[p] = max(st[p << 1], st[p <<  1 | 1]);
}
long long query(int l, int r) {
    long long res = 0;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmax(res, st[l++]);
        if (r & 1) chkmax(res, st[--r]);
    }
    return res;
}

void solve() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i] >> b[i] >> h[i], dc[a[i]], dc[a[i] + 1], dc[b[i]];
    int cnt = 0; FORall(it, dc) it->se = cnt++;
    vi v; FOR(i, 0, n) v.pb(i);
    sort(all(v), compare);
    long long ans = 0;
    FORd(ii, n, 0) {
        int i = v[ii];
        dp[i] = query(dc[a[i] + 1], maxn - 1) + h[i];
        upd(dc[b[i]], dp[i]);
        chkmax(ans, dp[i]);
    }
    cout << ans << "\n";
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    solve();
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}