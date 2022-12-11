#include <bits/stdc++.h>
const int MaxN = 300123;

int n, cnt, a[MaxN], b[MaxN], f[MaxN], g[MaxN], dis[MaxN * 10], pre[MaxN * 10];
std::vector<int> G0[MaxN * 10], G1[MaxN * 10];
int node[MaxN * 4];

void Build(int k = 1, int L = 1, int R = n)
{
	if(L == R)
	{
		node[k] = f[L];
		return;
	}
	
	int Mid = (L + R) / 2;
	node[k] = ++cnt;
	Build(k << 1, L, Mid); Build(k << 1 | 1, Mid + 1, R);
	G0[node[k]].push_back(node[k << 1]);
	G0[node[k]].push_back(node[k << 1 | 1]);
}

void Modify(int l, int r, int v, int k = 1, int L = 1, int R = n)
{
	if(l <= L && R <= r) return G1[v].push_back(node[k]), void();
	int Mid = (L + R) / 2;
	if(l <= Mid) Modify(l, r, v, k << 1, L, Mid);
	if(Mid < r) Modify(l, r, v, k << 1 | 1, Mid + 1, R);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= n; ++i) scanf("%d", b + i);
	
	for(int i = 1; i <= n; ++i) f[i] = ++cnt;
	for(int i = 1; i <= n; ++i) g[i] = ++cnt;
	for(int i = 1; i <= n; ++i) G0[f[i]].push_back(g[i + b[i]]);
		
	Build();
	
	for(int i = 1; i <= n; ++i)
	{
		if(i == a[i]) G1[g[i]].push_back(0);
		Modify(std::max(i - a[i], 1), i, g[i]);
	}
	
	for(int i = 0; i <= cnt; ++i) dis[i] = INT_MAX;
	dis[f[n]] = 0; std::deque<int> q = {f[n]};
	
	while(!q.empty())
	{
		int u = q.front(); q.pop_front();
		for(int v : G0[u]) if(dis[v] > dis[u])
		dis[v] = dis[u], pre[v] = u, q.push_front(v);
		for(int v : G1[u]) if(dis[v] > dis[u] + 1)
		dis[v] = dis[u] + 1, pre[v] = u, q.push_back(v);
	}
	
	if(dis[0] == INT_MAX) puts("-1");
	else
	{
		printf("%d\n", dis[0]);
		std::vector<int> V;
		for(int u = 0; u != f[n]; u = pre[u]) if(u <= n) V.push_back(u);
		std::reverse(V.begin(), V.end());
		for(int x : V) printf("%d ", x);
	}
	return 0;
}