#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 40;

template<typename _T>
void read( _T &x )/*{{{*/
{
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}/*}}}*/

template<typename _T>
void write( _T x )/*{{{*/
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}/*}}}*/

template<typename _T>
_T MAX( const _T a, const _T b )/*{{{*/
{
	return a > b ? a : b;
}/*}}}*/

LL A[MAXN][MAXN];
int c[MAXN][MAXN];

int N, M;

#define Val( x, y ) ( c[x][y] ? - A[x][y] : A[x][y] )

int main()
{
	read( N ), M = ( N + 1 ) >> 1;
	rep( i, 0, N - 1 ) rep( j, 0, N - 1 ) read( A[i][j] );
	LL ans = - INF, res, tmp, col, cur; int m = M - 1;
	for( int S = 0 ; S < ( 1 << M ) ; S ++ )
	{
		c[m][m] = S >> ( M - 1 ) & 1;
		res = Val( m, m );
		for( int i = 0 ; i < m ; i ++ )
		{
			c[m][i] = S >> i & 1, res += Val( m, i );
			c[m][i + M] = c[m][m] ^ c[m][i], res += Val( m, i + M );	
		}
		for( int i = 0 ; i < m ; i ++ )
		{
			col = - INF;
			for( int &d = c[i][m] = 0 ; d < 2 ; d ++ )
			{
				c[i + M][m] = c[m][m] ^ c[i][m];
				tmp = Val( i, m ) + Val( i + M, m );
				for( int j = 0 ; j < m ; j ++ )
				{
					cur = - INF;
					for( int &e = c[i][j] = 0 ; e < 2 ; e ++ )
					{
						c[i][j + M] = c[i][j] ^ c[i][m];
						c[i + M][j] = c[i][j] ^ c[m][j];
						c[i + M][j + M] = c[i][j + M] ^ c[m][j + M];
						cur = MAX( cur, Val( i, j ) + Val( i, j + M ) + 
										Val( i + M, j ) + Val( i + M, j + M ) );
					}
					tmp += cur;
				}
				col = MAX( col, tmp );
			}
			res += col;
		}
		ans = MAX( ans, res );
	}
	write( ans ), putchar( '\n' );
	return 0;
}