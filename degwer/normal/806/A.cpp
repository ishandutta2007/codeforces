#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int data;
	scanf("%d", &data);
	for (int i = 0; i < data; i++)
	{
		ll x, y, p, q;
		scanf("%I64d%I64d%I64d%I64d", &x, &y, &p, &q);
		if (p == 0)
		{
			if (x == 0)printf("0\n");
			else printf("-1\n");
		}
		else if (p == q)
		{
			if (x == y)printf("0\n");
			else printf("-1\n");
		}
		else
		{
			ll beg = 0, end = 2000000000;
			for (;;)
			{
				if (beg == end)break;
				ll med = (beg + end) / 2;
				ll s = med*p, t = med*q;
				ll z = s - x, w = t - y;
				if (z < 0 || w<0 || z>w)beg = med + 1;
				else end = med;
			}
			printf("%I64d\n", beg*q - y);
		}
	}
}