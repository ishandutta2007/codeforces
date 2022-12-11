#include <cmath>
#include <queue>
#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 4e5 + 5, MAXLOG = 19;

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
	LL d; int u, fr;
	
	Node(): d( INF ), u( 0 ), fr( 0 ) {}
	Node( LL D, int U, int F ): d( D ), u( U ), fr( F ) {}
	bool operator < ( const Node &g ) const { return ! ( d < g.d ); }
};

struct Edge
{
	int to, nxt, w;
}Graph[MAXN << 1];

struct KruEdge
{
	int u, v; LL w;	
	
	KruEdge(): u( 0 ), v( 0 ), w( 0 ) {}
	KruEdge( int U, int V, LL W ): u( U ), v( V ), w( W ) {}
	bool operator < ( const KruEdge &e ) const { return w < e.w; }
}edg[MAXN];

std :: priority_queue<Node> q;

int dep[MAXN], fath[MAXN][MAXLOG];
int fa[MAXN], lch[MAXN], rch[MAXN];
LL cost[MAXN];
int ID = 0;

int fr[MAXN], to[MAXN], wei[MAXN];

LL dist[MAXN];
int bel[MAXN];

int head[MAXN];
int N, M, K, Q, tot = 0, lg2, cnt = 0;

void AddEdge( const int from, const int to, const int W )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	Graph[cnt].w = W, head[from] = cnt;
}

void Dijkstra()
{
	rep( i, 1, N ) dist[i] = INF, bel[i] = 0;
	rep( i, 1, K ) q.push( Node( dist[i] = 0, i, i ) );
	while( ! q.empty() )
	{
		Node h = q.top(); q.pop();
		if( bel[h.u] ) continue; bel[h.u] = h.fr;
		for( int i = head[h.u], v ; i ; i = Graph[i].nxt )
			if( ! bel[v = Graph[i].to] && dist[v] > dist[h.u] + Graph[i].w )
				q.push( Node( dist[v] = dist[h.u] + Graph[i].w, v, h.fr ) );
	}
}

void MakeSet( const int n ) { rep( i, 1, n ) fa[i] = i; }
int FindSet( const int u ) { return fa[u] = ( fa[u] == u ? u : FindSet( fa[u] ) ); }

void Init( const int u )
{
	if( lch[u] ) dep[lch[u]] = dep[u] + 1, Init( lch[u] );
	if( rch[u] ) dep[rch[u]] = dep[u] + 1, Init( rch[u] );
}

void Init()
{
	Init( ID ), lg2 = log2( ID );
	rep( j, 1, lg2 ) rep( i, 1, ID )
		fath[i][j] = fath[fath[i][j - 1]][j - 1];
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

int main()
{
	read( N ), read( M ), read( K ), read( Q );
	rep( i, 1, M ) 
	{
		int u, v, w;
		read( u ), read( v ), read( w );
		AddEdge( u, v, w ), AddEdge( v, u, w );
		fr[i] = u, to[i] = v, wei[i] = w;
	}
	Dijkstra();
	rep( i, 1, M ) if( bel[fr[i]] ^ bel[to[i]] )
		edg[++ tot] = KruEdge( bel[fr[i]], bel[to[i]], dist[fr[i]] + dist[to[i]] + wei[i] );
//	if( Q == 300000 ) write( tot ), putchar( '\n' );
	std :: sort( edg + 1, edg + 1 + tot ), MakeSet( K + tot ), ID = K;
	rep( i, 1, tot )
	{
		int u = FindSet( edg[i].u ), 
			v = FindSet( edg[i].v );
		if( u ^ v )
		{
			cost[++ ID] = edg[i].w;
			lch[ID] = u, rch[ID] = v;
			fath[u][0] = fath[v][0] = ID;
			fa[u] = fa[v] = ID;
		}
	}
//	if( Q == 300000 ) write( ID ), putchar( '\n' );
	Init();
	while( Q -- )
	{
		int u, v;
		read( u ), read( v );
		write( cost[LCA( u, v )] ), putchar( '\n' );
	}
	return 0;
}