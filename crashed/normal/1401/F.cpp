#include <cstdio>
 
typedef long long LL;
 
const int MAXS = ( 1 << 18 ) + 5, MAXN = 25;
 
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
 
int a[MAXS];
LL su[MAXS << 2]; 
int lay[MAXS << 2];
int N, Q;
bool rev[MAXN], swa[MAXN];
 
void upt( const int x ) { su[x] = su[x << 1] + su[x << 1 | 1]; }
int lch( const int x, const bool t ) { return swa[lay[x]] ^ t ? x << 1 | 1 : x << 1; }
int rch( const int x, const bool t ) { return swa[lay[x]] ^ t ? x << 1 : x << 1 | 1; }
 
void build( const int x, const int l, const int r, const int dep )
{
	if( l > r ) return ;
	if( l == r ) { su[x] = a[l]; return ; }
	int mid = l + r >> 1; lay[x] = dep;
	build( x << 1, l, mid, dep - 1 );
	build( x << 1 | 1, mid + 1, r, dep - 1 );
	upt( x );
}
 
void change( const int x, const int l, const int r, const int p, const int v, bool t )
{
	if( l == r ) { su[x] = v; return ; }
	int mid = l + r >> 1; t ^= rev[lay[x]];
	if( p <= mid ) change( lch( x, t ), l, mid, p, v, t );
	else change( rch( x, t ), mid + 1, r, p, v, t );
	upt( x );
}
 
LL query( const int x, const int l, const int r, const int segL, const int segR, bool t )
{
	if( segL <= l && r <= segR ) return su[x];
	int mid = l + r >> 1; LL ret = 0; t ^= rev[lay[x]];
	if( segL <= mid ) ret += query( lch( x, t ), l, mid, segL, segR, t );
	if( mid < segR ) ret += query( rch( x, t ), mid + 1, r, segL, segR, t );
	return ret;
} 
 
int main()
{
	read( N ), read( Q );
	int len = 1 << N;
	for( int i = 1 ; i <= len ; i ++ ) read( a[i] );
	build( 1, 1, len, N );
	int opt, a, b;
	while( Q -- )
	{
		read( opt ), read( a );
		if( opt == 1 ) read( b ), change( 1, 1, len, a, b, 0 );
		if( opt == 2 ) rev[a] ^= 1;
		if( opt == 3 ) swa[a + 1] ^= 1;
		if( opt == 4 ) read( b ), write( query( 1, 1, len, a, b, 0 ) ), putchar( '\n' );
	}
	return 0;
}