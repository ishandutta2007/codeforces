#include <bits/stdc++.h>
#define maxn 4010
#define getsum(l, r) (sum[r] - sum[l - 1])
using namespace std;
int sum[maxn], dp[30000010], n;

inline int read(){
	int s = 0, w = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') w = -1;
	for (; isdigit(c); c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
	return s * w;
}

int Hash(int a, int b, int c, int d){
	return ((((a * 4000ll) + b) * 100 + c) * 2 + d) % 29999999;
}

int dfs(int l, int r, int x, int k){
	if (r - l + 1 < x) return 0;
	if (r - l + 1 == x) return getsum(l, r) * (k ? -1 : 1);
	int sta = Hash(l, r, x, k);
	if (~dp[sta]) return dp[sta];
	int ans = 0;
	if (k){
		ans = dfs(l, r - x, x, 0) - getsum(r - x + 1, r);
		if (l <= r - x) ans = min(ans, dfs(l, r - x - 1, x + 1, 0) - getsum(r - x, r));
		return dp[sta] = ans;
	} else{
		ans = dfs(l + x, r, x, 1) + getsum(l, l + x - 1);
		if (l + x <= r) ans = max(ans, dfs(l + x + 1, r, x + 1, 1) + getsum(l, l + x));
		return dp[sta] = ans;
	}
}

int main(){
	n = read();
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; ++i) sum[i] = read(), sum[i] += sum[i - 1];
	printf("%d\n", dfs(1, n, 1, 0));
	return 0;
}