#include <cstdio>
#include <cstdlib>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 3e5 + 5;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

struct Edge {
	int to, nxt;
} Graph[MAXN << 1];

int tag[MAXN], val[MAXN], lim[MAXN];
int lch[MAXN], rch[MAXN], dist[MAXN];
int ntot;

int head[MAXN], dep[MAXN], cnt = 1;
int rt[MAXN];

LL ans = 0;
int N, M;

inline void AddEdge( const int &from, const int &to ) {
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

inline void Add( const int &x, const int &delt ) {
	if( x ) val[x] += delt, tag[x] += delt;
}

inline void Normalize( const int &x ) {
	if( ! x || ! tag[x] ) return ;
	Add( lch[x], tag[x] );
	Add( rch[x], tag[x] );
	tag[x] = 0;
}

int Merge( int u, int v ) {
	if( ! u || ! v ) return u | v;
	if( val[u] > val[v] ) std :: swap( u, v );
	Normalize( u );
	rch[u] = Merge( rch[u], v );
	if( dist[lch[u]] < dist[rch[u]] )
		std :: swap( lch[u], rch[u] );
	dist[u] = dist[rch[u]] + 1;
	return u;
}

inline void Pop( int &u ) {
	Normalize( u ), u = Merge( lch[u], rch[u] );
}

void Init( const int &u, const int &fa ) {
	dep[u] = dep[fa] + 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			Init( v, u );
}

void DFS( const int &u, const int &fa ) {
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			DFS( v, u ), rt[u] = Merge( rt[u], rt[v] );
	if( fa ) {
		while( rt[u] && lim[rt[u]] >= dep[u] ) 
			Pop( rt[u] );
		if( ! rt[u] ) {
			puts( "-1" );
			exit( 0 );
		}
		ans += val[rt[u]], Add( rt[u], - val[rt[u]] );
	}
}

int main() {
	read( N ), read( M );
	rep( i, 1, N - 1 ) {
		int u, v; read( u ), read( v );
		AddEdge( u, v ), AddEdge( v, u );
	}
	Init( 1, 0 );
	rep( i, 1, M ) {
		int u, v, c;
		read( u ), read( v ), read( c );
		val[i] = c, lim[i] = dep[v];
		rt[u] = Merge( rt[u], i );
	}
	DFS( 1, 0 );
	write( ans ), putchar( '\n' );
	return 0;
}