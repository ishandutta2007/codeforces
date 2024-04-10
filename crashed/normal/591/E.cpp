#include <deque>
#include <cstdio>
#include <cstring>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 1005;

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

std :: deque<std :: pair<int, int> > q;

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

int dist[4][MAXN][MAXN];

char grid[MAXN][MAXN];
int N, M; 	

inline bool Inside( const int x, const int y )
{
	return 1 <= x && x <= N && 1 <= y && y <= M;
}

void BFS( const int id )
{
	q.clear();
	memset( dist[id], 0x3f, sizeof dist[id] );
	rep( i, 1, N ) rep( j, 1, M )
		if( grid[i][j] == id + '0' )
			dist[id][i][j] = 0, q.push_back( std :: make_pair( i, j ) );
	while( ! q.empty() )
	{
		int ux = q.front().first,
			uy = q.front().second; 
		q.pop_front();
		for( int i = 0 ; i < 4 ; i ++ )
		{
			int vx = ux + dir[i][0], vy = uy + dir[i][1];
			if( Inside( vx, vy ) && grid[vx][vy] != '#' )
			{
				int w = grid[vx][vy] == '.';
				if( dist[id][vx][vy] > dist[id][ux][uy] + w )
				{
					dist[id][vx][vy] = dist[id][ux][uy] + w;
					if( w == 1 ) q.push_back( std :: make_pair( vx, vy ) );
					else q.push_front( std :: make_pair( vx, vy ) );
				}
			}
		}
	}
}

int main()
{
	read( N ), read( M );
	rep( i, 1, N ) scanf( "%s", grid[i] + 1 );
	rep( i, 1, 3 ) BFS( i );
	LL ans = 1e18;
	rep( i, 1, N ) rep( j, 1, M )
	{
		LL tmp = 0;
		rep( k, 1, 3 ) tmp += dist[k][i][j];
		if( grid[i][j] == '.' ) tmp -= 2;
		ans = std :: min( ans, tmp );
	}
	write( ans > 1e9 ? -1 : ans ), putchar( '\n' );
	return 0;
}