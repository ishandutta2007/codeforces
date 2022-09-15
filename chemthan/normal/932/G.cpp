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

struct PalindromicTree {
    static const int maxn = 1e6 + 5;
    static const int maxc = 26;
    int next[maxn][maxc], link[maxn], cnt[maxn];
    int num[maxn], len[maxn], s[maxn];
    int dif[maxn], slink[maxn];
    int dp[maxn], series[maxn];
    int last, n, p;
    int newnode(int l) {
        for (int i = 0; i < maxc; i++) next[p][i] = 0;
        cnt[p] = num[p] = 0;
        len[p] = l;
        return p++;
    }
    void init() {
        p = 0;
        newnode(0), newnode(-1);
        n = last = 0;
        s[n] = -1, link[0] = 1;
        dp[0] = series[0] = 1;
    }
    int getlink(int x) {
        while (s[n - len[x] - 1] != s[n]) {
            x = link[x];
        }
        return x;
    }
    void add(char c) {
        c -= 'a';
        s[++n] = c;
        int cur = getlink(last);
        if (!next[cur][c]) {
            int now = newnode(len[cur] + 2);
            link[now] = next[getlink(link[cur])][c];
            next[cur][c] = now;
            dif[now] = len[now] - len[link[now]];
            if (dif[now] == dif[link[now]]) {
                slink[now] = slink[link[now]];
            }
            else {
                slink[now] = link[now];
            }
            num[now] = num[link[now]] + 1;
        }
        last = next[cur][c];
        cnt[last]++;
        for (int u = last; len[u] > 0; u = slink[u]) {
            series[u] = dp[n - len[slink[u]] - dif[u]];
            if (dif[u] == dif[link[u]]) {
                addmod(series[u], series[link[u]]);
            }
            if (!(n & 1)) {
                addmod(dp[n], series[u]);
            }
        }
    }
    void upd() {
        for (int i = p - 1; i >= 0; i--) {
            cnt[link[i]] += cnt[i];
        }
    }
} pdt;

void chemthan() {
    string s; cin >> s;
    string t;
    FOR(i, 0, sz(s) / 2) {
        t += s[i];
        t += s[sz(s) - i - 1];
    }
    pdt.init();
    for (char c : t) {
        pdt.add(c);
    }
    cout << pdt.dp[sz(s)] << "\n";
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