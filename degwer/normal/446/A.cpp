#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int r1[100010], r2[100010];
int d[100010];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &d[i]);
	r1[0] = 1;
	for (int i = 1; i < num; i++)
	{
		if (d[i - 1] < d[i])r1[i] = r1[i - 1] + 1;
		else r1[i] = 1;
	}
	r2[num - 1] = 1;
	for (int i = num - 2; i >= 0; i--)
	{
		if (d[i + 1] > d[i])r2[i] = r2[i + 1] + 1;
		else r2[i] = 1;
	}
	if (num <= 2)
	{
		printf("%d\n", num);
		return 0;
	}
	int maxi = 2;
	for (int i = 0; i < num; i++)
	{
		if (i == 0)maxi = max(maxi, r2[1] + 1);
		else if (i == num - 1)maxi = max(maxi, r1[num - 2] + 1);
		else
		{
			if (d[i - 1] + 1 < d[i + 1])maxi = max(maxi, r1[i - 1] + r2[i + 1] + 1);
			else maxi = max(maxi, max(r1[i - 1] + 1, r2[i + 1] + 1));
		}
	}
	printf("%d\n", maxi);
}