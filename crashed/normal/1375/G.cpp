#include <cstdio>

const int MAXN = 2e5 + 5;

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

struct Edge
{
	int to, nxt;
}Graph[MAXN << 1];

int tot[2];
int head[MAXN];
int N, cnt;

void AddEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void DFS( const int u, const int fa, const int dep )
{
	tot[dep & 1] ++;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			DFS( v, u, dep + 1 );
}

int main()
{
	read( N );
	for( int i = 1, a, b ; i < N ; i ++ )
		read( a ), read( b ), AddEdge( a, b ), AddEdge( b, a );
	DFS( 1, 0, 0 );
	write( MIN( tot[0] - 1, tot[1] - 1 ) ), putchar( '\n' );
	return 0;
}