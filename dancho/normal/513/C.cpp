#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double p[8][10020];

int main()
{
	int n;
	int l[8], r[8];
	scanf("%d", &n);
	double ex = 0;
	double all = 1.0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &l[i], &r[i]);
		all *= (r[i] - l[i] + 1);
	}
	
	for (int i = 1; i <= 10000; ++i)
	{
		double cr = 0;
		for (int j = 0; j < n; ++j)  // eq
		{
			if (r[j] < i || l[j] > i)
				continue;
			for (int k = 0; k < n; ++k)
			{
				if (k == j)
					continue;
				// k is bigger
				double t = 1.0;
				if (k < j)
				{
					if (r[k] < i)
						continue;
					t *= (r[k] - max(i, l[k]) + 1);
				}
				else
				{
					if (r[k] <= i)
						continue;
					t *= (r[k] - max(i + 1, l[k]) + 1);
				}
				for (int s = 0; s < n; ++s)
				{
					if (s == j || s == k)
						continue;
					if (s < j)
					{
						if (l[s] >= i)
						{
							t = 0;
							break;
						}
						t *= (min(r[s], i - 1) - l[s] + 1);
					}
					else
					{
						if (l[s] > i)
						{
							t = 0;
							break;
						}
						t *= (min(r[s], i) - l[s] + 1);
					}
				}
				if (t != 0)
				{
					//~ printf("O %d %d %d : %lf\n", i, j, k, t);
				}
				cr += t;
			}
		}
		//~ if (cr != 0)
			//~ printf("CNT %d %lf :: %lf\n", i, cr, all);
		ex += cr / all * i;
	}
	
	printf("%.15lf\n", ex);
	return 0;
}