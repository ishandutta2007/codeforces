#include<bits/stdc++.h>
#define ll long long

const int N = 100010;
const int M = 30000010;

int a[N], dp[N], cnt[M], max = 0;
int n;
std::vector <int> e[N];

void dfs(int u){
	max = std::max(max, dp[u]);
	for (auto v : e[u]){
		dp[v] = dp[u] + 1;
		dfs(v);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 2, x; i <= n; ++ i){
		scanf("%d", &x);
		e[x].push_back(i);
	}
	dfs(1);
	int count = 0, sum = 0;
	for (int i = 1; i <= n; ++ i){
		if ((dp[i] & 1) == (max & 1)){
			++ count;
			sum ^= a[i];
		}
		else{
			++ cnt[a[i]];
		}
	}
	ll ans = 0;
	if (!sum){
		ans += 1ll * count * (count - 1) >> 1;
		ans += 1ll * (n - count) * (n - count - 1) >> 1;
	}
	for (int i = 1; i <= n; ++ i){
		if ((dp[i] & 1) == (max & 1)){
			ans += cnt[sum ^ a[i]];
		}
	}
	return printf("%I64d\n", ans), 0;
}