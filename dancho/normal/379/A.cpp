#include <cstdio>
#include <cstring>

int main()
{
	int a, b;
	int r = 0;
	scanf("%d %d", &a, &b);
	int tot = 0;
	
	while (a > 0)
	{
		tot += a;
		int p = a+r;
		a = p/b;
		r = p%b;
	}
	
	printf("%d\n", tot);
	return 0;
}