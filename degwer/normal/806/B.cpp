#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[5];
int p1[5], p2[5];
typedef pair<int, int>pii;
int sc[4001][4001];
vector<pii>ans[5];
int getsc(int tim, int sc)
{
	if (tim == -1)return 0;
	return (sc + 1) * 2 * (250 - tim);
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int z;
			scanf("%d", &z);
			if (z >= 0)dat[j]++;
			if (i == 0)p1[j] = z;
			if (i == 1)p2[j] = z;
		}
	}
	for (int i = 2; i <= 4000; i++)
	{
		for (int j = 0; j <= 4000; j++)
		{
			if ((j << 5) <= i)sc[i][j] = 5;
			else if ((j << 4) <= i)sc[i][j] = 4;
			else if ((j << 3) <= i)sc[i][j] = 3;
			else if ((j << 2) <= i)sc[i][j] = 2;
			else if ((j << 1) <= i)sc[i][j] = 1;
			else sc[i][j] = 0;
		}
	}
	for (int i = 0; i <= 3850; i++)
	{
		bool x[5][6];
		for (int j = 0; j < 5; j++)for (int k = 0; k < 6; k++)x[j][k] = false;
		for (int j = 0; j < 5; j++)
		{
			if (p1[j] >= 0)for (int k = dat[j]; k <= i + dat[j]; k++)x[j][sc[num + i][k]] = true;
			else x[j][sc[num + i][dat[j]]] = true;
		}
		for (int a = 0; a < 6; a++)
		{
			for (int b = 0; b < 6; b++)
			{
				for (int c = 0; c < 6; c++)
				{
					for (int d = 0; d < 6; d++)
					{
						for (int e = 0; e < 6; e++)
						{
							if (x[0][a] && x[1][b] && x[2][c] && x[3][d] && x[4][e])
							{
								int xx = getsc(p1[0], a) + getsc(p1[1], b) + getsc(p1[2], c) + getsc(p1[3], d) + getsc(p1[4], e);
								int yy = getsc(p2[0], a) + getsc(p2[1], b) + getsc(p2[2], c) + getsc(p2[3], d) + getsc(p2[4], e);
								if (xx > yy)
								{
									//printf("%d %d %d %d %d  %d %d\n", a, b, c, d, e, xx, yy);
									printf("%d\n", i);
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	printf("-1\n");
}