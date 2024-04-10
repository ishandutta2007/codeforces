#include <cstdio>
#include <algorithm>

const int MAXN = 1e5 + 5;

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

int a[MAXN << 1];
int N;

int main()
{
	int T, half, ans;
	read( T );
	while( T -- )
	{
		read( N );
		for( int i = 1 ; i <= N << 1 ; i ++ ) read( a[i] );
		std :: sort( a + 1, a + 1 + N * 2 );
		write( a[N + 1] - a[N] ), putchar( '\n' );
	}
	return 0;
}