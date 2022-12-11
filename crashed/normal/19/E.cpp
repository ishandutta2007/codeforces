#include <cmath>
#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e5 + 5, MAXLOG = 17;

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

struct Edge
{
	int to, nxt, id;
}Graph[MAXN << 1];

int fath[MAXN][MAXLOG];
int fr[MAXN], to[MAXN], count[MAXN];

int odd[MAXN], even[MAXN];
int oE[MAXN], eE[MAXN];

int head[MAXN], dep[MAXN];
int N, M, cnt = 1, tot, lg2;
bool onTre[MAXN], vis[MAXN];

namespace UFS
{
	int fa[MAXN];
	
	void MakeSet( const int n ) { rep( i, 1, n ) fa[i] = i; }
	int FindSet( const int u ) { return fa[u] = ( fa[u] == u ? u : FindSet( fa[u] ) ); }
	
	bool UnionSet( int u, int v )
	{
	u = FindSet( u ), v = FindSet( v );
	if( u == v ) return false; fa[u] = v; return true;
	}
}

void AddEdge( const int from, const int to, const int i )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	Graph[cnt].id = i, head[from] = cnt;
}

void DFS( const int u, const int fa )
{
	dep[u] = dep[fa] + 1, fath[u][0] = fa;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa ) DFS( v, u );
}

void Init()
{
	lg2 = log2( N );
	rep( i, 1, N ) if( ! dep[i] ) DFS( i, 0 );
	rep( j, 1, lg2 ) rep( i, 1, N ) fath[i][j] = fath[fath[i][j - 1]][j - 1];
}

void Balance( int &u, const int stp )
{
	for( int i = 0 ; ( 1 << i ) <= stp ; i ++ )
		if( stp >> i & 1 ) u = fath[u][i];
}

int LCA( int u, int v )
{
	if( dep[u] > dep[v] ) Balance( u, dep[u] - dep[v] );
	if( dep[v] > dep[u] ) Balance( v, dep[v] - dep[u] );
	if( u == v ) return u;
	per( i, lg2, 0 ) if( fath[u][i] ^ fath[v][i] ) u = fath[u][i], v = fath[v][i];
	return fath[u][0];
}

void DFS2( const int u, const int fa )
{
	vis[u] = true;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
		{
			DFS2( v, u ); 
			odd[u] += odd[v], even[u] += even[v];
			oE[Graph[i].id] += odd[v], eE[Graph[i].id] += even[v];
		}
}

int main()
{
	read( N ), read( M );
	UFS :: MakeSet( N );
	rep( i, 1, M )
	{
		int u, v;
		read( u ), read( v );
		if( UFS :: UnionSet( u, v ) )
			AddEdge( u, v, i ), AddEdge( v, u, i ), onTre[i] = true;
		fr[i] = u, to[i] = v;
	}
	Init();
	rep( i, 1, M ) if( ! onTre[i] )
	{
		int lca = LCA( fr[i], to[i] );
		int d = dep[fr[i]] + dep[to[i]] - 2 * dep[lca];
		if( ! ( d & 1 ) ) oE[i] ++, odd[fr[i]] ++, odd[to[i]] ++, odd[lca] -= 2, tot ++;
		else eE[i] ++, even[fr[i]] ++, even[to[i]] ++, even[lca] -= 2;
	}
	if( ! tot )
	{
		write( M ), putchar( '\n' );
		rep( i, 1, M ) write( i ), putchar( i == M ? '\n' : ' ' );
		return 0;
	}
	rep( i, 1, N ) if( ! vis[i] ) DFS2( i, 0 );
	int ans = 0;
	rep( i, 1, M ) ans += oE[i] == tot && ! eE[i];
	write( ans ), putchar( '\n' );
	rep( i, 1, M ) if( oE[i] == tot && ! eE[i] )
		write( i ), putchar( ' ' ); puts( "" );
	return 0;
}