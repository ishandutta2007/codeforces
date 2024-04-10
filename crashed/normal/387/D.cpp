#include <cstdio>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5, MAXM = 1e5 + 5;
const int MAXS = 5e2 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct Edge
{
	int to, nxt, c;
}Graph[MAXM << 1];

int q[MAXN];

vector<int> G[MAXS];

int head[MAXN], dep[MAXN], cur[MAXN];
int N, M, cnt = 1, tot;
bool con[MAXS][MAXS];

void AddEdge( const int from, const int to, const int C )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	Graph[cnt].c = C, head[from] = cnt;
}

void AddE( const int from, const int to, const int C ) { AddEdge( from, to, C ), AddEdge( to, from, 0 ); }

bool BFS( const int S, const int T )
{
	int h = 1, t = 0, u, v;
	for( int i = 1 ; i <= tot ; i ++ ) dep[i] = INF;
	dep[q[++ t] = S] = 0;
	while( h <= t )
	{
		u = q[h ++];
		for( int i = head[u] ; i ; i = Graph[i].nxt )
			if( Graph[i].c && dep[v = Graph[i].to] > dep[u] + 1 )
				dep[q[++ t] = v] = dep[u] + 1;
	}
	return dep[T] < INF;
}

int DFS( const int u, const int lin, const int T )
{
	if( u == T ) return lin;
	int used = 0, ret, v, c;
	for( int &i = cur[u] ; i ; i = Graph[i].nxt )
	{
		v = Graph[i].to, c = Graph[i].c;
		if( dep[v] == dep[u] + 1 && c && ( ret = DFS( v, MIN( lin - used, c ), T ) ) )
		{
			used += ret, Graph[i].c -= ret, Graph[i ^ 1].c += ret;
			if( used == lin ) break;
		}
	}
	if( used < lin ) dep[u] = INF;
	return used;
}

int Dinic( const int S, const int T )
{
	int f = 0;
	while( BFS( S, T ) )
	{
		for( int i = 1 ; i <= tot ; i ++ ) cur[i] = head[i];
		f += DFS( S, INF, T );
	}
	return f;
}

void Clean()
{
	cnt = 1, tot = 2 * N;
	for( int i = 1 ; i <= tot + 2 ; i ++ )
		head[i] = cur[i] = dep[i] = 0;
}

int main()
{
	read( N ), read( M );
	for( int i = 1, a, b ; i <= M ; i ++ )
		read( a ), read( b ), G[a].push_back( b ), con[a][b] = true;
	int ans = INF;
	for( int i = 1 ; i <= N ; i ++ )
	{
		int have = 0;
		for( int j = 1 ; j <= N ; j ++ )
			have += con[i][j] + con[j][i] * ( i != j );
		Clean();
		const int s = ++ tot, t = ++ tot;
		for( int a = 1 ; a <= N ; a ++ )
			if( a ^ i )
			{
				AddE( s, a, 1 ), AddE( a + N, t, 1 );
				for( int k = 0 ; k < ( int ) G[a].size() ; k ++ )
					if( G[a][k] ^ i )
						AddE( a, G[a][k] + N, 1 );
			}
		int flow = Dinic( s, t );
		ans = MIN( ans, 2 * N - 1 - have + M - have - flow + N - 1 - flow );
	}
	write( ans ), putchar( '\n' );
	return 0;
}