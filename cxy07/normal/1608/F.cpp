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

const int MAXN = 2010;
const int MAXK = 55;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, Ans;
int b[MAXN], L[MAXN], R[MAXN];
int fac[MAXN], ifac[MAXN], Inv[MAXN];
int dp[2][MAXK << 1][MAXN];
int coef[2][MAXK << 1][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

#define dp(i, j, c) dp[(i) & 1][(j) - b[i] + k][c]
#define coef(i, j, c) coef[(i) & 1][(j) - b[i] + k][c]

void pushup(int i) {
	for(int j = max(0ll, L[i]); j <= min(i, R[i]); ++j)
		for(int c = 0; c <= i; ++c) {
			if(j > L[i] && coef(i, j - 1, c + 1)) 
				(coef(i, j, c) += coef(i, j - 1, c + 1) * (c + 1)) %= mod;
			(dp(i, j, c) += coef(i, j, c)) %= mod;
		}
}

signed main () {
#ifdef FILE
	freopen("CF1608F.in", "r", stdin);
	freopen("CF1608F.out", "w", stdout);
#endif
	read(n), read(k); Inv[1] = fac[0] = ifac[0] = 1;
	for(int i = 1; i <= n; ++i) read(b[i]);
	for(int i = 0; i <= n; ++i) L[i] = b[i] - k, R[i] = b[i] + k;
	for(int i = 2; i < MAXN; ++i)
		Inv[i] = Inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 1; i < MAXN; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * Inv[i] % mod;
	}
	dp(0, 0, 0) = 1;
	for(int i = 0; i < n; ++i) {
		memset(dp[(i + 1) & 1], 0, sizeof dp[(i + 1) & 1]);
		memset(coef[(i + 1) & 1], 0, sizeof coef[(i + 1) & 1]);
		for(int j = max(0ll, L[i]); j <= min(i, R[i]); ++j) {
			for(int c = 0, p; c <= i; ++c) {
				if(!dp(i, j, c)) continue;
				if(L[i + 1] <= j && j <= R[i + 1]) {
					(dp(i + 1, j, c) += dp(i, j, c) * (j + c)) %= mod;
					(dp(i + 1, j, c + 1) += dp(i, j, c)) %= mod;
				}
				if(j <= R[i + 1]) {
					p = max(j + 1, L[i + 1]) - j;
					if(p - 1 <= c)
						(coef(i + 1, j + p, c - p + 1) += dp(i, j, c) * fac[c] % mod * ifac[c - p + 1]) %= mod;
				}
			}
		}
		pushup(i + 1);
	}
	for(int j = max(0ll, L[n]); j <= min(n, R[n]); ++j)
		for(int c = 0; c <= n; ++c)
			if(c <= n - j && dp(n, j, c))
				(Ans += dp(n, j, c) * fac[n - j] % mod * ifac[n - j - c]) %= mod;
	printf("%lld\n", Ans);
	return 0;
}