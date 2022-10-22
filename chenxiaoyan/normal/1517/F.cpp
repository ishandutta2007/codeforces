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
constexpr int P = 998244353;
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

// /tuu/tuu/tuu
// It's like a dream.
constexpr int N = 310;

int n, r;
vi nei[N];

int dep[N];
int f[N][N], F[N][N]; // deepest uncovered
int g[N][N], G[N][N]; // highest colored

void dfs(int x = 1, int fa = 0) {
    for(int y : nei[x]) if(y != fa) dfs(y, x), chkmx(dep[x], dep[y] + 1);
    auto ways = [&](int y, int a, int b) { // highest colored >= a, deepest uncovered <= b
        int ans = b < 0 ? 0 : F[y][b];
        addto(ans, G[y][a]);
        return ans;
    };
    auto solve_f = [&]() { // start solving f (only solving 0)
        { // solving d = 0 
            int ans = 1;
            for(int y : nei[x]) if(y != fa) {
                ans = (ll)ans * G[y][r] % P;
            }
            addto(f[x][0], ans);
        }
        REP(d, 1, min(r, dep[x])) {
            int ans1 = 1, ans2 = 1;
            for(int y : nei[x]) if(y != fa) {
                ans1 = (ll)ans1 * ways(y, r - d, d - 1) % P;
                ans2 = (ll)ans2 * ways(y, r - d, d - 2) % P;
            }
            f[x][d] = add(ans1, -ans2);
        }
    };
    solve_f();
    auto solve_g = [&]() { // start solving g
        auto solve0 = [&]() {
            REP(d, 1, min(r, dep[x])) {
                static int Prod[N], proD[N];
                REP(i, 0, SZ(nei[x]) - 1) {
                    int y = nei[x][i];
                    if(y == fa) Prod[i] = proD[i] = 1;
                    else {
                        Prod[i] = ways(y, d, r - d - 1);
                        proD[i] = ways(y, d - 1, r - d - 1);
                    }
                }
                REP(i, 1, SZ(nei[x]) - 1) Prod[i] = (ll)Prod[i] * Prod[i - 1] % P;
                PER(i, SZ(nei[x]) - 2, 0) proD[i] = (ll)proD[i] * proD[i + 1] % P;
                REP(i, 0, SZ(nei[x]) - 1) {
                    int y = nei[x][i];
                    if(y == fa) continue;
                    int pp = (ll)(i ? Prod[i - 1] : 1) * (i < SZ(nei[x]) - 1 ? proD[i + 1] : 1) % P;
                    addto(g[x][d], (ll)pp * g[y][d - 1] % P);
                }
            }
        };
        auto solve1 = [&]() {
            int ans = 1;
            for(int y : nei[x]) if(y != fa) {
                ans = (ll)ans * ways(y, 0, r - 1) % P;
            }
            addto(g[x][0], ans);
        };
        solve0();
        solve1();
    };
    solve_g();
    // start solving F, G
    REP(i, 0, n) F[x][i] = add(i ? F[x][i - 1] : 0, f[x][i]);
    PER(i, n, 0) G[x][i] = add(i < n ? G[x][i + 1] : 0, g[x][i]); 
}

void mian() {
    n = read();
    REP(i, 1, n - 1) {
        int x = read(), y = read();
        nei[x].pb(y), nei[y].pb(x);
    }
    static int cnt[N];
    REP(r, 1, n) {
        if(r == n) cnt[r] = qpow(2, n);
        else {
            ::r = r;
            memset(f, 0, sizeof(f));
            memset(g, 0, sizeof(g));
            memset(F, 0, sizeof(F));
            memset(G, 0, sizeof(G));
            dfs();
            cnt[r] = G[1][0];
        }
    }
    int ans = 0;
    REP(r, 1, n - 1) {
        int c = add(cnt[r + 1], -cnt[r]);
        addto(ans, (ll)c * r % P);
    }
    cerr << "ans = " << ans << "\n";
    ans = (ll)ans * inv(qpow(2, n)) % P;
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

/*
5
1 2
2 3
3 4
3 5
*/