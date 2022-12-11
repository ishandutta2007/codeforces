#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5 + 5, MAXM = 6e5 + 5, MAXLOG = 20;

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

struct edge
{
	int to, nxt, w;
}Graph[MAXM];

struct Edge
{
	int u, v, w;
}E[MAXM];

struct node
{
	int u; LL d;
	node() { u = d = 0; }
	node( const int U, const int D ) { u = U, d = D; }
	bool operator < ( const node &b ) const { return ! ( d < b.d ); }
};

priority_queue<node> pq;

LL dist[MAXN];
int f[MAXN][MAXLOG];
int dep[MAXN], tmp[MAXN], siz[MAXN];
int head[MAXN], into[MAXN];
int q[MAXN];
int N, M, S, lg2, base, cnt;
bool vis[MAXN];

void addEdge( const int from, const int to, const int w = 0 )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from], Graph[cnt].w = w;
	head[from] = cnt, into[to] ++;
}

void Dijkstra()
{
	for( int i = 1 ; i <= N ; i ++ ) dist[i] = INF, vis[i] = false;
	pq.push( node( S, dist[S] = 0 ) );
	while( ! pq.empty() )
	{
		int u = pq.top().u; pq.pop();
		if( vis[u] ) continue; vis[u] = false;
		for( int i = head[u], v, w ; i ; i = Graph[i].nxt )
			if( ! vis[v = Graph[i].to] && dist[v] > dist[u] + ( w = Graph[i].w ) )
				pq.push( node( v, dist[v] = dist[u] + w ) );
	}
}

void balance( int &u, const int stp )
{
	for( int i = 0 ; 1 << i <= stp ; i ++ )
		if( stp >> i & 1 )
			u = f[u][i];
}

int LCA( int u, int v )
{
	if( dep[u] > dep[v] ) balance( u, dep[u] - dep[v] );
	if( dep[v] > dep[u] ) balance( v, dep[v] - dep[u] );
	if( u == v ) return u;
	for( int i = lg2 ; ~ i ; i -- ) if( f[u][i] ^ f[v][i] ) u = f[u][i], v = f[v][i];
	return f[u][0];
}

void Insert( const int u, const int fa )
{
	dep[u] = dep[fa] + 1, f[u][0] = fa;
	for( int j = 1 ; j <= lg2 ; j ++ )
	 	f[u][j] = f[f[u][j - 1]][j - 1];
}

void clear()
{
	cnt = 0;
	memset( into, 0, sizeof into );
	memset( head, 0, sizeof head );
}

void DFS( const int u )
{
	siz[u] = 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		DFS( v = Graph[i].to ), siz[u] += siz[v];
}

void build()
{
	clear(), lg2 = log2( N );
	for( int i = 1 ; i <= N ; i ++ )
		if( dist[i] == INF )
			base ++;
	for( int i = 1 ; i <= M ; i ++ )
	{
		if( dist[E[i].v] == dist[E[i].u] + E[i].w )
			addEdge( E[i].u, E[i].v );
		if( dist[E[i].u] == dist[E[i].v] + E[i].w )
			addEdge( E[i].v, E[i].u );
	}
	int h = 1, t = 0, u, v; q[++ t] = S;
	while( h <= t )
	{
		u = q[h ++];
		for( int i = head[u] ; i ; i = Graph[i].nxt )
		{
			v = Graph[i].to;
			if( ! tmp[v] ) tmp[v] = u;
			else tmp[v] = LCA( tmp[v], u );
			if( ! ( -- into[v] ) ) q[++ t] = v, Insert( v, tmp[v] );
		}
	}
	clear();
	for( int i = 1 ; i <= N ; i ++ )
		addEdge( f[i][0], i );
	DFS( S );
}

int main()
{
	read( N ), read( M ), read( S );
	for( int i = 1 ; i <= M ; i ++ )
		read( E[i].u ), read( E[i].v ), read( E[i].w ),
		addEdge( E[i].u, E[i].v, E[i].w ),
		addEdge( E[i].v, E[i].u, E[i].w );
	Dijkstra(), build();
	int ans = 0;
	for( int i = 1 ; i <= N ; i ++ )
		if( ans < siz[i] && i ^ S ) ans = siz[i];
	write( ans ), putchar( '\n' );
	return 0;
}