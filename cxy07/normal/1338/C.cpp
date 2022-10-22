//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'
#define y1 _y1

const int MAXN = 101010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, B;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve1(int l, int r, int c) {
	if(l + 1 == r) return assert(c == 0), printf("%lld\n", l), void();
	assert((r - l) % 4 == 0); int len = (r - l) / 4;
	if(c < len) return solve1(l, l + len, c), void();
	c -= len;
	if(c < len) return solve1(l + 2 * len, l + 3 * len, c), void();
	c -= len;
	if(c < len) return solve1(l + 3 * len, l + 4 * len, c), void();
	c -= len; assert(c < len);
	if(c < len) return solve1(l + len, l + 2 * len, c), void();
}

void solve2(int l, int r, int c) {
	if(l + 1 == r) return assert(c == 0), printf("%lld\n", l), void();
	assert((r - l) % 4 == 0); int len = (r - l) / 4;
	if(c < len) return solve2(l, l + len, c), void();
	c -= len;
	if(c < len) return solve2(l + 3 * len, l + 4 * len, c), void();
	c -= len;
	if(c < len) return solve2(l + 1 * len, l + 2 * len, c), void();
	c -= len; assert(c < len);
	if(c < len) return solve2(l + 2 * len, l + 3 * len, c), void();
}

void solve() {
	read(n); B = 1; m = (n - 1) / 3;
	int sum = 0;
	while(sum + B <= m) { sum += B; B <<= 2; }
	m -= sum; assert(m < B);
	if(n % 3 == 1) printf("%lld\n", B + m);
	if(n % 3 == 2) solve1(2 * B, 3 * B, m);
	if(n % 3 == 0) solve2(3 * B, 4 * B, m);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}