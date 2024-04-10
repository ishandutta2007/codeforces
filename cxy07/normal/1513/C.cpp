//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, Ans;
int dp[MAXN][11];
char nn[11];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void DP() {
	for(int i = 0; i < 10; ++i) dp[0][i] = 1;
	for(int i = 1; i <= (int)2e5; ++i) {
		for(int x = 0, y; x < 10; ++x) {
			y = x + 1;
			if(y < 10) dp[i][x] = dp[i - 1][y];
			else dp[i][x] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T); DP();
	while(T--) {
		scanf("%s", nn + 1); read(m); Ans = 0;
		int len = strlen(nn + 1);
		for(int i = 1; i <= len; ++i) {
			Ans += dp[m][nn[i] - '0'];
			if(Ans >= mod) Ans -= mod;
		}
		printf("%d\n", Ans);
	}
	return 0;
}