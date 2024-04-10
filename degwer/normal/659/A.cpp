#include<stdio.h>
int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	a += b;
	a %= n;
	a += n;
	a %= n;
	if (a == 0)a = n;
	printf("%d\n", a);
}