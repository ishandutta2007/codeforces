#include <iostream>
#include <cstdio>
using namespace std; 
int main()
{
	// freopen("755E.in", "r", stdin); 
	int n, k; 
	scanf("%d%d", &n, &k); 
	if (k == 1 || k >= 4)
	{
		puts("-1"); 
		return 0; 
	}
	if (k == 2)
	{
		if (n < 5)
			puts("-1"); 
		else
		{
			printf("%d\n", n - 1);
			for (int i = 1; i < n; i++)
				printf("%d %d\n", i, i + 1);
		}
	}
	else
	{
		if (n < 4)
			puts("-1"); 
		else
		{
			printf("%d\n", n - 1);
			for (int i = 1; i < n - 1; i++)
				printf("1 %d\n", i + 1);
			printf("%d %d\n", n - 1, n);
		}
	}
	return 0; 
}