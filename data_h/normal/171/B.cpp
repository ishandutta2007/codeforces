#include <cstdio>
#include <cstdlib>
int main()
{
	int a;
	long long res = 0;
	res = 1;
	scanf("%d", &a);
	for(int i = 2; i <= a; i++)
		res += (long long)(i - 1) * 2 * 6;
	printf("%I64d\n", res);
	return 0;
}