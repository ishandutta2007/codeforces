#include <cstdio>
#include <cstring>

int h12, h13, h14, h23, h24, h34;

int b2, b3, b4;
int y2, y3, y23;
int x2, x3, x23, x4;

int main()
{
	int len;
	int blen = (1<<29);
	int i, j = -1;
	scanf( "%d %d %d", &h12, &h13, &h14 );
	scanf( "%d %d", &h23, &h24 );
	scanf( "%d", &h34 );
	
	b2 = h12; b3 = h13; b4 = h14;
	
	y23 = b2+b3-h23;
	if ( ( y23 % 2 == 1 ) || ( y23 < 0 ) )
	{
		printf( "-1\n" );
		return 0;
	}
	
	y23 = y23 / 2;
	y2 = b2 - y23;
	y3 = b3 - y23;
	
	if ( y2 < 0 || y3 < 0 )
	{
		printf( "-1\n" );
		return 0;
	}
	
	for ( x2 = 0; x2 <= y2; x2++ )
	{
		x23 = b4+y2-2*x2+y23-h24;
		if ( ( x23 % 2 == 1 ) || ( x23 < 0 ) )
		{
			continue;
		}
		x23 = x23 / 2;
		if ( x23 > y23 ) continue;
		
		x3 = b4+y3+y23-2*x23-h34;
		if ( ( x3 % 2 == 1 ) || ( x3 < 0 ) )
		{
			continue;
		}
		x3 = x3 / 2;
		if ( x3 > y3 ) continue;
		
		x4 = b4-x2-x3-x23;
		if ( x4 < 0 ) continue;
		
		len = x4+y2+y3+y23;
		
		if ( len < blen )
		{
			blen = len;
			j = x2;
		}
		
	}
	if ( j == -1 )
		printf( "-1\n" );

	for ( x2 = j; x2 <= j; x2++ )
	{
		x23 = b4+y2-2*x2+y23-h24;
		if ( ( x23 % 2 == 1 ) || ( x23 < 0 ) )
		{
			continue;
		}
		x23 = x23 / 2;
		if ( x23 > y23 ) continue;
		
		x3 = b4+y3+y23-2*x23-h34;
		if ( ( x3 % 2 == 1 ) || ( x3 < 0 ) )
		{
			continue;
		}
		x3 = x3 / 2;
		if ( x3 > y3 ) continue;
		
		x4 = b4-x2-x3-x23;
		if ( x4 < 0 ) continue;
		
		len = x4+y2+y3+y23;
		
		printf( "%d\n", len );
		
		for ( i = 1; i <= len; i++ )
			printf( "a" );
		printf( "\n" );
	
		for ( i = 1; i <= len-y23-y2; i++ )
			printf( "a" );
		for ( ; i <= len; i++ )
			printf( "b" );
		printf( "\n" );

		for ( i = 1; i <= len-y23-y2-y3; i++ )
			printf( "a" );
		for ( ; i <= len-y2-y23; i++ )
			printf( "b" );
		for ( ; i <= len-y23; i++ )
			printf( "a" );
		for ( ; i <= len; i++ )
			printf( "b" );
		printf( "\n" );

		for ( i = 1; i <= x4; i++ )
			printf( "b" );
		for ( i = 1; i <= x3; i++ )
			printf( "b" );
		for ( i = 1; i <= y3-x3; i++ )
			printf( "a" );
		for ( i = 1; i <= x2; i++ )
			printf( "b" );
		for ( i = 1; i <= y2-x2; i++ )
			printf( "a" );
		for ( i = 1; i <= x23; i++ )
			printf( "b" );
		for ( i = 1; i <= y23-x23; i++ )
			printf( "a" );
		printf( "\n" );
	}
	
	return 0;
}