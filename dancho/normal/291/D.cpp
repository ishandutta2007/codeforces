#include <cstdio>
#include <cstring>

int n, k;
int a[1<<17];
int c[1<<17];

int main()
{
	int i;
	
	scanf( "%d %d", &n, &k );
	for ( i = 1; i < n; i++ )
	{
		a[i] = 1;
	}
	a[n] = 0;
	
	while ( k-- )
	{
		for ( i = 1; i <= n; i++ )
		{
			if ( a[i] + a[i] <= n-i )
			{
				c[i] = i;
				a[i] = a[i] + a[i];
			}
			else
			{
				c[i] = n-((n-i)-a[i]);
				a[i] = n-i;
			}
		}
		for ( i = 1; i < n; i++ )
			printf( "%d ", c[i] );
		printf( "%d\n", c[n] );
	}
	return 0;
}