#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 223456;
int n, k, u, v;
vector<int> e[maxN];
int sz[maxN], dep[maxN], f[maxN];
i64 ans;
void dfs(int u, int f)
{
	sz[u] = 1;
	dep[u] = dep[f] + 1;
	for (auto v : e[u])
	{
		if (v == f)
			continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		f[i] = dep[i] - sz[i];
	sort(f + 1, f + n + 1);
	for (int i = 0; i < k; i++)
		ans += f[n - i];
	printf("%lld\n", ans);
}