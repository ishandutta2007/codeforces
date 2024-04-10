#include <bits/stdc++.h>
using namespace std;
bool Mbe;

namespace temp {
// NORMAL
using ll = long long; using i128 = __int128_t;
using uint = unsigned; using ull = unsigned long long; // using u128 = __uint128_t;
using db = double; using ld = long double; // using f128 = __float128;
// #define int ll
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

constexpr int N = 1.2e5 + 10;

fc_init(N);

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
		static comp w[N]; w[0] = 1;
		REP(k, 1, i - 1) w[k] = w[k - 1] * omega;
		for(int j = 0; j < n; j += 2 * i) REP(k, 0, i - 1) {
			comp x = f[j + k], y = w[k] * f[i + j + k];
			f[j + k] = x + y, f[i + j + k] = x - y;
		}
	}
	if(iv == -1) for(auto &x : f) x = x * (1. / n);
}
vector<comp> operator+(vector<comp> f, vector<comp> g) {
	REP(i, 0, SZ(f) - 1) f[i] = f[i] + g[i];
	return f;
}
vector<comp> operator*(vector<comp> f, vector<comp> g) {
	REP(i, 0, SZ(f) - 1) f[i] = f[i] * g[i];
	return f;
}
struct poly : vi {
	using vi::vi;
	int val(int x) { return x < size() ? operator[](x) : 0; }
	friend poly operator*(poly f, poly g) {
		vector<comp> F0(SZ(f)), G0(SZ(g)), F1(SZ(f)), G1(SZ(g));
		REP(i, 0, SZ(f) - 1) F0[i] = f[i] & 32767, F1[i] = f[i] >> 15;
		REP(i, 0, SZ(g) - 1) G0[i] = g[i] & 32767, G1[i] = g[i] >> 15;
		int n = 0;
		while(1 << n < SZ(f) + SZ(g) - 1) ++n;
		F0.resize(1 << n, 0), F1.resize(1 << n, 0), G0.resize(1 << n, 0), G1.resize(1 << n, 0);
		dft(F0, 1), dft(F1, 1), dft(G0, 1), dft(G1, 1);
		vector<comp> h0 = F0 * G0, h1 = F0 * G1 + F1 * G0, h2 = F1 * G1;
		dft(h0, -1), dft(h1, -1), dft(h2, -1);
		f.resize(SZ(F0));
		REP(i, 0, SZ(f) - 1) f[i] = ((i128(h2[i].r + .5) << 30) + (i128(h1[i].r + .5) << 15) + i128(h0[i].r + .5)) % P;
		while(f.back() == 0) f.pop_back();
		return f;
	}
};

ll n;
int k;

struct matrix {
    int n;
    poly f;
    matrix() {}
    void operator*=(matrix gg) {
        int m = gg.n;
        n += m;
        poly h, g = gg.f;
        int twom = qpow(2, m), now = 1;
        REP(i, 0, SZ(f) - 1) {
            f[i] = (ll)f[i] * now % P * fc[k - i] % P * ifc[k] % P;
            now = (ll)now * twom % P;
        }
        REP(i, 0, SZ(g) - 1) {
            g[i] = (ll)g[i] * fc[k - i] % P;
        }
        h = f * g;
        if(SZ(h) > k + 1) h.resize(k + 1);
        REP(i, 0, SZ(h) - 1) h[i] = (ll)h[i] * ifc[k - i] % P;
        f = h;
    }
    friend matrix operator^(matrix f, int e) {
        matrix res;
        res.n = 0;
        res.f = {1};
        PER(i, 30, 0) {
            res *= res;
            if(e >> i & 1) res *= f;
        }
        return res;
    }
} D;

void mian() {
    n = read<ll>(), k = read();
    if(n > k) return puts("0"), void();
    D.n = 1;
    D.f.resize(k + 1, 0);
    REP(i, 1, k) D.f[i] = comb(k, i);
    D = D ^ n;
    int ans = 0;
    for(int x : D.f) addto(ans, x);
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