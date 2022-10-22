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
#define vec vector

const int MAXN = 210;
const int MAXK = 1010;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, k, ans;
int a[MAXN], pre = 0, now = 1;
int dp[2][MAXN][MAXK];

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
	read(n); read(k);
	for(int i = 1; i <= n; ++i) read(a[i]);
	sort(a + 1, a + n + 1);
	dp[now][0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		swap(now, pre);
		memset(dp[now], 0, sizeof dp[now]);
		for(int j = 0; j <= i; ++j) {
			for(int p = 0; p <= k; ++p) {
				int v = a[i] - a[i - 1];
				//
				if(p - v * j >= 0) 
					(dp[now][j][p] += j * dp[pre][j][p - v * j] % mod) %= mod;
				//
				if(j != n && p - v * (j + 1) >= 0)
					(dp[now][j][p] += (j + 1) * dp[pre][j + 1][p - v * (j + 1)]) %= mod;
				//
				if(j && p - v * (j - 1) >= 0)
					(dp[now][j][p] += dp[pre][j - 1][p - v * (j - 1)]) %= mod;
				//&
				if(p - v * j >= 0)
					(dp[now][j][p] += dp[pre][j][p - v * j]) %= mod;
			}
		}
	}
	for(int i = 0; i <= k; ++i)
		(ans += dp[now][0][i]) %= mod;
	cout << (ans % mod + mod) % mod << endl;
	return 0;
}