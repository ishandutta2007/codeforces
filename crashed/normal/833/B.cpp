#include <cmath>
#include <cstdio>

#define isLeaf( a ) ( segTree[a].l == segTree[a].r ) 

const int INF = 0x3f3f3f3f, MAXN = 35005, MAXK = 55;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar();int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + s - '0', s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) { putchar( '-' ), x = -x; }
	if( 9 < x ) { write( x / 10 ); }
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

struct segmentTreeNode
{
	int l, r;
	int mx, tag;
}segTree[MAXN << 2];

int f[MAXK][MAXN];
int a[MAXN], lst[MAXN];
int N, K, siz;

void upt( const int now ) { segTree[now].mx = MAX( segTree[now << 1].mx, segTree[now << 1 | 1].mx ); }

void build( const int k, const int now, const int left, const int right )
{
	#ifdef _DEBUG
	segmentTreeNode &node4 = segTree[now];
	#endif
	segTree[now].l = left, segTree[now].r = right, segTree[now].tag = 0;
	if( isLeaf( now ) ) { segTree[now].mx = f[k - 1][left]; return; }
	int mid = left + right >> 1;
	build( k, now << 1, left, mid ), build( k, now << 1 | 1, mid + 1, right );
	upt( now );
}

void add( const int now, const int val ) 
{
	#ifdef _DEBUG
	segmentTreeNode &node3 = segTree[now];
	#endif
	segTree[now].tag += val;
	segTree[now].mx += val;
	int cc = 1;
}

void normalize( const int now )
{
	if( ! segTree[now].tag ) return ;
	add( now << 1, segTree[now].tag ), add( now << 1 | 1, segTree[now].tag );
	segTree[now].tag = 0;
}

void update( const int now, const int segL, const int segR, const int val )
{
	#ifdef _DEBUG
	segmentTreeNode &node1 = segTree[now];
	#endif
	if( segR < segTree[now].l || segTree[now].r < segL ) return ;
	if( segL <= segTree[now].l && segTree[now].r <= segR ) { add( now, val ); return ; }
	if( isLeaf( now ) ) return ; normalize( now );
	update( now << 1, segL, segR, val ), update( now << 1 | 1, segL, segR, val );
	upt( now );
}

int query( const int now, const int segL, const int segR )
{
	#ifdef _DEBUG
	segmentTreeNode &node2 = segTree[now];
	#endif
	if( segR < segTree[now].l || segTree[now].r < segL ) return -INF;
	if( segL <= segTree[now].l && segTree[now].r <= segR ) return segTree[now].mx;
	if( isLeaf( now ) ) return -INF; normalize( now );
	int val = query( now << 1, segL, segR );
	return MAX( val, query( now << 1 | 1, segL, segR ) );
}

int main()
{
	read( N ), read( K );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	for( int i = 1 ; i <= N ; i ++ ) f[0][i] = -INF;
	for( int j = 1 ; j <= K ; j ++ )
	{
		for( int i = 1 ; i <= N ; i ++ ) lst[i] = -1;
		build( j, 1, 0, N - 1 );
		for( int i = 1 ; i <= N ; i ++ )
		{
			if( ~ lst[a[i]] ) update( 1, 0, lst[a[i]] - 1, -1 );
			update( 1, 0, i - 1, 1 ), lst[a[i]] = i;
			if( i >= j ) f[j][i] = query( 1, j - 1, i - 1 );
			else f[j][i] = -INF;
		}
	}
	write( f[K][N] ), putchar( '\n' );
	return 0;
}