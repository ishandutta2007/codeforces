#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[11000000][3];
int n[3], t[3];
int main()
{
	int num;
	scanf("%d", &num);
	scanf("%d%d%d%d%d%d", &n[0], &n[1], &n[2], &t[0], &t[1], &t[2]);
	int pt = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < t[j]; k++)dat[pt + k][j]++;
		}
		for (;;)
		{
			bool f = false;
			for (int k = 0; k < 3; k++)
			{
				if (dat[pt][k] == n[k])
				{
					pt++;
					f = true;
					break;
				}
			}
			if (!f)break;
		}
	}
	int maxi = 0;
	for (int i = 0; i < 11000000; i++)
	{
		if (dat[i][0])maxi = max(maxi, i + 1);
		if (dat[i][1])maxi = max(maxi, i + 1 + t[0]);
		if (dat[i][2])maxi = max(maxi, i + 1 + t[0] + t[1]);
	}
	printf("%d\n", maxi);
}