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
struct data
{
	int num, pre, idx; 
	data(int _num = 0, int _pre = 0, int _idx = 0)
	{
		num = _num; 
		pre = _pre; 
		idx = _idx; 
	}
	inline bool operator <(const data &a) const
	{
		return num < a.num; 
	}
} dp[5000005]; 
int adj[25], ans[25]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("906C.in", "r", stdin); 
#endif
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < m; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		adj[--u] |= 1 << --v; 
		adj[v] |= 1 << u; 
	}
	int mask = 1; 
	for (int i = 1; i < n; i++)
	{
		bool f = true; 
		for (int j = 0; j < n && f; j++)
		{
			if (!(mask & (1 << j)))
				continue; 
			if (!(adj[j] & (1 << i)))
				f = false; 
		}
		if (f)
			mask |= 1 << i; 
	}
	memset(dp, 0x3f, sizeof(dp)); 
	dp[mask] = data(0, -1, -1); 
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!(i & (1 << j)))
				continue; 
			int x = i | adj[j]; 
			dp[x] = min(dp[x], data(dp[i].num + 1, j, i)); 
		}
	}
	int cur = (1 << n) - 1, cnt = 0; 
	while (~dp[cur].pre)
	{
		ans[cnt++] = dp[cur].pre; 
		cur = dp[cur].idx; 
	}
	printf("%d\n", cnt);
	for (int i = cnt - 1; i >= 0; i--)
		printf("%d%c", ans[i] + 1, " \n"[i == 0]);
	return 0; 
}