#include<bits/stdc++.h>

const int N = 200010;

std::vector <int> e[N];
int n;
int a[N], now[N], ans[N];

void dfs(int u, int fa, std::set <int> set){
	for (auto v : e[u]){
		if (v == fa){
			continue;
		}
		now[v] = std::__gcd(now[u], a[v]);
		std::set <int> _set;
		for (auto w : set){
			_set.insert(std::__gcd(w, a[v]));
		}
		_set.insert(now[u]);
		ans[v] = std::max(now[v], *(-- _set.end()));
		dfs(v, u, _set);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	now[1] = ans[1] = a[1];
	dfs(1, 0, {0});
	for (int i = 1; i <= n; ++ i){
		printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}