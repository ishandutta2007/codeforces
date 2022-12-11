#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 5e3 + 5;

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

template<typename _T>
_T ABS( const _T a )
{
	return a < 0 ? -a : a;
}

LL dp[MAXN];

int tag[MAXN], s[MAXN];
int N;

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		read( N );
		rep( i, 1, N ) read( tag[i] );
		rep( i, 1, N ) read( s[i] );
		rep( i, 1, N ) dp[i] = 0;
		rep( i, 1, N ) per( j, i - 1, 1 )
		{
			if( tag[i] == tag[j] ) continue;
			LL a = dp[i], b = dp[j];
			dp[i] = std :: max( dp[i], b + ABS( s[i] - s[j] ) );
			dp[j] = std :: max( dp[j], a + ABS( s[i] - s[j] ) );
		}
		LL ans = 0;
		rep( i, 1, N ) ans = std :: max( ans, dp[i] );
		write( ans ), putchar( '\n' );
	}
	return 0;
}