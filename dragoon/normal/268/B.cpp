#include<stdio.h>

int main()
{
	int ans, n, i;

	scanf("%d", &n);
	ans = n;
	for(i = 1; i <= n; i++)
	{
		ans += (n-i)*i;
	}

	printf("%d\n", ans); 

	return 0;
}