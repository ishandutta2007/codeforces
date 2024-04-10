#include <cstdio>
#include <cstdlib>

int c[200];

int main()
{
	long long a, b;
	int len;
	scanf("%I64d %I64d", &a, &b);
	len = 0;
	while(b)
	{
		c[++len] = b % 10;
		b /= 10;
	}
	long long res = 1;
	for(int i = len; i >= 1; i--)
	{
		a += res * c[i];
		res *= 10;
	}
	printf("%d\n", a);
	return 0;
}