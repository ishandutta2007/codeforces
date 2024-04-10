#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	set<int>se;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		se.insert(z);
	}
	vector<int>ans;
	for (int i = 1;; i++)
	{
		if (se.find(i) == se.end())
		{
			if (gen < i)break;
			ans.push_back(i);
			gen -= i;
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}