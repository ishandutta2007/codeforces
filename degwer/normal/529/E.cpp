#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	map<int, int>ma;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		for (int k = 0; k <= gen; k++)
		{
			if (ma.count(z*k) == 0)ma[z*k] = k;
			else ma[z*k] = min(ma[z*k], k);
		}
	}
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		int z;
		scanf("%d", &z);
		int mini = 100;
		map<int, int>::iterator it = ma.begin();
		for (;;)
		{
			if (it == ma.end())break;
			if (ma.count(z - (*it).first))
			{
				mini = min(mini, (*it).second + ma[z - (*it).first]);
			}
			it++;
		}
		if (mini > gen)printf("-1\n");
		else printf("%d\n", mini);
	}
}