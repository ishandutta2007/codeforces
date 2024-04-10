#include <stdio.h>
#define MIN(a, b)	(((a) < (b)) ? (a) : (b))

int main()
{
	long long n, a, b, c;	scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
	long long mod = n % 4;
	if(mod == 0)
	{
		puts("0");
		return 0;
	}
	else if(mod == 1)
	{
		printf("%lld\n", MIN(MIN(a + a + a, a + b), c));
		return 0;
	}
	else if(mod == 2)
	{
		printf("%lld\n", MIN(MIN(b, a + a), c + c));
	}
	else
	{
		printf("%lld\n", MIN(MIN(a, b + c), c + c + c));
	}
	return 0;
}