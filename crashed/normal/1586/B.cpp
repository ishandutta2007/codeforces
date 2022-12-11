#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
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

bool app[MAXN];

int fr[MAXN], md[MAXN], to[MAXN];

int N, M;

int main()
{
	int T; read( T );
	while( T -- )
	{
		read( N ), read( M );
		rep( i, 1, N ) app[i] = false;
		rep( i, 1, M )
		{
			read( fr[i] ), read( md[i] ), read( to[i] );
			app[md[i]] = true;
		}
		int rt = 0;
		rep( i, 1, N ) if( ! app[i] )
		{ rt = i; break; }
		rep( i, 1, N ) if( i ^ rt ) printf( "%d %d\n", i, rt );
	}
	return 0;
}