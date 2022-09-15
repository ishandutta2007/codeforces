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
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 2000 + 5;
int n, k;
string a[maxn];
int dp[maxn][maxn];

void chemthan() {
    cin >> n >> k;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) FOR(j, 0, n) dp[i][j] = INF;
    dp[0][0] = a[0][0] != 'a';
    FOR(i, 0, n) FOR(j, 0, n) {
        if (i + 1 < n) {
            chkmin(dp[i + 1][j], dp[i][j] + (a[i + 1][j] != 'a'));
        }
        if (j + 1 < n) {
            chkmin(dp[i][j + 1], dp[i][j] + (a[i][j + 1] != 'a'));
        }
    }
    if (dp[n - 1][n - 1] <= k) {
        FOR(i, 0, n + n - 1) cout << 'a';
        cout << "\n";
        return;
    }
    string res;
    queue<int> que;
    int mx = -1;
    FOR(i, 0, n) FOR(j, 0, n) {
        if (dp[i][j] == k) {
            if (chkmax(mx, i + j)) {
                while (sz(que)) que.pop();
                que.push(i), que.push(j);
            }
            else if (mx == i + j) {
                que.push(i), que.push(j);
            }
        }
    }
    if (mx == -1) {
        mx++;
        res += a[0][0];
        que.push(0), que.push(0);
    }
    else {
        FOR(i, 0, mx + 1) res += "a";
    }
    static int vis[maxn][maxn];
    FOR(i, mx + 1, n + n - 1) {
        queue<int> nque;
        char mn = 'z';
        while (sz(que)) {
            int u = que.front(); que.pop();
            int v = que.front(); que.pop();
            if (u + 1 < n && !vis[u + 1][v]) {
                vis[u + 1][v] = 1;
                if (chkmin(mn, a[u + 1][v])) {
                    while (sz(nque)) nque.pop();
                    nque.push(u + 1), nque.push(v);
                }
                else if (mn == a[u + 1][v]) {
                    nque.push(u + 1), nque.push(v);
                }
            }
            if (v + 1 < n && !vis[u][v + 1]) {
                vis[u][v + 1] = 1;
                if (chkmin(mn, a[u][v + 1])) {
                    while (sz(nque)) nque.pop();
                    nque.push(u), nque.push(v + 1);
                }
                else if (mn == a[u][v + 1]) {
                    nque.push(u), nque.push(v + 1);
                }
            }
        }
        res += mn;
        que = nque;
    }
    cout << res << "\n";
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