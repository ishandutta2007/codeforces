#include <cmath>
#include <cstdio>
#include <cstring>

const int mod = 998244353, phi = mod - 1, g = 3, inv2 = 499122177;
const int MAXN = 1e5 + 5;

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
void swapp( _T &x, _T &y )
{
	_T t = x; x = y, y = t;
}

int A[MAXN << 2], H_[MAXN << 2], C1[MAXN << 2], C2[MAXN << 2];
int a[MAXN];
int N, M;

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

int inv( const int a ) { return qkpow( a, mod - 2 ); }
int fix( const int a ) { return ( a % mod + mod ) % mod; }

void NTT( int *coe, const int len, const int t )
{
	int lg2 = log2( len );
	for( int i = 0, rev ; i < len ; i ++ )
	{
		rev = 0;
		for( int j = 0 ; j < lg2 ; j ++ ) rev |= ( ( i >> j ) & 1 ) << ( lg2 - j - 1 );
		if( rev < i ) swapp( coe[rev], coe[i] );
	}
	int wp, wo, we;
	for( int s = 2, p ; s <= len ; s <<= 1 )
	{
		p = s >> 1; wp = t > 0 ? qkpow( g, phi / s ) : inv( qkpow( g, phi / s ) );
		for( int i = 0 ; i < len ; i += s )
			for( int j = 0, w = 1 ; j < p ; j ++, w = 1ll * w * wp % mod )
			{
				we = coe[i + j], wo = 1ll * coe[i + j + p] * w % mod;
				coe[i + j] = ( we + wo ) % mod, coe[i + j + p] = fix( we - wo );
			}
	}
	if( t > 0 ) return ;
	int inver = inv( len );
	for( int i = 0 ; i <= len ; i ++ ) coe[i] = 1ll * coe[i] * inver % mod;
}

void polyInv( const int n, int *F, int *H )
{
	if( n == 1 ) { H[0] = inv( F[0] ); return ; }
	int half = n + 1 >> 1, len = 1;
	polyInv( half, F, H );
	while( len < ( n << 1 ) ) len <<= 1;
	for( int i = 0 ; i < n ; i ++ ) A[i] = F[i];
	for( int i = n ; i <= len ; i ++ ) H[i] = A[i] = 0;
	NTT( A, len, 1 ), NTT( H, len, 1 );
	for( int i = 0 ; i <= len ; i ++ ) H[i] = 1ll * H[i] * fix( 2 - 1ll * A[i] * H[i] % mod ) % mod; 
	NTT( H, len, -1 );
	for( int i = n ; i <= len ; i ++ ) H[i] = 0;
}

void polySqrt( const int n, int *F, int *H )
{
	if( n == 1 ) { H[0] = 1; return ; }
	int half = n + 1 >> 1, len = 1;
	polySqrt( half, F, H );
	while( len < ( n << 1 ) ) len <<= 1;
	polyInv( n, H, H_ );
	for( int i = 0 ; i < n ; i ++ ) A[i] = F[i];
	for( int i = n ; i <= len ;            i ++ ) A[i] = 0;
	NTT( A, len, 1 ), NTT( H_, len, 1 );
	for( int i = 0 ; i <= len ; i ++ ) A[i] = 1ll * A[i] * H_[i] % mod;
	NTT( A, len, -1 );
	for( int i = 0 ; i < n ; i ++ ) H[i] = 1ll * ( H[i] + A[i] ) % mod * inv2 % mod;
	for( int i = n ; i <= len ; i ++ ) H[i] = 0;
}

int main()
{
	read( N ), read( M );
	for( int i = 1, v ; i <= N ; i ++ ) read( v ), a[v] = 1;
	for( int i = 0 ; i <= M ; i ++ ) C1[i] = 1ll * ( mod - 4 ) * a[i] % mod;
	C1[0] = ( C1[0] + 1 ) % mod;
	polySqrt( M + 1, C1, C2 );
	C2[0] = ( C2[0] + 1 ) % mod;
	memset( C1, 0, sizeof C1 );
	polyInv( M + 1, C2, C1 );
	for( int i = 1 ; i <= M ; i ++ ) write( 2ll * C1[i] % mod ), putchar( '\n' );
	return 0;
}