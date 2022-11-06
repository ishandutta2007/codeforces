#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std; 
int w[1024], v[1024], dp[1024][1024], fa[1024], idx[1024]; 
int getfa(int x)
{
	if (fa[x] == x)
		return x; 
	return fa[x] = getfa(fa[x]); 
}
bool comp(int a, int b)
{
	return getfa(a) < getfa(b); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("741B.in", "r", stdin); 
#endif
	int n, m, W; 
	scanf("%d%d%d", &n, &m, &W); 
	for (int i = 0; i < n; i++)
		scanf("%d", w + i); 
	for (int i = 0; i < n; i++)
		scanf("%d", v + i); 
	for (int i = 0; i < n; i++)
	{
		fa[i] = i; 
		idx[i] = i; 
	}
	for (int i = 0; i < m; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		u--; 
		v--; 
		if (getfa(u) != getfa(v))
			fa[getfa(u)] = getfa(v); 
	}
	sort(idx, idx + n, comp);
	for (int i = 0, pos; i < n; i = pos)
	{
		pos = i; 
		int totw = 0, totv = 0; 
		while (pos < n && getfa(idx[pos]) == getfa(idx[i]))
		{
			totw += w[idx[pos]]; 
			totv += v[idx[pos]];
			pos++; 
		}
		for (int j = 0; j <= W; j++)
		{
			dp[pos][j] = max(dp[pos][j], dp[i][j]); 
			if (j + totw <= W)
				dp[pos][j + totw] = max(dp[pos][j + totw], dp[i][j] + totv); 
			for (int k = i; k < pos; k++)
			{
				if (j + w[idx[k]] <= W)
					dp[pos][j + w[idx[k]]] = max(dp[pos][j + w[idx[k]]], dp[i][j] + v[idx[k]]); 
			}
		}
	}
	int ans = 0; 
	for (int i = 0; i <= W; i++)
	{
		// cout << dp[n][i] << endl; 
		ans = max(ans, dp[n][i]); 
	}
	printf("%d\n", ans);
	return 0; 
}