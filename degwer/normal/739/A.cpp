#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	int mini = 1000000000;
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		mini = min(mini, zb - za + 1);
	}
	printf("%d\n", mini);
	for (int i = 0; i < num; i++)printf("%d ", i%mini); printf("\n");
}