#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)swap(a, b);
	if (b > c)swap(b, c);
	if (a > b)swap(a, b);
	if (a > b || b > c)abort();
	if (a + b > c)
	{
		int na = 0, nb = 0, nc = 0, nab = 0, nac = 0, nbc = 0, nabc = 0;
		for (int i = 0; i < num; i++)
		{
			int z;
			scanf("%d", &z);
			if (z <= a)na++;
			else if (z <= b)nb++;
			else if (z <= c)nc++;
			else if (z <= a + b)nab++;
			else if (z <= a + c)nac++;
			else if (z <= b + c)nbc++;
			else if (z <= a + b + c)nabc++;
			else
			{
				printf("-1\n");
				return 0;
			}
		}
		int ans = 0;
		ans += nabc;
		ans += nbc + nac + nab;
		int mini = 1000000000;
		for (int i = 0; i <= nc; i++)
		{
			int t = max(max(0, nc - i - nab - i), max((nc - i + nb - nab - i - nac + 1) / 2, (nc - i + nb + na - nab - i - nac - nbc + 2) / 3));
			mini = min(mini, t + i);
		}
		printf("%d\n",ans + mini);
	}
	else
	{
		int na = 0, nb = 0, nc = 0, nab = 0, nac = 0, nbc = 0, nabc = 0;
		for (int i = 0; i < num; i++)
		{
			int z;
			scanf("%d", &z);
			if (z <= a)na++;
			else if (z <= b)nb++;
			else if (z <= a + b)nab++;
			else if (z <= c)nc++;
			else if (z <= a + c)nac++;
			else if (z <= b + c)nbc++;
			else if (z <= a + b + c)nabc++;
			else
			{
				printf("-1\n");
				return 0;
			}
		}
		int ans = 0;
		ans += nabc;
		ans += nbc + nac;
		int mini = 1000000000;
		for (int i = 0; i <= nab; i++)
		{
			int t;
			if (i <= nc)
			{
				t = max(max(nc - i, nab - i + nc - i), max((nb - nac + nab - i + nc - i + 1) / 2, (na + nb - nbc - nac + nab - i + nc - i + 2) / 3));
			}
			else
			{
				t = max(max(0, nab - i + nc - i), max((nb - nac + nab - i + nc - i + 1) / 2, (na + nb - nbc - nac + nab - i + nc - i + 2) / 3));
			}
			mini = min(mini, t + i);
		}
		printf("%d\n", ans + mini);
	}
}