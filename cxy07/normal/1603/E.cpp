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

const int MAXN = 210;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, mod, Ans;
int fac[MAXN], ifac[MAXN];
int dp[2][MAXN][MAXN], now = 1, pre;

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

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(mod); fac[0] = ifac[0] = 1;
	for(int i = 1; i < MAXN; ++i) fac[i] = fac[i - 1] * i % mod;
	ifac[MAXN - 1] = inv(fac[MAXN - 1]);
	for(int i = MAXN - 2; i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
	for(int a1 = max(1ll, n - 30); a1 <= n; ++a1) {
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= a1; ++i) dp[now][i][0] = ifac[i];
		for(int cur = a1 + 1; cur <= n; ++cur) {
			swap(now, pre);
			memset(dp[now], 0, sizeof dp[now]);
			for(int c = cur - 1 - (cur - 1 != a1); c >= 0; --c)
				for(int v = 0; v + (n - c) * (cur - a1) <= a1; ++v)
					for(int i = 0; i + c < cur; ++i)
						(dp[now][i + c][v + (cur - a1) * i] += dp[pre][c][v] * ifac[i]) %= mod;
		}
		for(int v = 0; v <= a1; ++v)
			for(int c = n - 1; v + (n - c) * (n + 1 - a1) <= a1; --c)
				(Ans += dp[now][c][v] * ifac[n - c]) %= mod;
	}
	Ans = (Ans * fac[n] % mod + 2 + mod) % mod;
	printf("%lld\n", Ans);
	return 0;
}