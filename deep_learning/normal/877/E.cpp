#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int lst[200005], to[200005], pre[200005], tot; 
int st[200005], en[200005], seq[200005], t;
int lazy[800005], seg[800005], arr[200005]; 
char str[15];
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
void dfs(int u, int fa = -1)
{
	seq[t] = arr[u]; 
	st[u] = t++; 
	for (int i = lst[u]; ~i; i = pre[i])
		dfs(to[i], u); 
	en[u] = t; 
}
inline void push_down(int u, int l, int r)
{
	if (!lazy[u])
		return; 
	int m = l + r >> 1; 
	lazy[u << 1] ^= 1; 
	lazy[u << 1 | 1] ^= 1; 
	seg[u << 1] = m - l + 1 - seg[u << 1]; 
	seg[u << 1 | 1] = r - m - seg[u << 1 | 1]; 
	lazy[u] = 0; 
}
void build(int u, int l, int r)
{
	if (l == r)
	{
		seg[u] = seq[l];
		return; 
	}
	int m = l + r >> 1; 
	build(u << 1, l, m); 
	build(u << 1 | 1, m + 1, r); 
	seg[u] = seg[u << 1] + seg[u << 1 | 1]; 
}
void modify(int u, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
	{
		lazy[u] ^= 1; 
		seg[u] = r - l + 1 - seg[u]; 
		return; 
	}
	push_down(u, l, r); 
	int m = l + r >> 1; 
	if (L <= m)
		modify(u << 1, l, m, L, R); 
	if (m < R)
		modify(u << 1 | 1, m + 1, r, L, R); 
	seg[u] = seg[u << 1] + seg[u << 1 | 1]; 
}
int query(int u, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return seg[u]; 
	push_down(u, l, r); 
	int m = l + r >> 1, res = 0; 
	if (L <= m)
		res += query(u << 1, l, m, L, R); 
	if (m < R)
		res += query(u << 1 | 1, m + 1, r, L, R); 
	return res; 
}
int main()
{
	// freopen("877E.in", "r", stdin); 
	memset(lst, -1, sizeof(lst)); 
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i < n; i++)
	{
		int x; 
		scanf("%d", &x); 
		add_edge(--x, i); 
	}
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	dfs(0); 
	build(1, 0, n - 1); 
	int q; 
	scanf("%d", &q); 
	while (q--)
	{
		int u; 
		scanf("%s%d", str, &u); 
		u--; 
		if (str[0] == 'g')
			printf("%d\n", query(1, 0, n - 1, st[u], en[u] - 1));
		else
			modify(1, 0, n - 1, st[u], en[u] - 1); 
	}
	return 0; 
}