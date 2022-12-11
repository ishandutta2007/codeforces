#include <cstdio>

const int MAXN = 505;

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

int f[MAXN][MAXN], g[MAXN][MAXN];
int a[MAXN];
int N;

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	for( int i = N ; i ; i -- )
	{
		f[i][i] = 1, g[i][i] = a[i];
		for( int j = i + 1 ; j <= N ; j ++ )
		{
			f[i][j] = N + 1;
			for( int k = i ; k < j ; k ++ )
			{
				if( f[i][k] == 1 && f[k + 1][j] == 1 && g[i][k] == g[k + 1][j] )
					f[i][j] = 1, g[i][j] = g[i][k] + 1;
				else if( f[i][j] > f[i][k] + f[k + 1][j] )
				{
					f[i][j] = f[i][k] + f[k + 1][j];
					g[i][j] = g[i][k] + g[k + 1][j];
				}
			}
		}
	}
	write( f[1][N] ), putchar( '\n' );
	return 0;
}