#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = ( s == '-' ), s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int N;

int main()
{
	read( N );
	LL b = 0, w = 0;
	rep( i, 1, N )
	{
		int a; read( a );
		if( i & 1 ) b += ( a + 1 ) >> 1, w += a >> 1;
		else b += a >> 1, w += ( a + 1 ) >> 1;
	}
	write( b < w ? b : w ), putchar( '\n' );
	return 0;
}