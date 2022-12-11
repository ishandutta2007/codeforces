#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1005;

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

int ok[MAXN][10];

int N;

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		read( N );
		rep( i, 1, N ) rep( j, 1, 5 ) read( ok[i][j] );
		if( N & 1 ) { puts( "NO" ); continue; }
		bool flg = false;
		rep( j, 1, 4 ) rep( k, j + 1, 5 )
		{
			int fir = 0, sec = 0, both = 0;
			rep( i, 1, N )
			{
				if( ok[i][j] && ok[i][k] ) both ++;
				else if( ok[i][j] ) fir ++;
				else if( ok[i][k] ) sec ++;
			}
			if( fir + sec + both != N ) continue;
			if( fir * 2 <= N && sec * 2 <= N ) flg = true;
		}
		puts( flg ? "YES" : "NO" );
	}
	return 0;
}