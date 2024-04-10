#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

template<typename _T>
void read( _T &x )
{
    x = 0; char s = getchar(); int f = 1;
    while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    x *= f;
}

template<typename _T>
void write( _T x )
{
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) write( x / 10 );
    putchar( x % 10 + '0' );
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

LL S( const LL n ) { return n * ( n + 1 ) / 2; }

int main()
{
	int K;
	LL N, X, T;
	read( K );
	while( K -- )
	{
		read( N ), read( X ), read( T );
		LL ans = ( T / X ) * MAX( 0ll, N - ( T / X ) );
		ans += S( MAX( N - MAX( 0ll, N - ( T / X ) ) - 1, 0ll ) );
		write( ans ), putchar( '\n' );
	}
	return 0;
}