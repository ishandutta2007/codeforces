#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
struct query_tp
{
	int l, r, y, w; 
	query_tp()
	{
	}
	query_tp(int _l, int _r, int _y, int _w)
	{
		l = _l; 
		r = _r; 
		y = _y; 
		w = _w; 
	}
	inline bool operator <(const query_tp &a) const
	{
		return y < a.y; 
	}
} query[400005]; 
int arr[200005], pre[35][200005], suf[35][200005], seg[800005], lazy[800005]; 
inline void push_up(int u, int l, int r)
{
	if (lazy[u])
		seg[u] = r - l + 1; 
	else if (l == r)
		seg[u] = 0; 
	else
		seg[u] = seg[u << 1] + seg[u << 1 | 1]; 
}
void modify(int u, int l, int r, int L, int R, int x)
{
	if (L <= l && r <= R)
	{
		lazy[u] += x; 
		push_up(u, l, r); 
		return; 
	}
	int m = l + r >> 1; 
	if (L <= m)
		modify(u << 1, l, m, L, R, x); 
	if (m < R)
		modify(u << 1 | 1, m + 1, r, L, R, x); 
	push_up(u, l, r); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("875D.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	for (int i = 0; i < 30; i++)
	{
		int lst = -1; 
		for (int j = 0; j < n; j++)
		{
			if (arr[j] & (1 << i))
				lst = j; 
			pre[i][j] = lst; 
		}
		lst = n; 
		for (int j = n - 1; j >= 0; j--)
		{
			if (arr[j] & (1 << i))
				lst = j; 
			suf[i][j] = lst; 
		}
	}
	int tot = 0; 
	for (int i = 0; i < n; i++)
	{
		int l = -1, r = n; 
		for (int j = 0; j < 30; j++)
		{
			if (!(arr[i] & (1 << j)))
			{
				l = max(l, pre[j][i]); 
				r = min(r, suf[j][i]); 
			}
		}
		// cout << l + 1 << " " << i << " " << i << " " << r - 1 << endl; 
		query[tot++] = query_tp(l + 1, i, i, 1); 
		query[tot++] = query_tp(l + 1, i, r, -1); 
	}
	sort(query, query + tot); 
	ll ans = 0; 
	int idx = 0; 
	for (int i = 0; i < n; i++)
	{
		while (idx < tot && query[idx].y == i)
		{
			// cout << query[idx].l << " " << query[idx].r << " " << query[idx].w << endl; 
			modify(1, 0, n - 1, query[idx].l, query[idx].r, query[idx].w); 
			idx++; 
		}
		// cout << seg[1] << endl; 
		ans += n - i - seg[1]; 
	}
	printf("%lld\n", ans);
	return 0; 
}