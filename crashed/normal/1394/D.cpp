#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 2e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 1 ) + ( x << 3 ) + s - '0', s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) { putchar( '-' ), x = -x; }
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

struct Edge
{
	int to, nxt;
}Graph[MAXN << 1];

vector<LL> vec[MAXN];

LL f[MAXN][2];

int head[MAXN], a[MAXN], b[MAXN];
int N, cnt; LL ans = 0x3f3f3f3f3f3f3f3f;

void AddEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void DFS1( const int u, const int fa )
{
	LL base = 0, in = 0, out = 0;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
		{
			DFS1( v, u );
			if( b[u] == b[v] ) base += f[v][0], vec[u].push_back( f[v][1] - f[v][0] ), out ++;
			if( b[v] < b[u] ) in ++, base += f[v][1];
			if( b[v] > b[u] ) out ++, base += f[v][0];
		}
	sort( vec[u].begin(), vec[u].end() );
	f[u][0] = f[u][1] = 0x3f3f3f3f3f3f3f3f;
	for( int i = 0 ; i <= ( int ) vec[u].size() ; i ++ )
	{
		f[u][0] = MIN( f[u][0], base + 1ll * MAX( out, in + bool( fa ) ) * a[u] );
		f[u][1] = MIN( f[u][1], base + 1ll * MAX( out + bool( fa ), in ) * a[u] );
		out --, in ++; if( i < ( int ) vec[u].size() ) base += vec[u][i];
	}
}

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	for( int i = 1 ; i <= N ; i ++ ) read( b[i] );
	for( int i = 1, a, b ; i < N ; i ++ )
		read( a ), read( b ), AddEdge( a, b ), AddEdge( b, a );
	DFS1( 1, 0 ); 
	write( MIN( f[1][0], f[1][1] ) ), putchar( '\n' );
	return 0;
}