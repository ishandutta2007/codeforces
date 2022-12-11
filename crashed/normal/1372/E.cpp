#include <cstdio>

const int INF = 0x3f3f3f3f;
const int MAXN = 105;

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

int f[MAXN][MAXN];
int su[MAXN][MAXN][MAXN];

int N, M;

int main()
{
	read( N ), read( M );
	for( int i = 1 ; i <= N ; i ++ )
	{
		int K, l, r;
		read( K );
		while( K -- )
		{
			read( l ), read( r );
			for( int a = 1 ; a <= l ; a ++ )
				for( int b = r ; b <= M ; b ++ )
					su[a][b][l] ++, su[a][b][r + 1] --;
		}
	}
	for( int i = 1 ; i <= M ; i ++ )
		for( int j = i + 1 ; j <= M ; j ++ )
			for( int k = i ; k <= j ; k ++ )
				su[i][j][k] += su[i][j][k - 1];
	for( int i = M ; i ; i -- )
	{
		f[i][i + 1] = -INF;
		for( int j = i ; j <= M ; j ++ )
			for( int k = i ; k <= j ; k ++ )
				f[i][j] = MAX( f[i][j], f[i][k - 1] + f[k + 1][j] + su[i][j][k] * su[i][j][k] );
	}
	write( f[1][M] ), putchar( '\n' );
	return 0;
}