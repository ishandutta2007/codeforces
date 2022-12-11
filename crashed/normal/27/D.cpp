#include <cstdio>

const int MAXN = 205, MAXE = 1e4 + 5;

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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct edge
{
	int to, nxt;
}Graph[MAXE];

int sta[MAXN], top;
int head[MAXN], DFN[MAXN], LOW[MAXN], bel[MAXN];
int lef[MAXN], rig[MAXN];
int N, M, cnt, tot, ID;
bool inSta[MAXN];

bool junc( const int l1, const int r1, const int l2, const int r2 )
{ return ( l1 < l2 && l2 < r1 && r1 < r2 ) || ( l2 < l1 && l1 < r2 && r2 < r1 ); }

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void addE( const int from, const int to ) { addEdge( from, to ), addEdge( to, from ); }

void Tarjan( const int u )
{
	DFN[u] = LOW[u] = ++ ID;
	inSta[sta[++ top] = u] = true;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
	{
		if( ! DFN[v = Graph[i].to] ) Tarjan( v ), LOW[u] = MIN( LOW[u], LOW[v] );
		else if( inSta[v] ) LOW[u] = MIN( LOW[u], DFN[v] );
	}
	if( LOW[u] == DFN[u] )
	{
		int v; tot ++;
		do inSta[v = sta[top --]] = false, bel[v] = tot;
		while( u ^ v );
	}
}

int main()
{
	read( N ), read( M );
	for( int i = 1 ; i <= M ; i ++ )
	{
		read( lef[i] ), read( rig[i] );
		if( lef[i] > rig[i] ) rig[i] ^= lef[i], lef[i] ^= rig[i], rig[i] ^= lef[i];
		for( int j = 1 ; j < i ; j ++ )
			if( junc( lef[i], rig[i], lef[j], rig[j] ) )
				addE( i, j + M ), addE( j, i + M );
	}
	for( int i = 1 ; i <= M << 1 ; i ++ ) if( ! DFN[i] ) Tarjan( i );
	for( int i = 1 ; i <= M ; i ++ ) if( bel[i] == bel[i + M] ) { puts( "Impossible" ); return 0; }
	for( int i = 1 ; i <= M ; i ++ )
	{
		if( bel[i] < bel[i + M] ) putchar( 'i' );
		else putchar( 'o' );
	}
	puts( "" );
	return 0;
}