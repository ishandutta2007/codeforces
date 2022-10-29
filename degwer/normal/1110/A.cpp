#include<stdio.h>
int main()
{
	int b, n;
	scanf("%d%d", &b, &n);
	int r = 0;
	for (int i = 0; i < n; i++)
	{
		int z;
		scanf("%d", &z);
		if (b % 2 == 1)r ^= z % 2;
		else if (i == n - 1)r ^= z % 2;
	}
	printf(r ? "odd\n" : "even\n");
}