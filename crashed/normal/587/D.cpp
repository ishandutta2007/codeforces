#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef vector<int> vi;
 
const int INF = 0x3f3f3f3f;
const int MAXN = 5e5 + 5, MAXM = 5e4 + 5, MAXE = 1e7 + 5;
 
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
}Graph[MAXE];
 
vi G[MAXN], tmp, same;
 
int sta[MAXN], top;
int head[MAXN], DFN[MAXN], LOW[MAXN], bel[MAXN];
int c[MAXM], t[MAXM];
int N, M, cnt, tot, ID, siz;
bool inSta[MAXN];
 
bool cmp( const int x, const int y ) { return c[x] < c[y]; }
 
void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}
 
void Tarjan( const int u )
{
	DFN[u] = LOW[u] = ++ ID;
	inSta[sta[++ top] = u] = true;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
	{
		if( ! DFN[v = Graph[i].to] ) Tarjan( v ), LOW[u] = MIN( LOW[u], LOW[v] );
		else if( inSta[v] ) LOW[u] = MIN( LOW[u], DFN[v] );
	}
	if( LOW[u] == DFN[u] )
	{
		int v; tot ++;
		do inSta[v = sta[top --]] = false, bel[v] = tot;
		while( u ^ v );
	}
}
 
void addE1( vi G )
{
	int nxt = G.size(), lst1, lst2;
	for( int i = 0 ; i < nxt ; i ++ )
	{
		int x = G[i], y = G[i] + M, s = ++ siz, t = ++ siz;
		addEdge( x, s ), addEdge( t, y );
		if( i ) addEdge( lst1, s ), addEdge( t, lst2 ), addEdge( lst1, y ), addEdge( x, lst2 );
		lst1 = s, lst2 = t;
	}
}
 
void addE2( vi G )
{
	int nxt = G.size(), lst1, lst2;
	for( int i = 0 ; i < nxt ; i ++ )
	{
		int x = G[i], y = G[i] + M, s = ++ siz, t = ++ siz;
		addEdge( s, x ), addEdge( y, t );
		if( i ) addEdge( s, lst1 ), addEdge( lst2, t ), addEdge( y, lst1 ), addEdge( lst2, x );
		lst1 = s, lst2 = t;
	}
}
 
void remove( const int len )
{
	for( int i = 1 ; i <= M ; i ++ ) if( t[i] > len ) head[i] = Graph[head[i]].nxt;
}
 
bool chk( const int len )
{	
	top = tot = ID = 0;
	for( int i = 1 ; i <= siz ; i ++ ) DFN[i] = LOW[i] = bel[i] = inSta[i] = 0;
	for( int i = 1 ; i <= M ; i ++ ) if( t[i] > len ) addEdge( i, i + M );
	for( int i = 1 ; i <= siz ; i ++ ) if( ! DFN[i] ) Tarjan( i );
	for( int i = 1 ; i <= M ; i ++ ) if( bel[i] == bel[i + M] ){ remove( len ); return 0; }
	remove( len ); return true;
}
 
int main()
{
	int l = 0, r = -INF, mid;
	read( N ), read( M );
	for( int i = 1, a, b ; i <= M ; i ++ )
		read( a ), read( b ), read( c[i] ), read( t[i] ), G[a].push_back( i ), G[b].push_back( i ), r = MAX( r, t[i] );
	siz = M << 1;
	for( int i = 1 ; i <= N ; i ++ )
	{
		addE1( tmp = G[i] );
		std :: sort( tmp.begin(), tmp.end(), cmp );
		for( int k = 0, r ; k < tmp.size() ; k = r )
		{
			for( r = k ; r < tmp.size() && c[tmp[r]] == c[tmp[k]] ; r ++ );
			for( int j = k ; j < r ; j ++ ) same.push_back( tmp[j] );
			addE2( same ), same.clear();
		}
	}
	if( ! chk( INF ) ) { puts( "No" ); return 0; }
	puts( "Yes" );
	while( l < r )
	{
		if( chk( mid = l + r >> 1 ) ) r = mid;
		else l = mid + 1;
	}
	chk( l );
	write( l ), putchar( ' ' ); 
	int count = 0;
	for( int i = 1 ; i <= M ; i ++ ) count += bel[i] < bel[i + M];
	write( count ), putchar( '\n' ); 
	for( int i = 1 ; i <= M ; i ++ ) if( bel[i] < bel[i + M] ) write( i ), putchar( ' ' );
	puts( "" );
	return 0;
}
/*
2 2
1 2 1 1
1 2 1 2
*/