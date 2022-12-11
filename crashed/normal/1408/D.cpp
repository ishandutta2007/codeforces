#include <cstdio>

const int MAXN = 2005, MAXA = 1e6 + 5;

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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

int mov[MAXA];
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int N, M;

int main()
{
	read( N ), read( M );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] ), read( b[i] );
	for( int i = 1 ; i <= M ; i ++ ) read( c[i] ), read( d[i] );
	
	int ans = 1e9;
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 1 ; j <= M ; j ++ )
			if( a[i] <= c[j] && b[i] <= d[j] )
				mov[c[j] - a[i]] = MAX( mov[c[j] - a[i]], d[j] - b[i] + 1 );
	for( int i = 1e6 ; ~ i ; i -- ) mov[i] = MAX( mov[i], mov[i + 1] );
	for( int i = 1e6 ; ~ i ; i -- ) ans = MIN( ans, i + mov[i] );
	write( ans ), putchar( '\n' );
	return 0;
}