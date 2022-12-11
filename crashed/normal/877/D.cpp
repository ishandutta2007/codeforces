#include <set>
#include <queue>
#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
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

std :: set<int> rUnv[MAXN], cUnv[MAXN];
std :: queue<std :: pair<int, int> > q;

int up[MAXN][MAXN], dn[MAXN][MAXN];
int lef[MAXN][MAXN], rig[MAXN][MAXN];

int dist[MAXN][MAXN];
char grid[MAXN][MAXN];
int N, M, K;

using Iter = std :: set<int> :: iterator;

void Init()
{
	int lst;
	rep( i, 1, N ) 
	{
		lst = 0;
		rep( j, 1, M )
		{
			if( grid[i][j] == '#' ) lst = j;
			else lef[i][j] = std :: max( lst + 1, j - K );
		}
		lst = M + 1;
		per( j, M, 1 )
		{
			if( grid[i][j] == '#' ) lst = j;
			else rig[i][j] = std :: min( lst - 1, j + K );
		}
	}
	rep( j, 1, M )
	{
		lst = 0;
		rep( i, 1, N )
		{
			if( grid[i][j] == '#' ) lst = i;
			else up[i][j] = std :: max( lst + 1, i - K );
		}
		lst = N + 1;
		per( i, N, 1 )
		{
			if( grid[i][j] == '#' ) lst = i;
			else dn[i][j] = std :: min( lst - 1, i + K );
		}
	}
}

inline void Delete( const int x, const int y )
{
	Iter it;
	if( ( it = rUnv[x].find( y ) ) != rUnv[x].end() ) rUnv[x].erase( it );
	if( ( it = cUnv[y].find( x ) ) != cUnv[y].end() ) cUnv[y].erase( it );
}

int BFS( const int sx, const int sy, const int tx, const int ty )
{
	rep( i, 1, N ) rep( j, 1, M ) 
	{
		dist[i][j] = INF;
		rUnv[i].insert( j );
		cUnv[j].insert( i );
	}
	dist[sx][sy] = 0, Delete( sx, sy ), q.push( std :: make_pair( sx, sy ) );
	while( ! q.empty() )
	{
		int ux = q.front().first,
			uy = q.front().second; q.pop();
		for( Iter it ; ; Delete( ux, *it ) )
		{
			it = rUnv[ux].lower_bound( lef[ux][uy] );
			if( it == rUnv[ux].end() || *it > rig[ux][uy] ) break;
			dist[ux][*it] = dist[ux][uy] + 1, q.push( std :: make_pair( ux, *it ) );
		}
		for( Iter it ; ; Delete( *it, uy ) )
		{
			it = cUnv[uy].lower_bound( up[ux][uy] );
			if( it == cUnv[uy].end() || *it > dn[ux][uy] ) break;
			dist[*it][uy] = dist[ux][uy] + 1, q.push( std :: make_pair( *it, uy ) );
		}
	}
	return dist[tx][ty] == INF ? -1 : dist[tx][ty];
}

int main()
{
	read( N ), read( M ), read( K );
	rep( i, 1, N ) scanf( "%s", grid[i] + 1 );
	Init(); int tx, ty, sx, sy;
	read( sx ), read( sy ), read( tx ), read( ty );
	write( BFS( sx, sy, tx, ty ) ), putchar( '\n' );
	return 0;
}