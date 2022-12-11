#include <set>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5;

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

std :: set<int> adj[MAXN];

int N, M, ans = 0;

inline bool Chk( const int u )
{
	return adj[u].empty() || *adj[u].rbegin() < u;
}

void AddEdge( const int u, const int v )
{
	ans -= Chk( u ) + Chk( v );
	adj[u].insert( v );
	adj[v].insert( u );
	ans += Chk( u ) + Chk( v );
}

void DelEdge( const int u, const int v )
{
	ans -= Chk( u ) + Chk( v );
	adj[u].erase( adj[u].find( v ) );
	adj[v].erase( adj[v].find( u ) );
	ans += Chk( u ) + Chk( v );
}

int main()
{
	read( N ), read( M );
	rep( i, 1, M )
	{
		int u, v;
		read( u ), read( v );
		adj[u].insert( v ), adj[v].insert( u );
	}
	rep( i, 1, N ) ans += Chk( i );
	int Q, opt, A, B; read( Q );
	while( Q -- )
	{
		read( opt );
		if( opt == 1 ) read( A ), read( B ), AddEdge( A, B );
		if( opt == 2 ) read( A ), read( B ), DelEdge( A, B );
		if( opt == 3 ) write( ans ), putchar( '\n' );
	}
	return 0;
}