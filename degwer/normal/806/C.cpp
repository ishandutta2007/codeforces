#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int dat[100];
int rem[100];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		int t = -1;
		for (int j = 0; j < 50; j++)if (z == (1LL << j))t = j;
		if (t != -1)dat[t]++;
		else
		{
			for (int j = 0; j < 50; j++)if ((1LL << j) <= z)t = j;
			rem[t]++;
		}
	}
	for (int i = 0; i < 50; i++)if (dat[i] < dat[i + 1])rem[i] += dat[i + 1] - dat[i], dat[i + 1] = dat[i];
	vector<int>ans;
	for (int i = 1; i <= num; i++)
	{
		if (dat[0] < i)continue;
		int c = 0;
		for (int j = 0; j < 50; j++)
		{
			c += rem[j] + max(0, dat[j] - i);
			c = max(0, c - (min(dat[j], i) - min(dat[j + 1], i)));
		}
		if (c == 0)ans.push_back(i);
	}
	if (ans.empty())printf("-1\n");
	else
	{
		for (int i = 0; i < ans.size(); i++)printf("%d ", ans[i]);
		printf("\n");
	}
}