#include <cstdio>

int gcd( int a, int b )
{
	if ( b == 0 ) return a;
	return gcd( b, a%b );
}

int main()
{
	int n, a[2];
	scanf( "%d %d %d", &a[0], &a[1], &n );
	
	int la = 0;
	while ( 1 )
	{
		if ( n < gcd( n, a[la] ) )
		{
			la = 1-la;
			break;
		}
		n = n - gcd( n, a[la] );
		la = 1-la;
	}
	printf( "%d\n", la );
	
	return 0;
}