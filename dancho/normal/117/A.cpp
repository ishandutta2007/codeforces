#include <cstdio>

int n, m;

int main()
{
	int i, j, k;
	int s, f, t;
	int q, r;
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d %d", &s, &f, &t );
		if ( s == f )
		{
			printf( "%d\n", t );
			continue;
		}
		q = t/(2*m-2); r = t%(2*m-2);
		if ( r <= s-1 )
		{
			k = s-1;
		}
		else if ( r <= 2*m-1-s )
		{
			k = 2*m-1-s;
		}
		else
		{
			k = 2*m-2+s-1;
		}

		if ( ( r <= f-1 ) && ( f-1 >= k ) )
		{
			j = f-1;
		}
		else if ( ( r <= 2*m-1-f ) && ( 2*m-1-f >= k ) )
		{
			j = 2*m-1-f;
		}
		else if ( 2*m-2+f-1 >= k )
		{
			j = 2*m-2+f-1;
		}
		else
		{
			j = 2*m-2+2*m-1-f;
		}
		
//		printf( "A %d %d %d %d\n", k, j, q, r );
		
		if ( k <= j )
		{
			printf( "%d\n", q*(2*m-2) + j );
		}
		else
		{
			printf( "%d\n", q*(2*m-2) + 2*m-2+f-1 );
		}
	}
	return 0;
}