#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 5005, MAXS = MAXN * 6, MAXE = MAXS * 10;

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
	int to, nxt, c;
	edge() {} edge( const int T, const int N, const int W ) { to = T, nxt = N, c = W; }
}Graph[MAXE];

queue<int> q;

int type[MAXS], val[MAXS][3];
int lch[MAXN << 2], rch[MAXN << 2], lef[MAXN << 2], rig[MAXN << 2], ref[MAXS], ind[MAXS];
int head[MAXS], dep[MAXS], cur[MAXS], bel[MAXS], tot[MAXS];
int N, M, rt, siz, segSiz, cnt = 1;

void addEdge( const int from, const int to, const int c )
{ Graph[++ cnt] = edge( to, head[from], c ), head[from] = cnt; }
void addE( const int from, const int to, const int c ) { addEdge( from, to, c ), addEdge( to, from, 0 ); }

bool BFS( const int S, const int T )
{
	while( ! q.empty() ) q.pop();
	for( int i = 1 ; i <= siz ; i ++ ) dep[i] = INF;
	dep[S] = 0, q.push( S );
	int u, v;
	while( ! q.empty() )
	{
		u = q.front(), q.pop();
		for( int i = head[u] ; i ; i = Graph[i].nxt )
		{
			v = Graph[i].to;
			if( Graph[i].c && dep[v] == INF ) dep[v] = dep[u] + 1, q.push( v );
		}
	}
	return dep[T] < INF;
}

int DFS( const int u, const int lin, const int T )
{
	if( u == T ) return lin;
	int used = 0, res = 0, v, c;
	for( int &i = cur[u] ; i ; i = Graph[i].nxt )
	{
		v = Graph[i].to, c = Graph[i].c;
		if( dep[v] == dep[u] + 1 && c && ( res = DFS( v, MIN( lin - used, c ), T ) ) )
		{
			used += res, Graph[i].c -= res, Graph[i ^ 1].c += res;
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
		for( int i = 1 ; i <= siz ; i ++ ) cur[i] = head[i];
		f += DFS( S, INF, T );
	}
	return f;
}

int build( const int l, const int r )
{
	if( l > r ) return 0;
	int mid = l + r >> 1, u = ++ segSiz; 
	lef[u] = l, rig[u] = r;
	if( l == r ) { ref[l] = u, ind[u] = l; return u; }
	lch[u] = build( l, mid ), rch[u] = build( mid + 1, r );
	if( lch[u] ) addE( u, lch[u], INF ); 
	if( rch[u] ) addE( u, rch[u], INF );
	return u;
}

void cover( const int u, const int l, const int r, const int segL, const int segR, const int fr )
{
	if( l > r ) return ;
	int mid = l + r >> 1; 
	if( segL <= l && r <= segR ) { addE( fr, u, INF ); return; } 
	if( l == r ) return ;
	if( segL <= mid ) cover( lch[u], l, mid, segL, segR, fr );
	if( mid < segR ) cover( rch[u], mid + 1, r, segL, segR, fr );
}

void prepare( const int u, const int l, const int r )
{
	if( l > r ) return ;
	if( l == r ) { addE( u, M + segSiz + 2, 1 ); return ; }
	prepare( lch[u], l, l + r >> 1 ), prepare( rch[u], ( l + r >> 1 ) + 1, r );
}

int findAns( const int u )
{
	if( segSiz < u && u <= segSiz + M ) return u - segSiz;
	int v, tmp;
	for( int i = head[u] ; i ; i = Graph[i].nxt )
		if( ( i & 1 ) && Graph[i].c )
		{
			v = Graph[i].to;
			if( lef[u] == rig[u] )
			{
				while( Graph[i].c )
				{
					tmp = findAns( v ), bel[ind[u]] = tmp;
					if( ~ tmp ) Graph[i].c --;
					else break;
				}
			}
			else
			{
				tmp = findAns( v );
				if( ~ tmp ) { Graph[i].c --; return tmp; }
			}
		}
	return -1;
}

int main()
{
	read( M ), read( N );
	rt = build( 1, N ), siz = segSiz + M + 2;
	prepare( rt, 1, N );
	const int S = M + segSiz + 1, T = M + segSiz + 2;
	for( int i = 1, u ; i <= M ; i ++ )
	{
		read( type[i] ), u = i + segSiz;
		if( type[i] == 0 ) 
		{
			read( val[i][0] ), addE( S, u, 1 );
			while( val[i][0] -- ) read( val[i][1] ), addE( u, ref[val[i][1]], INF );
		}
		if( type[i] == 1 ) read( val[i][0] ), read( val[i][1] ), addE( S, u, 1 ), 
		cover( rt, 1, N, val[i][0], val[i][1], u );
		if( type[i] == 2 ) read( val[i][0] ), read( val[i][1] ), read( val[i][2] ), 
		addE( S, u, 2 ), addE( u, ref[val[i][0]], 1 ), addE( u, ref[val[i][1]], 1 ), addE( u, ref[val[i][2]], 1 );
	}
	write( Dinic( S, T ) ), putchar( '\n' );
	findAns( T );
	for( int i = 1 ; i <= N ; i ++ ) tot[bel[i]] ++;
	for( int i = 1 ; i <= M ; i ++ )
		if( type[i] == 2 && tot[i] == 1 ) 
			for( int j = 0 ; j < 3 ; j ++ )
				if( bel[val[i][j]] ^ i ) { bel[val[i][j]] = i; break; }
	for( int i = 1 ; i <= N ; i ++ )
		if( bel[i] ) write( bel[i] ), putchar( ' ' ), write( i ), putchar( '\n' );
	return 0;
}