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
constexpr int P = 1e9 + 7;
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

constexpr int N = 1e5 + 10;

int n, m;
vii nei[N];

struct lbase {
    int b[6];
    int &operator[](int x) { return b[x]; }
    lbase() { memset(b, 0, sizeof(b)); }
    bool insert(int x) {
        PER(i, 4, 0) if(x >> i & 1) {
            if(b[i]) x ^= b[i];
            else return b[i] = x, true;
        }
        return false;
    }
};
struct arr {
    uint key, all;
    arr() { key = all = 0; }
    arr(uint k) {
        key = all = 0;
        lbase b;
        while(k) {
            int x = __builtin_ctz(k);
            k ^= 1 << x;
            if(b.insert(x)) key |= 1 << x;
            else { key = all = 0; return; }
        }
        REP(msk, 0, 31) {
            int xsm = 0;
            REP(i, 0, 4) if(msk >> i & 1) xsm ^= b[i];
            all |= 1 << xsm;
        }
    }
    bool operator<(const arr &f) const { return all < f.all; }
    bool operator==(const arr &f) const { return all == f.all; }
    friend arr operator+(arr x, arr y) {
        if(x.all == 0 || y.all == 0) return arr();
        if(x.key & y.key) return arr();
        return arr(x.key | y.key);
    }
};
vector<arr> arrs;
void bf(int x = 1, uint msk = 0, lbase bs = lbase()) {
    if(x == 32) {
        arrs.pb(arr(msk));
        return;
    }
    bf(x + 1, msk, bs);
    if(bs.insert(x)) bf(x + 1, msk | 1u << x, bs);
}
int sum[375][375];

int fa[N];
int pre[N];
bool vis[N];
vi pa;
void dfs(int x, int fa) {
    pa.pb(x);
    vis[x] = true;
    for(tii e : nei[x]) {
        int y = X(e), v = Y(e);
        if(vis[y] || y == fa || y == 1) continue;
        ::fa[y] = x, pre[y] = pre[x] ^ v;
        dfs(y, x);
    }
}
int calc(int rt, int ban) {
    pa.clear(), dfs(rt, ban);
    uint key = 0;
    // for(int x : pa) cout << fa[x] << " -> " << x << "\n";
    for(int x : pa) for(tii e : nei[x]) {
        int y = X(e), v = Y(e);
        if(y == 1 || y == ban || x == fa[y] || y == fa[x] || x > y) continue;
        if(key >> (pre[x] ^ pre[y] ^ v) & 1) return 0;
        key |= 1u << (pre[x] ^ pre[y] ^ v);
    }
    return lower_bound(ALL(arrs), arr(key)) - arrs.begin();
}

void mian() {
    bf(); arrs.pb(arr());
    sort(ALL(arrs)), arrs.resize(unique(ALL(arrs)) - arrs.begin());
    cerr << SZ(arrs) << " arrs\n";
    REP(i, 0, 374) REP(j, i, 374) {
        sum[i][j] = sum[j][i] = lower_bound(ALL(arrs), arrs[i] + arrs[j]) - arrs.begin();
    }
    cerr << "init over in " << (db)clock() / CLOCKS_PER_SEC << " s\n";
    n = read(), m = read();
    while(m--) {
        int x = read(), y = read(), w = read();
        nei[x].pb(y, w), nei[y].pb(x, w);
    }
    static bool is1nei[N];
    static int valto1[N];
    for(tii e : nei[1]) is1nei[X(e)] = true, valto1[X(e)] = Y(e);
    vi3 v;
    REP(x, 1, n) if(is1nei[x]) {
        for(tii e : nei[x]) if(is1nei[X(e)]) {
            if(x < X(e)) v.pb(x, X(e), Y(e));
            goto edlp;
        }
        v.pb(x, 0, 0);
        edlp:;
    }
    vvi kd;
    for(ti3 t : v) {
        int x = X(t), y = Y(t), v = Z(t);
        if(y) {
            int a = calc(x, y), b = calc(y, x);
            int xsm = valto1[x] ^ valto1[y] ^ v;
            int all = sum[sum[a][b]][lower_bound(ALL(arrs), arr(1u << xsm)) - arrs.begin()];
            kd.pb((vi){1, sum[a][b], sum[a][b], all});
        } else {
            int a = calc(x, 0);
            kd.pb((vi){1, a});
        }
    }
    static int dp[375];
    dp[1] = 1;
    for(vi &v : kd) {
        static int f[375]; memset(f, 0, sizeof(f));
        REP(i, 0, 374) if(dp[i])
            for(int a : v) addto(f[sum[i][a]], dp[i]);
        REP(i, 0, 374) dp[i] = f[i];
    }
    int ans = 0;
    REP(i, 1, 374) addto(ans, dp[i]);
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