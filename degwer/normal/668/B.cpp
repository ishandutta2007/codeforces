#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int ans[1000000];
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	int now = 0;
	int st = 0;
	for (int i = 0; i < query; i++)
	{
		int za;
		scanf("%d", &za);
		if (za == 1)
		{
			int zb;
			scanf("%d", &zb);
			now = (now + num - zb) % num;
		}
		else
		{
			if ((st % 2 == 0) == (now % 2 == 0))st++;
			else st--;
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (i % 2 == 0)
		{
			ans[((i + st) % num + num) % num] = i;
		}
		else
		{
			ans[((i - st) % num + num) % num] = i;
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[(i + now) % num] + 1);
	}
	printf("\n");
}