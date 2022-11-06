#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
using namespace std; 
typedef long long ll; 
int mn[800005], mx[800005], arr[200005]; 
ll seg[800005], ans[200005], lazy[800005]; 
vector<int> app[200005], vec[200005]; 
inline void push_up(int u)
{
	seg[u] = seg[u << 1] + seg[u << 1 | 1]; 
	mn[u] = min(mn[u << 1], mn[u << 1 | 1]); 
	mx[u] = max(mx[u << 1], mx[u << 1 | 1]); 
}
inline void push_down(int u, int l, int r)
{
	if (!lazy[u])
		return; 
	int m = l + r >> 1; 
	lazy[u << 1] = mn[u << 1] = mx[u << 1] = lazy[u]; 
	lazy[u << 1 | 1] = mn[u << 1 | 1] = mx[u << 1 | 1] = lazy[u]; 
	seg[u << 1] = lazy[u] * (m - l + 1); 
	seg[u << 1 | 1] = lazy[u] * (r - m); 
	lazy[u] = 0; 
}
void build(int u, int l, int r)
{
	if (l >= r)
	{
		seg[u] = mn[u] = mx[u] = l; 
		return; 
	}
	int m = l + r >> 1; 
	build(u << 1, l, m); 
	build(u << 1 | 1, m + 1, r); 
	push_up(u); 
}
void modify(int u, int l, int r, int L, int R, int num)
{
	if (L > R || l > R || r < L)
		return; 
	if (mn[u] >= num)
		return; 
	if (L <= l && r <= R && mx[u] <= num)
	{
		lazy[u] = mn[u] = mx[u] = num; 
		seg[u] = (ll)(r - l + 1) * num; 
		return; 
	}
	push_down(u, l, r); 
	int m = l + r >> 1; 
	modify(u << 1, l, m, L, R, num); 
	modify(u << 1 | 1, m + 1, r, L, R, num); 
	push_up(u); 
}
int main()
{
	// freopen("C.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		app[arr[i]].pb(i); 
	}
	build(1, 0, n - 1); 
	for (int i = 1; i < 200005; i++)
	{
		for (int j = i; j < 200005; j += i)
		{
			for (int k = 0; k < app[j].size(); k++)
				vec[i].pb(app[j][k]);
		}
		sort(vec[i].begin(), vec[i].end()); 
	}
	for (int i = 200004; i >= 1; i--)
	{
		if (vec[i].size() > 1)
		{
			modify(1, 0, n - 1, vec[i][1] + 1, n - 1, n); 
			modify(1, 0, n - 1, vec[i][0] + 1, vec[i][1], vec[i][vec[i].size() - 1]); 
			modify(1, 0, n - 1, 0, vec[i][0], vec[i][vec[i].size() - 2]); 
		}
		ans[i] = (ll)n * n - seg[1]; 
	}
	ll res = 0; 
	for (int i = 1; i <= 200000; i++)
		res += (ans[i + 1] - ans[i]) * i; 
	printf("%lld\n", res);
	return 0; 
}