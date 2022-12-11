#include <cstdio>

typedef long long LL;

const int MAXN = 1e5 + 5;

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
	int to, nxt;
}Graph[MAXN << 1];

LL w[MAXN];
int siz[MAXN], tot[MAXN];
int head[MAXN], fath[MAXN], dep[MAXN];
LL ans;
int N, Q, cnt;

namespace dsu
{
	int fa[MAXN];
	void makeSet( const int n ) { for( int i = 1 ; i <= n ; i ++ ) fa[i] = i; }
	int findSet( const int u ) { return fa[u] = ( u == fa[u] ? u : findSet( fa[u] ) ); }
	void unionSet( const int u, const int v ) { fa[findSet( u )] = findSet( v ); }
}

LL sqr( LL x ) { return x * x; }

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void init( const int u, const int fa )
{
	fath[u] = fa, tot[u] = siz[u] = 1, dep[u] = dep[fa] + 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			init( v, u ), siz[u] += siz[v], w[u] += sqr( siz[v] );
	w[u] += sqr( N - siz[u] ), ans += sqr( N - 1 ) - w[u];
}

LL contribute( const int u )
{
	LL ret = 0;
	ret += 1ll * tot[u] * ( tot[u] - 1 ) * ( tot[u] - 2 );
	ret += 2ll * tot[u] * ( tot[u] - 1 ) * ( N - tot[u] );
	ret += 1ll * tot[u] * ( sqr( N - tot[u] ) - w[u] );
	return ret;
}

void merg( int u ) // u  fath[u]  
{
	int v = dsu :: findSet( fath[u] );
	ans -= contribute( u ) + contribute( v );
	
	tot[v] += tot[u];
	w[v] += w[u] - sqr( N - siz[u] ) - sqr( siz[u] );
	ans += contribute( v );
	dsu :: unionSet( u, v );
}

void update( int u, int v )
{
	u = dsu :: findSet( u ), v = dsu :: findSet( v );
	while( u ^ v )
	{
		if( dep[u] > dep[v] ) 
			merg( u ), 
			u = dsu :: findSet( u );
		else 
			merg( v ), 
			v = dsu :: findSet( v );
	}
}

int main()
{
	read( N );
	for( int i = 1, a, b ; i < N ; i ++ )
		read( a ), read( b ), addEdge( a, b ), addEdge( b, a );
	init( 1, 0 ), dsu :: makeSet( N );
	write( ans ), putchar( '\n' );
	read( Q );
	int x, y;
	while( Q -- )
	{
		read( x ), read( y );
		update( x, y );
		write( ans ), putchar( '\n' );
	}
	return 0;
}