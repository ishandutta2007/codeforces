#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std; 
typedef long long ll; 
int seg[10000005], lson[10000005], rson[10000005], tot; 
int rt[200005], n, q; 
void modify(int lst, int &u, int l, int r, int pos)
{
	u = ++tot; 
	if (l == r)
	{
		seg[u]++; 
		return; 
	}
	int m = l + r >> 1; 
	if (pos <= m)
	{
		rson[u] = rson[lst]; 
		modify(lson[lst], lson[u], l, m, pos); 
	}
	else
	{
		lson[u] = lson[lst]; 
		modify(rson[lst], rson[u], m + 1, r, pos); 
	}
	seg[u] = seg[lson[u]] + seg[rson[u]]; 
}
int query(int u, int l, int r, int L, int R)
{
	if (L > R)
		return 0; 
	if (L <= l && r <= R)
		return seg[u]; 
	int m = l + r >> 1, res = 0; 
	if (L <= m)
		res += query(lson[u], l, m, L, R); 
	if (m < R)
		res += query(rson[u], m + 1, r, L, R); 
	return res; 
}
inline ll query(int l, int r, int d, int u)
{
	if (l > r)
		return 0; 
	return query(rt[r], 1, n, d, u) - query(rt[l - 1], 1, n, d, u); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("853C.in", "r", stdin); 
#endif
	scanf("%d%d", &n, &q); 
	for (int i = 1; i <= n; i++)
	{
		int x; 
		scanf("%d", &x); 
		modify(rt[i - 1], rt[i], 1, n, x); 
	}
	while (q--)
	{
		int l, r, u, d; 
		scanf("%d%d%d%d", &l, &d, &r, &u); 
		ll a[] = {query(1, l - 1, 1, d - 1), query(l, r, 1, d - 1), query(r + 1, n, 1, d - 1)
			, query(1, l - 1, d, u), query(l, r, d, u), query(r + 1, n, d, u)
			, query(1, l - 1, u + 1, n), query(l, r, u + 1, n), query(r + 1, n, u + 1, n)}; 
		printf("%lld\n", a[0] * (a[4] + a[7] + a[8] + a[5]) + a[1] * (a[3] + a[4] + a[5] + a[6] + a[7] + a[8])
			+ a[2] * (a[3] + a[4] + a[6] + a[7]) + a[3] * (a[4] + a[5] + a[7] + a[8]) + a[4] * (a[5] + a[6] + a[7] + a[8])
			+ a[5] * (a[6] + a[7]) + a[4] * (a[4] - 1) / 2); 
	}
	return 0; 
}