#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
#define prec(n) fixed << setprecision(n)
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
template<class T1, class T2> inline int chkmin(T1& a, const T2& val) {return val < a ? a = val, 1 : 0;}
template<class T1, class T2> inline int chkmax(T1& a, const T2& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return (int) fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

pi cel[110 * 110 * 5];
long long cnt[110][110];

void solve() {
    int n, m;
    long long k;
    int x, y;
    cin >> n >> m >> k >> x >> y; x--, y--;
    if (n == 1) {
        cout << (k + m - 1) / m << " " << k / m << " " << k / m + (k % m > y) << "\n";
        return;
    }
    long long turn = k / (n - 1) / 2 / m;
    long long r = k % ((n - 1) * 2 * m);
    int ptr = 0;
    FOR(i, 0, n) FOR(j, 0, m) {
        cel[ptr++] = mp(i, j);
    }
    FORd(i, n - 1, 1) FOR(j, 0, m) {
        cel[ptr++] = mp(i, j);
    }
    FOR(i, 0, n) FOR(j, 0, m) {
        if (!i || i == n - 1) {
            cnt[i][j] = turn;
        }
        else {
            cnt[i][j] = turn + turn;
        }
    }
    FOR(i, 0, r) {
        int u = cel[i].fi;
        int v = cel[i].se;
        cnt[u][v]++;
    }
    long long mx = 0, mn = LINF;
    FOR(i, 0, n) FOR(j, 0, m) {
        chkmax(mx, cnt[i][j]);
        chkmin(mn, cnt[i][j]);
    }
    cout << mx << " " << mn << " " << cnt[x][y] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    solve();
    cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms\n";
    return 0;
}