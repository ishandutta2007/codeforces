#include<bits/stdc++.h>
using namespace std;

const int maxn = 200005;
vector<int> e[maxn], ans;
int flag[maxn], n, p, root;

int dfs(int u, int fa) {
	int res = 0;
	for (auto v : e[u])
		if (v != fa) res += dfs(v, u);
	if (res & 1) {
		flag[u] = 1;
		ans.push_back(u);
		return 0;
	}
	return 1;
}

void solve(int u, int fa) {
	if (!flag[u]) ans.push_back(u);
	for (auto v : e[u])
		if (v != fa) solve(v, u);
} 

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &p);
		if (!p) continue;
		e[p].push_back(i);
		e[i].push_back(p);
	}
	for (int i=1; i<=n; i++)
		if (e[i].size() == 1) root = i;
	if (n == 1) return puts("YES\n1"), 0;
	if (dfs(e[root][0], root)) return puts("NO"), 0;
	puts("YES");
	solve(e[root][0], root); ans.push_back(root);
	for (int i=0; i<ans.size(); i++)
		printf("%d\n", ans[i]);
	return 0;
}