#include <cstdio>
#include <cstring>

int ia( int x )
{
	if ( x < 0 ) return -x;
	return x;
}

int x1, x2, a, b, mid, mxd;

int main()
{
	int d;
	scanf( "%d %d %d %d", &x1, &x2, &a, &b );
	if ( ( x1+a <= x2 ) && ( x2 <= x1+b ) )
	{
		printf( "FIRST\n" );
		printf( "%d\n", x2 );
		return 0;
	}
	if ( ( a <= 0 ) && ( x1 <= x2 ) )
	{
		printf( "DRAW\n" );
		return 0;
	}
	if ( ( b >= 0 ) && ( x1 >= x2 ) )
	{
		printf( "DRAW\n" );
		return 0;
	}
	if ( ( x1 <= x2 ) && ( x1 + a > x2 ) && ( x1+b > x2 ) )
	{
		printf( "DRAW\n" );
		return 0;
	}
	if ( ( x1 >= x2 ) && ( x1 + a < x2 ) && ( x1+b < x2 ) )
	{
		printf( "DRAW\n" );
		return 0;
	}

	if ( x1 <= x2 )
	{
		mid = a;
		mxd = b;
		d = x2-x1;
	}
	else if ( x1 >= x2 )
	{
		mid = -b;
		mxd = -a;
		d = x1-x2;
	}

	d = d % (mxd+mid);
	if ( d == 0 )
	{
		printf( "SECOND\n" );
	}
	else if ( d <= mid-1 )
	{
		printf( "DRAW\n" );
	}
	else if ( d <= mxd )
	{
		printf( "FIRST\n" );
		if ( x1 <= x2 )
			printf( "%d\n", x1+d );
		else printf( "%d\n", x1-d );
	}
	else if ( d <= mid+mxd-1 )
	{
		printf( "DRAW\n" );
	}
	return 0;
}