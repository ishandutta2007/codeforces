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

const int MAXN = 110;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, k, mod, fac[MAXN];
int C[MAXN][MAXN], dp[MAXN][MAXN][MAXN];

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
	read(n), read(m), read(k), read(mod); fac[0] = 1;
	for(int i = 0; i <= n; ++i) {
		C[i][0] = 1; if(i) fac[i] = fac[i - 1] * i % mod;
		for(int j = 1; j <= i; ++j) 
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
   	for(int i = 0; i <= m; ++i) dp[0][i][0] = 1;
	for(int i = 1; i <= n; ++i) dp[i][1][1] = fac[i];
	for(int j = 2; j <= m; ++j)
		for(int L = 0; L < n; ++L)
			for(int kl = 0; kl <= L; ++kl) {
				if(!dp[L][j - 1][kl]) continue;
				for(int R = 0; L + R < n; ++R)
					for(int kr = 0; kr <= R; ++kr) {
						if(!dp[R][j - 1][kr]) continue;
						(dp[L + R + 1][j][kl + kr] += dp[L][j - 1][kl] * dp[R][j - 1][kr] % mod * C[L + R][L]) %= mod;
					}
			}
	cout << dp[n][m][k] << endl;
	return 0;
}