#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 15, MAXS = ( 1 << 10 ) + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
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

LL dp[MAXS][MAXS];

bool Graph[MAXN][MAXN];
int N, M, K;

int main()
{
	read( N ), read( M ), read( K );
	rep( i, 1, M )
	{
		int u, v;
		read( u ), read( v ), u --, v --;
		Graph[u][v] = Graph[v][u] = true;
	}
	dp[1][1] = 1;
	for( int S = 1 ; S < ( 1 << N ) ; S ++ )
		for( int T = 0 ; T < ( 1 << N ) ; T ++ )
		{
			if( ( T & S ) ^ T ) continue;
			int siz = __builtin_popcount( S );
			for( int u = 0 ; u < N ; u ++ ) if( S >> u &  1 )
				for( int v = 0 ; v < N ; v ++ ) if( ! ( S >> v & 1 ) )
				{
					if( ! Graph[u][v] ) continue;
					if( siz == 1 ) dp[S | ( 1 << v )][T | ( 1 << v )] += dp[S][T];
					else
					{
						int nwT = ( T | ( 1 << v ) ) & ( ~ ( 1 << u ) );
						if( ! ( nwT >> v ^ 1 ) )dp[S | ( 1 << v )][nwT] += dp[S][T];
					}
				}
		}
	int all = 1 << N; LL ans = 0;
	for( int T = 0 ; T < ( 1 << N ) ; T ++ )
		if( __builtin_popcount( T ) == K )
			ans += dp[all - 1][T];
	write( ans ), putchar( '\n' );
	return 0;
}