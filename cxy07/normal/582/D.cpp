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

const int MAXN = 4010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, p, K, len, Ans;
int dp[2][MAXN][2][2], now, pre = 1;
int lim[MAXN];
char N[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void up(int &x, int y, int z) { z %= mod; (x += y * z) %= mod; }

void calc() {
	memset(dp, 0, sizeof dp); 
	memset(lim, 0, sizeof lim); int top = 1;
	for(int i = 1; i <= len; ++i) {
		for(int j = 1; j <= top; ++j) lim[j] *= 10;
		lim[1] += N[i] - '0';
		for(int j = 1; j <= top; ++j) {
			lim[j + 1] += lim[j] / p, lim[j] %= p;
			if(lim[top + 1]) top++;
		}
	}
	reverse(lim + 1, lim + top + 1);
	dp[now][0][0][0] = 1;
	for(int i = 1, x; i <= top; ++i) {
		x = lim[i]; swap(now, pre); memset(dp[now], 0, sizeof dp[now]);
		for(int j = 0; j <= i; ++j) {
			up(dp[now][j][0][0], dp[pre][j][0][0], x + 1);
			up(dp[now][j][0][0], dp[pre][j][0][1], p - x - 1);
			up(dp[now][j + 1][0][1], dp[pre][j][0][0], x);
			up(dp[now][j + 1][0][1], dp[pre][j][0][1], p - x);
			up(dp[now][j][1][0], dp[pre][j][0][0], (x + 1) * x >> 1);
			up(dp[now][j][1][0], dp[pre][j][0][1], x * (2 * p - x - 1) >> 1);
			up(dp[now][j][1][0], dp[pre][j][1][0], (p + 1) * p >> 1);
			up(dp[now][j][1][0], dp[pre][j][1][1], (p - 1) * p >> 1);
			up(dp[now][j + 1][1][1], dp[pre][j][0][0], (x - 1) * x >> 1);
			up(dp[now][j + 1][1][1], dp[pre][j][0][1], x * (2 * p - x + 1) >> 1);
			up(dp[now][j + 1][1][1], dp[pre][j][1][0], (p - 1) * p >> 1);
			up(dp[now][j + 1][1][1], dp[pre][j][1][1], (p + 1) * p >> 1);
		}
	}
	for(int i = top; i >= K; --i) 
		(Ans += (dp[now][i][0][0] + dp[now][i][1][0]) % mod + mod) %= mod;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(p), read(K); scanf("%s", N + 1); 
	len = strlen(N + 1); calc(); 
	printf("%lld\n", Ans);
	return 0;
}