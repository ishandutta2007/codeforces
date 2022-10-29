#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int ans[1000];
int main()
{
	int num;
	scanf("%d", &num);
	fill(ans, ans + num, 2000000000);
	for (int i = 0; i < 10; i++)
	{
		vector<int>v1, v2;
		for (int j = 0; j < num; j++)
		{
			if (j&(1 << i))v1.push_back(j);
			else v2.push_back(j);
		}
		if (!v1.empty())
		{
			printf("%d\n", v1.size()); fflush(stdout);
			for (int j = 0; j < v1.size(); j++)printf("%d ", v1[j] + 1); printf("\n"); fflush(stdout);
			for (int j = 0; j < num; j++)
			{
				int z;
				scanf("%d", &z);
				if (!(j&(1 << i)))ans[j] = min(ans[j], z);
			}
		}
		if (!v2.empty())
		{
			printf("%d\n", v2.size()); fflush(stdout);
			for (int j = 0; j < v2.size(); j++)printf("%d ", v2[j] + 1); printf("\n"); fflush(stdout);
			for (int j = 0; j < num; j++)
			{
				int z;
				scanf("%d", &z);
				if ((j&(1 << i)))ans[j] = min(ans[j], z);
			}
		}
	}
	printf("-1\n"); fflush(stdout);
	for (int j = 0; j < num; j++)printf("%d ", ans[j]); printf("\n"); fflush(stdout);
}