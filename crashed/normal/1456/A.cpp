#include <cmath>
#include <cstdio>

#define rep( x, a, b ) for( int ( x ) = a ; x <= b ; x ++ )
#define per( x, a, b ) for( int ( x ) = a ; x >= b ; x -- )

const int MAXN = 1e5 + 5;

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

int cnt[MAXN];
int A[MAXN];

int N, P, K, X, Y;

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		read( N ), read( P ), read( K );
		rep( i, 0, P - 1 ) cnt[i] = 0;
		rep( i, 1, N ) 
		{
			scanf( "%1d", &A[i] );
			if( i >= P ) cnt[i % K] += A[i]; 
		}
		int ans = 0x3f3f3f3f, res = 0;
		read( X ), read( Y );
		rep( i, P, N )
		{
			ans = MIN( ans, res + X * MAX( 0, ( int ) ceil( 1.0 * ( N - i + 1 ) / K ) - cnt[i % K] ) );
			cnt[i % K] -= A[i], res += Y;
		}
		write( ans ), putchar( '\n' );
	}
	return 0;
}
/*
3
10 3 2
0101010101
2 2
5 4 1
00000
2 10
11 2 3
10110011000
4 3

1
5 4 1
00000
2 10
*/