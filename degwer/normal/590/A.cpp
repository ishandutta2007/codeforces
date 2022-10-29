#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int ans[500002];
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	int now = v[0];
	int c = 1;
	vector<int>rl;
	for (int i = 0; i < num; i++)
	{
		if (now != v[i])
		{
			now = v[i];
			rl.push_back(c);
			c = 1;
		}
		else c++;
	}
	rl.push_back(c + 1);
	int maxi = 0;
	c = 0;
	int pt = 0;
	int cur = v[0];
	for (int i = 0; i < rl.size(); i++)
	{
		if (rl[i] == 1)
		{
			c++;
		}
		else
		{
			if (c % 2 == 0)
			{
				for (int j = 0; j < c / 2; j++)
				{
					ans[pt - j - 1] = cur;
				}
				for (int j = c / 2; j < c; j++)
				{
					ans[pt - j - 1] = 1 - cur;
				}
			}
			else
			{
				for (int j = 0; j < c; j++)ans[pt - j - 1] = cur;
			}
			maxi = max(maxi, c);
			c = 0;
			for (int j = 0; j < rl[i]; j++)
			{
				ans[pt + j] = cur;
			}
		}
		pt += rl[i];
		cur = 1 - cur;
	}
	printf("%d\n", (maxi + 1) / 2);
	for (int i = 1; i <= num; i++)
	{
		if (i != 1)printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}