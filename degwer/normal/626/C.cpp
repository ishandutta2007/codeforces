#include<stdio.h>
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ca = 0, cb = 0, cc = 0;
	for (int i = 1;; i++)
	{
		if (i % 2 == 0 && i % 3 != 0)ca++;
		if (i % 3 == 0 && i % 2 != 0)cb++;
		if (i % 6 == 0)cc++;
		if (ca + cb + cc >= a + b&&ca + cc >= a&&cb + cc >= b)
		{
			printf("%d\n", i);
			return 0;
		}
	}
}