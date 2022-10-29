#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int dat[202020];
int mini[202020], maxi[202020];
int ans[202020];
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	fill(mini, mini + query + 10, num);
	fill(maxi, maxi + query + 10, -1);
	int po = -1;
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &dat[i]);
		if (dat[i] != 0)mini[dat[i]] = min(mini[dat[i]], i), maxi[dat[i]] = max(maxi[dat[i]], i);
		else po = i;
	}
	if (mini[query] == num)
	{
		if (po == -1)
		{
			printf("NO\n");
			return 0;
		}
		mini[query] = maxi[query] = po;
	}
	fill(ans, ans + num, 1);
	set<int>se;
	for (int i = 0; i < num; i++)se.insert(i);
	for (int i = query; i >= 2; i--)
	{
		set<int>::iterator it = se.lower_bound(mini[i]);
		for (;;)
		{
			if (it == se.end() || (*it)>maxi[i])break;
			ans[(*it)] = i;
			se.erase(it++);
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (dat[i] != ans[i] && dat[i] != 0)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 0; i < num; i++)printf("%d ", ans[i]); printf("\n");
}