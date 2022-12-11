#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 5e5 + 5, MAXM = 1e6 + 5;

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

struct Edge
{
	int to, nxt;
}Graph[MAXM << 1];

vector<int> point[MAXN];

int q[MAXN];

int dep[MAXN];
int head[MAXN];
int N, M, cnt;
bool onT[MAXM];

void AddEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void Init()
{
	cnt = 1;
	for( int i = 1 ; i <= N ; i ++ )
		head[i] = dep[i] = 0, point[i].clear();
	for( int i = 1 ; i <= M ; i ++ )
		onT[i] = false;
}

void DFS( const int u, const int fa )
{
	dep[u] = dep[fa] + 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ! dep[v = Graph[i].to] )
			onT[i >> 1] = true, DFS( v, u );
	point[dep[u]].push_back( u );
}

int BFS( const int sta )
{
	int h = 1, t = 0, u, v;
	for( int i = 1 ; i <= N ; i ++ ) dep[i] = -1;
	dep[q[++ t] = sta] = 0;
	
	while( h <= t )
	{
		u = q[h ++];
		for( int i = head[u] ; i ; i = Graph[i].nxt )
			if( onT[i >> 1] && dep[v = Graph[i].to] < 0 )
				dep[q[++ t] = v] = dep[u] + 1;
	}
	
	int ret = 1;
	for( int i = 2 ; i <= N ; i ++ )
		if( dep[i] > dep[ret] ) ret = i;
	return ret;
}

bool PathOutput( const int u, const int fa, const int T )
{
	if( u == T ) { write( u ), putchar( ' ' ); return true; }
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( onT[i >> 1] && ( v = Graph[i].to ) ^ fa )
			if( PathOutput( v, u, T ) )
				return write( u ), putchar( ' ' ), true;
	return false;
}

bool PathSolve()
{
	int u = BFS( 1 ), v = BFS( u );
	if( dep[v] >= ( N - 1 ) / 2 + 1 ) 
	{
		puts( "PATH" );
		write( dep[v] + 1 ), putchar( '\n' );
		PathOutput( u, 0, v ), puts( "" ); 
		return true;
	}
	return false;
}

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		read( N ), read( M ), Init();
		for( int i = 1, a, b ; i <= M ; i ++ )
			read( a ), read( b ), AddEdge( a, b ), AddEdge( b, a );
		DFS( 1, 0 );
		if( PathSolve() ) continue;
		puts( "PAIRING" ); int tot = 0;
		for( int i = 1 ; i <= N ; i ++ ) tot += ( int ) point[i].size() / 2;
		write( tot ), putchar( '\n' );
		for( int i = 1 ; i <= N ; i ++ )
			for( int k = 0 ; k + 1 < ( int ) point[i].size() ; k += 2 )
				write( point[i][k] ), putchar( ' ' ), write( point[i][k + 1] ), putchar( '\n' );
	}
	return 0;
}