#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[1000];
int main()
{
	int num;
	scanf("%d", &num);
	int c = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			int g;
			if (i != j)scanf("%d", &g);
			else scanf("%d", &d[i]), c ^= d[i];
		}
	}
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		int za;
		scanf("%d", &za);
		if (za == 3)printf("%d", c);
		else
		{
			int g;
			scanf("%d", &g);
			c ^= 1;
		}
	}
	printf("\n");
}