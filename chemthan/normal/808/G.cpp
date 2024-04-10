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
#define chkpt cerr << "-----\n";

struct KMP {
    static const int MAXC = 26;
    string s;
    int n;
    vector<int> link;
    vector<int> nxt[MAXC];
    void build(string str) {
        s = str, n = (int) s.size();
        link.resize(n);
        for (int i = 0; i < MAXC; i++) {
            nxt[i].resize(n);
        }
        int cur = link[0] = -1;
        for (int i = 1; i < n; i++) {
            while (cur >= 0 && s[i] != s[cur + 1]) cur = link[cur];
            if (s[i] == s[cur + 1]) cur++;
            link[i] = cur;
        }
        for (int c = 0; c < MAXC; c++) {
            for (int i = 0; i < n; i++) {
                if (s[i] == 'a' + c) {
                    nxt[c][i] = i + 1;
                }
                else if (i && ~link[i - 1]) {
                    nxt[c][i] = nxt[c][link[i - 1] + 1];
                }
                else {
                    if (s[0] == 'a' + c) {
                        nxt[c][i] = 1;
                    }
                    else {
                        nxt[c][i] = 0;
                    }
                }
            }
        }
    }
} kmp;

int n, m;
string s, t;
vector<vi> dp;

int func(int u, int v) {
    if (u == n) return 0;
    int& res = dp[u][v];
    if (~res) return res;
    res = 0;
    if (s[u] != '?') {
        int c = s[u] - 'a';
        if (kmp.nxt[c][v] == m) {
            chkmax(res, func(u + 1, kmp.link[v] + 1) + 1);
        }
        else {
            chkmax(res, func(u + 1, kmp.nxt[c][v]));
        }
    }
    else {
        FOR(c, 0, 26) {
            if (kmp.nxt[c][v] == m) {
                chkmax(res, func(u + 1, kmp.link[v] + 1) + 1);
            }
            else {
                chkmax(res, func(u + 1, kmp.nxt[c][v]));
            }
        }
    }
    return res;
}

void solve() {
    cin >> s >> t;
    n = sz(s), m = sz(t);
    kmp.build(t);
    dp.resize(n + 1);
    FOR(i, 0, n + 1) {
        dp[i].resize(m + 1);
        FOR(j, 0, m + 1) {
            dp[i][j] = -1;
        }
    }
    cout << func(0, 0) << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    } else {
        //ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}