#include <cstdio>

const int MAXN = 1e5 + 5, MAXLOG = 35;

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

struct segmentTreeNode
{
	int val;
	#define val( x ) ( segTree[x].val )
}segTree[MAXN << 2];

int a[MAXN];
int N;

void upt( const int x ) { val( x ) = val( x << 1 ) | val( x << 1 | 1 ); }

void build( const int u, const int l, const int r )
{
	if( l > r ) return ; if( l == r ) { val( u ) = a[l]; return ; }
	int mid = l + r >> 1;
	build( u << 1, l, mid ), build( u << 1 | 1, mid + 1, r );
	upt( u );
}

void update( const int u, const int l, const int r, const int pos, const int nVal )
{
	#ifdef _DEBUG
	segmentTreeNode &node1 = segTree[u];
	#endif
	int mid = l + r >> 1;
	if( l == r ) { val( u ) = nVal; return ; }
	if( pos <= mid ) update( u << 1, l, mid, pos, nVal );
	else update( u << 1 | 1, mid + 1, r, pos, nVal );
	upt( u );
	return ;
}

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	build( 1, 1, N );
	int mx = -1, mxIndx;
	for( int i = 1, v ; i <= N ; i ++ )
	{
		update( 1, 1, N, i, 0 );
		v = a[i] - ( val( 1 ) & a[i] );
		if( mx < v ) mx = v, mxIndx = i;
		update( 1, 1, N, i, a[i] );
	}
	write( a[mxIndx] );
	for( int i = 1 ; i <= N ; i ++ )
		if( i ^ mxIndx ) putchar( ' ' ), write( a[i] );
	puts( "" );
	return 0;
}
/*
3
11 11 8
*/