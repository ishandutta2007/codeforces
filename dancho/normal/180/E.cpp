#include <cstdio>
#include <cstring>

int n, m, k;
int a[200020];

int nc[200020];
int lv[200020];

int main()
{
	int i, j, be, us;
	
	scanf( "%d %d %d", &n, &m, &k );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
	}
	
	for ( i = 1; i <= m; i++ )
	{
		lv[i] = n+1;
	}
	
	for ( i = n; i > 0; i-- )
	{
		nc[ i ] = lv[ a[i] ];
		lv[ a[i] ] = i;
	}
	
	be = -1;
	for ( int cur = 1; cur <= m; cur++ )
	{
		i = j = lv[ cur ];
		for ( j = lv[ cur ], us = 0; j <= n; us += (nc[j] - j - 1), j = nc[j] )
		{
			while ( ( us > k ) && ( i <= j ) )
			{
				us -= (nc[i] - i - 1 );
				i = nc[i];
			}
			if ( j-i+1 - us >= be )
			{
				be = j-i+1-us;
			}
		}
	}
	printf( "%d\n", be );
	return 0;
}