#include <cstdio>
#include <cstring>

int n;

int p[512];
int c[512][512];

int a[512];

int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			scanf( "%d", &c[i][j] );
		}
	}
	
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &p[i] );
	}
	
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			if ( c[i][j] == i ) continue;
			for ( k = 1; k <= n; k++ )
			{
				if ( p[k] == c[i][j] )
					break;
				if ( ( p[k] < c[i][j] ) && ( p[k] != i ) )
					break;
			}
			if ( p[k] == c[i][j] )
			{
				a[i] = c[i][j];
				break;
			}
		}
	}
	for ( i = 1; i < n; i++ )
		printf( "%d ", a[i] );
	printf( "%d\n", a[n] );
	return 0;
}