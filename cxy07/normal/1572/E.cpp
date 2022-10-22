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

const int MAXN = 410;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, L, R, mid, X[MAXN], Y[MAXN];
int dp[MAXN][MAXN], s[MAXN][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int cross(int x1, int y1, int x2, int y2) { return x1 * y2 - x2 * y1; }

int S(int a, int b, int c) { return abs(cross(X[b] - X[a], Y[b] - Y[a], X[c] - X[a], Y[c] - Y[a])); }

bool chk(int lim) {
	memset(dp, 0, sizeof dp); memset(s, 0, sizeof s);
	for(int l = 3; l <= n; ++l)
		for(int i = 1, j; i + l - 1 <= n; ++i) {
			j = i + l - 1;
			for(int k = i + 1, v, curs; k < j; ++k) {
				v = dp[i][k] + dp[k][j];
				curs = S(i, k, j) + s[i][k] + s[k][j];
				if(curs >= lim) {
					if(dp[i][j] < v + 1) dp[i][j] = v + 1, s[i][j] = 0;
				} else {
					if(dp[i][j] < v) dp[i][j] = v, s[i][j] = curs;
					else if(dp[i][j] == v) s[i][j] = max(s[i][j], curs);
				}
			}
		}
	return dp[1][n] >= k + 1;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k);
	for(int i = 1; i <= n; ++i) read(X[i]), read(Y[i]);
	L = 0, R = 1e18;
	while(L < R) {
		mid = (L + R + 1) >> 1;
		if(chk(mid)) L = mid;
		else R = mid - 1;
	} printf("%lld\n", L);
	return 0;
}