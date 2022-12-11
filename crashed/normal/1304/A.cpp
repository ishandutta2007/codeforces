#include <cstdio>

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

int main()
{
	int T, x, y, a, b;
	read( T );
	while( T -- )
	{
		read( x ), read( y ), read( a ), read( b );
		if( ( y - x ) % ( a + b ) ) { puts( "-1" ); continue; }
		write( ( y - x ) / ( a + b ) ), putchar( '\n' );
	}
	return 0;
}