#include <cstdio>

const int MAXN = 2e5 + 5, MAXM = 5e5 + 5;

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
}Graph[MAXM << 1];

int DFN[MAXN], LOW[MAXN], col[MAXN];
int head[MAXN];
int N, M, A, B, ID, cnt;
bool isCut[MAXN], visited[MAXN];

void addEdge( const int from, const int to )
{
	cnt ++;
	Graph[cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void Tarjan( const int u, const int faU )
{
	int v, ccnt = 0;
	DFN[u] = LOW[u] = ++ ID;
	for( int i = head[u] ; i ; i = Graph[i].nxt )
	{
		if( ! DFN[v = Graph[i].to] )	
		{
			ccnt ++; Tarjan( v, u );
			if( LOW[v] >= DFN[u] ) isCut[u] = true;
			LOW[u] = MIN( LOW[u], LOW[v] );
		}
		else if( DFN[v] < DFN[u] && v ^ faU ) LOW[u] = MIN( LOW[u], DFN[v] );
	} 
	if( ! faU && ccnt == 1 ) isCut[u] = false;
}

void DFS( const int u, const int color )
{
	visited[u] = true, col[u] += color;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ! visited[v = Graph[i].to] ) 
			DFS( v, color );
}

int main()
{
	int T, sza, szb;
	read( T );
	while( T -- )
	{
		read( N ), read( M ), read( A ), read( B );
		cnt = 0; for( int i = 1 ; i <= N ; i ++ ) col[i] = DFN[i] = LOW[i] = head[i] = 0;
		for( int i = 1, u, v ; i <= M ; i ++ )
			read( u ), read( v ), addEdge( u, v ), addEdge( v, u );
		Tarjan( 1, 0 );
		if( ! ( isCut[A] && isCut[B] ) ) { puts( "0" ); continue; }
		for( int i = 1 ; i <= N ; i ++ ) visited[i] = false;
		visited[B] = visited[A] = true;
		for( int i = head[A] ; i ; i = Graph[i].nxt )
			if( ! visited[Graph[i].to] )
				DFS( Graph[i].to, 1 );
		for( int i = 1 ; i <= N ; i ++ ) visited[i] = false;
		visited[A] = visited[B] = true;
		for( int i = head[B] ; i ; i = Graph[i].nxt )
			if( ! visited[Graph[i].to] )
				DFS( Graph[i].to, 2 );
		sza = 0, szb = 0;
		for( int i = 1 ; i <= N ; i ++ ) sza += col[i] == 1, szb += col[i] == 2;
		write( 1ll * sza * szb ), putchar( '\n' );
	}
	return 0;
}
/*
1
4 3 2 1
1 2
2 3
4 1
*/