#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL, int> Point;

#define int LL

const int MAXN = 2e5 + 5;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct Edge
{
	int to, nxt, w;
}Graph[MAXN << 1];

Point inQ[MAXN], inA[MAXN], allQ[MAXN], tmp[MAXN];

int BIT[MAXN];

int head[MAXN], siz[MAXN], mx[MAXN];
int N, L, cnt, tQ, tA; LL lW, ans = 0;
bool vis[MAXN];

#define Lb( x ) ( x & ( -x ) )
void Update( int x, int v ) { for( x ++ ; x <= N ; x += Lb( x ) ) BIT[x] += v; }
int Get( int x ) { int ret = 0; for( x ++ ; x ; x -= Lb( x ) ) ret += BIT[x]; return ret; }

void AddEdge( const int from, const int to, const int W )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from], Graph[cnt].w = W;
	head[from] = cnt;
}

int GetCen( const int u, const int fa, const int all )
{
	int ret = 0; mx[u] = 0, siz[u] = 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && ! vis[v = Graph[i].to] )
			ret |= GetCen( v, u, all ), siz[u] += siz[v], mx[u] = MAX( mx[u], siz[v] );
	if( MAX( all - siz[u], mx[u] ) <= ( all >> 1 ) ) ret = u; return ret;
}

void DFS( const int u, const int fa, const int d, const LL w )
{
	if( d <= L ) 
		inA[++ tQ] = Point( lW - w, L - d ), 
		inQ[++ tA] = Point( w, d );
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && ! vis[v] )
			DFS( v, u, d + 1, w + Graph[i].w );
}

LL Query( Point *Q, int lQ, Point *A, int lA )
{
	LL ret = 0; int i = 1, j = 1;
	for( ; i <= lQ && j <= lA ; )
		if( Q[i] <= A[j] ) Update( Q[i ++].second, 1 );
		else ret += Get( A[j ++].second );
	while( i <= lQ ) Update( Q[i ++].second, 1 );
	while( j <= lA ) ret += Get( A[j ++].second );
	for( i = 1 ; i <= lQ ; i ++ ) Update( Q[i].second, -1 );
	return ret;
}

void Merge( Point *Q, int lQ, Point *nw, int lNw )
{
	int i = 1, j = 1, k = 0;
	while( i <= lQ && j <= lNw )
		if( Q[i] <= nw[j] ) tmp[++ k] = Q[i ++];
		else tmp[++ k] = nw[j ++];
	while( i <= lQ ) tmp[++ k] = Q[i ++];
	while( j <= lNw ) tmp[++ k] = nw[j ++];
	for( int i = 1 ; i <= k ; i ++ ) Q[i] = tmp[i];
}

void Calc( const int u )
{
	int len = 1;
	allQ[len] = Point( 0, 0 );
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ! vis[v = Graph[i].to] )
		{
			DFS( v, u, 1, Graph[i].w );
			sort( inQ + 1, inQ + 1 + tQ );
			sort( inA + 1, inA + 1 + tA );
			ans += Query( allQ, len, inA, tA );
			Merge( allQ, len, inQ, tQ );
			len += tQ, tQ = tA = 0;
		}
}

void Divide( const int u, const int all )
{
	Calc( u ); int nSiz; vis[u] = true;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ! vis[v = Graph[i].to] )
		{
			if( siz[v] > siz[u] ) nSiz = all - siz[u];
			else nSiz = siz[v]; 
			Divide( GetCen( v, u, nSiz ), nSiz );
		}
}

signed main()
{
	read( N ), read( L ), read( lW );
	for( int i = 1, p, c ; i < N ; i ++ )
		read( p ), read( c ), AddEdge( i + 1, p, c ), AddEdge( p, i + 1, c );
	Divide( GetCen( 1, 0, N ), N ); write( ans ), putchar( '\n' );
	return 0;
}
/*
7 1 1
1 1
1 1
2 2
2 2
3 3
3 3
*/