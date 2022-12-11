#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e6 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
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

std :: vector<std :: vector<char> > grid;
std :: vector<std :: vector<int> > pref;

char str[MAXN];
int N, M, Q;

int main()
{
	read( N ), read( M );
	pref.resize( N + 5, std :: vector<int>( M + 5, 0 ) );
	grid.resize( N + 5, std :: vector<char>( M + 5, '.' ) );
	rep( i, 1, N )
	{
		scanf( "%s", str + 1 );
		rep( j, 1, M ) grid[i][j] = str[j];
	}
	rep( i, 2, N ) rep( j, 2, M ) 
	{
		bool un = grid[i - 1][j] == 'X' && grid[i][j - 1] == 'X';
		pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + un;
	}
	read( Q );
	while( Q -- )
	{
		int p, q;
		read( p ), read( q );
		if( p == q ) puts( "YES" );
		else puts( pref[N][q] - pref[N][p] ? "NO" : "YES" );
	}
	return 0;
}
/*
2 2
.X
X.
1
1 2
*/