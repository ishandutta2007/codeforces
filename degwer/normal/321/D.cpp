#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[34][34][2];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)scanf("%d", &dat[i][j][0]), dat[i][j][1] = -dat[i][j][0];
	num = (num + 1) / 2;
	int maxi = -1000000000;
	for (int p = 0; p < (1 << num); p++)
	{
		int d[17];
		for (int i = 0; i < num; i++)d[i] = (0 != (p&(1 << i)));
		int s = 0;
		for (int i = 0; i < num - 1; i++)
		{
			int s0 = dat[i][num - 1][0] + dat[i + num][num - 1][d[num - 1]], s1 = dat[i][num - 1][1] + dat[i + num][num - 1][1 ^ d[num - 1]];
			for (int j = 0; j < num - 1; j++)
			{
				s0 += max(dat[i][j][0] + dat[i][j + num][0] + dat[i + num][j][d[j]] + dat[i + num][j + num][d[j] ^ d[num - 1]], dat[i][j][1] + dat[i][j + num][1] + dat[i + num][j][1 ^d[j]] + dat[i + num][j + num][1 ^ d[j] ^ d[num - 1]]);
				s1 += max(dat[i][j][0] + dat[i][j + num][1] + dat[i + num][j][d[j]] + dat[i + num][j + num][1 ^ d[j] ^ d[num - 1]], dat[i][j][1] + dat[i][j + num][0] + dat[i + num][j][1 ^d[j]] + dat[i + num][j + num][d[j] ^ d[num - 1]]);
			}
			s += max(s0, s1);
		}
		for (int i = 0; i < num - 1; i++)s += dat[num - 1][i][d[i]] + dat[num - 1][i + num][d[i] ^ d[num - 1]];
		s += dat[num - 1][num - 1][d[num - 1]];
		//for (int i = 0; i < num; i++)printf("%d", d[i]); printf(" %d\n", s);
		maxi = max(maxi, s);
	}
	printf("%d\n", maxi);
}