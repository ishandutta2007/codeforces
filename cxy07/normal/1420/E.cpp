//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))

const int MAXN = 85;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n,m,tot,minval;
int a[MAXN],at[MAXN],sum[MAXN],cnt = 1;
int dp[MAXN][MAXN][MAXN * MAXN];//dp[i][j][k]:ijk

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int val(int x) {return (x - 1) * x / 2;}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 1,x;i <= n; ++i) {
		read(x);
		if(x) at[cnt++] = i;
		else a[cnt]++;
	}
	//a[1-cnt],at[1-(cnt-1)]
	for(int i = 1;i <= cnt; ++i) tot += a[i];
	int tmp = val(tot);
	for(int i = 1;i <= cnt; ++i) {
		tmp -= val(a[i]);
		minval += val(a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	printf("%d ",tmp);	
	memset(dp,0x3f,sizeof dp);
	dp[0][0][0] = 0;
	for(int i = 0;i <= tot; ++i) {
		for(int j = 1;j < cnt; ++j) {
			int st = abs(at[j] - (i + j));
			for(int k = 0;k <= n * (n - 1) / 2; ++k) {
				if(k < st) continue;
				for(int p = 0;p <= i; ++p) {
					dp[i][j][k] = min(dp[i][j][k],dp[p][j - 1][k - st] + val(i - p));
				}
			}
		}
	}
	for(int t = 1;t <= (n - 1) * n / 2; ++t) {
		for(int i = 0;i <= tot; ++i)
			minval = min(minval,dp[i][cnt - 1][t] + val(tot - i));
		printf("%d ",val(tot) - minval);
	}
	return 0;
}