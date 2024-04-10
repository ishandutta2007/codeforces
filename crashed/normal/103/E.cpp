#include <cstdio>

typedef long long LL;

const int INF = 0x3f3f3f3f, SMA = 5e7;
const int MAXN = 2e5 + 5, MAXM = 2e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct Edge
{
	int to, nxt, c;
}Graph[MAXM << 1];

int q[MAXN];

int head[MAXN], dep[MAXN], cur[MAXN];
int N, cnt = 1, tot;

void AddEdge( const int from, const int to, const int C )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	Graph[cnt].c = C, head[from] = cnt;
}

void AddE( const int from, const int to, const int C ) { AddEdge( from, to, C ), AddEdge( to, from, 0 ); }

bool BFS( const int S, const int T )
{
	int h = 1, t = 0, u, v;
	for( int i = 1 ; i <= tot ; i ++ ) dep[i] = INF;
	dep[q[++ t] = S] = 0;
	while( h <= t )
	{
		u = q[h ++];
		for( int i = head[u] ; i ; i = Graph[i].nxt )
			if( Graph[i].c && dep[v = Graph[i].to] > dep[u] + 1 )
				dep[q[++ t] = v] = dep[u] + 1;
	}
	return dep[T] < INF;
}

int DFS( const int u, const int lin, const int T )
{
	if( u == T ) return lin;
	int used = 0, ret, v, c;
	for( int &i = cur[u] ; i ; i = Graph[i].nxt )
	{
		v = Graph[i].to, c = Graph[i].c;
		if( dep[v] == dep[u] + 1 && c && ( ret = DFS( v, MIN( lin - used, c ), T ) ) )
		{
			used += ret, Graph[i].c -= ret, Graph[i ^ 1].c += ret;
			if( used == lin ) break;
		}
	}
	if( used < lin ) dep[u] = INF;
	return used;
}

int Dinic( const int S, const int T )
{
	int f = 0;
	while( BFS( S, T ) )
	{
		for( int i = 1 ; i <= tot ; i ++ ) cur[i] = head[i];
		f += DFS( S, INF, T );
	}
	return f;
}

int main()
{
	read( N ), tot = N << 1;
	const int s = ++ tot, t = ++ tot;
	for( int i = 1, m ; i <= N ; i ++ )
	{
		read( m );
		for( int to ; m -- ; )
			read( to ), AddE( i, to + N, INF );
	}
	int ans = 0;
	for( int i = 1, v ; i <= N ; i ++ )
	{
		read( v ), ans += ( v = SMA - v );
		AddE( s, i, v ), AddE( i + N, t, SMA );
	}
	write( MIN( 0, Dinic( s, t ) - ans ) ), putchar( '\n' );
	return 0;
}