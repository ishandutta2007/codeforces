#include <bits/stdc++.h>
using namespace std;
bool Mbe;

namespace temp {
// NORMAL
using ll = long long; // using i128 = __int128_t;
using uint = unsigned; using ull = unsigned long long; // using u128 = __uint128_t;
using db = double; using ld = long double; // using f128 = __float128;
// #define int ll
// #define db ld

using tii = tuple<int, int>; using ti3 = tuple<int, int, int>; using ti4 = tuple<int, int, int, int>;
#define mt(...) make_tuple(__VA_ARGS__)
#define X(x) get<0>(x)
#define Y(x) get<1>(x)
#define Z(x) get<2>(x)
#define W(x) get<3>(x)

using vi = vector<int>; using vii = vector<tii>; using vi3 = vector<ti3>; using vi4 = vector<ti4>;
using vvi = vector<vi>; using vvii = vector<vii>; using vvi3 = vector<vi3>; using vvi4 = vector<vi4>;
#define pf(...) emplace_front(__VA_ARGS__)
#define pb(...) emplace_back(__VA_ARGS__)

#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)
#define y0 kehaixing
#define y1 yigeiwoligiaogiao
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
int lowbit(int x) { return x & -x; }
template<class T, class U> void chkmx(T &x, U y) { if(y > x) x = y; }
template<class T, class U> void chkmn(T &x, U y) { if(y < x) x = y; }

// FASTIO
namespace fastio {
// #define fread_io
#ifdef fread_io
char buf[1 << 16], *st, *ed, wbuf[1 << 16], *wst = wbuf, *wed = wbuf + (1 << 16);
char gc() { return st == ed && (ed = (st = buf) + fread(buf, 1, 1 << 16, stdin), st == ed) ? -1 : *st++; }
void flush() { fwrite(wbuf, 1, wst - wbuf, stdout), wst = wbuf; }
struct flusher_t { ~flusher_t() { flush(); } } flusher;
void pc(char x) { wst == wed && (flush(), 0), *wst++ = x; }
#else
char gc() { return getchar(); } void pc(char x) { putchar(x); }
#endif
#define notspace(x) (!isspace(x) && ~(x))
template<class T = int> T read() {
    T x = 0; char c = gc(); bool ne = false;
    while(!isdigit(c)) ne |= c == '-', c = gc();
    while(isdigit(c)) x = 10 * x + (c ^ 48), c = gc();
    return ne ? -x : x;
}
int reads(char *s) {
    int n = 0; char c = gc();
    while(!notspace(c)) c = gc();
    while(notspace(c)) s[n++] = c, c = gc();
    return s[n] = 0, n;
}
template<class T> void prt(T x) {
    x < 0 && (pc('-'), x = -x);
    x > 9 && (prt(x / 10), 0);
    pc(x % 10 ^ 48);
}
void prts(const char *s, int n = INT_MAX) { while(n-- && *s) pc(*s++); }
} using fastio::gc; using fastio::pc;
using fastio::read; using fastio::reads; using fastio::prt; using fastio::prts;

// MATH
constexpr int P = 1e4 + 7;
constexpr ll lnf = 0x3f3f3f3f3f3f3f3f;
#ifdef int
constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#else
constexpr int inf = 0x3f3f3f3f;
#endif

int gcd(int x, int y) { return __gcd(x, y); }
int exgcd(int a, int b, int &x, int &y) {
    if(!b) return x = 1, y = 0, a;
    int d = exgcd(b, a % b, y, x);
    return y -= a / b * x, d;
}
int qpow(int x, int y = P - 2, int p = P) {
    int res = 1;
    while(y) {
        if(y & 1) res = (ll)res * x % p;
        x = (ll)x * x % p;
        y >>= 1;
    } return res;
}
int inv(int a, int p = P) {
    int x, y, d = exgcd(a, p, x, y);
    if(d != 1) return -1;
    return x < 0 ? x + p : x;
}

namespace modint {
    void addto(int &x, int y) { x += y, x >= P && (x -= P), x < 0 && (x += P); }
    int add(int x, int y) { return x < 0 && (x += P), x += y, x >= P ? x - P : x < 0 ? x + P : x; }
    int add0(int x) { return x < 0 ? x + P : x; }
}
using namespace modint;

template<int N, int p = P> struct fc_t {
    int iv[N], fc[N], ifc[N];
    fc_t() {
        iv[1] = 1; REP(i, 2, N - 1) iv[i] = (ll)iv[p % i] * (p - p / i) % p;
        fc[0] = ifc[0] = 1; REP(i, 1, N - 1) fc[i] = (ll)fc[i - 1] * i % p, ifc[i] = (ll)ifc[i - 1] * iv[i] % p;
    }
    int operator()(int n, int m) {
        if(m < 0 || m > n) return 0;
        return (ll)fc[n] * ifc[m] % p * ifc[n - m] % p;
    }
};
#define fc_init(...) fc_t<__VA_ARGS__> comb; int *iv = comb.iv, *fc = comb.fc, *ifc = comb.ifc
template<int N, int p = P> struct comb_t {
    int comb[N][N];
    comb_t() {
        comb[0][0] = 1;
        REP(i, 1, N - 1) REP(j, 0, i) comb[i][j] = ((j ? comb[i - 1][j - 1] : 0) + comb[i - 1][j]) % p;
    }
};
#define comb_init(...) comb_t<__VA_ARGS__> _comb; auto comb = _comb.comb
} using namespace temp;

