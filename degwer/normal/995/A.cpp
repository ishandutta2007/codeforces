#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
typedef pair<int, pii>pi3;
int dat[4][55];
pii getnext(int x, int y, int num)
{
	if (x == 1)
	{
		if (y == num - 1)return make_pair(2, num - 1);
		else return make_pair(1, y + 1);
	}
	else
	{
		if (y == 0)return make_pair(1, 0);
		else return make_pair(2, y - 1);
	}
}
int main()
{
	int my, ko;
	scanf("%d%d", &my, &ko);
	for (int i = 0; i < 4; i++)for (int j = 0; j < my; j++)scanf("%d", &dat[i][j]);
	vector<pi3>ans;
	for (;;)
	{
		/*for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < my; j++)
			{
				printf("%d ", dat[i][j]);
			}
			printf("\n");
		}
		printf("----\n");*/
		if (ko == 0)break;
		for (int i = 0; i < my; i++)
		{
			if (dat[0][i] == dat[1][i] && dat[0][i] != 0)
			{
				ans.push_back(make_pair(dat[0][i], make_pair(1, i + 1))), dat[0][i] = dat[1][i] = 0, ko--;
				goto l01;
			}
		}
		for (int i = 0; i < my; i++)
		{
			if (dat[3][i] == dat[2][i] && dat[3][i] != 0)
			{
				ans.push_back(make_pair(dat[3][i], make_pair(4, i + 1))), dat[3][i] = dat[2][i] = 0, ko--;
				goto l01;
			}
		}
		for (int i = 1; i <= 2; i++)
		{
			for (int j = 0; j < my; j++)
			{
				pii z = getnext(i, j, my);
				if (dat[i][j] != 0 && dat[z.first][z.second] == 0)
				{
					ans.push_back(make_pair(dat[i][j], make_pair(z.first + 1, z.second + 1))), dat[z.first][z.second] = dat[i][j], dat[i][j] = 0;
					goto l01;
				}
			}
		}
		printf("-1\n");
		return 0;
		l01:;
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
}