#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXN = 20005, MAXL = 105;

template<typename _T>
void read( _T &x )/*{{{*/
{
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}/*}}}*/

template<typename _T>
void write( _T x )/*{{{*/
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}/*}}}*/

int A[MAXN];
int N;

bool Check( int x )
{
	if( x <= 1 ) return false;
	for( int i = 2 ; 1ll * i * i <= x ; i ++ )
		if( ! ( x % i ) ) return true;
	return false;
}

int main()
{
	int T; read( T );
	while( T -- )
	{
		read( N ); int su = 0;
		rep( i, 1, N ) read( A[i] ), su += A[i];
		if( Check( su ) )
		{
			write( N ), putchar( '\n' );
			rep( i, 1, N ) write( i ), putchar( i == N ? '\n' : ' ' );
		}
		else
		{
			write( N - 1 ), putchar( '\n' );
			bool flg = false;
			rep( i, 1, N )
			{
				if( A[i] % 2 == 1 && ! flg ) { flg = true; continue; }
				write( i ), putchar( ' ' );
			}
			puts( "" );
		}
	}
	return 0;
}