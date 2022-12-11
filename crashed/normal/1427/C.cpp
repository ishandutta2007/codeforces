#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5, MAXR = 505;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = - x;
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

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int dp[MAXN];
int x[MAXN], y[MAXN], t[MAXN];

int N, R;

int main()
{
//	freopen( "coincidence.in", "r", stdin );
//	freopen( "coincidence.out", "w", stdout );
	read( R ), read( N );
	rep( i, 1, N ) read( t[i] ), read( x[i] ), read( y[i] );
	int pref = - INF, ans = 0; x[0] = y[0] = 1, t[0] = 0;
	rep( i, 1, N )
	{
		dp[i] = - INF;
		if( i - 2 * R - 1 >= 0 )
			pref = MAX( dp[i - 2 * R - 1], pref );
		for( int j = 1 ; j <= 2 * R && j <= i ; j ++ )
			if( ABS( x[i] - x[i - j] ) + ABS( y[i] - y[i - j] ) <= t[i] - t[i - j] )
				dp[i] = MAX( dp[i], dp[i - j] + 1 );
		dp[i] = MAX( dp[i], pref + 1 );
		ans = MAX( ans, dp[i] ); 
	}
	write( ans ), putchar( '\n' );
	return 0;
}