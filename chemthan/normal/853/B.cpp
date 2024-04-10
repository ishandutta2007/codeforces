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

const int maxn = 1e6 + 5;
int n, m, k;
int d[maxn];
int f[maxn];
int t[maxn];
int c[maxn];
long long mn[maxn];
long long tot;
long long prf[maxn];
long long suf[maxn];

void solve() {
    scanf("%d%d%d", &n, &m, &k);
    vector<pair<pi, pi> > v;
    FOR(i, 0, m) {
        scanf("%d%d%d%d", d + i, f + i, t + i, c + i);
        v.pb(mp(mp(d[i], f[i]), mp(t[i], c[i])));
    }
    sort(all(v));
    FOR(i, 0, m) {
        d[i] = v[i].fi.fi;
        f[i] = v[i].fi.se;
        t[i] = v[i].se.fi;
        c[i] = v[i].se.se;
    }
    fill_n(mn, n + 1, (long long) 1e12);
    tot = accumulate(mn + 1, mn + n + 1, 0LL);
    int ptr = 0;
    FOR(i, 0, maxn) {
        prf[i] = tot;
        while (ptr < m && d[ptr] <= i) {
            if (!t[ptr]) {
                if (mn[f[ptr]] > c[ptr]) {
                    tot -= mn[f[ptr]];
                    mn[f[ptr]] = c[ptr];
                    tot += mn[f[ptr]];
                }
            }
            ptr++;
        }
    }
    fill_n(mn, n + 1, (long long) 1e12);
    tot = accumulate(mn + 1, mn + n + 1, 0LL);
    ptr = m - 1;
    FORd(i, maxn, 0) {
        suf[i] = tot;
        while (ptr >= 0 && d[ptr] >= i) {
            if (!f[ptr]) {
                if (mn[t[ptr]] > c[ptr]) {
                    tot -= mn[t[ptr]];
                    mn[t[ptr]] = c[ptr];
                    tot += mn[t[ptr]];
                }
            }
            ptr--;
        }
    }
    long long ans = (long long) 1e12;
    FOR(i, 0, maxn - k + 1) {
        chkmin(ans, prf[i] + suf[i + k - 1]);
    }
    if (ans == (long long) 1e12) {
        ans = -1;
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
        //ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}