#include <cstdio>
#include <algorithm>

typedef long long LL;

#define int LL

const int INF = 2.001e9;
const int MAXN = 2e5 + 5, MAXLOG = 25;

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

struct monster
{
	int x, y, z;
	bool operator < ( const monster & b ) { return x < b.x; }
}b[MAXN];

struct weapon
{
	int x, y;
	bool operator < ( const weapon &b ) { return x < b.x; }
}a[MAXN];

struct segmentTreeNode
{
	int lch, rch, mx, tag;
	#define mx( x ) ( segTree[x].mx )
	#define lch( x ) ( segTree[x].lch )
	#define rch( x ) ( segTree[x].rch )
	#define tag( x ) ( segTree[x].tag )
	segmentTreeNode() { lch = rch = tag = 0, mx = -INF; }
}segTree[MAXN * MAXLOG];

int y[MAXN], py[MAXN];
int N, M, P, rt, siz;

void upt( int &x, const int v ) { x = MAX( x, v ); }
void upt( const int x ) { mx( x ) = MAX( mx( lch( x ) ), mx( rch( x ) ) ); }
void add( const int x, const int v ) { if( x ) tag( x ) += v, mx( x ) += v; }
void normalize( const int x ) { if( tag( x ) ) add( lch( x ), tag( x ) ), add( rch( x ), tag( x ) ), tag( x ) = 0; }

void upt( const int u, const int l, const int r, const int segL, const int segR, const int val )
{
	#ifdef _DEBUG
	segmentTreeNode &node1 = segTree[u];
	#endif
	if( ! u ) return ;
	if( segL <= l && r <= segR ) 
	{ 
		add( u, val ); 
		return ; 
	}
	int mid = l + r >> 1; normalize( u );
	if( segL <= mid ) upt( lch( u ), l, mid, segL, segR, val );
	if( segR > mid ) upt( rch( u ), mid + 1, r, segL, segR, val );
	upt( u ); 
	return ;
}

int update( const int u, const int l, const int r, const int segL, const int segR, const int val )
{
	int cur = u ? u : ++ siz, mid = l + r >> 1;
	#ifdef _DEBUG
	segmentTreeNode &node2 = segTree[u], &node3 = segTree[cur];
	#endif
	if( segL <= l && r <= segR ) { mx( cur ) = MAX( mx( cur ), val ); return cur; }
	normalize( u );
	if( segL <= mid ) lch( cur ) = update( lch( u ), l, mid, segL, segR, val );
	if( segR > mid ) rch( cur ) = update( rch( u ), mid + 1, r, segL, segR, val );
 	upt( cur ); 
	return cur;
}

signed main()
{
	int mx = 0;
	read( N ), read( M ), read( P );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i].x ), read( a[i].y );
	for( int i = 1 ; i <= M ; i ++ ) read( y[i] ), read( py[i] ), mx = MAX( mx, y[i] );
	for( int i = 1 ; i <= M ; i ++ ) rt = update( rt, 1, mx, y[i], y[i], - py[i] );
	for( int i = 1 ; i <= P ; i ++ ) read( b[i].x ), read( b[i].y ), read( b[i].z );
	std :: sort( a + 1, a + 1 + N ), std :: sort( b + 1, b + 1 + P );
	int p = 0, ans = -INF;
	for( int i = 1 ; i <= N ; i ++ )
	{
		for( ; p < P && b[p + 1].x < a[i].x ; )
		{
			p ++;
			if( b[p].y < mx ) upt( rt, 1, mx, b[p].y + 1, mx, b[p].z );
		}
		ans = MAX( ans, mx( rt ) - a[i].y );
	}
	write( ans ), putchar( '\n' );
	return 0;
}