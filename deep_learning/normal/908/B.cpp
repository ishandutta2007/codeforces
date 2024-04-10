#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp make_pair
#define pb push_back
#define X first
#define Y second
using namespace std; 
typedef long long ll; 
char arr[55][55], str[105]; 
bool vis[5]; 
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("908B.in", "r", stdin); 
#endif
	int n, m, stx, sty; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i]); 
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'S')
			{
				stx = i; 
				sty = j; 
			}
		}
	}
	scanf("%s", str); 
	int ans = 0; 
	for (int i = 0; i < 1 << 8; i++)
	{
		memset(vis, false, sizeof(vis)); 
		bool f = true;
		for (int j = 0; j < 4 && f; j++)
		{
			if (vis[(i >> (j << 1)) & 3])
				f = false; 
			vis[(i >> (j << 1)) & 3] = true; 
		}
		int x = stx, y = sty; 
		for (int j = 0; str[j] && f; j++)
		{
			int newx = x + dx[(i >> (str[j] - '0' << 1)) & 3], newy = y + dy[(i >> (str[j] - '0' << 1)) & 3]; 
			if (newx < 0 || newx >= n || newy < 0 || newy >= m || arr[newx][newy] == '#')
			{
				f = false; 
				break; 
			}
			x = newx; 
			y = newy; 
			if (arr[x][y] == 'E')
				break;
		}
		ans += f && arr[x][y] == 'E'; 
	}
	printf("%d\n", ans);
	return 0; 
}