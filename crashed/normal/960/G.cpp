#include <cstdio>
#include <vector>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
const int MAXN = ( 1 << 18 ) + 5;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

typedef std :: vector<int> Poly;

int fac[MAXN], ifac[MAXN];

int N, A, B;

inline int Qkpow( int, int );
inline int Inv( const int &a ) { return Qkpow( a, mod - 2 ); }
inline int Mul( int x, const int &v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int& MulEq( int &x, const int &v ) { return x = 1ll * x * v % mod; }
inline int& SubEq( int &x, const int &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline int& AddEq( int &x, const int &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

inline int Qkpow( int base, int indx ) {
	int ret = 1;
	while( indx ) {
		if( indx & 1 ) MulEq( ret, base );
		MulEq( base, base ), indx >>= 1;
	}
	return ret;
}

inline int C( int n, int m ) { return n < m || m < 0 ? 0 : Mul( fac[n], Mul( ifac[m], ifac[n - m] ) ); }

namespace Basics {
	const int L = 18, g = 3, phi = mod - 1;

	int w[MAXN];

	inline void NTTInit( const int &n = 1 << L ) {
		w[0] = 1, w[1] = Qkpow( g, phi >> L );
		rep( i, 2, n - 1 ) w[i] = Mul( w[i - 1], w[1] );
	}

	inline void DIF( int *coe, const int &n ) {
		int *wp, p, e, o;
		for( int s = n >> 1 ; s ; s >>= 1 )
			for( int i = 0 ; i < n ; i += s << 1 ) {
				p = ( 1 << L ) / ( s << 1 ), wp = w;
				for( int j = 0 ; j < s ; j ++, wp += p ) {
					e = coe[i + j], o = coe[i + j + s];
					coe[i + j] = Add( e, o );
					coe[i + j + s] = Mul( *wp, Sub( e, o ) );
				}
			}
	}

	inline void DIT( int *coe, const int &n ) {
		int *wp, p, k;
		for( int s = 1 ; s < n ; s <<= 1 )
			for( int i = 0 ; i < n ; i += s << 1 ) {
				p = ( 1 << L ) / ( s << 1 ), wp = w;
				for( int j = 0 ; j < s ; j ++, wp += p )
					k = Mul( *wp, coe[i + j + s] ),
					coe[i + j + s] = Sub( coe[i + j], k ),
					coe[i + j] = Add( coe[i + j], k );
			}
		std :: reverse( coe + 1, coe + n );
		int inv = Inv( n ); rep( i, 0, n - 1 ) MulEq( coe[i], inv );
	}
}

inline void Init( const int &n = 1 << 18 ) {
	fac[0] = 1; rep( i, 1, n ) fac[i] = Mul( fac[i - 1], i );
	ifac[n] = Inv( fac[n] ); per( i, n - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

inline Poly operator * ( const Poly &A, const Poly &B ) {
	static int P[MAXN] = {}, Q[MAXN] = {};

	int n = A.size(), m = B.size();
	int L; for( L = 1 ; L <= n + m - 2 ; L <<= 1 );
	rep( i, 0, L - 1 ) P[i] = Q[i] = 0;
	rep( i, 0, n - 1 ) P[i] = A[i];
	rep( i, 0, m - 1 ) Q[i] = B[i];
	Basics :: DIF( P, L );
	Basics :: DIF( Q, L );
	rep( i, 0, L - 1 ) MulEq( P[i], Q[i] );
	Basics :: DIT( P, L ); Poly ret;
	rep( i, 0, n + m - 2 ) ret.push_back( P[i] );
	return ret;
}

inline Poly Shift( Poly &A, const int &c ) {
	static int P[MAXN] = {}, Q[MAXN] = {};

	int n = A.size(), L = 1;
	for( ; L <= 2 * n - 2 ; L <<= 1 );
	rep( i, 0, L - 1 ) P[i] = Q[i] = 0;
	for( int i = 0, pw = 1 ; i < n ; i ++, MulEq( pw, c ) )
		P[i] = Mul( A[i], fac[i] ), Q[i] = Mul( pw, ifac[i] );
	std :: reverse( Q, Q + n );
	Basics :: DIF( P, L );
	Basics :: DIF( Q, L );
	rep( i, 0, L - 1 ) MulEq( P[i], Q[i] );
	Basics :: DIT( P, L ); Poly ret;
	rep( i, 0, n - 1 ) ret.push_back( Mul( P[i + n - 1], ifac[i] ) );
	return ret;
}

int main() {
	Init();
	Basics :: NTTInit();
	read( N ), read( A ), read( B );
	if( A == 0 || B == 0 )
		return puts( "0" ), 0;
	if( A + B - 2 > N - 1 )
		return puts( "0" ), 0;
	Poly bas( { 0, 1 } ), res( { 1 } );
	for( int i = 0 ; ( 1 << i ) <= N - 1 ; i ++ ) {
		if( ( N - 1 ) >> i & 1 ) 
			res = res * Shift( bas, ( N - 1 ) & ( ( 1 << i ) - 1 ) );
		bas = bas * Shift( bas, 1 << i );
	}
	write( Mul( res[A + B - 2], C( A + B - 2, A - 1 ) ) ), putchar( '\n' );
	return 0;
}