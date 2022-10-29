#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
typedef bitset<1024>bi;
int d[1024][1024];
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	for (int i = 0; i < mx; i++)for (int j = 0; j < my; j++)scanf("%d", &d[i][j]);
	int maxi = 0;
	for (int i = 0; i < mx; i++)
	{
		for (int j = i + 1; j < mx; j++)
		{
			int m1 = 0, m2 = 0;
			for (int k = 0; k < my; k++)
			{
				int x = min(d[i][k], d[j][k]);
				if (x > m2)
				{
					if (x > m1)m2 = m1, m1 = x;
					else m2 = x;
				}
			}
			maxi = max(maxi, m2);
		}
	}
	printf("%d\n", maxi);
}