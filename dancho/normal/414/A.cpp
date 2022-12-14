#include <cstdio>
#include <cstring>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	if (n == 1 && k > 0)
	{
		printf("-1\n");
		return 0;
	}
	if (n == 1 && k == 0)
	{
		printf("5\n");
		return 0;
	}
	int p = n / 2;
	int nk = k - (p-1);
	if (nk <= 0)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d %d", nk, nk * 2);
	int j = 1;
	for (int i = 2; i + 1 < n; i += 2)
	{
		while (j == nk || j == 2 * nk || j + 1 == nk || j + 1 == 2 * nk)
			++j;
		printf(" %d %d", j, j + 1);
		j += 2;
	}
	if (n & 1)
	{
		printf(" %d", 1000000000);
	}
	printf("\n");
	return 0;
}