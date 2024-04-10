#include <cstdio>

typedef long long LL;

#define int LL

const int MAXN = 1e5 + 5;

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
void swapp( _T &x, _T &y )
{
	_T t = x; x = y, y = t;
}

int f[MAXN][2][2];

int GetWin( const int x, const int e )
{
	// printf( "Getting Win: Currnet Statement: { x = %d, e = %d };\n", x, e );
	if( x > e ) return 1;
	if( e == 1 ) return 0;
	if( e & 1 ) return ( e - x ) & 1;
	int l = e >> 2, r = e >> 1;
	if( x > r ) return ( e - x ) & 1;
	if( ! ( r & 1 ) ) r ++;
	if( l < x && x <= r ) return 1;
	return GetWin( x, l );
}

int GetFail( const int x, const int e )
{
	// printf( "Getting Fail: Currnet Statement: { x = %d, e = %d };\n", x, e );
	if( x > e ) return 0;
	if( e == 1 ) return 1;
	int l = e >> 2, r = e >> 1;
	if( x > r ) return 1;
	if( r & 1 ) return ( r - x ) & 1;
	if( l < x && x <= r ) return ( r - x ) & 1;
	return GetFail( x, l );
}

signed main()
{
	f[0][0][0] = 1;

	int T;
	read( T );
	for( int i = 1 ; i <= T ; i ++ )
	{
		int s, t;
		read( s ), read( t );
		int fw = GetWin( s, t ), fl = GetFail( s, t );
		// printf( "First: \n	Win: %d;\n	Lose: %d;\nLast: \n	Win: %d;\n	Lose: %d;\n", fw, fl, fw ^ 1, fl ^ 1 );
		if( fw ) f[i][0][1] = f[i - 1][1][0] | f[i - 1][0][0];
		else f[i][1][1] = f[i - 1][1][1] | f[i - 1][0][1];
		if( fl ) f[i][0][0] = f[i - 1][1][0] | f[i - 1][0][0];
		else f[i][1][0] = f[i - 1][1][1] | f[i - 1][0][1];
		// printf( "Case #%lld: Done\n", i );
	}
	write( f[T][1][1] | f[T][0][1] ), putchar( ' ' ), 
	write( f[T][1][0] | f[T][0][0] ), putchar( '\n' );
	return 0;
}