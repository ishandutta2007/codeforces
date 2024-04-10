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

const int MAXN = 5010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, Ans;
int dp[MAXN][MAXN], sum[2][MAXN], tmp[MAXN];
vec<int> G[MAXN];

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

void DFS(int x, int f) {
	dp[x][0] = 1;
	for(auto to : G[x]) {
		if(to == f) continue;
		DFS(to, x); sum[0][0] = dp[x][0], sum[1][0] = dp[to][0];
		for(int i = 1; i <= k; ++i) {
			sum[0][i] = sum[0][i - 1]; modadd(sum[0][i], dp[x][i]);
			sum[1][i] = sum[1][i - 1]; modadd(sum[1][i], dp[to][i]);
		}
		for(int i = 0; i <= k; ++i) (tmp[i] = dp[x][i] * sum[1][k]) %= mod; // cut
		for(int i = 0; i <= k; ++i) {
			if(min(k - i, i) - 1 >= 0) (tmp[i] += dp[x][i] * sum[1][min(k - i, i) - 1]) %= mod;
			if(min(k - i, i - 1) >= 0) (tmp[i] += dp[to][i - 1] * sum[0][min(k - i, i - 1)]) %= mod;
			dp[x][i] = tmp[i]; if(dp[x][i] < 0) dp[x][i] += mod;
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k);
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	} DFS(1, 0);
	for(int i = 0; i <= k; ++i) modadd(Ans, dp[1][i]);
	printf("%lld\n", Ans);
	return 0;
}