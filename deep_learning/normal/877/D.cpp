#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
char str[1005][1005]; 
int que[2000005], dis[1005][1005], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}; 
int main()
{
	// freopen("877D.in", "r", stdin); 
	int n, m, k; 
	scanf("%d%d%d", &n, &m, &k); 
	for (int i = 0; i < n; i++)
		scanf("%s", str[i]); 
	int he = 0, ta = 0, stx, sty, enx, eny;
	scanf("%d%d%d%d", &stx, &sty, &enx, &eny); 
	que[ta++] = --stx; 
	que[ta++] = --sty; 
	enx--; 
	eny--; 
	memset(dis, 0x3f, sizeof(dis)); 
	dis[stx][sty] = 0; 
	while (he < ta)
	{
		int x = que[he++], y = que[he++]; 
		if (x == enx && y == eny)
		{
			printf("%d\n", dis[x][y]);
			return 0; 
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				int newx = x + dx[i] * j, newy = y + dy[i] * j; 
				if (newx < 0 || newx >= n || newy < 0 || newy >= m || str[newx][newy] == '#')
					break; 
				if (dis[newx][newy] > dis[x][y] + 1)
				{
					dis[newx][newy] = dis[x][y] + 1; 
					que[ta++] = newx; 
					que[ta++] = newy; 
				}
				else if (dis[newx][newy] <= dis[x][y])
					break; 
			}
		}
	}
	printf("-1\n");
	return 0; 
}