#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 5;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

struct edge
{
	int to, nxt;
}Graph[MAXN << 1];

vector<int> f[MAXN];
int head[MAXN], height[MAXN], heavy[MAXN], ans[MAXN];
int N, cnt;

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void init( const int u, const int fa )
{
	heavy[u] = -1, height[u] = 0;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
		{
			init( v, u );
			height[u] = MAX( height[u], height[v] + 1 );
			if( heavy[u] == -1 || height[heavy[u]] < height[v] ) heavy[u] = v;
		}
}

void DFS( const int u, const int fa )
{
	if( ~ heavy[u] ) DFS( heavy[u], u ), f[u].swap( f[heavy[u]] ), ans[u] = ans[heavy[u]];
	f[u].push_back( 1 );
	if( f[u][ans[u]] == 1 ) ans[u] = height[u];
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && v ^ heavy[u] )
		{
			DFS( v, u );
			for( int i = 0, pos ; i <= height[v] ; i ++ )
			{
				pos = height[u] - ( height[v] - i + 1 );
				f[u][pos] += f[v][i];
				if( f[u][ans[u]] <= f[u][pos] ) ans[u] = pos;
			}
		}
}

int main()
{
	read( N );
	for( int i = 1, a, b ; i < N ; i ++ ) read( a ), read( b ), addEdge( a, b ), addEdge( b, a );
	init( 1, 0 );
	DFS( 1, 0 );
	for( int i = 1 ; i <= N ; i ++ ) write( height[i] - ans[i] ), putchar( '\n' );
	return 0;
}