#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int ia( int x )
{
	if ( x < 0 ) return -x;
	return x;
}

int n, m, x1, y1, x2, y2;

int main()
{
	int dx, dy;
	
	scanf( "%d %d %d %d %d %d", &n, &m, &x1, &y1, &x2, &y2 );
	
	dx = ia( x1-x2 );
	dy = ia( y1-y2 );
	if ( dx < dy ) 
	{
		swap( dx, dy );
	}
	
	if ( ( dx == 4 ) && ( dy <= 2 ) )
		printf( "First\n" );
	else if ( ( dx == 4 ) && ( dy == 4 ) )
		printf( "Second\n" );
	else if ( ( dx == 4 ) && ( dy == 3 ) )
	{
		printf( "Second\n" );
	}
	else if ( ( dx <= 4 ) && ( dy <= 4 ) )
		printf( "First\n" );
	else printf( "Second\n" );
	
	return 0;
}