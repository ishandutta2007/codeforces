#include <bits/stdc++.h>

#define MAXN (100010)

int n, m, h;
std::vector<int> vec[MAXN];
int u[MAXN];
int dfn[MAXN], low[MAXN], cnt;
int sccno[MAXN], scc_cnt;
std::stack<int> st;
int du[MAXN];
std::vector<int> cev[MAXN];

void dfs(int x){
	st.push(x);
	dfn[x] = low[x] = ++ cnt;
	for (auto &y : vec[x]){
		if (!dfn[y]){
			dfs(y);
			low[x] = std::min(low[x], low[y]);
		}
		else if (!sccno[y]){
			low[x] = std::min(low[x], dfn[y]);
		}
	}
	if (dfn[x] == low[x]){
		sccno[x] = ++ scc_cnt;
		cev[scc_cnt].push_back(x);
		while (st.top() != x){
			sccno[st.top()] = scc_cnt;
			cev[scc_cnt].push_back(st.top());
			st.pop();
		}
		st.pop();
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 1; i <= n; ++ i) scanf("%d", u + i);
	for (int i = 1; i <= m; ++ i){
		int a, b;
		scanf("%d%d", &a, &b);
		if((u[a] + 1) % h == u[b]){
			vec[a].push_back(b);
		}
		if((u[b] + 1) % h == u[a]){
			vec[b].push_back(a);
		}
	}
	for (int i = 1; i <= n; ++ i){
		if (!dfn[i]){
			dfs(i);
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (auto j : vec[i]){
			if (sccno[i] == sccno[j]) continue;
			++ du[sccno[i]];
		}
	}
	int ans = INT_MAX, sit = 0;
	for (int i = 1; i <= scc_cnt; ++ i){
		if (!du[i] && ans > cev[i].size()){
			ans = cev[i].size();
			sit = i;
		}
	}
	printf("%d\n", ans);
	for (auto u : cev[sit]){
		printf("%d ", u);
	}
	printf("\n");
	return 0;
}