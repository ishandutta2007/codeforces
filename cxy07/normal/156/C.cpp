//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
//#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) ksm(x,mod - 2)
#define lowbit(x) (x & (-x))

const int MAXN = 110;
const int INF = 2e9;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;

int T,n,sum,ans;
int dp[MAXN][MAXN * 26];
char s[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int DP(int x,int s) {
	if(x < 0) return 0;
	if(dp[x][s] != -1) return dp[x][s];
	dp[x][s] = 0;
	for(int i = 1;i <= min(s,26); ++i)
		(dp[x][s] += DP(x - 1,s - i)) %= mod;
	return dp[x][s];
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	memset(dp,-1,sizeof dp);
	dp[0][0] = 1;
	while(T--) {
		scanf("%s",s + 1);
		n = strlen(s + 1);
		sum = ans = 0;
		for(int i = 1;i <= n; ++i) sum += s[i] - 'a' + 1;
		//cout << sum << endl;
		//cout << n << endl;
		ans = ((DP(n,sum) - 1) % mod + mod) % mod;
		printf("%d\n",ans);
	}
	return 0;
}