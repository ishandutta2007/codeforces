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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 1e5 + 5;
const int magic = 500;
int n, k;
int a[maxn];
int nxt[maxn];
int off[magic];
int c[maxn];
int f[magic][maxn];
int dp[maxn];

int sum;
void inc(int d) {
    if (0 <= k - off[d] && k - off[d] < maxn) {
        submod(sum, f[d][k - off[d]]);
    }
    off[d]++;
}
void dec(int d) {
    off[d]--;
    if (0 <= k - off[d] && k - off[d] < maxn) {
        addmod(sum, f[d][k - off[d]]);
    }
}
void upd(int d, int l, int r, int val) {
    for (int i = d * magic; i < (d + 1) * magic && i < n; i++) {
        if (c[i] + off[d] <= k) {
            submod(sum, f[d][c[i]]);
        }
        f[d][c[i]] = 0;
        c[i] += off[d];
    }
    off[d] = 0;
    for (int i = l; i <= r; i++) {
        c[i] += val;
    }
    for (int i = d * magic; i < (d + 1) * magic && i < n; i++) {
        addmod(f[d][c[i]], dp[i + 1]);
        if (c[i] <= k) {
            addmod(sum, dp[i + 1]);
        }
    }
}
void upd(int l, int r, int val) {
    int il = (l + magic - 1) / magic;
    int ir = r / magic;
    FOR(i, il, ir) {
        if (val == 1) {
            inc(i);
        }
        else {
            dec(i);
        }
    }
    if (l < il * magic) {
        upd(il - 1, l, min(il * magic - 1, r), val);
    }
    if (il <= ir && ir * magic <= r) {
        upd(ir, max(l, ir * magic), r, val);
    }
}

void chemthan() {
    cin >> n >> k;
    FOR(i, 0, n) cin >> a[i];
    dp[n] = 1;
    vi lst(n + 1, n);
    fill_n(nxt, n + 1, n);
    FORd(i, n, 0) {
        addmod(sum, dp[i + 1]);
        addmod(f[i / magic][0], dp[i + 1]);
        nxt[i] = lst[a[i]];
        if (nxt[i] == n) {
            upd(i, nxt[i] - 1, 1);
        }
        else {
            int ni = nxt[i];
            upd(ni, nxt[ni] - 1, -1);
            upd(i, ni - 1, 1);
        }
        dp[i] = sum;
        lst[a[i]] = i;
    }
    cout << dp[0] << "\n";
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