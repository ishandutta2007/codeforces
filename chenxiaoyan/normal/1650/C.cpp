#include <bits/stdc++.h>
using namespace std;
bool Mbe;

namespace temp {
// NORMAL
using ll = long long; // using i128 = __int128_t;
using uint = unsigned; using ull = unsigned long long; // using u128 = __uint128_t;
using db = double; using ld = long double; // using f128 = __float128;
#define int ll
//#define db ld

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

// DEBUG
template<class T, int n> struct prttuple { static void p(T x) { prttuple<T, n - 1>::p(x), cout << ", " << get<n - 1>(x); } };
template<class T> struct prttuple<T, 1> { static void p(T x) { cout << X(x); } };
template<class... T> ostream &operator<<(ostream &cout, tuple<T...> x) {
	cout << '('; prttuple<tuple<T...>, tuple_size<tuple<T...>>::value>::p(x); cout << ')';
	return cout;
}
template<class T, class U> ostream &operator<<(ostream &cout, pair<T, U> x) { return cout << tuple<T, U>(x); }

#define prtstl(vector) template<class... T> ostream &operator<<(ostream &cout, vector<T...> x) {\
	cout << '{'; for(auto i = x.begin(); i != x.end(); ++i) i != x.begin() && (cout << ", ", 0), cout << *i; cout << '}';\
	return cout;\
}
prtstl(vector) prtstl(deque) prtstl(list) prtstl(set) prtstl(unordered_set) prtstl(multiset) prtstl(map) prtstl(unordered_map) prtstl(multimap)
template<class T> void prtarr(T a, int l, int r) { cout << '{'; REP(i, l, r) i > l && (cout << ", ", 0), cout << a[i]; cout << '}'; }
template<class T> void prtarr2(T a, int l1, int r1, int l2, int r2) {
	cout << "{\n";
	REP(i, l1, r1) i > l1 && (cout << ",\n", 0), cout << i << ":\t", prtarr(a[i], l2, r2);
	cout << "\n}";
}

#define debug0(x) (cout << "FUNC " << __FUNCTION__ << " LINE " << __LINE__ << ": "#x" = " << (x) << '\n')
#define debugarr(x, l, r) (\
	cout << "FUNC " << __FUNCTION__ << " LINE " << __LINE__ << ": "#x"[" << (l) << ", " << (r) << "] = ",\
	prtarr(x, l, r), cout << '\n'\
)
#define debugarr2(x, l1, r1, l2, r2) (\
	cout << "FUNC " << __FUNCTION__ << " LINE " << __LINE__ << ": "#x"[" << (l1) << ", " << (r1) << "][" << (l2) << ", " << (r2) << "] = ",\
	prtarr2(x, l1, r1, l2, r2), cout << '\n'\
)
#define get_debug(a, b, c, d, e, f, ...) f
#define debug(...) get_debug(__VA_ARGS__, debugarr2, 0, debugarr, 0, debug0)(__VA_ARGS__)

// FASTIO
namespace fastio {
//#define fread_io
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
} using fastio::gc; using fastio::pc; using fastio::read; using fastio::reads; using fastio::prt; using fastio::prts;

// MATH
constexpr int P = 0;
constexpr ll lnf = 0x3f3f3f3f3f3f3f3f;
#ifdef int
constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#else
constexpr int inf = 0x3f3f3f3f;
#endif

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int exgcd(int a, int b, int &x, int &y) {
	if(!b) return x = 1, y = 0, a;
	int d = exgcd(b, a % b, y, x);
	return y -= a / b * x, d;
}
int qpow(int x, int y = P - 2, int P = P) {
	int res = 1;
	while(y) {
		if(y & 1) res = (ll)res * x % P;
		x = (ll)x * x % P;
		y >>= 1;
	}
	return res;
}
int inv(int a, int P = P) {
	int x, y, d = exgcd(a, P, x, y);
	if(d != 1) return -1;
	return x < 0 ? x + P : x;
}

namespace modint {
	void addto(int &x, int y) { x += y, x >= P && (x -= P), x < 0 && (x += P); }
	int add(int x, int y) { return x < 0 && (x += P), y < 0 && (y += P), x += y, x >= P ? x - P : x; }
	int add0(int x) { return x < 0 ? x + P : x; }
} // using namespace modint;

template<int N, int P = P> struct fc_t {
	int iv[N], fc[N], ifc[N];
	fc_t() {
		iv[1] = 1; REP(i, 2, N - 1) iv[i] = (ll)iv[P % i] * (P - P / i) % P;
		fc[0] = ifc[0] = 1; REP(i, 1, N - 1) fc[i] = (ll)fc[i - 1] * i % P, ifc[i] = (ll)ifc[i - 1] * iv[i] % P;
	}
	int operator()(int n, int m) {
		if(m < 0 || m > n) return 0;
		return (ll)fc[n] * ifc[m] % P * ifc[n - m] % P;
	}
};
#define fc_init(...) fc_t<__VA_ARGS__> comb; int *iv = comb.iv, *fc = comb.fc, *ifc = comb.ifc
template<int N, int P = P> struct comb_t {
	int comb[N][N];
	comb_t() {
		comb[0][0] = 1;
		REP(i, 1, N - 1) REP(j, 0, i) comb[i][j] = ((j ? comb[i - 1][j - 1] : 0) + comb[i - 1][j]) % P;
	}
};
#define comb_init(...) comb_t<__VA_ARGS__> _comb; auto comb = _comb.comb
} using namespace temp;

constexpr int N = 2e5 + 10;

int m, n;
ti3 a[N];

void mian() {
	m = read(), n = read();
	REP(i, 1, n) Y(a[i]) = read(), X(a[i]) = read(), Z(a[i]) = i;
	sort(a + 1, a + n + 1);
	int ans = 0;
	REP(i, 1, 2 * m) ans += X(a[i]);
	prt(ans), pc('\n');
	sort(a + 1, a + 2 * m + 1, [&](ti3 x, ti3 y) { return Y(x) < Y(y); });
	REP(i, 1, m) prt(Z(a[i])), pc(' '), prt(Z(a[2 * m + 1 - i])), pc('\n');
}

bool Med;
signed main() {
	cout.setf(ios_base::fixed); cerr.setf(ios_base::fixed);
	fprintf(stderr, "%.3lfMB\n", (&Mbe - &Med) / 1048576.);
//	freopen("xxx.in", "r", stdin); freopen("xxx.out", "w", stdout);
	int t = 1;
	t = read();
	while(t--) mian();
	return 0;
}