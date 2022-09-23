#include <stdio.h>

int main()
{
	int t, x, s;
	scanf("%d %d %d", &t, &s, &x);
	if(x < t)
	{
		puts("NO");
		return 0;
	}

	x -= t;
	if(x == 1)	puts("NO");
	else if(x % s == 0 || x % s == 1)	puts("YES");
	else	puts("NO");
	return 0;
}