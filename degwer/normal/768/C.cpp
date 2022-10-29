#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[2][2000];
int main()
{
	int num, kai, x;
	scanf("%d%d%d", &num, &kai, &x);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		d[0][z]++;
	}
	int cur = 0;
	for (int q = 0; q < kai; q++)
	{
		int now = 0;
		for (int i = 0; i < 1024; i++)
		{
			d[1 - cur][i^x] += ((now + d[cur][i] + 1) >> 1) - ((now + 1) >> 1);
			d[1 - cur][i] += ((now + d[cur][i]) >> 1) - ((now) >> 1);
			now += d[cur][i];
		}
		for (int i = 0; i < 1024; i++)d[cur][i] = 0;
		cur = 1 - cur;
	}
	int mini = 1000000000, maxi = -1;
	for (int i = 0; i < 1024; i++)if (d[cur][i]>0)mini = min(mini, i), maxi = max(maxi, i);
	printf("%d %d\n", maxi, mini);
}