#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>dat[11];
int pr[10] = { 2,3,5,7,11,13,17,19,23,29 };
void dfs(int now, int pt)
{
	dat[pt].push_back(now);
	if (pt == 10)return;
	for (;;)
	{
		if (now > 50000000)return;
		dfs(now, pt + 1);
		now *= pr[pt];
	}
}
int main()
{
	dfs(1, 0);
	for (int i = 0; i <= 10; i++)sort(dat[i].begin(), dat[i].end());
	int n;
	scanf("%d", &n);
	//for (n = 10; n <= 5000; n++) 
	//{
		//bool fff = false;
		for (int i = 0; i <= 10; i++)
		{
			if (n > dat[i].size())continue;
			if (2 * n*n < dat[i][n - 1])continue;
			vector<int>v;
			int t[11];
			fill(t, t + 11, n / 2);
			for (int j = 0; j < dat[i].size(); j++)
			{
				if (dat[i][j]>2 * n*n)break;
				bool bb = true;
				for (int k = 0; k < i; k++)
				{
					if (t[k] == 0 && dat[i][j] % pr[k] != 0)bb = false;
				}
				if (bb)
				{
					for (int k = 0; k < i; k++)
					{
						if (dat[i][j] % pr[k] != 0)t[k]--;
					}
					v.push_back(dat[i][j]);
				}
			}
			if (v.size() < n)continue;
		//	fff = true;
			//printf("%d %d\n", n, pr[i - 1]);
			for (int i = 0; i < n; i++)printf("%d ", v[i]); printf("\n");
			break;
		}
		//if (!fff)abort();
	//}
	//printf("uiukhjnk\n");
}