#include <cstdio>

typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 205;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ); s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct Edge
{
	int to, nxt, c, w;
}Graph[MAXN * MAXN * 2];

int q[MAXN * MAXN];

LL dist[MAXN];
int head[MAXN], cur[MAXN];

int a[MAXN], b[MAXN];

int N, K, tot, cnt;
bool vis[MAXN], inQ[MAXN];

void AddEdge( const int from, const int to, const int C, const int W )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	Graph[cnt].c = C, Graph[cnt].w = W;
	head[from] = cnt;
}

void AddE( const int from, const int to, const int C, const int W )
{
	AddEdge( from, to, C, W ), AddEdge( to, from, 0, -W );
//	printf( "%d -> %d: c= %d, w= %d\n", from, to, C, W );
}

bool SPFA( const int S, const int T )
{
	int h = 1, t = 0, u, v;
	for( int i = 1 ; i <= tot ; i ++ ) inQ[i] = false, dist[i] = INF;
	dist[q[++ t] = S] = 0, inQ[S] = true;
	while( h <= t )
	{
		u = q[h ++], inQ[u] = false;
		for( int i = head[u], w ; i ; i = Graph[i].nxt )
		{
			v = Graph[i].to, w = Graph[i].w;
			if( Graph[i].c && dist[v] > dist[u] + w )
			{
				dist[v] = dist[u] + w;
				if( ! inQ[v] ) q[++ t] = v, inQ[v] = true;
			}
		}
	}
	return dist[T] < INF;
}

int DFS( const int u, const int lin, const int T, LL &cost )
{
	if( u == T ) return lin;
	int ret, used = 0, v, c, w; vis[u] = true;
	for( int &i = cur[u] ; i ; i = Graph[i].nxt )
	{
		v = Graph[i].to, c = Graph[i].c, w = Graph[i].w;
		if( c && ! vis[v] && dist[v] == dist[u] + w && ( ret = DFS( v, MIN( lin - used, c ), T, cost ) ) )
		{
			cost += 1ll * ret * Graph[i].w;
			used += ret, Graph[i].c -= ret, Graph[i ^ 1].c += ret;
			// printf( "cur: %d; oppo: %d\n", Graph[i].c, Graph[i ^ 1].c );
			if( used == lin ) break;
		}
	}
	vis[u] = false;
	if( used < lin ) dist[u] = INF;
	return used; 
}

LL Dinic( const int S, const int T )
{
	LL ret = 0;
	while( SPFA( S, T ) )
	{
		// for( int i = 1 ; i <= tot ; i ++ ) write( dist[i] ), putchar( i == tot ? '\n' : ' ' );
		for( int i = 1 ; i <= tot ; i ++ ) vis[i] = false, cur[i] = head[i];
		DFS( S, 0x3f3f3f3f, T, ret );
		// printf( "current cost: %lld\n", ret );
	}
	return ret;
}

void Clean()
{
	cnt = 1;
	for( int i = 0 ; i <= tot ; i ++ )
		q[i] = head[i] = 0, vis[i] = inQ[i] = false;
	tot = 0;
}

void Build()
{
	tot = 2 * N;
	const int S = ++ tot, T = ++ tot;
	for( int i = 1 ; i <= N ; i ++ )
		AddE( S, i, 1, 0 ), AddE( i + N, T, 1, 0 );
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 1 ; j <= N ; j ++ )
		{
			int w;
			if( j <= K ) w = - ( a[i] + b[i] * ( j - 1 ) );
			else w = - b[i] * ( K - 1 );
			AddE( i, j + N, 1, w );
		}
}

void FindAndPrint( const int u, const bool f )
{
	int tar = 0;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
	{
		// printf( "Current edge: %d -> %d, c = %d\n", u, Graph[i].to, Graph[i].c );
		if( ( v = Graph[i].to ) <= N && Graph[i].c )
			{ tar = v; break; }
	}
	printf( "%d ", tar );
	if( f ) printf( "%d ", -tar );
}

int main()
{
	int T;
	read( T );
	for( int cas = 1 ; cas <= T ; cas ++ )
	{
		// printf( "\nCase #%d: Processing\n", cas );
		read( N ), read( K ), Clean();
		for( int i = 1 ; i <= N ; i ++ ) read( a[i] ), read( b[i] );
		Build();

		Dinic( 2 * N + 1, 2 * N + 2 );
		printf( "%d\n", ( N - K ) * 2 + K );
		for( int i = 1 ; i < K ; i ++ ) FindAndPrint( i + N, 0 );
		for( int i = K + 1 ; i <= N ; i ++ ) FindAndPrint( i + N, 1 );
		FindAndPrint( K + N, 0 ), putchar( '\n' );
	}
	return 0;
}