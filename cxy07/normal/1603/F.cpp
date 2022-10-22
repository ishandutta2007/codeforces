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

const int MAXN = 1e7 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, k, x, Ans, iv2 = (mod + 1) >> 1;
int p2[MAXN], ip2[MAXN], _p2[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

void Init() {
	p2[0] = ip2[0] = 1;
	for(int i = 1; i < MAXN; ++i) p2[i] = p2[i - 1] * 2 % mod;
	for(int i = 1; i < MAXN; ++i) ip2[i] = ip2[i - 1] * (p2[i] - 1) % mod;
	ip2[MAXN - 1] = inv(ip2[MAXN - 1]);
	for(int i = MAXN - 2; i; --i) ip2[i] = ip2[i + 1] * (p2[i + 1] - 1) % mod;
}

void sub1() {
	if(n > k) return puts("0"), void();
	Ans = 1;
	for(int i = 1; i <= n; ++i)
		Ans = Ans * (p2[k] - p2[i - 1] + mod) % mod;
	printf("%lld\n", Ans);
}

void sub2() {
	_p2[0] = 1; Ans = 0;
	for(int i = 1, pow2 = qpow(2, n); i <= k; ++i) {
		_p2[i] = _p2[i - 1] * (pow2 - 1) % mod;
		pow2 = pow2 * iv2 % mod;
	}
	for(int r = 1, prod = 1, coef; r <= n + 1; ++r) {
		if(r > k) break;
		prod = prod * (p2[k] - p2[r - 1]) % mod;
		if(n + 1 - r <= r) coef = ip2[n + 1 - r] * _p2[n + 1 - r] % mod;
		else coef = ip2[r - 1] * _p2[r - 1] % mod;
		(Ans += prod * coef) %= mod;
	}
	Ans = (Ans * inv(p2[k] - 1) % mod + mod) % mod;
	printf("%lld\n", Ans);
}

void solve() {
	read(n), read(k), read(x);
	if(!x) return sub1(), void();
	else return sub2(), void();
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	Init(); read(T);
	while(T--) solve();
	return 0;
}