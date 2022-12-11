#include <cstdio>

const int INF = 0x3f3f3f3f;
const int MAXN = 3.1e3 + 5, MAXM = 4e5;

#define rep( i, a, b ) for( int (i) = (a) ; (i) <= (b) ; (i) ++ )
#define per( i, a, b ) for( int (i) = (a) ; (i) >= (b) ; (i) -- )

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

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

struct edge
{
	int to, nxt, c;
}Graph[MAXM << 1];

int q[MAXN];
int head[MAXN], dep[MAXN], cur[MAXN];

int A[MAXN];
int N, tot, cnt = 1;

void AddEdge( const int from, const int to, const int C )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from], Graph[cnt].c = C;
	head[from] = cnt;
}

void AddE( const int from, const int to, const int C ) { AddEdge( from, to, C ), AddEdge( to, from, 0 ); }

bool BFS( const int S, const int T )
{
	int h = 1, t = 0, u, v;
	rep( i, 1, tot ) dep[i] = INF;
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
	int v, c, ret, used = 0;
	for( int &i = cur[u] ; i ; i = Graph[i].nxt )
	{
		v = Graph[i].to, c = Graph[i].c;
		if( dep[v] == dep[u] + 1 && c && ( ret = DFS( v, MIN( c, lin - used ), T ) ) )
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
	int ret = 0;
	while( BFS( S, T ) )
	{
		rep( i, 1, tot ) cur[i] = head[i];
		ret += DFS( S, INF, T );
	}
	return ret;
}

int main()
{
	int ans = 0;
	read( N ); tot = N;
	const int s = ++ tot, t = ++ tot;
	rep( i, 1, N ) read( A[i] );
	rep( i, 1, N ) { int B;
		read( B );
		if( B > 0 ) ans += B, AddE( s, i, B );
		else AddE( i, t, - B );
	}
	rep( i, 1, N )
		per( j, i - 1, 1 )
			if( ! ( A[i] % A[j] ) )
			{
				AddE( i, j, INF );
				if( A[i] == A[j] ) break;
			}
	write( MAX( ans - Dinic( s, t ), 0 ) ), putchar( '\n' );
	return 0;
}