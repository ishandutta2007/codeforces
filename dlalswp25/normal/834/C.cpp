#include <stdio.h>

int main()
{
	int n;	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		int a, b;	scanf("%d %d", &a, &b);

		long long x = (long long)a * b;

		long long l = 0, r = 1000000;
		while(l <= r)
		{
			long long mid = (l + r) / 2;
			if(mid * mid * mid < x)	l = mid + 1;
			else	r = mid - 1;
		}

		if(l * l * l != x)
		{
			puts("No");
			continue;
		}

		if(a % l == 0 && b % l == 0)
		{
			puts("Yes");
		}
		else	puts("No");
	}
	return 0;
}