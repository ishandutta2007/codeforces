#include <algorithm>
#include <cstdio>
typedef long long ll; 
ll sum[400005]; 
int mx[400005]; 
inline void push_up(int u)
{
	mx[u] = std::max(mx[u << 1], mx[u << 1 | 1]); 
	sum[u] = sum[u << 1] + sum[u << 1 | 1]; 
}
void build(int u, int l, int r)
{
	if (l == r)
	{
		scanf("%lld", sum + u); 
		mx[u] = sum[u]; 
		return; 
	}
	int m = l + r >> 1; 
	build(u << 1, l, m); 
	build(u << 1 | 1, m + 1, r); 
	push_up(u); 
}
inline ll query(int u, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return sum[u]; 
	int m = l + r >> 1; 
	ll res = 0; 
	if (L <= m)
		res += query(u << 1, l, m, L, R); 
	if (m < R)
		res += query(u << 1 | 1, m + 1, r, L, R); 
	return res; 
}
void modify(int u, int l, int r, int L, int R, int x)
{
	if (mx[u] < x)
		return; 
	if (l == r)
	{
		mx[u] = sum[u] = sum[u] % x; 
		return; 
	}
	int m = l + r >> 1; 
	if (L <= m)
		modify(u << 1, l, m, L, R, x); 
	if (m < R)
		modify(u << 1 | 1, m + 1, r, L, R, x); 
	push_up(u); 
}
void modify(int u, int l, int r, int pos, int x)
{
	if (l == r)
	{
		mx[u] = sum[u] = x; 
		return; 
	}
	int m = l + r >> 1; 
	if (pos <= m)
		modify(u << 1, l, m, pos, x); 
	else
		modify(u << 1 | 1, m + 1, r, pos, x); 
	push_up(u); 
}
int main()
{
	int n, m; 
	scanf("%d%d", &n, &m); 
	build(1, 0, n - 1); 
	while (m--)
	{
		int tp; 
		scanf("%d", &tp);
		if (tp == 1)
		{
			int l, r; 
			scanf("%d%d", &l, &r); 
			printf("%lld\n", query(1, 0, n - 1, --l, --r)); 
		}
		else if (tp == 2)
		{
			int l, r, x; 
			scanf("%d%d%d", &l, &r, &x);
			modify(1, 0, n - 1, --l, --r, x); 
		}
		else
		{
			int k, x; 
			scanf("%d%d", &k, &x); 
			modify(1, 0, n - 1, --k, x); 
		}
	}
	return 0; 
}