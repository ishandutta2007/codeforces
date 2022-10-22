#include <bits/stdc++.h>

#define MAXN (2010)

int n;
int a[MAXN];
int cnt1[MAXN], cnt2[MAXN];
int dp[MAXN][2];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i){
		scanf("%d", a + i);
	}
	for(int i = 1; i <= n; ++ i){
		cnt1[i] = cnt1[i - 1] + (a[i] == 1);
	}
	for(int i = n; i >= 1; -- i){
		cnt2[i] = cnt2[i + 1] + (a[i] == 2);
	}
	int ans = 0;
	for(int l = 1; l <= n; ++ l){
		memset(dp, 0, sizeof(dp));
		for(int r = l; r <= n; ++ r){
			if(a[r] == 1){
				dp[r][0] = std::max(dp[r - 1][0], dp[r - 1][1]) + 1;
				dp[r][1] = dp[r - 1][1];
			}
			else{
				dp[r][1] = dp[r - 1][1] + 1;
				dp[r][0] = dp[r - 1][0];
			}
			ans = std::max(ans, cnt1[l - 1] + std::max(dp[r][0], dp[r][1]) + cnt2[r + 1]);
		}
	}
	printf("%d\n", ans);
	return 0;
}