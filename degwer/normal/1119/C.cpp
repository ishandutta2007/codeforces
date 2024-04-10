#include<stdio.h>
int d[2020];
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	for (int t = 0; t < 2; t++)
	{
		for (int i = 0; i < mx; i++)
		{
			for (int j = 0; j < my; j++)
			{
				int z;
				scanf("%d", &z);
				d[i] ^= z;
				d[j + mx] ^= z;
			}
		}
	}
	for (int i = 0; i < mx + my; i++)
	{
		if (d[i])
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}