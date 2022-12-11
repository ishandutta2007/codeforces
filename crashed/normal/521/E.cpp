#include <set>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5;

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

std :: vector<int> tag[MAXN];
std :: vector<int> res, rt;

bool vis[MAXN];

int dep[MAXN], fath[MAXN];
bool tre[MAXN];

int head[MAXN], cnt = 1;

int N, M;

inline void AddEdge( const int &from, const int &to ) {
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void DFS( const int &u, const int &fa ) {
	dep[u] = dep[fath[u] = fa] + 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ! dep[v = Graph[i].to] )
			DFS( v, u ), tre[i >> 1] = true;
		else if( v ^ fa && dep[v] < dep[u] )
			tag[u].push_back( i >> 1 ),
			tag[v].push_back( - ( i >> 1 ) );
}

void Merge( std :: set<int> &a, std :: set<int> &b ) {
	if( a.size() < b.size() ) a.swap( b );
	for( const int &x : b ) a.insert( x );
	b.clear();
}

void PrintPath( const std :: vector<int> &p ) {
	int n = p.size();
	write( n ), putchar( ' ' );
	rep( i, 0, n - 1 ) write( p[i] ), putchar( " \n"[i == n - 1] );
}

std :: set<int> Find( const int &u, const int &fa ) {
	std :: set<int> cur, tmp;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( tre[i >> 1] && ( v = Graph[i].to ) ^ fa ) 
			Merge( cur, tmp = Find( v, u ) );
	for( const int &e : tag[u] )
		if( e < 0 ) cur.erase( - e );
		else cur.insert( e );
	if( cur.size() > 1u ) {
		puts( "YES" );
		int e1 = *cur.begin(), e2 = *cur.rbegin();
		int p1 = Graph[e1 << 1].to, q1 = Graph[e1 << 1 | 1].to,
			p2 = Graph[e2 << 1].to, q2 = Graph[e2 << 1 | 1].to;
		if( dep[p1] > dep[q1] ) std :: swap( p1, q1 );
		if( dep[p2] > dep[q2] ) std :: swap( p2, q2 );
		int s = dep[p1] < dep[p2] ? p2 : p1, t = 0;
		for( int x = q1, y = q2 ; x ^ y ; t = x )
			if( dep[x] > dep[y] ) x = fath[x];
			else y = fath[y];
		if( ! t ) t = q1;
		res.clear();
		for( int x = t ; x ^ s ; x = fath[x] )
			res.push_back( x );
		res.push_back( s );
		std :: reverse( res.begin(), res.end() );
		PrintPath( res ), res.clear();

		for( int x = s ; x ^ p1 ; x = fath[x] )
			res.push_back( x );
		res.push_back( p1 );
		for( int x = q1 ; x ^ t ; x = fath[x] )
			res.push_back( x );
		res.push_back( t );
		PrintPath( res ), res.clear();

		for( int x = s ; x ^ p2 ; x = fath[x] )
			res.push_back( x );
		res.push_back( p2 );
		for( int x = q2 ; x ^ t ; x = fath[x] )
			res.push_back( x );
		res.push_back( t );
		PrintPath( res ), res.clear();
		exit ( 0 );
	}
	return cur;
}

int main() {
	read( N ), read( M );
	rep( i, 1, M ) {
		int u, v; read( u ), read( v );
		AddEdge( u, v ), AddEdge( v, u );
	}
	rep( i, 1, N ) if( ! dep[i] )
		DFS( i, 0 ), rt.push_back( i );
	for( const int &r : rt )
		Find( r, 0 );
	puts( "NO" );
	return 0;
}