#include <iostream>
#include <cstdio>
using namespace std; 
struct Tree
{
	int pre, pos; 
	Tree()
	{
	}
	Tree(int _pre, int _pos)
	{
		pre = _pre; 
		pos = _pos; 
	}
	inline bool operator <(const Tree &a) const
	{
		return pre < a.pre; 
	}
} data[2000005]; 
int pre[500005], nxt[500005], ans[500005], n, seq[500005], tot; 
bool vis[500005];
void build(int u, int l, int r)
{
	if (l == r)
	{
		data[u] = Tree(pre[l], l); 
		return;
	}
	int m = l + r >> 1; 
	build(u << 1, l, m); 
	build(u << 1 | 1, m + 1, r); 
	data[u] = max(data[u << 1], data[u << 1 | 1]); 
}
void modify(int u, int l, int r, int pos)
{
	if (l == r)
	{
		data[u].pre = 0; 
		return; 
	}
	int m = l + r >> 1; 
	if (pos <= m)
		modify(u << 1, l, m, pos); 
	else
		modify(u << 1 | 1, m + 1, r, pos); 
	data[u] = max(data[u << 1], data[u << 1 | 1]); 
}
Tree query(int u, int l, int r, int L, int R)
{
	// cout << u << " " << l << " " << r << " " << L << " " << R << endl; 
	if (L > R)
		return Tree(0, 0); 
	if (L <= l && r <= R)
		return data[u]; 
	int m = l + r >> 1; 
	Tree res(0, 0); 
	if (L <= m)
		res = max(res, query(u << 1, l, m, L, R)); 
	if (m < R)
		res = max(res, query(u << 1 | 1, m + 1, r, L, R)); 
	return res; 
}
void dfs(int u)
{
	vis[u] = true; 
	modify(1, 0, n - 1, u); 
	if (pre[u] != n && !vis[pre[u]])
		dfs(pre[u]); 
	while (true)
	{
		Tree res = query(1, 0, n - 1, 0, nxt[u] - 1); 
		if (res.pre > u)
			dfs(res.pos); 
		else
			break; 
	}
	seq[tot++] = u; 
}
int main()
{
	// freopen("798E.in", "r", stdin); 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", nxt + i); 
		if (nxt[i] == -1)
			nxt[i] = n; 
		else
			nxt[i]--; 
		pre[i] = n; 
	}
	for (int i = 0; i < n; i++)
	{
		if (nxt[i] != n)
			pre[nxt[i]] = i; 
	}
	build(1, 0, n - 1); 
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
			dfs(i); 
	}
	for (int i = 0; i < n; i++)
		ans[seq[i]] = i; 
	for (int i = 0; i < n; i++)
		printf("%d%c", ans[i] + 1, " \n"[i + 1 == n]);
	return 0; 
}