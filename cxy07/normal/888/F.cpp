//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
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

const int MAXN = 510;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int dp[MAXN][MAXN][2], ok[MAXN][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) read(ok[i][j]);
	for(int i = 1; i <= n; ++i) dp[i][i][0] = 1;
	for(int l = 2; l <= n; ++l)
		for(int i = 1, j; i + l - 1 <= n; ++i) {
			j = i + l - 1;
			for(int k = i; k < j; ++k) {
				if(ok[i][j]) (dp[i][j][1] += (dp[i][k][0] + dp[i][k][1]) * (dp[k + 1][j][0] + dp[k + 1][j][1])) %= mod;
				(dp[i][j][0] += dp[i][k][1] * (dp[k][j][0] + dp[k][j][1])) %= mod;
			}
		}
	printf("%lld\n", (dp[1][n][0] + dp[1][n][1]) % mod);
	return 0;
}