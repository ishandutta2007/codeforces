#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXN = 5e5 + 5, MAXS = ( 1 << 22 ) + 5;

template<typename _T>
inline void Read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
inline void Write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) Write( x / 10 );
	putchar( x % 10 + '0' );
}

struct Edge {
	int to, nxt, w;
} Graph[MAXN << 1];

int stk[MAXN], top;
int buc[MAXS], res;

int wei[MAXN], dep[MAXN], ans[MAXN];
int head[MAXN], siz[MAXN], heavy[MAXN], cnt = 1;

int N;

inline void AddEdge( const int &from, const int &to, const int &W ) {
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	Graph[cnt].w = W, head[from] = cnt;
}

void DFS1( const int &u, const int &fa ) {
	heavy[u] = 0, siz[u] = 1, dep[u] = dep[fa] + 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa ) {
			wei[v] = wei[u] ^ Graph[i].w;
			DFS1( v, u ), siz[u] += siz[v];
			if( siz[heavy[u]] < siz[v] ) heavy[u] = v;
		}
}

inline void Query( const int &x, const int &v ) {
	res = std :: max( res, buc[x] + v );
	rep( i, 0, 21 ) res = std :: max( res, buc[x ^ ( 1 << i )] + v );
}

inline void Update( const int &x, const int &v ) {
	buc[x] = std :: max( buc[x], v );
}

void Obtain( const int &u, const int &fa, const int &sub ) {
	stk[++ top] = u, Query( wei[u], - sub * 2 + dep[u] );
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa ) Obtain( v, u, sub );
}

void Erase( const int &u, const int &fa ) {
	buc[wei[u]] = - INF;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa ) Erase( v, u );
}

void DFS2( const int &u, const int &fa, const bool &typ ) {
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && v ^ heavy[u] )
			DFS2( v, u, false );
	if( heavy[u] ) DFS2( heavy[u], u, true );
	res = 0, Query( wei[u], - dep[u] ), Update( wei[u], dep[u] );
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && v ^ heavy[u] ) {
			top = 0, Obtain( v, u, dep[u] );
			for( ; top ; top -- ) Update( wei[stk[top]], dep[stk[top]] );
		}
	ans[u] = res;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa ) ans[u] = std :: max( ans[u], ans[v] );
	if( ! typ ) Erase( u, fa );
}

int main() {
	Read( N );
	rep( i, 2, N ) {
		int p; char buf[10];
		Read( p ), scanf( "%s", buf );
		AddEdge( i, p, 1 << ( buf[0] - 'a' ) );
		AddEdge( p, i, 1 << ( buf[0] - 'a' ) );
	}
	rep( i, 0, ( 1 << 22 ) - 1 ) buc[i] = - INF;
	DFS1( 1, 0 );
	DFS2( 1, 0, true );
	rep( i, 1, N ) Write( ans[i] ), putchar( " \n"[i == N] );
	return 0;
}