constexpr int N = 210, T = 310;

int n, m;
char a[N];
int dp[N][N][N];
int ways[N];

int tot;
int id[2][N]; // 0: 24, 1: 25

struct matrix {
    int a[T][T];
    int *operator[](int x) { return a[x]; }
    matrix(int v = 0) {
        memset(a, 0, sizeof(a));
        REP(i, 0, T - 1) a[i][i] = v;
    }
    friend matrix operator*(matrix f, matrix g) {
        matrix h;
        static ll H[T][T];
        memset(H, 0, sizeof(H));
        REP(i, 1, tot) REP(j, 1, i) REP(k, j, i) H[i][j] += f[i][k] * g[k][j];
        REP(i, 1, tot) REP(j, 1, tot) h[i][j] = H[i][j] % P;
        return h;
    }
    friend matrix operator^(matrix f, int e) {
        matrix res(1);
        while(e) {
            if(e & 1) res = res * f;
            f = f * f;
            e >>= 1;
        } return res;
    }
} D;

int solve(bool spc) {
    dp[0][0][0] = 1;
    REP(i, 0, n) PER(l, n, 1) REP(r, l, n) {
        dp[i][l][r] = 0;
        if(a[l] == a[r]) {
            if(spc && l == r) continue;
            int nwl = r <= l + 1 ? 0 : l + 1, nwr = r <= l + 1 ? 0 : r - 1;
            addto(dp[i][l][r], dp[i][nwl][nwr]);
        } else {
            if(!i) continue;
            addto(dp[i][l][r], dp[i - 1][l + 1][r]);
            addto(dp[i][l][r], dp[i - 1][l][r - 1]);
        }
    }
    assert(dp[n][1][n] == 0);
    REP(i, 0, n - 1) ways[i] = dp[i][1][n];
    tot = 0;
    REP(i, 0, n - 1) id[0][i] = ++tot;
    PER(i, n + 1 >> 1, 0) id[1][i] = ++tot;
    D = matrix();
    REP(i, 1, n - 1) D[id[0][i]][id[0][i - 1]] = 1;
    PER(i, n + 1 >> 1, 1) D[id[1][i - 1]][id[1][i]] = 1;
    REP(i, 1, n - 1) D[id[0][i]][id[0][i]] = 24;
    REP(i, 1, n + 1 >> 1) D[id[1][i]][id[1][i]] = 25;
    if(!spc) D[tot][tot] = 26;
    REP(i, 0, n - 1) D[id[1][n - i + 1 >> 1]][id[0][i]] = ways[i];
    // REP(i, 1, tot) REP(j, 1, tot) cout << D[i][j] << " \n"[j == tot];
    D = D ^ ((m + 1) / 2 + 1);
    return D[tot][1];
}

void mian() {
    n = reads(a + 1);
    m = read() + n;
    int ans = solve(0);
    if(m & 1) addto(ans, -solve(1));
    prt(ans), pc('\n');
}

bool Med;
signed main() {
    fprintf(stderr, "(%.3lfMB used)\n", (&Mbe - &Med) / 1048576.);
    // freopen("xxx.in", "r", stdin); freopen("xxx.out", "w", stdout);
    int t = 1;
    // t = read();
    while(t--) mian();
    fprintf(stderr, "(%.3lfs used)\n", (db)clock() / CLOCKS_PER_SEC);
    return 0;
}