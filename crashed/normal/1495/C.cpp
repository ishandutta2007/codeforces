#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 505, MAXS = MAXN * MAXN;

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

bool board[MAXN][MAXN];
char str[MAXN];
int N, M;

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		read( N ), read( M );
		rep( i, 1, N )
		{
			scanf( "%s", str + 1 );
			rep( j, 1, M ) board[i][j] = str[j] == 'X';
		}
		int rem = N % 3 == 1 ? 1 : 2, lst = 0;
		rep( i, 1, N ) if( i % 3 == rem )
		{
			rep( j, 1, M ) board[i][j] = true;
			if( lst )
			{
				if( board[i - 2][2] || board[i - 1][2] )
					board[i - 2][2] = board[i - 1][2] = true;
				else 
					board[i - 1][1] = board[i - 2][1] = true;
			}
			lst = i;
		}
		rep( i, 1, N )
		{
			rep( j, 1, M )
				putchar( board[i][j] ? 'X' : '.' );
			putchar( '\n' );
		}
	}
	return 0;
}