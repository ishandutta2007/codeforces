#include<bits/stdc++.h>

const int N = 110;
const int INF = 0x3f3f3f3f;

int dp[N][2];
int n, m;
int left[N], right[N];
int a[N][N];

int main(){
	scanf("%d%d", &n, &m);
	memset(left, 0x3f, sizeof(left));
	int min = n;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j <= m + 1; ++ j){
			scanf("%1d", &a[i][j]);
			if (a[i][j]){
				left[i] = std::min(left[i], j);
				right[i] = std::max(right[i], j);
				min = std::min(min, i);
			}
		}
	}
	if (min == n){
		return printf("0\n"), 0;
	}
	for (int i = 0; i < n; ++ i){
		if (left[i] == INF){
			left[i] = m + 1;
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[n - 1][0] = 0;
	for (int i = n - 1; i > min; -- i){
		if (dp[i][0] != INF){
			dp[i - 1][1] = std::min(dp[i - 1][1], dp[i][0] + m + 2);
			dp[i - 1][0] = std::min(dp[i - 1][0], dp[i][0] + 2 * right[i] + 1);
		}
		if (dp[i][1] != INF){
			dp[i - 1][0] = std::min(dp[i - 1][0], dp[i][1] + m + 2);
			dp[i - 1][1] = std::min(dp[i - 1][1], dp[i][1] + 2 * (m + 1 - left[i]) + 1);
		}
	}
	int ans = std::min(dp[min][0] + right[min], dp[min][1] + (m + 1 - left[min]));
	return printf("%d\n", ans), 0;
}