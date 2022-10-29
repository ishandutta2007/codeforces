#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>dat[3][3];
int p[200000], a[200000], b[200000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &p[i]);
	for (int i = 0; i < num; i++)scanf("%d", &a[i]);
	for (int i = 0; i < num; i++)scanf("%d", &b[i]);
	for (int i = 0; i < num; i++)dat[a[i] - 1][b[i] - 1].push_back(p[i]);
	for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)sort(dat[i][j].begin(), dat[i][j].end()), reverse(dat[i][j].begin(), dat[i][j].end());
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		int z;
		scanf("%d",&z);
		z--;
		int mini = 1050000000, rx = -1, ry = -1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (z == i || z == j)
				{
					if (!dat[i][j].empty())
					{
						if (mini > dat[i][j][dat[i][j].size() - 1])
						{
							mini = dat[i][j][dat[i][j].size() - 1];
							rx = i, ry = j;
						}
					}
				}
			}
		}
		if (rx == -1)printf("-1 ");
		else
		{
			printf("%d ", mini);
			dat[rx][ry].pop_back();
		}
	}
	printf("\n");
}