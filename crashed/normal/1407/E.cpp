#include <cstdio>

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

struct Node
{
	int u, t;
	Node() { u = t = 0; }
	Node( int U, int T ) { u = U, t = T; }
};

struct Edge
{
	int to, nxt, c;
}Graph[MAXN];

Node q[MAXN];

int vis[MAXN], dist[MAXN][2];
int head[MAXN];
int N, M, cnt;

void AddEdge( const int from, const int to, const int c )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from], Graph[cnt].c = c;
	head[from] = cnt;
}

int main()
{
	read( N ), read( M );
	for( int i = 1, a, b, c ; i <= M ; i ++ )
		read( a ), read( b ), read( c ), AddEdge( b, a, c );
	int h = 1, t = 0, u, v; Node cur;
	for( int i = 1 ; i <= N ; i ++ ) dist[i][0] = dist[i][1] = INF;
	dist[N][0] = dist[N][1] = 0, q[++ t] = Node( N, 0 ), q[++ t] = Node( N, 1 );
	
	while( h <= t )
	{
		cur = q[h ++]; u = cur.u;
		if( vis[u] == 3 ) continue;
		vis[u] |= 1 << cur.t;
		if( vis[u] < 3 ) continue;
		int val = MAX( dist[u][0], dist[u][1] );
		for( int i = head[u], c ; i ; i = Graph[i].nxt )
		{
			c = Graph[i].c, v = Graph[i].to;
			if( ! ( vis[v] >> c & 1 ) && dist[v][c] > val + 1 )
				dist[v][c] = val + 1, q[++ t] = Node( v, c );
		}
	}
	
	int ans = MAX( dist[1][0], dist[1][1] );
	write( ans == INF ? -1 : ans ), putchar( '\n' );
	for( int i = 1 ; i <= N ; i ++ )
		write( dist[i][1] > dist[i][0] );
	puts( "" );
	return 0;
}