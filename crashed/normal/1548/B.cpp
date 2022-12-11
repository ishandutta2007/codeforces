#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 2e5 + 5, MAXLOG = 19;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
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
_T ABS( const _T a )
{
	return a < 0 ? -a : a;
}

LL d[MAXN][MAXLOG];
int lg2[MAXN];

LL A[MAXN];
int N;

LL Gcd( LL x, LL y ) { for( LL z ; y ; z = x, x = y, y = z % y ); return x; }

LL Query( const int l, const int r )
{
	if( l > r ) return 0;
	int k = lg2[r - l + 1];
	return Gcd( d[l][k], d[r - ( 1 << k ) + 1][k] );
}

int main()
{
	
	int T; read( T );
	while( T -- )
	{
		read( N );
		rep( i, 1, N ) read( A[i] );
		lg2[0] = -1; rep( i, 1, N ) lg2[i] = lg2[i >> 1] + 1;
		rep( i, 1, N - 1 ) d[i][0] = ABS( A[i + 1] - A[i] );
		for( int j = 1 ; j <= lg2[N - 1] ; j ++ )
			for( int i = 1 ; i + ( 1 << j - 1 ) < N ; i ++ )
				d[i][j] = Gcd( d[i][j - 1], d[i + ( 1 << j - 1 )][j - 1] );
		int ans = 1;
		for( int i = 1, j = 1 ; i < N ; i ++ )
		{
			for( j = std :: max( j, i ) ; j < N && Query( i, j ) > 1 ; j ++ );
			ans = std :: max( ans, j - i + 1 );
		}
		write( ans ), putchar( '\n' );
	}
	return 0;
}