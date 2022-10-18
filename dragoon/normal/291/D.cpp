#include<stdio.h>
#include<assert.h>

int a[10005];

int main()
{
	int n, k;
	int i, j;

	scanf("%d %d", &n, &k);

	for(i = 1; i <= n; i++)
		a[i] = (i < n);

	for(i = 1; i <= k; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(j > 1) printf(" ");

			if(a[j] == n-j)
			{
				printf("%d", n);
				a[j] += a[n];
			}
			else if(a[j] + a[j] <= n-j)
			{
				printf("%d", j);
				a[j] += a[j];
			}
			else
			{
				printf("%d", n - (n-j - a[j]));
				a[j] += a[n - (n-j - a[j])];
			}

		}

		printf("\n");
	}

//	for(i = 1; i <= k; i++)
//		assert(a[i] == n-i);

	return 0;
}