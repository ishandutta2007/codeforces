#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>dat[200000];
#define B 320
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		dat[za].push_back(zb);
	}
	for (int i = 0; i <= 100000; i++)sort(dat[i].begin(), dat[i].end());
	int ans = 0;
	for (int i = 0; i <= 100000; i++)
	{
		if (dat[i].size() < B)
		{
			for (int j = 0; j < dat[i].size(); j++)
			{
				for (int k = j + 1; k < dat[i].size(); k++)
				{
					int a = dat[i][j], b = dat[i][k];
					if (i - (b - a) >= 0)
					{
						int x = i - (b - a);
						int l1 = lower_bound(dat[x].begin(), dat[x].end(), a) - dat[x].begin();
						int l2 = lower_bound(dat[x].begin(), dat[x].end(), b) - dat[x].begin();
						if (l1 < dat[x].size() && l2 < dat[x].size())if (dat[x][l1] == a&&dat[x][l2] == b)ans++;
					}
				}
			}
		}
		else
		{
			for (int x = 0; x < i; x++)
			{
				for (int j = 0; j < dat[x].size(); j++)
				{
					int y = dat[x][j];
					int d = i - x;
					int l2 = lower_bound(dat[x].begin(), dat[x].end(), y + d) -dat[x].begin();
					int l3 = lower_bound(dat[i].begin(), dat[i].end(), y) - dat[i].begin();
					int l4 = lower_bound(dat[i].begin(), dat[i].end(), y + d) - dat[i].begin();
					if (l2 < dat[x].size() && l3 < dat[i].size() && l4 < dat[i].size())if (dat[x][l2] == y + d&&dat[i][l3] == y&&dat[i][l4] == y + d)ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
}