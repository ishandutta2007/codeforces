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

int n, lim_d, mod, Ans;
int dp[MAXN][MAXN], sum[MAXN], C[MAXN][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(lim_d), read(mod);
	for(int i = 0; i <= n; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	} dp[1][0] = 1, sum[1] = 1;
	for(int i = 2; i <= n; ++i) {
		for(int s = 1; s < i; ++s)
			for(int d = 1; d <= lim_d; ++d)
				(dp[i][d] += dp[i - s][d - 1] * sum[s] % mod * C[i - 2][s - 1]) %= mod;
		for(int d = 0; d < lim_d; ++d) (sum[i] += dp[i][d]) %= mod;
	}
	for(int i = 1; i <= n; ++i)
		for(int a = 0; a <= lim_d; ++a)
			for(int b = 0; a + b <= lim_d; ++b)
				(Ans += dp[i][a] * dp[n - i + 1][b]) %= mod;
	for(int i = 1; i < n; ++i)
		for(int a = 0; a < lim_d; ++a)
			for(int b = 0; b < lim_d; ++b)
				(Ans += mod - dp[i][a] * dp[n - i][b] % mod) %= mod;
	Ans = Ans * 2 * n % mod * (n - 1) % mod;
	printf("%lld\n", Ans);
	return 0;
}