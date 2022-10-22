#include <bits/stdc++.h>
using namespace std;
bool Mbe;

namespace temp {
// NORMAL
using ll = long long; // using i128 = __int128_t;
using uint = unsigned; using ull = unsigned long long; // using u128 = __uint128_t;
using db = double; using ld = long double; // using f128 = __float128;
#define int ll
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
constexpr int P = 0;
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
// using namespace modint;

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

constexpr int N = 1e7 + 10, NN = 2e5 + 10;

int n, qu;
int a[NN], pos[NN];
int lft[NN], rit[NN];

struct addedge {
    signed sz, head[NN], nxt[N], y[N], id[N], v[N];
    void ae(int x, int yy, int vv, int i = 0) {
        ++sz, nxt[sz] = head[x], head[x] = sz, y[sz] = yy, v[sz] = vv, id[sz] = i;
    }
} todo, qry;
void add(int x, int y, int v) {
    todo.ae(x, y, v);
}
void add(int l, int r, int L, int R) {
    add(l, L, 1);
    add(l, R + 1, -1);
    add(r + 1, L, -1);
    add(r + 1, R + 1, 1);
}

struct bitree {
    int sum[NN];
    void add(int x, int v) {
        while(x <= n) sum[x] += v, x += lowbit(x);
    }
    int Sum(int x) {
        int res = 0;
        while(x) res += sum[x], x -= lowbit(x);
        return res;
    }
} s0, sx, sy, s;

void doit(int x, int y, int v) {
    s0.add(y, v);
    sx.add(y, (x - 1) * v);
    sy.add(y, (y - 1) * v);
    s.add(y, (x - 1) * (y - 1) * v);
}
int ask(int x, int y) {
    int res = 0;
    res += s0.Sum(y) * x * y;
    res -= sx.Sum(y) * y;
    res -= sy.Sum(y) * x;
    res += s.Sum(y);
    return res;
}

int ans[N];

void mian() {
    n = read(), qu = read();
    REP(i, 1, n) a[i] = read(), pos[a[i]] = i;
    static int stk[N], top = 0;
    REP(i, 1, n) {
        while(top && a[stk[top - 1]] < a[i]) --top;
        lft[i] = top ? stk[top - 1] + 1 : 1;
        stk[top++] = i;
    }
    top = 0;
    PER(i, n, 1) {
        while(top && a[stk[top - 1]] < a[i]) --top;
        rit[i] = top ? stk[top - 1] - 1 : n;
        stk[top++] = i;
    }
    REP(i, 1, n) {
        int L = lft[i], R = rit[i];
        int x = a[i];
        vii v;
        for(int y = 1; y * y <= x; ++y) if(x % y == 0) {
            int j = pos[y], z = x / y, k = pos[z];
            if(j == k) continue;
            int l = i, r = i;
            if(j < i) chkmn(l, j); else chkmx(r, j);
            if(k < i) chkmn(l, k); else chkmx(r, k);
            if(l >= L && r <= R) v.pb(l, r);
        }
        if(v.empty()) continue;
        sort(ALL(v));
        int now = inf;
        PER(i, SZ(v) - 1, 0) {
            int l = i ? X(v[i - 1]) + 1 : L, r = X(v[i]);
            chkmn(now, Y(v[i]));
            add(l, r, now, R);
        }
    }
    REP(i, 1, qu) {
        int l = read(), r = read();
        qry.ae(r, r, 1, i);
        qry.ae(l - 1, r, -1, i);
        qry.ae(r, l - 1, -1, i);
        qry.ae(l - 1, l - 1, 1, i);
    }
    REP(i, 1, n) {
        for(int e = todo.head[i]; e; e = todo.nxt[e]) {
            int y = todo.y[e], v = todo.v[e];
            doit(i, y, v);
        }
        for(int e = qry.head[i]; e; e = qry.nxt[e]) {
            int y = qry.y[e], v = qry.v[e], id = qry.id[e];
            ans[id] += v * ask(i, y);
        }
    }
    REP(i, 1, qu) prt(ans[i]), pc('\n');
}

bool Med;
signed main() {
    fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
    // freopen("xxx.in", "r", stdin); freopen("xxx.out", "w", stdout);
    int t = 1;
    // t = read();
    while(t--) mian();
    fprintf(stderr, "(%.3lfs used)\n", (db)clock() / CLOCKS_PER_SEC);
    return 0;
}