#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

const int nax = 1e5 + 111;
const LL INF = 1e18;

void maxi(LL &a, LL b) {
	a = max(a, b);
}

int n;
LL a[nax][3];
LL dp[nax][3];

int main() {	
	scanf ("%d", &n);
	
	rep(j, 0, 2) rep(i, 1, n) scanf ("%lld", &a[i][j]);
	
	LL Down = -INF, Up = -INF, Sum = 0;
	
	dp[0][1] = -INF;
	dp[0][2] = -INF;
	
	rep(i, 1, n) {
		
		Sum += a[i][0];
		Sum += a[i][1];
		Sum += a[i][2];
		
		dp[i][0] = -INF;
		dp[i][1] = -INF;
		dp[i][2] = -INF;
		
		maxi(dp[i][0], dp[i - 1][0] + a[i][0]);
		maxi(dp[i][0], dp[i - 1][1] + a[i][0] + a[i][1]);
		maxi(dp[i][0], dp[i - 1][2] + a[i][0] + a[i][1] + a[i][2]);
		
		maxi(dp[i][1], dp[i - 1][1] + a[i][1]);
		maxi(dp[i][1], dp[i - 1][0] + a[i][0] + a[i][1]);
		maxi(dp[i][1], dp[i - 1][2] + a[i][1] + a[i][2]);
		
		maxi(dp[i][2], dp[i - 1][2] + a[i][2]);
		maxi(dp[i][2], dp[i - 1][1] + a[i][1] + a[i][2]);
		maxi(dp[i][2], dp[i - 1][0] + a[i][0] + a[i][1] + a[i][2]);
		
		maxi(dp[i][0], Sum + Down);
		maxi(dp[i][2], Sum + Up);
		
		LL x = a[i][0] + a[i][1] + a[i][2];
		
		maxi(Up, dp[i - 1][0] - (Sum - x));
		maxi(Down, dp[i - 1][2] - (Sum - x));
	}
		
	printf ("%lld", dp[n][2]);	
	
	
	return 0;
}