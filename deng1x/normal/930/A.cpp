#include <bits/stdc++.h>

#define MAXN (100010) 

int n;
std::vector<int> vec[MAXN];
int dep[MAXN], cnt[MAXN];

void dfs(int u){
	for (auto v : vec[u]){
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 2; i <= n; ++ i){
		int pi;
		scanf("%d", &pi);
		vec[pi].push_back(i);
	}
	dfs(1);
	int ans = 0;
	for (int i = 1; i <= n; ++ i){
		++ cnt[dep[i]];
	}
	for (int i = 0; i <= n; ++ i){
		ans += cnt[i] % 2;
	}
	printf("%d\n", ans);
	return 0;
}