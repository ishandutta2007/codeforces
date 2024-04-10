#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <random>
#include <time.h>

using namespace std;

#define SIZE 1000228
int l[2][SIZE];
int n, q;
int beg[2];
int ch[2];

int main()
{
	scanf("%d%d", &n, &q);
	beg[0] = 0;
	beg[1] = 0;
	ch[0] = 0;
	ch[1] = 1;
	//Print();
	int type, d = 0;
	int d1 = 0;
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d", &d);
			if (d > 0)
			{
				if (d % 2 == 0)
				{
					int x = d / 2;
					beg[0] = (beg[0] - x + n / 2) % (n / 2);
					beg[1] = (beg[1] - x + n / 2) % (n / 2);
				}
				else
				{
					int x = d / 2;
					beg[0] = (beg[0] - x + n / 2) % (n / 2);
					beg[1] = (beg[1] - x - 1 + n / 2) % (n / 2);
					swap(beg[0], beg[1]);
					swap(ch[0], ch[1]);
				}
			}
			else
			{
				d *= -1;
				if (d % 2 == 0)
				{
					int x = d / 2;
					beg[0] = (beg[0] + x) % (n / 2);
					beg[1] = (beg[1] + x) % (n / 2);
				}
				else
				{
					int x = d / 2;
					beg[0] = (beg[0] + x + 1) % (n / 2);
					beg[1] = (beg[1] + x) % (n / 2);
					swap(beg[0], beg[1]);
					swap(ch[0], ch[1]);
				}
			}
		}
		else
		{
			swap(beg[0], beg[1]);
			swap(ch[0], ch[1]);
		}
	}
	for (int i = 0; i < n / 2; i++)
	{
		l[0][i] = ((beg[0] + i) * 2 + ch[0]) % n + 1;
		l[1][i] = ((beg[1] + i) * 2 + ch[1]) % n + 1;
	}
	for (int i = 0; i < n / 2; i++)
		printf("%d %d ", l[0][i], l[1][i]);
	return 0;
}