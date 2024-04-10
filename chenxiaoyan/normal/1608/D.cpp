#include <bits/stdc++.h>
using namespace std;
bool Mbe;

using ll = long long; // using i128 = __int128_t;
using uint = unsigned; using ull = unsigned long long; // using u128 = __uint128_t;
using db = double; using ld = long double; // using f128 = __float128;
//#define int ll
//#define db ld

using tii = tuple<int, int>; using ti3 = tuple<int, int, int>; using ti4 = tuple<int, int, int, int>;
#define mt make_tuple
#define X(x) get<0>(x)
#define Y(x) get<1>(x)
#define Z(x) get<2>(x)
#define W(x) get<3>(x)

using vi = vector<int>; using vii = vector<tii>; using vi3 = vector<ti3>; using vi4 = vector<ti4>;
using vvi = vector<vi>; using vvii = vector<vii>; using vvi3 = vector<vi3>; using vvi4 = vector<vi4>;
#define push emplace
#define pf emplace_front
#define pb emplace_back

#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)
#define y0 kehaixing
#define y1 yigeiwoligiaogiao
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
int lowbit(int x) { return x & -x; }
void chkmx(auto &x, auto y) { if(y > x) x = y; }
void chkmn(auto &x, auto y) { if(y < x) x = y; }

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
template<class T = int> T read() {
	T x = 0; char c = gc(); bool ne = false;
	while(!isdigit(c)) ne |= c == '-', c = gc();
	while(isdigit(c)) x = 10 * x + (c ^ 48), c = gc();
	return ne ? -x : x;
}
void prt(auto x) {
	x < 0 && (pc('-'), x = -x);
	x > 9 && (prt(x / 10), 0);
	pc(x % 10 ^ 48);
}
} using fastio::gc; using fastio::pc; using fastio::read; using fastio::prt;
/*----------------------------------------------------------------------------------------------------*/
constexpr int P = 998244353;
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
	int add(int x, int y) { return x < 0 && (x += P), addto(x, y), x; }
	int add0(int x) { return x < 0 ? x + P : x; }
} using namespace modint;

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
/******************************************************************************************************/
constexpr int N = 1e5 + 10;

int n;
char a[N][5];

void mian() {
	n = read();
	int W = 0, B = 0;
	REP(i, 1, n) scanf("%s", a[i]);
	REP(i, 1, n) REP(j, 0, 1) {
		if(a[i][j] == 'W') ++W;
		if(a[i][j] == 'B') ++B;
	}
	if(W > n || B > n) return puts("0"), void();
	int ans = 1;
	REP(i, 1, 2 * n - W - B) ans = (ll)ans * i % P;
	REP(i, 1, n - W) ans = (ll)ans * inv(i) % P;
	REP(i, 1, n - B) ans = (ll)ans * inv(i) % P;
	int sub = 1, w = 0, b = 0;
	REP(i, 1, n) {
		if(a[i][0] == a[i][1] && a[i][0] != '?') { sub = 0; break; }
		if(a[i][0] == '?' && a[i][1] == '?') addto(sub, sub);
		if(a[i][0] == 'W' || a[i][1] == 'B') ++w;
		if(a[i][0] == 'B' || a[i][1] == 'W') ++b;
	}
	if(sub) { if(!w) addto(sub, -1); if(!b) addto(sub, -1); }
	prt(add(ans, -sub)), pc('\n');
}

bool Med;
signed main() {
	fprintf(stderr, "%.3lfMB\n", (&Mbe - &Med) / 1048576.);
//	freopen("xxx.in", "r", stdin); freopen("xxx.out", "w", stdout);
	int t = 1;
//	t = read();
	while(t--) mian();
	return 0;
}