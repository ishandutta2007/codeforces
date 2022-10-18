#include<stdio.h>

int m[1000006];

void f(int n)
{
	if( n < 0 )
		return;

	if(n == 0)
	{
		m[0] = 0;
		return;
	}

	if(n == 1)
	{
		m[0] = 1;
		m[1] = 0;
		return;
	}

	int i, j, p2 = 1;
	for(i = 0; ; i++)
	{
		if(p2*2 > n)
			break;
		p2 *= 2;
	}

	for(i = p2, j = p2 - 1; i <= n; i++, j--)
	{
		m[i] = j;
		m[j] = i;
	}

	f(j);
}

int main()
{
	int n, i;
	__int64 ans = 0;

	scanf("%d", &n);

	f(n);


	for(i = 0; i <= n; i++)
		ans += m[i]^i;

	printf("%I64d\n", ans);
	for(i = 0; i <= n; i++)
	{
		if(i) printf(" ");
		printf("%d", m[i]);
	}
	printf("\n");

	return 0;
}