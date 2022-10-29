#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
double dp[2002][2002];
double kak[2002][2002];
int c1[2000], c2[2000];
int main()
{
	int num, kai;
	scanf("%d%d", &num, &kai);
	for (int i = 0; i < kai; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		c1[za]++, c2[zb]++;
	}
	int a1 = 0, a2 = 0;
	for (int i = 0; i < num; i++)
	{
		if (c1[i] != 0)a1++;
		if (c2[i] != 0)a2++;
	}
	kak[a1][a2] = 1.0;
	for (int i = a1; i <= num; i++)
	{
		for (int j = a2; j <= num; j++)
		{
			if (i == num&&j == num)
			{
				printf("%.15lf\n", dp[i][j]);
				return 0;
			}
			double ex = double(num*num) / double(num*num - i*j);
			kak[i + 1][j] += kak[i][j] * double((num - i)*j) / double(num*num - i*j);
			kak[i][j + 1] += kak[i][j] * double(i*(num - j)) / double(num*num - i*j);
			kak[i + 1][j + 1] += kak[i][j] * double((num - i)*(num - j)) / double(num*num - i*j);
			dp[i + 1][j] += (dp[i][j] + ex*kak[i][j]) * double((num - i)*j) / double(num*num - i*j);
			dp[i][j + 1] += (dp[i][j] + ex*kak[i][j]) * double(i*(num - j)) / double(num*num - i*j);
			dp[i + 1][j + 1] += (dp[i][j] + ex*kak[i][j]) * double((num - i)*(num - j)) / double(num*num - i*j);
		}
	}
}