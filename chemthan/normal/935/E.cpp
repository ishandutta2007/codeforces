#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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

const int maxn = 1e5 + 5;
const int maxk = 1e2 + 5;
string s;
int p, m;
int num;
int f[maxn];
int g[maxn];
int h[maxn];
int mn[maxn][maxk];
int mx[maxn][maxk];
int cnt[maxn];

int go(string s) {
    if (sz(s) == 1) {
        f[num] = g[num] = -1;
        h[num] = s[0] - '0';
        return num++;
    }
    s = s.substr(1, sz(s) - 2);
    int tot = 0;
    FOR(i, 0, sz(s)) {
        if (s[i] == '(') {
            tot++;
        }
        else if (s[i] == ')') {
            tot--;
        }
        else if (s[i] == '?') {
            if (!tot) {
                int t = num++;
                f[t] = go(s.substr(0, i));
                g[t] = go(s.substr(i + 1, sz(s) - i - 1));
                h[t] = -1;
                return t;
            }
        }
    }
}

void dfs1(int u) {
    fill_n(mn[u], maxk, +INF);
    fill_n(mx[u], maxk, -INF);
    if (f[u] == -1) {
        mn[u][0] = mx[u][0] = h[u];
        return;
    }
    dfs1(f[u]), dfs1(g[u]);
    cnt[u] = cnt[f[u]] + cnt[g[u]] + 1;
    FOR(i, 0, min(maxk, cnt[f[u]] + 1)) FOR(j, 0, min(maxk, cnt[g[u]] + 1)) {
        if (i + j + 1 < maxk) {
            chkmin(mn[u][i + j + 1], mn[f[u]][i] + mn[g[u]][j]);
            chkmax(mx[u][i + j + 1], mx[f[u]][i] + mx[g[u]][j]);
        }
        if (i + j < maxk) {
            chkmin(mn[u][i + j], mn[f[u]][i] - mx[g[u]][j]);
            chkmax(mx[u][i + j], mx[f[u]][i] - mn[g[u]][j]);
        }
    }
}
void dfs2(int u) {
    fill_n(mn[u], maxk, +INF);
    fill_n(mx[u], maxk, -INF);
    if (f[u] == -1) {
        mn[u][0] = mx[u][0] = h[u];
        return;
    }
    dfs2(f[u]), dfs2(g[u]);
    cnt[u] = cnt[f[u]] + cnt[g[u]] + 1;
    FOR(i, 0, min(maxk, cnt[f[u]] + 1)) FOR(j, 0, min(maxk, cnt[g[u]] + 1)) {
        if (i + j < maxk) {
            chkmin(mn[u][i + j], mn[f[u]][i] + mn[g[u]][j]);
            chkmax(mx[u][i + j], mx[f[u]][i] + mx[g[u]][j]);
        }
        if (i + j  + 1 < maxk) {
            chkmin(mn[u][i + j + 1], mn[f[u]][i] - mx[g[u]][j]);
            chkmax(mx[u][i + j + 1], mx[f[u]][i] - mn[g[u]][j]);
        }
    }
}

void chemthan() {
    cin >> s >> p >> m;
    int rt = go(s);
    if (p < m) {
        dfs1(rt);
        cout << mx[rt][p] << "\n";
    }
    else {
        dfs2(rt);
        cout << mx[rt][m] << "\n";
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