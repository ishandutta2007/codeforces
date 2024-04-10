#include <queue>
#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 2e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = ( s == '-' ), s = getchar(); }
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

struct Node
{
	LL d; int u, a, b;
	
	Node(): d( INF ), u( 0 ) {}
	Node( LL D, int U, int A, int B ): d( D ), u( U ), a( A ), b( B ) {}
	bool operator < ( const Node &g ) const { return ! ( d < g.d ); }
};

struct Edge
{
	int to, nxt; LL w;
}Graph[MAXN << 1];

std :: priority_queue<Node> q;

LL dist[MAXN][2][2];
bool vis[MAXN][2][2];

int head[MAXN];
int N, M, cnt;

void AddEdge( const int from, const int to, const int W )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	Graph[cnt].w = W, head[from] = cnt;
}

void Dijkstra()
{
	rep( i, 1, N ) rep( j, 0, 1 ) rep( k, 0, 1 )
		dist[i][j][k] = INF, vis[i][j][k] = false;
	q.push( Node( dist[1][0][0] = 0, 1, 0, 0 ) );
	while( ! q.empty() )
	{
		Node h = q.top(); q.pop();
		if( vis[h.u][h.a][h.b] ) continue;
		vis[h.u][h.a][h.b] = true; LL tmp;
		for( int i = head[h.u], v ; i ; i = Graph[i].nxt )
		{
			v = Graph[i].to;
			if( ! vis[v][h.a][h.b] && dist[v][h.a][h.b] > ( tmp = dist[h.u][h.a][h.b] + Graph[i].w ) )
				q.push( Node( dist[v][h.a][h.b] = tmp, v, h.a, h.b ) );
			if( ! h.a && ! vis[v][1][h.b] && dist[v][1][h.b] > ( tmp = dist[h.u][0][h.b] ) )
				q.push( Node( dist[v][1][h.b] = tmp, v, 1, h.b ) );
			if( ! h.b && ! vis[v][h.a][1] && dist[v][h.a][1] > ( tmp = dist[h.u][h.a][0] + 2 * Graph[i].w ) )
				q.push( Node( dist[v][h.a][1] = tmp, v, h.a, 1 ) );
			if( ! h.a && ! h.b && ! vis[v][1][1] && dist[v][1][1] > ( tmp = dist[h.u][0][0] + Graph[i].w ) )
				q.push( Node( dist[v][1][1] = tmp, v, 1, 1 ) );
		}
	}
}

int main()
{
	read( N ), read( M );
	rep( i, 1, M )
	{
		int u, v, w;
		read( u ), read( v ), read( w );
		AddEdge( u, v, w ), AddEdge( v, u, w );
	}
	Dijkstra();
	rep( i, 2, N ) write( dist[i][1][1] ), putchar( i == N ? '\n' : ' ' );
	return 0;
}