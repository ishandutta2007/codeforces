#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
const int MAXN = ( 1 << 21 ) + 5;

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

int seq[MAXN], tot;

int A[MAXN], B[MAXN];

int N, M;

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

namespace Basics {
	const int L = 21, g = 3, phi = mod - 1;

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

int main() {
	Basics :: NTTInit();
	read( N ), read( M );
	rep( i, 1, N ) {
		int x; read( x );
		A[x] = B[x] = 1;
	}
	int L; for( L = 1 ; L <= 2 * M ; L <<= 1 );
	Basics :: DIF( B, L );
	rep( i, 0, L - 1 ) MulEq( B[i], B[i] );
	Basics :: DIT( B, L );
	rep( i, 0, M )
		if( ! A[i] && B[i] ) 
			return puts( "NO" ), 0;
	rep( i, 0, M )
		if( A[i] && ! B[i] )
			seq[++ tot] = i;
	puts( "YES" );
	write( tot ), putchar( '\n' );
	rep( i, 1, tot ) write( seq[i] ), putchar( " \n"[i == tot] );
	return 0;
}