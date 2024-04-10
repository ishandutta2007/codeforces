#include <algorithm>
#include <cstring>
#include <cstdio>
int lst[100005], to[200005], pre[200005], tot; 
int dep[100005], fa[100005][25], dfn[100005], clk; 
int rem[100005], seq[100005], node[100005], st[100005], vfa[100005]; 
bool imp[100005]; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u, int f = -1)
{
	dfn[u] = clk++; 
	fa[u][0] = f; 
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[u][i - 1] == -1 ? -1 : fa[fa[u][i - 1]][i - 1]; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		if (to[i] == f)
			continue; 
		dep[to[i]] = dep[u] + 1; 
		dfs(to[i], u); 
	}
}
inline int lca(int u, int v)
{
	if (dep[u] > dep[v])
		std::swap(u, v); 
	for (int i = 0; i < 20; i++)
	{
		if (dep[v] - dep[u] & (1 << i))
			v = fa[v][i]; 
	}
	if (u == v)
		return u; 
	for (int i = 19; i >= 0; i--)
	{
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i]; 
			v = fa[v][i]; 
		}
	}
	return fa[u][0]; 
}
inline bool comp(int u, int v)
{
	return dfn[u] < dfn[v]; 
}
int work(int u)
{
	int res = 0, sum = 0; 
	for (int i = lst[u]; ~i; i = pre[i])
	{
		res += work(to[i]); 
		sum += rem[to[i]]; 
	}
	if (imp[u])
	{
		res += sum; 
		rem[u] = 1; 
	}
	else
	{
		res += sum > 1; 
		rem[u] = sum == 1; 
	}
	return res; 
}
int main()
{
	// freopen("613D.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i < n; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v);
		add_edge(--u, --v); 
		add_edge(v, u); 
	}
	dfs(0); 
	memset(lst, -1, sizeof(lst)); 
	tot = 0; 
	st[0] = -1; 
	int q; 
	scanf("%d", &q); 
	while (q--)
	{
		int k, cnt = 0, tp = 0; 
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
		{
			scanf("%d", seq + i); 
			imp[--seq[i]] = true; 
			node[cnt++] = seq[i]; 
		}
		std::sort(seq, seq + k, comp); 
		for (int i = 0; i < k; i++)
		{
			if (!tp)
			{
				vfa[seq[i]] = -1; 
				st[++tp] = seq[i]; 
				continue; 
			}
			int x = lca(seq[i], st[tp]); 
			while (dep[st[tp]] > dep[x])
			{
				if (dep[st[tp - 1]] <= dep[x])
					vfa[st[tp]] = x; 
				tp--; 
			}
			if (x != st[tp])
			{
				vfa[x] = st[tp]; 
				st[++tp] = x; 
				node[cnt++] = x; 
			}
			st[++tp] = seq[i]; 
			vfa[seq[i]] = x; 
		}
		std::sort(node, node + cnt, comp);
		for (int i = 1; i < cnt; i++)
		{
			int u = node[i], v = vfa[u]; 
			add_edge(v, u); 
		}
		bool f = true; 
		for (int i = 0; i < k; i++)
			f &= -1 == fa[seq[i]][0] || !imp[fa[seq[i]][0]]; 
		printf("%d\n", f ? work(node[0]) : -1);
		for (int i = 0; i < k; i++)
			imp[seq[i]] = false; 
		for (int i = 0; i < cnt; i++)
			lst[node[i]] = -1; 
		tot = 0; 
	}
	return 0; 
}