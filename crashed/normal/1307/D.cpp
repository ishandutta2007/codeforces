#include <cstdio>
#include <algorithm>

typedef long long LL;

const int MAXN = 2e5 + 5, MAXE = 2e5 + 5;

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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct edge
{
	int to, nxt;
}Graph[MAXE << 1];

int seq[MAXN];
int q[MAXN];
int head[MAXN], distS[MAXN], distT[MAXN];
int N, M, K, cnt;
bool spe[MAXN];

bool cmp( const int &a, const int &b ) { return distS[a] < distS[b]; }

void addEdge( const int from, const int to ) 
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void BFS( const int S, int *d )
{
	int h = 1, t = 0, u, v;
	d[S] = 0, q[++ t] = S;
	while( h <= t )
	{
		u = q[h ++];
		for( int i = head[u] ; i ; i = Graph[i].nxt )
			if( ! d[v = Graph[i].to] && v ^ S )
				d[v] = d[u] + 1, q[++ t] = v;
	}
}

int main()
{
	read( N ), read( M ), read( K );
	for( int i = 1 ; i <= K ; i ++ ) read( seq[i] );
	for( int i = 1, a, b ; i <= M ; i ++ ) read( a ), read( b ), addEdge( a, b ), addEdge( b, a );
	BFS( 1, distS ), 
	BFS( N, distT );
	std :: sort( seq + 1, seq + 1 + K, cmp );
	int ans = 0, lst = distT[seq[K]];
	for( int i = K - 1 ; i ; i -- )
		ans = MAX( ans, distS[seq[i]] + lst + 1 ),
		lst = MAX( distT[seq[i]], lst );
	write( MIN( ans, distS[N] ) ), putchar( '\n' );
	return 0;
}
/*
5 4 2
1 5
1 2
2 3
3 4
4 5
*/