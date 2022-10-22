//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n,m;
int s[MAXN];
int dp[MAXN][3][2][2];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 1;i <= n; ++i) read(s[i]);
	memset(dp,-0x3f,sizeof dp);
	if(n == 1) return printf("%lld\n",s[1]),0;
	dp[1][1][1][0] = s[1];
	dp[1][2][0][0] = -s[1];
	for(int i = 1;i < n; ++i) {
		for(int m = 0;m <= 2; ++m) {
			for(int a = 0;a <= 1; ++a) 
				for(int b = 0;b <= 1; ++b)
					dp[i + 1][(m + 1) % 3][1][b || (a == 1)] = max(dp[i + 1][(m + 1) % 3][1][b || (a == 1)],dp[i][m][a][b] + s[i + 1]),
					dp[i + 1][(m + 2) % 3][0][b || (a == 0)] = max(dp[i + 1][(m + 2) % 3][0][b || (a == 0)],dp[i][m][a][b] - s[i + 1]);
		}
	}
	printf("%lld\n",max(dp[n][1][0][1],dp[n][1][1][1]));
	return 0;
}