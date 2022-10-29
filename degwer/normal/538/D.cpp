#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[50][50];
int ans[99][99];
int flag[50][50];
typedef pair<int, int>pii;
int main()
{
	int num;
	scanf("%d", &num);
	vector<pii>vec;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			char z;
			scanf(" %c", &z);
			if (z == 'o')
			{
				map[i][j] = 1;
				vec.push_back(make_pair(i, j));
			}
			if (z == 'x')
			{
				map[i][j] = -1;
			}
		}
	}
	for (int i = -num + 1; i <= num - 1; i++)
	{
		for (int j = -num + 1; j <= num - 1; j++)
		{
			bool f = true;
			for (int k = 0; k < vec.size(); k++)
			{
				int x = vec[k].first, y = vec[k].second;
				if (0 <= i + x&&i + x < num && 0 <= j + y&&j + y < num)
				{
					if (map[i + x][j + y] == 0)f = false;
				}
			}
			if (f)
			{
				for (int k = 0; k < vec.size(); k++)
				{
					int x = vec[k].first, y = vec[k].second;
					if (0 <= i + x&&i + x < num && 0 <= j + y&&j + y < num)
					{
						flag[i + x][j + y]++;
					}
				}
				ans[i + num - 1][j + num - 1] = 1;
			}
		}
	}
	bool f = true;
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)if (map[i][j] == -1 && flag[i][j] == 0)f = false;
	if (!f)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 0; i < num * 2 - 1; i++)
	{
		for (int j = 0; j < num * 2 - 1; j++)
		{
			if (i == num - 1 && j == num - 1)printf("o");
			else if (ans[i][j] == 0)printf(".");
			else printf("x");
		}
		printf("\n");
	}
}