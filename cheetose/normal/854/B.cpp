#include<cstdio>
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	if (k == 0 || k == n)
		puts("0 0");
	else if (k <= n / 3)
		printf("1 %d", 2 * k);
	else
		printf("1 %d", n - k);
}