#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x7f7f7f;
char a[505][505];
vector <int> num[505];
int s[505][505], dis[505][505], n, m, kk;
long long f[505][505]; 
int main()
{
//	memset(dis, 1, sizeof(dis));
	scanf("%d%d%d", &n, &m, &kk);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= kk; j++)
			f[i][j] = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '1') num[i].push_back(j);
		}
		int len = num[i].size();
		for (int j = 0; j < len; j++) s[i][j] = num[i][j] - num[i][0] + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		int len = num[i].size();
//		dis[i][0] = 1;
		for (int y = 0; y < len; y++) dis[i][len - y - 1] = s[i][y];
		for (int x = 1; x < len; x++)
			for (int y = x; y < len; y++)
			{
				int k = len - (y - x + 1);
				dis[i][k] = min(dis[i][k], s[i][y] - s[i][x] + 1)/*, printf("%d %d %d\n", i, k, dis[i][k]) */;
			}
/*		for (int k = 0; k <len; k++) printf("dis[%d][%d] = %d\n", i, k, dis[i][k]);*/
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= kk; j++)
		{
			int len = num[i].size();
			for (int k = 0; k <= min(j, len); k++)
				f[i][j] = min(f[i][j], f[i - 1][j - k] + dis[i][k]);
//			printf("f[%d][%d]=%d\n", i, j, f[i][j]);
		}
	cout << f[n][kk] << endl;
	return 0;
}