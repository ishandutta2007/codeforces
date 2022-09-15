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

void XORFFT(int a[], int n, int p, int invert) {
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                int u = a[j + k], v = a[i + j + k];
                a[j + k] = u + v;
                if (a[j + k] >= p) a[j + k] -= p;
                a[i + j + k] = u - v;
                if (a[i + j + k] < 0) a[i + j + k] += p;
            }
        }
    }
    if (invert) {
        long long inv = fpow(n, p - 2, p);
        for (int i = 0; i < n; i++) a[i] = a[i] * inv % p;
    }
}
void modified_XORFFT(int a[], int n, int p, int invert) {
    for (int i = n / 2; i >= 1; i >>= 1) {
        int j = n - (i << 1);
        for (int k = 0; k < i; k++) {
            int u = a[j + k], v = a[i + j + k];
            a[j + k] = u + v;
            if (a[j + k] >= p) a[j + k] -= p;
            a[i + j + k] = u - v;
            if (a[i + j + k] < 0) a[i + j + k] += p;
        }
    }
}

const int maxn = 50;
int n;
string a[maxn];
int dj[maxn];
int size[maxn];
map<int, int> hs;

int query(int x) {
    if (hs.count(x)) return hs[x];
    int res = sz(hs);
    return hs[x] = res;
}

void init() {
    FOR(i, 0, n) dj[i] = i, size[i] = 1;
}
int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v) {
    int p = find(u);
    int q = find(v);
    if (p != q) {
        dj[p] = q;
        size[q] += size[p];
    }
}

void solve() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    init();
    FOR(i, 0, n) FOR(j, i + 1, n) if (a[i][j] == 'A') {
        join(i, j);
    }
    FOR(i, 0, n) FOR(j, i + 1, n) if (a[i][j] == 'X' && find(i) == find(j)) {
        cout << -1 << "\n";
        return;
    }
    FOR(i, 0, n) if (dj[i] == i && size[i] > 1) {
        query(i);
    }
    static int f[maxn];
    FOR(i, 0, n) FOR(j, i + 1, n) if (a[i][j] == 'O') {
        int u = find(i);
        int v = find(j);
        if (size[u] > 1 && size[v] > 1) {
            u = query(u);
            v = query(v);
            f[u] |= 1 << v;
            f[v] |= 1 << u;
        }
    }
    FOR(i, 0, n) FOR(j, i + 1, n) if (a[i][j] == 'X') {
        int u = find(i);
        int v = find(j);
        if (size[u] > 1 && size[v] > 1) {
            u = query(u);
            v = query(v);
            f[u] |= 1 << v;
            f[u] ^= 1 << v;
            f[v] |= 1 << u;
            f[v] ^= 1 << u;
        }
    }
    int tot = 0;
    FOR(i, 0, n) tot += dj[i] == i;
    int k = sz(hs);
    if (!k) {
        cout << n - 1 << "\n";
        return;
    }
    static int g[1 << 23];
    static int gg[1 << 23];
    fill_n(gg, 1 << 23, 1);
    g[0] = 1;
    FOR(msk, 1, 1 << k) {
        int d = __lg(msk);
        int pmsk = msk ^ (1 << d);
        if (g[pmsk] && (f[d] & pmsk) == pmsk) {
            g[msk] = 1;
        }
    }
    XORFFT(g, 1 << k, FFTMOD, 0);
    FOR(i, 1, k + 1) {
        FOR(j, 0, 1 << k) gg[j] = mult(gg[j], g[j], FFTMOD);
        static int g3[1 << 23];
        FOR(j, 0, 1 << k) g3[j] = gg[j];
        modified_XORFFT(g3, 1 << k, FFTMOD, 1);
        if (g3[(1 << k) - 1]) {
            int ones = tot - k;
            cout << (n - ones) + i - 1 + ones << "\n";
            return;
        }
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
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}