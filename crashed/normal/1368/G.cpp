#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

#ifdef _DEBUG
const int MAXN = 105;
#else
const int MAXN = 2e5 + 5;
#endif

template<typename _T>
void read( _T &x )/*{{{*/
{
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}/*}}}*/

template<typename _T>
void write( _T x )/*{{{*/
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}/*}}}*/

struct MyGraph/*{{{*/
{
	struct Edge/*{{{*/
	{
		int to, nxt;
		Edge(): to( 0 ), nxt( 0 ) {}
	}Graph[MAXN];/*}}}*/

	int head[MAXN], cnt;
	int DFN[MAXN], siz[MAXN], ID;

	MyGraph(): head{}, cnt( 0 ), DFN{}, siz{}, ID( 0 ) {}
	
	Edge operator [] ( const int &idx ) const { return Graph[idx]; }

	void AddEdge( const int from, const int to )/*{{{*/
	{
		Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
		head[from] = cnt;
	}/*}}}*/

	void DFS( const int u )/*{{{*/
	{
		DFN[u] = ++ ID, siz[u] = 1;
		for( int i = head[u] ; i ; i = Graph[i].nxt )
			DFS( Graph[i].to ), siz[u] += siz[Graph[i].to];
	}/*}}}*/
};/*}}}*/

MyGraph tre[2];

char grid[MAXN], str[MAXN];
int cmpn[MAXN];

int su[MAXN << 2], cov[MAXN << 2];

LL ans = 0;
int N, M;

#define ID( x, y ) ( ( (x) - 1 ) * M + (y) )

inline bool Inside( const int x, const int y )
{ return 1 <= x && x <= N && 1 <= y && y <= M; }

inline void Cover( const int x, const int delt, const int leaf )/*{{{*/
{
	if( cov[x] += delt ) su[x] = 0;
	else su[x] = leaf ? 1 : su[x << 1] + su[x << 1 | 1];
}/*}}}*/

inline void Upt( const int x ) { su[x] = cov[x] ? 0 : su[x << 1] + su[x << 1 | 1]; }

void Build( const int x, const int l, const int r )/*{{{*/
{
	if( l > r ) return ; su[x] = cov[x] = 0;
	if( l == r ) { su[x] = l > 1; return ; }
	int mid = ( l + r ) >> 1;
	Build( x << 1, l, mid );
	Build( x << 1 | 1, mid + 1, r );
	Upt( x );
}/*}}}*/

inline void Cover( const int x, const int l, const int r, const int segL, const int segR, const int delt )/*{{{*/
{
	if( segL > segR ) return ;
	if( segL <= l && r <= segR ) { Cover( x, delt, l == r && l > 1 ); return ; }
	int mid = ( l + r ) >> 1;
	if( segL <= mid ) Cover( x << 1, l, mid, segL, segR, delt );
	if( mid  < segR ) Cover( x << 1 | 1, mid + 1, r, segL, segR, delt );
	Upt( x );
}/*}}}*/

int Query( const int x, const int l, const int r, const int segL, const int segR )/*{{{*/
{
	if( segL > segR ) return 0;
	if( segL <= segR ) return su[x];
	int mid = ( l + r ) >> 1, ret = 0;
	if( segL <= mid ) ret += Query( x << 1, l, mid, segL, segR );
	if( mid  < segR ) ret += Query( x << 1 | 1, mid + 1, r, segL, segR );
	return ret;
}/*}}}*/

void DFS( const int u )/*{{{*/
{
	if( u )
	{
		int d = tre[1].DFN[cmpn[u]], s = tre[1].siz[cmpn[u]];
		Cover( 1, 1, tre[1].ID, d, d + s - 1, 1 );
		ans -= su[1]; 
	}
	for( int i = tre[0].head[u] ; i ; i = tre[0][i].nxt ) 
		DFS( tre[0][i].to );
	if( u ) 
	{
		int d = tre[1].DFN[cmpn[u]], s = tre[1].siz[cmpn[u]];
		Cover( 1, 1, tre[1].ID, d, d + s - 1, -1 );
	}
}/*}}}*/

int main()
{
	read( N ), read( M );
	rep( i, 1, N )
	{
		scanf( "%s", str + 1 );
		rep( j, 1, M ) grid[ID( i, j )] = str[j];
	}
	rep( i, 1, N ) rep( j, 1, M )
	{
		int col = ( i + j ) & 1, tx, ty;
		if( grid[ID( i, j )] == 'L' ) tx = i, ty = j + 2, cmpn[ID( i, j )] = ID( i, j + 1 );
		if( grid[ID( i, j )] == 'R' ) tx = i, ty = j - 2, cmpn[ID( i, j )] = ID( i, j - 1 );
		if( grid[ID( i, j )] == 'U' ) tx = i + 2, ty = j, cmpn[ID( i, j )] = ID( i + 1, j );
		if( grid[ID( i, j )] == 'D' ) tx = i - 2, ty = j, cmpn[ID( i, j )] = ID( i - 1, j );
		if( ! Inside( tx, ty ) ) tre[col].AddEdge( 0, ID( i, j ) );
		else tre[col].AddEdge( ID( tx, ty ), ID( i, j ) );
	}
	ans = 1ll * ( N * M / 2 ) * ( N * M / 2 );
	tre[1].DFS( 0 );
	Build( 1, 1, tre[1].ID );
	DFS( 0 );
	write( ans ), putchar( '\n' );
	return 0;
}