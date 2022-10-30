#include<stdio.h>
int main()
{
	int a, b, c, n;
	scanf("%d%d%d%d", &a, &b, &c, &n);
	int r = 0;
	for (int i = 0; i < n; i++)
	{
		int z;
		scanf("%d", &z);
		if (b < z&&z < c)r++;
	}
	printf("%d\n", r);
}