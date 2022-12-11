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

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		int x1, y1, z1;
		int x2, y2, z2;
		read( x1 ), read( y1 ), read( z1 );
		read( x2 ), read( y2 ), read( z2 );
		if( z1 < y2 )
		{
			write( 2 * z1 - MAX( z2 - x1, 0 ) * 2 ), putchar( '\n' );
		}
		else
		{
			write( 2 * y2 - MAX( z2 - x1 - ( z1 - y2 ), 0 ) * 2 ), putchar( '\n' );
		}
	}
	return 0;
}