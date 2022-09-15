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

const int maxn = 2e5 + 5;
const int magic = 200;
int n, k, q;
int a[maxn];
int b[maxn];
int c[maxn];

struct block_t {
    const static int magic = 500;
    vector<vector<int> > blocks;
    vector<vector<int> > cnt;
    vector<int> offset;
    block_t(int n) {
        int num = (n + magic - 1) / magic;
        blocks.resize(num);
        cnt.resize(num, vector<int>(1 << 14));
        FOR(i, 0, num) {
            int num = min((i + 1) * magic, n) - i * magic;
            blocks[i].resize(num);
            cnt[i][0] = num;
        }
        offset.resize(num);
    }
    void upd(int d, int val) {
        for (int i = 0; (i + 1) * magic - 1 < d; i++) {
            offset[i] ^= val;
        }
        if (d % magic) {
            int i = d / magic;
            FOR(j, 0, sz(blocks[i])) {
                int& x = blocks[i][j];
                cnt[i][x]--;
                x ^= offset[i];
                cnt[i][x]++;
            }
            offset[i] = 0;
            FOR(j, 0, d - i * magic) {
                int& x = blocks[i][j];
                cnt[i][x]--;
                x ^= val;
                cnt[i][x]++;
            }
        }
    }
    int query(int u) {
        int i = u / magic;
        int j = u % magic;
        return blocks[i][j] ^ offset[i];
    }
    int count_zero() {
        int res = 0;
        FOR(i, 0, sz(cnt)) {
            res += cnt[i][offset[i]];
        }
        return res;
    }
};

void solve_small() {
    static int g[maxn];
    vector<block_t> blocks;
    FOR(i, 0, k) {
        blocks.pb(block_t((n - i) / k));
    }
    auto upd = [&] (int i, int val) {
        if (!val) return;
        if (i - k + 1 >= 0) {
            int d = (i - k + 1) / k + 1;
            int r = (i + 1) % k;
            blocks[r].upd(d, val);
        }
        if (i - k >= 0) {
            int d = (i - k) / k + 1;
            int r = i % k;
            blocks[r].upd(d, val);
        }
        for (int j = i; j <= i + 1 && j < k - 1; j++) {
            g[j] ^= val;
        }
    };
    FOR(i, 0, n) upd(i, c[i]);
    int num = 0;
    FOR(i, 0, k - 1) {
        if (g[i] != blocks[i % k].query(i / k)) {
            num++;
        }
    }
    if (num) {
        cout << -1 << "\n";
    }
    else {
        int res = n - k + 1;
        FOR(i, 0, sz(blocks)) {
            res -= blocks[i].count_zero();
        }
        cout << res << "\n";
    }
    while (q--) {
        string s; int u, v; cin >> s >> u >> v; u--;
        if (s == "a") {
            upd(u, a[u] ^ v);
            a[u] = v;
        }
        else {
            upd(u, b[u] ^ v);
            b[u] = v;
        }
        int num = 0;
        FOR(i, 0, k - 1) {
            if (g[i] != blocks[i % k].query(i / k)) {
                num++;
            }
        }
        if (num) {
            cout << -1 << "\n";
        }
        else {
            int res = n - k + 1;
            FOR(i, 0, sz(blocks)) {
                res -= blocks[i].count_zero();
            }
            cout << res << "\n";
        }
    }
}

void solve_large() {
    static int f[maxn];
    static int g[maxn];
    int num1 = 0, num2 = 0;
    auto upd = [&] (int i, int val) {
        if (!val) return;
        for (int j = i - k + 1; j >= 0; j -= k) {
            if (j < k - 1 && f[j] != g[j]) {
                num1--;
            }
            if (f[j]) {
                num2--;
            }
            f[j] ^= val;
            if (j < k - 1 && f[j] != g[j]) {
                num1++;
            }
            if (f[j]) {
                num2++;
            }
        }
        for (int j = i - k; j >= 0; j -= k) {
            if (j < k - 1 && f[j] != g[j]) {
                num1--;
            }
            if (f[j]) {
                num2--;
            }
            f[j] ^= val;
            if (j < k - 1 && f[j] != g[j]) {
                num1++;
            }
            if (f[j]) {
                num2++;
            }
        }
        for (int j = i; j <= i + 1 && j < k - 1; j++) {
            if (f[j] != g[j]) {
                num1--;
            }
            g[j] ^= val;
            if (f[j] != g[j]) {
                num1++;
            }
        }
    };
    FOR(i, 0, n) upd(i, c[i]);
    if (num1) {
        cout << -1 << "\n";
    }
    else {
        cout << num2 << "\n";
    }
    while (q--) {
        string s; int u, v; cin >> s >> u >> v; u--;
        if (s == "a") {
            upd(u, a[u] ^ v);
            a[u] = v;
        }
        else {
            upd(u, b[u] ^ v);
            b[u] = v;
        }
        if (num1) {
            cout << -1 << "\n";
        }
        else {
            cout << num2 << "\n";
        }
    }
}

void chemthan() {
    cin >> n >> k >> q;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) {
        cin >> b[i];
        c[i] = a[i] ^ b[i];
    }
    if (k > magic || n <= k + k) {
        solve_large();
    }
    else {
        solve_small();
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