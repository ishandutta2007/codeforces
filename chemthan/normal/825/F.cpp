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

const int maxn = 8000 + 5;
int n;
string s;
int f[maxn][maxn];
int g[maxn][maxn];
int h[maxn];
vi dvs[maxn];
int dp[maxn];

struct KMP {
    string s;
    int n;
    int link[maxn];
    int len[maxn];
    void build(char* str, int* f) {
        s = str, n = (int) s.size();
        int cur = link[0] = -1;
        f[0] = 2, len[0] = 1;
        for (int i = 1; i < n; i++) {
            while (cur >= 0 && s[i] != s[cur + 1]) cur = link[cur];
            if (s[i] == s[cur + 1]) cur++;
            link[i] = cur;
            if (cur >= 0) {
                if (i - cur == len[cur]) {
                    len[i] = len[cur];
                    f[i] = g[i + 1][(i + 1) / len[i]];
                }
                else {
                    len[i] = i + 1;
                    f[i] = g[i + 1][1];
                }
            }
            else {
                len[i] = i + 1;
                f[i] = g[i + 1][1];
            }
        }
    }
} kmp;

int calc(int pos) {
    if (pos == n) return 0;
    int& res = dp[pos];
    if (~res) return res;
    res = INF;
    FOR(i, pos, n) {
        chkmin(res, f[pos][i - pos] + calc(i + 1));
    }
    return res;
}

void solve() {
    FOR(i, 1, maxn) {
        int t = i;
        while (t) {
            h[i]++;
            t /= 10;
        }
    }
    FOR(i, 1, maxn) {
        for (int j = i; j < maxn; j += i) {
            dvs[j].pb(i);
        }
    }
    FOR(i, 1, maxn) FOR(j, 1, i + 1) {
        g[i][j] = INF;
        if (i % j == 0) {
            FOR(k, 0, sz(dvs[j])) {
                int d = dvs[j][k];
                chkmin(g[i][j], h[d] + i / d);
            }
        }
    }
    cin >> s; n = sz(s);
    FOR(i, 0, n) {
        kmp.build((char*) s.substr(i).data(), f[i]);
    }
    ms(dp, -1);
    cout << calc(0) << "\n";
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