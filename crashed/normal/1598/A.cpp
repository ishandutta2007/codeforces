#include <queue>
#include <cstdio>
#include <utility>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 100 + 5;

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

typedef std :: pair<int, int> Cell;

std :: queue<Cell> q;

int dir[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };

bool vis[2][MAXN];
int grid[2][MAXN];

int N;

inline bool Inside( const int x, const int y )
{
	return 0 <= x && x <= 1 && 1 <= y && y <= N;
}

int main()
{
	int T; read( T );
	while( T -- )
	{
		read( N );
		rep( i, 0, 1 ) rep( j, 1, N ) scanf( "%1d", &grid[i][j] );
		rep( i, 0, 1 ) rep( j, 1, N ) vis[i][j] = false;
		while( ! q.empty() ) q.pop();
		vis[0][1] = true, q.push( Cell( 0, 1 ) );
		while( ! q.empty() )
		{
			Cell cur = q.front(); q.pop();
			for( int k = 0 ; k < 8 ; k ++ )
			{
				int tx = cur.first + dir[k][0],
					ty = cur.second + dir[k][1];
				if( Inside( tx, ty ) && ! grid[tx][ty] && ! vis[tx][ty] )
					vis[tx][ty] = true, q.push( Cell( tx, ty ) );
			}
		}
		puts( vis[1][N] ? "YES" : "NO" );
	}
	return 0;
}