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
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int N, X, Y;

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		read( N ), read( X ), read( Y );
		write( MIN( MAX( 1, X + Y - N + 1 ), N ) ), putchar( ' ' ), write( MIN( N, X + Y - 1 ) ), putchar( '\n' );
	}
	return 0;
}