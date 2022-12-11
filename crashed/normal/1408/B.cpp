#include <cstdio>

const int MAXN = 105;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ); s = getchar(); }
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

int a[MAXN];
int N, K;

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		int cnt = 0;
		read( N ), read( K );
		for( int i = 1 ; i <= N ; i ++ ) 
		{
			read( a[i] );
			cnt += a[i] != a[i - 1];
		}
		if( K == 1 )
			write( cnt > 1 || ! a[1] ? -1 : 1 ), putchar( '\n' );
		else
		{
			if( a[1] ) write( 1 + ( cnt <= K ? 0 : ( cnt - K - 1 ) / ( K - 1 ) + 1 ) ), putchar( '\n' );
			else write( ( cnt - 1 ) / ( K - 1 ) + 1 ), putchar( '\n' );
		}
	}
	return 0;
}