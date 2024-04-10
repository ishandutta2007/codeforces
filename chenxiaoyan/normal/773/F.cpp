#include <bits/stdc++.h>
using namespace std;
bool Mbe;

namespace temp {
// NORMAL
using ll = long long; // using i128 = __int128_t;
using uint = unsigned; using ull = unsigned long long; // using u128 = __uint128_t;
using db = double; using ld = long double; // using f128 = __float128;
#define int ll
#define db ld

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
int P = 0;
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
} using namespace temp;

constexpr int N = 1 << 16 | 10;

int n, m;

const db pi = acos(-1);

struct comp {
	db r, i;
	comp(db r = 0, db i = 0) : r(r), i(i) {}
	comp operator+(const comp &b) const { return comp(r + b.r, i + b.i); }
	comp operator-(const comp &b) const { return comp(r - b.r, i - b.i); }
	comp operator*(const comp &b) const { return comp(r * b.r - i * b.i, r * b.i + i * b.r); }
	static comp root(int n, int i) { return comp(cos(2 * pi / n * i), sin(2 * pi / n * i)); }
};

void dft(vector<comp> &f, int iv) {
	int n = SZ(f);
	static int to[N];
	REP(i, 1, n - 1) to[i] = (to[i >> 1] >> 1) | ((i & 1) << 30 - __builtin_clz(n));
	REP(i, 0, n - 1) if(i < to[i]) swap(f[i], f[to[i]]);
	for(int i = 1; i < n; i *= 2) {
		comp omega = comp::root(2 * i, iv);
		for(int j = 0; j < n; j += 2 * i) {
			comp w(1, 0);
			REP(k, 0, i - 1) {
				comp x = f[j + k], y = w * f[i + j + k];
				f[j + k] = x + y, f[i + j + k] = x - y;
				w = w * omega;
			}
		}
	}
	if(iv == -1) for(auto &x : f) x = x * (1. / n);
}
vector<comp> dot(vector<comp> f, vector<comp> g) {
    REP(i, 0, SZ(f) - 1) f[i] = f[i] * g[i];
    return f;
}
vector<comp> operator+(vector<comp> f, vector<comp> g) {
    REP(i, 0, SZ(f) - 1) f[i] = f[i] + g[i];
    return f;
}

struct poly : vi {
	using vi::vi;
    poly(vector<comp> f) {
        resize(SZ(f));
        REP(i, 0, SZ(f) - 1) operator[](i) = int(f[i].r + .5) % P;
    }
	int val(int x) { return x < size() ? operator[](x) : 0; }
    vector<comp> dft(int n, int iv) {
        vector<comp> v(n);
        REP(i, 0, size() - 1) v[i] = operator[](i);
        ::dft(v, iv);
        return v;
    }
};

struct matrix {
    poly f0, f1, g0, g1;
    bool operator==(const matrix &g) const {
        return f0 == g.f0 && f1 == g.f1 && g0 == g.g0 && g1 == g.g1;
    }
    friend matrix operator*(matrix f, matrix g) {
        int n = 0;
        while(1 << n < 2 * max({SZ(f.f0), SZ(f.f1), SZ(f.g0), SZ(f.g1),
                                SZ(g.f0), SZ(g.f1), SZ(g.g0), SZ(g.g1)})) ++n;
        n = 1 << n;
        auto ff0 = f.f0.dft(n, 1), ff1 = f.f1.dft(n, 1), fg0 = f.g0.dft(n, 1), fg1 = f.g1.dft(n, 1);
        vector<comp> gf0, gf1, gg0, gg1;
        if(f == g) gf0 = ff0, gf1 = ff1, gg0 = fg0, gg1 = fg1;
        else gf0 = g.f0.dft(n, 1), gf1 = g.f1.dft(n, 1), gg0 = g.g0.dft(n, 1), gg1 = g.g1.dft(n, 1);
        auto f0 = dot(ff0, gf0) + dot(ff1, gf1); dft(f0, -1); if(SZ(f0) > ::n + 1) f0.resize(::n + 1);
        auto f1 = dot(ff0, gf1) + dot(ff1, gf0); dft(f1, -1); if(SZ(f1) > ::n + 1) f1.resize(::n + 1);
        auto g0 = dot(fg0, gf0) + dot(fg1, gf1) + gg0; dft(g0, -1); if(SZ(g0) > ::n + 1) g0.resize(::n + 1);
        auto g1 = dot(fg0, gf1) + dot(fg1, gf0) + gg1; dft(g1, -1); if(SZ(g1) > ::n + 1) g1.resize(::n + 1);
        matrix h;
        h.f0 = f0, h.f1 = f1, h.g0 = g0, h.g1 = g1;
        return h;
    }
};

void mian() {
    n = read(), m = read(), P = read();
    matrix D, res;
    D.f0 = {0}, D.f1 = {1, 1}, D.g0 = {1}, D.g1 = {0};
    res.f0 = {1}, res.f1 = {0}, res.g0 = {0}, res.g1 = {0};
    int ans = 0;
    PER(i, 30, 0) {
        res = res * res;
        if(m >> i & 1) res = res * D;
        if(i) {
            REP(n, 1, ::n) if(n & 1) {
                addto(ans, res.g0.val(n - 1));
            }
        }
    }
    prt(ans), pc('\n');
}

bool Med;
signed main() {
    fprintf(stderr, "(%.3lfMB used (not including static!!!))\n", (&Mbe - &Med) / 1048576.);
    // freopen("xxx.in", "r", stdin); freopen("xxx.out", "w", stdout);
    int t = 1;
    // t = read();
    while(t--) mian();
    fprintf(stderr, "(%.3Lfs used)\n", (db)clock() / CLOCKS_PER_SEC);
    return 0;
}