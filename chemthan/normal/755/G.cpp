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
template<class T1, class T2> inline int chkmin(T1& a, const T2& val) {return val < a ? a = val, 1 : 0;}
template<class T1, class T2> inline int chkmax(T1& a, const T2& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return (int) fpow(a, p - 2, p);}

const int maxn = 1 << 20;
const int mod = 998244353;
void fft(int a[], int p, int r, int n) {
    for (int m = n, h; h = m / 2, m >= 2; r = (long long) r * r % p, m = h) {
        for (int i = 0, w = 1; i < h; i++, w = (long long) w * r % p) {
            for (int j = i; j < n; j += m) {
                int k = j + h, x = a[j] - a[k];
                if (x < 0) x += p;
                a[j] += a[k];
                if (a[j] >= p) a[j] -= p;
                a[k] = (long long) w * x % p;
            }
        }
    }
    for (int i = 0, j = 1; j < n - 1; j++) {
        for (int k = n / 2; k > (i ^= k); k /= 2);
        if (j < i) swap(a[i], a[j]);
    }
}

int n, k;
int c[maxn];
int fa[maxn];
int fb[maxn];

void multiply(vi& a, vi& b, int c[], int p) {
    int na = sz(a), nb = sz(b);
    int n = 1, d = p - 1; while (n < na + nb - 1) n <<= 1, d >>= 1;
    fill_n(fa, n, 0), fill_n(fb, n, 0);
    FOR(i, 0, na) fa[i] = a[i];
    FOR(i, 0, nb) fb[i] = b[i];
    int w1 = fpow(3, d, p);
    int w2 = inv(w1, p);
    fft(fa, p, w1, n);
    fft(fb, p, w1, n);
    FOR(i, 0, n) fa[i] = mult(fa[i], fb[i], p);
    fft(fa, p, w2, n);
    int rem = inv(n, p);
    FOR(i, 0, n) c[i] = mult(fa[i], rem, p);
}

struct Num {
    vi a, b;
    Num() {}
    Num(vi a, vi b) : a(a), b(b) {}
    Num(const Num& rhs) : a(rhs.a), b(rhs.b) {}
};

Num merge(Num& x, Num& y) {
    Num res;
    int ka = max(sz(x.a) + sz(y.a) - 1, sz(x.b) + sz(y.b) + 1);
    ka = min(ka, k + 1);
    int kb = max(sz(x.a) + sz(y.b) - 1, sz(x.b) + sz(y.a) - 1);
    kb = min(kb, k + 1);
    res.a.resize(ka, 0);
    res.b.resize(kb, 0);
    multiply(x.a, y.a, c, mod);
    FOR(i, 0, min(k + 1, sz(x.a) + sz(y.a) - 1)) addmod(res.a[i], c[i], mod);
    multiply(x.b, y.b, c, mod);
    static int cof[] = {1, 6, 1};
    FOR(i, 0, sz(x.b) + sz(y.b) - 1) FOR(j, 0, 3) {
        if (i + j < ka) {
            addmod(res.a[i + j], mult(c[i], cof[j], mod), mod);
        }
    }
    multiply(x.a, y.b, c, mod);
    FOR(i, 0, min(k + 1, sz(x.a) + sz(y.b) - 1)) {
        addmod(res.b[i], c[i], mod);
    }
    multiply(x.b, y.a, c, mod);
    FOR(i, 0, min(k + 1, sz(x.b) + sz(y.a) - 1)) {
        addmod(res.b[i], c[i], mod);
    }
    return res;
}

Num pow(Num x, int k) {
    Num res = x, tmp = x; k--;
    while (k) {
        if (k & 1) res = merge(res, tmp);
        tmp = merge(tmp, tmp);
        k >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> k;
    vi a, b; a.pb(1), a.pb(1), b.pb(1);
    Num res = pow(Num(a, b), n + 1);
    while (sz(res.b) < k + 1) res.b.pb(0);
    FOR(i, 1, k + 1) cout << mult(res.b[i], fpow(inv(2, mod), n, mod), mod) << " \n"[i == k];
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