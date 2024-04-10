#include <cmath>
#include <cstdio>
#include <utility>
#pragma GCC optimize( 2 )

#define xx first
#define yy second

typedef std :: pair<int, int> coord;

const int mod = 1e9 + 7;
const int MAXR = 55, MAXSIZ = 7850, MAXP = MAXR * MAXR * 4;

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
_T ABS( const _T a )
{
	return a < 0 ? -a : a;
}

template<typename _T>
void swapp( _T &x, _T &y )
{
	_T t = x; x = y, y = t;
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

coord p[MAXSIZ];

int A[MAXSIZ][MAXSIZ], E[MAXSIZ];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
int pos[MAXP];
int R, siz, band;

int qkpow( int base, int indx )
{
	int ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = 1ll * ret * base % mod;
		base = 1ll * base * base % mod, indx >>= 1;
	}
	return ret;
}

double sqr( const double x ) { return x * x; }
int inv( const int a ) { return qkpow( a, mod - 2 ); }
int fix( const int a ) { return ( a % mod + mod ) % mod; }
int HASH( const int x, const int y ){ return ( x + R ) * R * 2 + y + R; }
double dist( double ax, double ay, double bx = 0, double by = 0 ) { return sqrt( sqr( ax - bx ) + sqr( ay - by ) ); }

void Gauss()
{
	int indx, tmp;
	for( int i = 1, opt = 1 ; i <= siz && opt <= siz ; i ++, opt ++ )
	{
		indx = -1;
		for( int j = opt ; j <= siz ; j ++ ) if( A[i][j] ) { indx = j; break; }
		if( ! ( ~ indx ) ) { opt --; continue; }
		for( int j = 1 ; j <= siz ; j ++ ) swapp( A[j][opt], A[j][indx] );
		tmp = inv( A[i][opt] );
		A[i][siz + 1] = 1ll * A[i][siz + 1] * tmp % mod;
		for( int j = opt ; j <= siz && j <= opt + band ; j ++ ) 
			A[i][j] = 1ll * A[i][j] * tmp % mod;
		for( int j = i + 1 ; j <= i + band && j <= siz ; j ++ )
			if( A[j][opt] )
			{
				tmp = A[j][opt];
				A[j][siz + 1] = fix( A[j][siz + 1] - 1ll * tmp * A[i][siz + 1] % mod );
				for( int k = opt ; k <= siz && k <= opt + band ; k ++ ) 
					A[j][k] = fix( A[j][k] - 1ll * tmp * A[i][k] % mod );
			}
	}
//	for( int i = 1, opt = 1 ; i <= siz && opt <= siz ; i ++, opt ++ )
//	{
//		indx = -1;
//		for( int j = i ; j <= siz ; j ++ ) if( A[j][opt] ) { indx = j; break; }
//		if( ! ( ~ indx ) ) { i --; continue; }
//		for( int j = 1 ; j <= siz + 1 ; j ++ ) swapp( A[i][j], A[indx][j] );
//		tmp = inv( A[i][opt] );
//		for( int j = 1 ; j <= siz + 1 ; j ++ ) A[i][j] = 1ll * A[i][j] * tmp % mod;
//		for( int j = i + 1 ; j <= siz ; j ++ )
//			if( A[j][opt] )
//			{
//				tmp = A[j][opt];
//				for( int k = 1 ; k <= siz + 1 ; k ++ )  A[j][k] = fix( A[j][k] - 1ll * tmp * A[i][k] % mod );
//			}
//	}
	for( int i = siz ; i ; i -- )
	{
		indx = -1;
		for( int j = 1 ; j <= siz ; j ++ ) if( A[i][j] == 1 ) { indx = j; break; }
		if( ! ( ~ indx ) ) continue;
		E[indx] = A[i][siz + 1];
		for( int j = 1 ; j < i ; j ++ ) 
			A[j][siz + 1] = fix( A[j][siz + 1] - 1ll * A[j][indx] * E[indx] % mod ),
			A[j][indx] = 0;
	}
}

int main()
{
	int ch[4];
	read( R );
	for( int i = 0 ; i < 4 ; i ++ ) read( ch[i] );
	for( int i = -R ; i <= R ; i ++ )
		for( int j = -R ; j <= R ; j ++ )
			if( dist( i, j ) <= R )
				p[pos[HASH( i, j )] = ++ siz] = coord( i, j );
//	for( int i = 1 ; i <= siz ; i ++ ) printf( "%2d %2d\n", p[i].xx, p[i].yy );
	int tmp = 0;
	for( int i = 0 ; i < 4 ; i ++ ) tmp = ( tmp + ch[i] ) % mod;
	tmp = inv( tmp );
	for( int i = 0 ; i < 4 ; i ++ ) ch[i] = 1ll * ch[i] * tmp % mod;
	for( int i = 1, x, y, t ; i <= siz ; i ++ )
	{
		x = p[i].xx, y = p[i].yy;
		A[i][i] = 1, A[i][siz + 1] = 1;
		for( int k = 0, tx, ty ; k < 4 ; k ++ )
			if( dist( tx = dir[k][0] + x, ty = dir[k][1] + y ) <= R )
				A[i][t = pos[HASH( tx, ty )]] = fix( -ch[k] ), 
				band = MAX( band, ABS( t - i ) );
	}
	Gauss();
//	write( siz ), putchar( '\n' );
	write( E[pos[HASH( 0, 0 )]] ), putchar( '\n' );
	return 0;
}