#include <algorithm>
#include <cstring>
#include <cstdio>
#define upd(x, y)	\
do					\
{					\
	if ((x) > ans)	\
	{				\
		ans = x; 	\
		cnt = 0; 	\
	}				\
	if ((x) == ans)	\
		cnt += y; 	\
} while (false)
int dis[100005][15], cost[15][15], que[100005], app[15][305], mask[100005]; 
char str[100005]; 
bool vis[15]; 
int main()
{
	// freopen("718E.in", "r", stdin); 
	int n; 
	scanf("%d%s", &n, str); 
	memset(dis, 0x3f, sizeof(dis)); 
	for (int c = 0; c < 8; c++)
	{
		memset(vis, false, sizeof(vis)); 
		int he = 0, ta = 0; 
		for (int i = 0; i < n; i++)
		{
			if (str[i] == c + 'a')
			{
				dis[i][c] = 0; 
				que[ta++] = i; 
			}
		}
		while (he < ta)
		{
			int u = que[he++], v = u - 1;
			if (!vis[str[u] - 'a'])
			{
				vis[str[u] - 'a'] = true; 
				for (int i = 0; i < n; i++)
				{
					if (str[i] == str[u] && dis[i][c] > dis[u][c] + 1)
					{
						dis[i][c] = dis[u][c] + 1; 
						que[ta++] = i; 
					}
				}
			}
			if (v >= 0 && dis[v][c] > dis[u][c] + 1)
			{
				dis[v][c] = dis[u][c] + 1; 
				que[ta++] = v; 
			}
			v = u + 1;
			if (v < n && dis[v][c] > dis[u][c] + 1)
			{
				dis[v][c] = dis[u][c] + 1; 
				que[ta++] = v; 
			}
		}
	}
	memset(cost, 0x3f, sizeof(cost)); 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 8; j++)
			cost[str[i] - 'a'][j] = std::min(cost[str[i] - 'a'][j], dis[i][j]); 
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 8; j++)
			mask[i] |= (dis[i][j] > cost[str[i] - 'a'][j]) << j; 
	}
	int ans = 0; 
	long long cnt = 0; 
	for (int i = 0; i < n; i++)
	{
		for (int j = std::max(0, i - 15); j < i; j++)
		{
			int res = i - j; 
			for (int k = 0; k < 8; k++)
				res = std::min(res, dis[i][k] + dis[j][k] + 1); 
			upd(res, 1); 
		}
		if (i >= 16)
			app[str[i - 16] - 'a'][mask[i - 16]]++; 
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 1 << 8; k++)
			{
				if (!app[j][k])
					continue; 
				int res = 1e9; 
				for (int x = 0; x < 8; x++)
					res = std::min(res, dis[i][x] + cost[x][j] + 1 + ((k >> x) & 1)); 
				if (res != 1e9)
					upd(res, app[j][k]); 
			}
		}
	}
	printf("%d %lld\n", ans, cnt);
	return 0; 
}