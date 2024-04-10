#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 131072
class BIT
{
public:
	int bit[SIZE + 1];
	void add(int a, int b)
	{
		a++;
		for (;;)
		{
			bit[a] += b;
			a += a&-a;
			if (a > SIZE)return;
		}
	}
	int get(int a)
	{
		a++;
		int ret = 0;
		for (;;)
		{
			ret += bit[a];
			a -= a&-a;
			if (a == 0)return ret;
		}
	}
};
BIT bi;
int now[100000];
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	for (int i = 0; i < num; i++)
	{
		now[i] = 1;
		bi.add(i, 1);
	}
	int beg = 0, end = num - 1;
	int dir = 0;
	for (int p = 0; p < query; p++)
	{
		int za;
		scanf("%d", &za);
		if (za == 1)
		{
			int zb;
			scanf("%d", &zb);
			if (zb + zb < (end - beg + 1))
			{
				if (dir == 0)
				{
					for (int i = 0; i < zb; i++)
					{
						bi.add(beg + i, -now[beg + i]);
						bi.add(beg + zb + zb - i - 1, now[beg + i]);
						now[beg + zb + zb - i - 1] += now[beg + i];
						now[beg + i] = 0;
					}
					beg = beg + zb;
				}
				else
				{
					for (int i = 0; i < zb; i++)
					{
						bi.add(end - i, -now[end - i]);
						bi.add(end - zb - zb + i + 1, now[end - i]);
						now[end - zb - zb + i + 1] += now[end - i];
						now[end - i] = 0;
					}
					end = end - zb;
				}
			}
			else
			{
				zb = (end - beg + 1) - zb;
				if (dir == 1)
				{
					for (int i = 0; i < zb; i++)
					{
						bi.add(beg + i, -now[beg + i]);
						bi.add(beg + zb + zb - i - 1, now[beg + i]);
						now[beg + zb + zb - i - 1] += now[beg + i];
						now[beg + i] = 0;
					}
					beg = beg + zb;
				}
				else
				{
					for (int i = 0; i < zb; i++)
					{
						bi.add(end - i, -now[end - i]);
						bi.add(end - zb - zb + i + 1, now[end - i]);
						now[end - zb - zb + i + 1] += now[end - i];
						now[end - i] = 0;
					}
					end = end - zb;
				}
				dir ^= 1;
			}
		}
		else
		{
			int zb, zc;
			scanf("%d%d", &zb, &zc);
			if (dir == 0)
			{
				printf("%d\n", bi.get(beg + zc - 1) - bi.get(beg + zb - 1));
			}
			else
			{
				printf("%d\n", bi.get(end - zb) - bi.get(end - zc));
			}
		}
	}
}