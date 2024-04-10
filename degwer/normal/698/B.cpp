#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int flag[200000];
int ans[200000];
int dat[200000];
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>vec;
	int root = -1;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		dat[i] = z;
		ans[i] = z;
		if (i == z)root = i;
	}
	fill(flag, flag + num, -1);
	int t = 0;
	for (int i = 0; i < num; i++)
	{
		if (flag[i] != -1)continue;
		int now = i;
		for (;;)
		{
			if (flag[now] != -1)
			{
				if (flag[now] == i)
				{
					if (root != -1)
					{
						if (root != now)
						{
							ans[now] = root;
							t++;
						}
					}
					else
					{
						ans[now] = now;
						root = now;
						t++;
					}
				}
				break;
			}
			flag[now] = i;
			now = dat[now];
		}
	}
	printf("%d\n", t);
	for (int i = 0; i < num; i++)printf("%d ", ans[i] + 1); printf("\n");
}