#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld long double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	

const int SUM = 100000;

int n, m;
int x[105];
int sum;

ld dp[105][100005];

ld get(int i, int l, int r) {
	l = max(l, 0);
	if(l <= r) return dp[i][r] - (l > 0 ? dp[i][l - 1] : 0.0);
	return 0.0;
}
			
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", x + i);
		sum += x[i];
	}
	if(m == 1) {
		printf("1.0000000000");
		return 0;
	}
	
	dp[0][0] = 1.0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= sum; ++j)	
			dp[i - 1][j] += dp[i - 1][j - 1];
			
		for(int j = 1; j <= sum; ++j) 
			dp[i][j] = (ld) (get(i - 1, j - m, j - 1) - (j - x[i] >= 0 ? get(i - 1, j - x[i], j - x[i]) : 0.0)) / (m - 1);
			
	}
	
	ld ans = 0.0;
	for(int i = 1; i < sum; ++i)
		ans += dp[n][i];
	printf("%.12Lf\n", 1.0 + (ld) (m - 1) * ans);
	
	
	return 0;
}