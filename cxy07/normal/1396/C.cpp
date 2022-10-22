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

const int MAXN = 1e6 + 10;
const int INF = 1e18;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, r1, r2, r3, d, Ans;
int a[MAXN], dp[MAXN][2];

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
	read(n), read(r1), read(r2), read(r3), read(d);
	r1 = min(r1, r3);
	for(int i = 1; i <= n; ++i) read(a[i]);
	dp[0][1] = INF;
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = dp[i - 1][0] + r1 * a[i] + r3;
		dp[i][0] = min(dp[i][0], dp[i - 1][1] + r1 * a[i] + r3 + d * 2 + r1);
		dp[i][0] = min(dp[i][0], dp[i - 1][1] + min(r1 * (a[i] + 1), r2) + r1 * 2 + d * 2);
		dp[i][1] = dp[i - 1][0] + min(r1 * (a[i] + 1), r2);
		dp[i][1] = min(dp[i][1], dp[i - 1][1] + min(r1 * (a[i] + 1), r2) + r1 + d * 2);
	}
	Ans = dp[n][0];
	Ans = min(Ans, dp[n - 1][1] + r1 * a[n] + r3 + d + r1);
	Ans += (n - 1) * d;
	printf("%lld\n", Ans);
	return 0;
}