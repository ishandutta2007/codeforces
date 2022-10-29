#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll>v[66];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		int t = 0;
		for (int j = 0; j <= 60; j++)if (z&(1LL << j))t = j;
		v[t].push_back(z);
	}
	vector<ll>ans;
	for (int i = 60; i >= 0; i--)
	{
		vector<int>z;
		z.push_back(0);
		for (int j = 0; j < ans.size(); j++)if (ans[j] & (1LL << i))z.push_back(j + 1);
		if (z.size() < v[i].size())
		{
			printf("No\n");
			return 0;
		}
		z.resize(v[i].size());
		vector<ll>n;
		int pt = 0;
		for (int j = 0; j < ans.size(); j++)
		{
			if (pt != z.size() && z[pt] == j)n.push_back(v[i][pt]), pt++;
			n.push_back(ans[j]);
		}
		if (pt != z.size())n.push_back(v[i][pt]);
		ans = n;
	}
	printf("Yes\n");
	for (int i = 0; i < num; i++)printf("%I64d ", ans[i]);
	printf("\n");
}