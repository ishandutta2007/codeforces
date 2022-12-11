#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5, MAXE = 4e5 + 5;

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

struct Edge
{
	int to, nxt;
}Graph[MAXE << 1];

int bf[MAXN], gf[MAXN];
int q[MAXN];

int head[MAXN], col[MAXN];
int N, cnt;

void AddEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void AddE( const int from, const int to )
{ AddEdge( from, to ), AddEdge( to, from ); }

void Color( const int s )
{
	int h = 1, t = 0;
	col[q[++ t] = s] = 0;
	while( h <= t )
	{
		int u = q[h ++];
		for( int i = head[u], v ; i ; i = Graph[i].nxt )
			if( col[v = Graph[i].to] == -1 )
				col[q[++ t] = v] = col[u] ^ 1;
	}
}

int main()
{
	read( N );
	rep( i, 0, N - 1 ) AddE( 2 * i + 1, 2 * i + 2 );
	rep( i, 1, N ) read( bf[i] ), read( gf[i] ), AddE( bf[i], gf[i] );
	rep( i, 1, 2 * N ) col[i] = -1;
	rep( i, 1, 2 * N ) if( col[i] == -1 ) 
		Color( i );
	rep( i, 1, N ) 
		write( col[bf[i]] + 1 ), putchar( ' ' ), 
		write( col[gf[i]] + 1 ), putchar( '\n' );
	return 0;
}