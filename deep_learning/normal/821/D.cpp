#include <iostream>
#include <cstring>
#include <utility>
#include <cstdio>
#include <queue>
#define mp make_pair
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std; 
int x[10005], y[10005], dis[10005]; 
int main()
{
	// freopen("821D.in", "r", stdin); 
	int n, m, tot; 
	bool f = false; 
	scanf("%d%d%d", &n, &m, &tot); 
	for (int i = 0; i < tot; i++)
	{
		scanf("%d%d", x + i, y + i); 
		x[i]--; 
		y[i]--; 
		if (!x[i] && !y[i])
		{
			swap(x[i], x[0]); 
			swap(y[i], y[0]); 
		}
		if (x[i] == n - 1 && y[i] == m - 1)
			f = true; 
	}
	if (!f)
	{
		x[tot] = n; 
		y[tot++] = m; 
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que; 
	que.push(mp(0, 0)); 
	memset(dis, 0x3f, sizeof(dis)); 
	dis[0] = 0; 
	while (!que.empty())
	{
		int u = que.top().second; 
		que.pop(); 
		for (int i = 0; i < tot; i++)
		{
			int a = my_abs(x[u] - x[i]), b = my_abs(y[u] - y[i]); 
			if (a + b <= 1 && dis[i] > dis[u])
			{
				dis[i] = dis[u]; 
				que.push(mp(dis[i], i)); 
			}
			else if (a <= 2 || b <= 2)
			{
				if (dis[i] > dis[u] + 1)
				{
					dis[i] = dis[u] + 1; 
					que.push(mp(dis[i], i)); 
				}
			}
		}
	}
	printf("%d\n", dis[tot - 1] == 0x3f3f3f3f ? -1 : dis[tot - 1]);
	return 0; 
}