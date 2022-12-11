#include <deque>
#include <cstdio>
#include <utility>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXN = 2005;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
int wei[4] = { 0, 0, 1, 0 };

std :: deque<std :: pair<int, int> > q;

int dist[MAXN][MAXN];
char grid[MAXN][MAXN];

int N, M;

inline bool Inside( const int x, const int y )
{
	return 1 <= x && x <= N && 1 <= y && y <= M;
}

void BFS( const int sx, const int sy )
{
	rep( i, 1, N ) rep( j, 1, M ) dist[i][j] = INF;
	dist[sx][sy] = 0, q.push_back( std :: make_pair( sx, sy ) );
	while( ! q.empty() )
	{
		int ux = q.front().first, 
			uy = q.front().second;
		q.pop_front();
		for( int k = 0 ; k < 4 ; k ++ )
		{
			int vx = ux + dir[k][0], vy = uy + dir[k][1];
			if( Inside( vx, vy ) && grid[vx][vy] == '.' )
				if( dist[vx][vy] > dist[ux][uy] + wei[k] )
				{
					dist[vx][vy] = dist[ux][uy] + wei[k];
					if( wei[k] == 0 ) q.push_front( std :: make_pair( vx, vy ) );
					else q.push_back( std :: make_pair( vx, vy ) );
				}
		}
	}
}

int main()
{
	int sx, sy, lef, rig;
	read( N ), read( M );
	read( sx ), read( sy );
	read( lef ), read( rig );
	rep( i, 1, N ) scanf( "%s", grid[i] + 1 );
	BFS( sx, sy ); int ans = 0;
	rep( i, 1, N ) rep( j, 1, M )
		if( grid[i][j] == '.' )
		{
			int l = dist[i][j],
				r = std :: max( j - sy + l, 0 );
			ans += l <= lef && r <= rig;
		}
	write( ans ), putchar( '\n' );
	return 0;
}