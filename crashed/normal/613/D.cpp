#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 5, MAXM = 1e5 + 5, MAXLOG = 20;
const int INF = 0x3f3f3f3f;

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
}Graph[MAXM * 2], nGraph[MAXM * 2];

LL DP[MAXN][2];
int sta[MAXN], top;
int f[MAXN][MAXLOG];
int seq[MAXN], lca[MAXN];
int dep[MAXN], DFN[MAXN];
int head[MAXN], nHead[MAXN];
int N, M, lg2, cnt, cnt1, ID, K;
bool imp[MAXN];

void addEdge( edge *G, int *h, int &count, const int from, const int to )
{
	count ++;
	G[count].to = to, G[count].nxt = h[from];
	h[from] = count;
}

void DFS( const int u, const int fa )
{
	DFN[u] = ++ID, dep[u] = dep[fa] + 1, f[u][0] = fa;
	int v;
	for( int i = head[u] ; i ; i = Graph[i].nxt )
	{
		v = Graph[i].to;
		if( v ^ fa ) DFS( v, u );
	}
}

void init()
{
	for( int j = 1 ; j <= lg2 ; j ++ )
		for( int i = 1 ; i <= N ; i ++ )
			f[i][j] = f[f[i][j - 1]][j - 1];
}

bool cmp( const int &x, const int &y ) { return DFN[x] < DFN[y]; }

void balance( int &u, const int steps )
{
	for( int i = 0 ; ( 1 << i ) <= steps ; i ++ )
		if( steps & ( 1 << i ) )
			u = f[u][i];
}

int LCA( int u, int v )
{
	if( dep[u] > dep[v] ) balance( u, dep[u] - dep[v] );
	if( dep[v] > dep[u] ) balance( v, dep[v] - dep[u] );
	if( u == v ) return u;
	for( int i = lg2 ; ~ i ; i -- )
		if( f[u][i] ^ f[v][i] )
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

void build()
{
	top = 0;
	if( seq[1] > 1 ) sta[++ top] = 1;
	for( int i = 1 ; i <= K ; i ++ )
	{
		if( top )
		{
			int z = LCA( sta[top], seq[i] );
			while( top > 1 && dep[z] < dep[sta[top - 1]] )
				addEdge( nGraph, nHead, cnt1, sta[top - 1], sta[top] ), top --;
			if( top && dep[z] < dep[sta[top]] ) addEdge( nGraph, nHead, cnt1, z, sta[top] ), top --;
			if( ! ( top && sta[top] == z ) ) sta[++top] = z;
		}
		sta[++top] = seq[i];
	}
	while( top > 1 ) addEdge( nGraph, nHead, cnt1, sta[top - 1], sta[top] ), top --;
}

void DPS( const int u )
{
	LL s = 0, v, tmp = 1;
	if( imp[u] ) DP[u][0] = INF, DP[u][1] = 0;
	else DP[u][0] = 0, DP[u][1] = INF;
	for( int i = nHead[u] ; i ; i = nGraph[i].nxt )
	{
		v = nGraph[i].to;
		DPS( v );
		s += DP[v][0];
		if( imp[u] ) DP[u][1] += MIN( DP[v][0], DP[v][1] + 1 );
		else DP[u][0] += DP[v][0], tmp += MIN( DP[v][0], DP[v][1] );
	}
	if( ! imp[u] )
	{
		DP[u][0] = MIN( DP[u][0], tmp );
		for( int i = nHead[u] ; i ; i = nGraph[i].nxt )
		{
			v = nGraph[i].to;
			DP[u][1] = MIN( DP[u][1], s - DP[v][0] + DP[v][1] );	
		}
	}
	imp[u] = false, nHead[u] = 0;
}

int main()
{
	int fr, to;
	read( N );
	lg2 = log2( N );
	for( int i = 1 ; i < N ; i ++ )
		read( fr ), read( to ), addEdge( Graph, head, cnt, fr, to ), addEdge( Graph, head, cnt, to, fr );
	DFS( 1, 0 );
	init();
	read( M );
	bool flag;
	while( M -- )
	{
		read( K );
		for( int i = 1 ; i <= K ; i ++ ) read( seq[i] ), imp[seq[i]] = true;
		std :: sort( seq + 1, seq + 1 + K, cmp );
		flag = false;
		for( int i = 1 ; i <= K ; i ++ )
			if( imp[f[seq[i]][0]] )
			{
				puts( "-1" );
				flag = true;
				break;
			}
		if( flag )
		{
			for( int i = 1 ; i <= K ; i ++ ) imp[seq[i]] = false;
			continue;
		}
		cnt1 = 0, build();
		DPS( 1 );
		write( MIN( DP[1][0], DP[1][1] ) ), putchar( '\n' );
	}
	return 0;
}