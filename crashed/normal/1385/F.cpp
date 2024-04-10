#include <cstdio>

const int MAXN = 2e5 + 5;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

struct Edge
{
	int to, nxt;
}Graph[MAXN << 1];

int f[MAXN], g[MAXN], su[MAXN], son[MAXN];
int head[MAXN];
int N, K, cnt, ans;

void Clean()
{
	ans = cnt = 0;
	for( int i = 1 ; i <= N ; i ++ ) 
		head[i] = f[i] = g[i] = su[i] = son[i] = 0;
}

void AddEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void Upt( const int u ) { g[u] += su[u] / K, f[u] = su[u] == son[u] && su[u] % K == 0; }

void DFS1( const int u, const int fa )
{
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			DFS1( v, u ), su[u] += f[v], son[u] ++, g[u] += g[v];
	Upt( u );
}

void DFS2( const int u, const int fa )
{
	ans = MAX( ans, g[u] );
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
		{
			g[u] -= su[u] / K, su[u] -= f[v], son[u] --, g[u] -= g[v], Upt( u );
			g[v] -= su[v] / K, su[v] += f[u], son[v] ++, g[v] += g[u], Upt( v );
			DFS2( v, u );
			g[v] -= su[v] / K, su[v] -= f[u], son[v] --, g[v] -= g[u], Upt( v );
			g[u] -= su[u] / K, su[u] += f[v], son[u] ++, g[u] += g[v], Upt( u );
		}
}

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		read( N ), read( K ), Clean();
		for( int i = 1, a, b ; i < N ; i ++ )
			read( a ), read( b ), AddEdge( a, b ), AddEdge( b, a );
		DFS1( 1, 0 ); 
		DFS2( 1, 0 );
		write( ans ), putchar( '\n' );
	}
	return 0;
}