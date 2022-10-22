#include <bits/stdc++.h>

#define MAX (1 << 17)
#define MAXN (100010)

int n, m;
int a[MAXN], dp1[MAXN], dp2[MAXN];
int seg[(MAXN << 1) + 10];

void solve(int *dp){
	memset(seg, 0, sizeof(seg));
	for (int i = 1; i <= m; ++ i){
		for (int l = MAX, r = a[i] + MAX + 1; l < r; l >>= 1, r >>= 1){
			if (l & 1) dp[i] = std::max(dp[i], seg[l ++]);
			if (r & 1) dp[i] = std::max(dp[i], seg[-- r]);
		}
		++ dp[i];
		
		int sit = a[i] + MAX;
		seg[sit] = dp[i];
		for (sit >>= 1; sit; sit >>= 1){
			seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i){
		int l, r;
		scanf("%d%d", &l, &r);
		++ r;
		++ a[l];
		-- a[r];
	}
	for (int i = 2; i <= m; ++ i){
		a[i] += a[i - 1];
	}
	solve(dp1);
	std::reverse(a + 1, m + a + 1);
	solve(dp2);
	int ans = 0;
	for (int i = 1; i <= m; ++ i){
		ans = std::max(ans, dp1[i] + dp2[m + 1 - i] - 1);
	}
	printf("%d\n", ans);
	return 0;
}