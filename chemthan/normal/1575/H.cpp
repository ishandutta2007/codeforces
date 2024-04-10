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
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n"; 

struct KMP {
    string s;
    int n;
    vector<int> link;
    void build(string str) {
        s = str;
        n = sz(s);
        link.resize(n);
        int cur = link[0] = -1;
        for (int i = 1; i < n; i++) {
            while (cur >= 0 && s[i] != s[cur + 1]) cur = link[cur];
            if (s[i] == s[cur + 1]) cur++;
            link[i] = cur;
        }
    }
    vector<int> query(char* t) {
        vector<int> res;
        int k = strlen(t);
        int cur = -1;
        for (int i = 0; i < k; i++) {
            while (cur >= 0 && t[i] != s[cur + 1]) cur = link[cur];
            if (t[i] == s[cur + 1]) cur++;
            if (cur == n - 1) {
                res.push_back(i - n + 1);
                cur = link[cur];
            }
        }
        return res;
    }
} kmp;

void chemthan() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    //int n = 500, m = 250;
    //string a, b;
    //FOR(i, 0, n) a.pb('0' + mrand(2));
    //FOR(i, 0, n) b.pb('0' + mrand(2));
    kmp.build(b);
    vector<vi> mem(m + 5, vi(2, -2));
    auto next_state = [&] (int v, int p) {
        int& res = mem[v + 1][p];
        if (res != -2) return res;
        res = v;
        while (0 <= res && b[res + 1] != '0' + p) res = kmp.link[res];
        if (b[res + 1] == '0' + p) res++;
        return res;
    };
    vector<vector<vi>> dp(2, vector<vi>(m + 5, vi(n - m + 5, INF)));
    int cur = 0, prv = 1;
    FORd(u, n + 1, 0) {
        FOR(v, 0, m + 1) FOR(c, 0, n - m + 2) dp[cur][v][c] = INF;
        FOR(v, -1, m - 1) FOR(c, 0, n - m + 2) {
            int& res = dp[cur][v + 1][c];
            if (u == n) {
                if (!c) {
                    res = 0;
                }
                continue;
            }
            FOR(i, 0, 2) {
                int cost = a[u] != '0' + i;
                int nv = next_state(v, i);
                int nc = c;
                if (nv == m - 1) {
                    nc--;
                    nv = kmp.link[nv];
                }
                if (0 <= nc) {
                    chkmin(res, dp[prv][nv + 1][nc] + cost);
                }
            }
        }
        swap(cur, prv);
    }
    FOR(i, 0, n - m + 2) {
        int res = dp[prv][0][i];
        if (n < res) res = -1;
        cout << res << " \n"[i == n - m + 1];
    }
}

int32_t main(int32_t argc, char* argv[]) {
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