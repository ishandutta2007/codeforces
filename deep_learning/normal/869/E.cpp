#include <iostream>
#include <utility>
#include <cstdio>
#include <vector>
#include <map>
#define mp make_pair
#define pb push_back
using namespace std; 
struct data
{
	int u, d, idx; 
	data(int _u, int _d, int _idx)
	{
		u = _u; 
		d = _d; 
		idx = _idx; 
	}
}; 
vector<data> vec[20005]; 
map<pair<int, int>, int> num; 
int cur, idx; 
void add(int u, int l, int r, int x1, int y1, int x2, int y2)
{
	if (x1 <= l && r <= x2)
	{
		vec[u].pb(data(y1, y2, idx)); 
		return; 
	}
	int m = l + r >> 1; 
	if (x1 <= m)
		add(u << 1, l, m, x1, y1, x2, y2); 
	if (m < x2)
		add(u << 1 | 1, m + 1, r, x1, y1, x2, y2); 
}
void del(int u, int l, int r, int x1, int y1, int x2, int y2)
{
	if (x1 <= l && r <= x2)
	{
		for (vector<data>::iterator it = vec[u].begin(); it != vec[u].end(); it++)
		{
			if (it->idx == idx)
			{
				vec[u].erase(it);
				break; 
			}
		}
		return; 
	}
	int m = l + r >> 1; 
	if (x1 <= m)
		del(u << 1, l, m, x1, y1, x2, y2); 
	if (m < x2)
		del(u << 1 | 1, m + 1, r, x1, y1, x2, y2); 
}
inline int ask(vector<data> vec, int x)
{
	int mn = 1e9, ans = -1; 
	for (vector<data>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it->u <= x && x <= it->d && it->d - it->u < mn)
		{
			mn = it->d - it->u; 
			ans = it->idx; 
		}
	}
	return ans; 
}
int query(int u, int l, int r, int x, int y)
{
	if (l == r)
		return ask(vec[u], y); 
	int m = l + r >> 1, res = -1; 
	if (x <= m)
		res = query(u << 1, l, m, x, y); 
	else
		res = query(u << 1 | 1, m + 1, r, x, y); 
	return ~res ? res : ask(vec[u], y); 
}
int main()
{
	// freopen("869E.in", "r", stdin); 
	int n, m, q; 
	scanf("%d%d%d", &n, &m, &q); 
	while (q--)
	{
		int t, x1, y1, x2, y2; 
		scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2); 
		x1--; 
		y1--; 
		x2--; 
		y2--;
		if (t == 3)
			printf("%s\n", query(1, 0, n - 1, x1, y1) == query(1, 0, n - 1, x2, y2) ? "Yes" : "No");
		else if (t == 1)
		{
			num[mp(x1, y1)] = idx = cur++; 
			add(1, 0, n - 1, x1, y1, x2, y2); 
		}
		else
		{
			idx = num[mp(x1, y1)]; 
			num.erase(mp(x1, y1)); 
			del(1, 0, n - 1, x1, y1, x2, y2); 
		}
	}
	return 0; 
}