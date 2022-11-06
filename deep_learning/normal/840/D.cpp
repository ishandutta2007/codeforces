#include <iostream>
#include <cstdio>
using namespace std; 
int rt[300005], seg[6000005], lson[6000005], rson[6000005], tot, n, q; 
void modify(int lst, int &u, int l, int r, int pos, int x)
{
	u = ++tot; 
	seg[u] = seg[lst] + x; 
	if (l == r)
		return; 
	int m = l + r >> 1; 
	if (pos <= m)
	{
		rson[u] = rson[lst]; 
		modify(lson[lst], lson[u], l, m, pos, x); 
	}
	else
	{
		lson[u] = lson[lst]; 
		modify(rson[lst], rson[u], m + 1, r, pos, x); 
	}
}
int main()
{
	// freopen("840D.in", "r", stdin); 
	scanf("%d%d", &n, &q); 
	for (int i = 1; i <= n; i++)
	{
		int x; 
		scanf("%d", &x); 
		modify(rt[i - 1], rt[i], 1, n, x, 1); 
	}
	while (q--)
	{
		int l, r, k, ans = 1e9; 
		scanf("%d%d%d", &l, &r, &k); 
		int delta = (r - l + 1) / k; 
		if (!delta)
		{
			int x = rt[l - 1], y = rt[r], lp = 1, rp = n; 
			while (lp < rp)
			{
				int m = lp + rp >> 1;
				if (seg[lson[y]] - seg[lson[x]] > 0)
				{
					x = lson[x]; 
					y = lson[y]; 
					rp = m; 
				}
				else
				{
					x = rson[x]; 
					y = rson[y]; 
					lp = m + 1; 
				}
			}
			printf("%d\n", lp);
			continue; 
		}
		for (int i = delta; i <= r - l + 1; i += delta)
		{
			int x = rt[l - 1], y = rt[r], lp = 1, rp = n, h = i; 
			while (lp < rp)
			{
				int m = lp + rp >> 1;
				if (seg[lson[y]] - seg[lson[x]] >= h)
				{
					x = lson[x]; 
					y = lson[y]; 
					rp = m; 
				}
				else
				{
					h -= seg[lson[y]] - seg[lson[x]]; 
					x = rson[x]; 
					y = rson[y]; 
					lp = m + 1; 
				}
			}
			// cout << i << " " << lp << " " << seg[y] << " " << seg[x] << endl; 
			if ((seg[y] - seg[x]) * k > r - l + 1)
				ans = min(ans, lp); 
		}
		printf("%d\n", ans == 1e9 ? -1 : ans);
	}
	return 0; 
}