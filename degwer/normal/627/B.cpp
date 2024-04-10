#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 262144
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
BIT bi1, bi2;
int dat[300000];
int main()
{
	int num, gen, xb, xa, query;
	scanf("%d%d%d%d%d", &num, &gen, &xa, &xb, &query);
	for (int i = 0; i < query; i++)
	{
		int za;
		scanf("%d", &za);
		if (za == 1)
		{
			int zb, zc;
			scanf("%d%d", &zb, &zc);
			if (dat[zb] < xb)
			{
				bi1.add(zb, min(xb - dat[zb], zc));
				bi2.add(zb, min(xa - dat[zb], zc));
			}
			else if (dat[zb] < xa)
			{
				bi2.add(zb, min(xa - dat[zb], zc));
			}
			dat[zb] += zc;
		}
		else
		{
			int zb;
			scanf("%d", &zb);
			printf("%d\n", bi1.get(zb - 1) + bi2.get(SIZE - 1) - bi2.get(zb + gen - 1));
		}
	}
}