#include<bits/stdc++.h>

const int N = 5010;
const int INF = 0x7f7f7f7f;

int left[N], right[N], dp[N];
int n, a[N];
int cnt[N][N], sum[N][N];

int main(){
	scanf("%d", &n);
	memset(left, 0x7f, sizeof(left));
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		left[a[i]] = std::min(left[a[i]], i);
		right[a[i]] = std::max(right[a[i]], i);
	}
	for (int i = 1; i <= n; ++ i){
		++ cnt[0][right[a[i]]];
		-- cnt[left[a[i]] + 1][right[a[i]]];
	}
	for (int i = 0; i < N; ++ i){
		if (left[i] == INF){
			continue;
		}
		sum[0][right[i]] ^= i;
		sum[left[i] + 1][right[i]] ^= i;
	}
	for (int i = 0; i < N; ++ i){
		for (int j = 1; j < N; ++ j){
			cnt[i][j] += cnt[i][j - 1];
			sum[i][j] ^= sum[i][j - 1];
		}
	}
	for (int j = 0; j < N; ++ j){
		for (int i = 1; i < N; ++ i){
			cnt[i][j] += cnt[i - 1][j];
			sum[i][j] ^= sum[i - 1][j];
		}
	}
	memset(dp, 0x7f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; ++ i){
		dp[i] = dp[i - 1];
		for (int j = 1; j <= i; ++ j){
			if (cnt[j][i] == i - j + 1){
				dp[i] = std::max(dp[i], dp[j - 1] + sum[j][i]);
			}
		}
	}
	return printf("%d\n", dp[n]), 0;
}