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

const int MAXN = 1010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans;
int dp[MAXN][MAXN][2], ok[2][MAXN];
char X[MAXN], Y[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void modadd(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	scanf("%s", X + 1); n = strlen(X + 1);
	scanf("%s", Y + 1); m = strlen(Y + 1);
	for(int i = 1; i <= n; ++i)
		ok[0][i] = 1 + (i > 1 && X[i] != X[i - 1]) * ok[0][i - 1];
	for(int i = 1; i <= m; ++i)
		ok[1][i] = 1 + (i > 1 && Y[i] != Y[i - 1]) * ok[1][i - 1];
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(X[i] != Y[j]) {
				modadd(dp[i][j][0], ok[1][j]), modadd(dp[i][j][1], ok[0][i]);
				modadd(dp[i][j][0], dp[i - 1][j][1]);
				modadd(dp[i][j][1], dp[i][j - 1][0]);
			}
			if(i > 1 && X[i] != X[i - 1]) modadd(dp[i][j][0], dp[i - 1][j][0]);
			if(j > 1 && Y[j] != Y[j - 1]) modadd(dp[i][j][1], dp[i][j - 1][1]);
			(Ans += dp[i][j][0] + dp[i][j][1]) %= mod;
		}
	} 
	printf("%lld\n", Ans);
	return 0;
}