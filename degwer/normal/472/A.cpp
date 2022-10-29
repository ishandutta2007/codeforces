#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 4;; i++)
	{
		if ((i % 2 == 0 || i % 3 == 0) && ((n - i) % 2 == 0 || (n - i) % 3 == 0))
		{
			printf("%d %d\n", i, n - i);
			return 0;
		}
	}
}