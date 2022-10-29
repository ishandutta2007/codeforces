#include<stdio.h>
int main()
{
	int num, d, h;
	scanf("%d%d%d", &num, &d, &h);
	if (h + h < d)
	{
		printf("-1\n");
		return 0;
	}
	if (d == 1)
	{
		if (num == 2)printf("1 2\n");
		else printf("-1\n");
		return 0;
	}
	for (int i = 2; i <= h + 1; i++)
	{
		printf("%d %d\n", i - 1, i);
	}
	if (d == h)
	{
		for (int i = h + 2; i <= num; i++)
		{
			printf("%d %d\n", 2, i);
		}
	}
	else
	{
		printf("%d %d\n", 1, h + 2);
		for (int i = h + 3; i <= d + 1; i++)
		{
			printf("%d %d\n", i - 1, i);
		}
		for (int i = d + 2; i <= num; i++)printf("%d %d\n", 1, i);
	}
}