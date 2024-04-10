#include <cstdio>
#include <algorithm>

typedef long long LL;

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

struct Edge
{
	int u, v, w;
	Edge() { u = v = w = 0; }
	Edge( int U, int V, int W ) { u = U, v = V, w = W; }
	bool operator < ( const Edge &b ) const { return w > b.w; }
};

Edge E[MAXN];

int fa[MAXN];
int a[MAXN], b[MAXN];
int N, M, cnt;

void MakeSet( const int siz ) { for( int i = 1 ; i <= siz ; i ++ ) fa[i] = i; }
int FindSet( const int u ) { return fa[u] = ( fa[u] == u ? u : FindSet( fa[u] ) ); }

bool UnionSet( int u, int v )
{
	u = FindSet( u ), v = FindSet( v );
	if( u == v ) return false; fa[u] = v; return true;
}

int main()
{
	LL su = 0;
	read( M ), read( N );
	for( int i = 1 ; i <= M ; i ++ ) read( a[i] );
	for( int i = 1 ; i <= N ; i ++ ) read( b[i] );
	for( int i = 1 ; i <= M ; i ++ )
	{
		int s; read( s );
		while( s -- )
		{
			int u; read( u );
			E[++ cnt] = Edge( u + M, i, a[i] + b[u] );
			su += a[i] + b[u];
		}
	}
	LL MST = 0;
	MakeSet( N + M );
	std :: sort( E + 1, E + 1 + cnt );
	for( int i = 1 ; i <= cnt ; i ++ )
		if( UnionSet( E[i].u, E[i].v ) )
			MST += E[i].w;
	write( su - MST ), putchar( '\n' );
	return 0;
}