#include<stdio.h>

int main()
{
	int n, i, k;

	scanf("%d%d", &n, &k);

	if(k==1)
	{
		if(n==1)
		{
			printf("a\n");
			return 0;
		}
		else
		{
			printf("-1\n");
			return 0;
		}
	}

	if(k > n)
	{
		printf("-1\n");
		return 0;
	}

	if(k == 2)
	{
		for(i = 0; i < n; i++)
		{
			if(i%2) printf("b");
			else printf("a");
		}

		printf("\n");
		return 0;
	}

	for(i = 0; i < n - (k-2); i++)
	{
		if(i%2) printf("b");
		else printf("a");		
	}

	for(i = 2; i < k; i++)
		printf("%c", 'a' + i);
	printf("\n");

	return 0;
}