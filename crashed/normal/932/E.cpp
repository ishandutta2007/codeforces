#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 1e9 + 7, inv2 = ( mod + 1 ) >> 1;
const int MAXN = 5005;

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

int fac[MAXN], ifac[MAXN];
int dn[MAXN], inv[MAXN];

int f[MAXN], pw[MAXN];

int prime[MAXN], pn;
bool isPrime[MAXN];

int N, K;

inline int Qkpow( int, int );
inline int Inv( const int &a ) { return Qkpow( a, mod - 2 ); }
inline int Mul( int x, const int &v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int& MulEq( int &x, const int &v ) { return x = 1ll * x * v % mod; }
inline int& SubEq( int &x, const int &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline int& AddEq( int &x, const int &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

inline int C( const int &r ) { return N < r ? 0 : Mul( dn[r], ifac[r] ); }
inline int C( int n, int m ) { return n < m ? 0 : Mul( fac[n], Mul( ifac[m], ifac[n - m] ) ); }

inline int Qkpow( int base, int indx ) {
	int ret = 1;
	while( indx ) {
		if( indx & 1 ) MulEq( ret, base );
		MulEq( base, base ), indx >>= 1;
	}
	return ret;
}

inline void EulerSieve( const int &n ) {
	pw[0] = K == 0, pw[1] = 1;
	for( int i = 2 ; i <= n ; i ++ ) {
		if( ! isPrime[i] ) {
			prime[++ pn] = i;
			pw[i] = Qkpow( i, K );
		}
		for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= n ; j ++ ) {
			isPrime[i * prime[j]] = true;
			pw[i * prime[j]] = Mul( pw[i], pw[prime[j]] );
			if( ! ( i % prime[j] ) ) break;
		}
	}
}

inline void Init( const int &n ) {
	EulerSieve( n );
	fac[0] = 1; rep( i, 1, n ) fac[i] = Mul( fac[i - 1], i );
	ifac[n] = Inv( fac[n] ); per( i, n - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
	dn[0] = 1; rep( i, 1, n ) dn[i] = Mul( dn[i - 1], ( N - i + 1 ) % mod );
	rep( i, 1, n ) inv[i] = Mul( ifac[i], fac[i - 1] );
}

int main() {
	read( N ), read( K );
	if( N <= K ) {
		Init( N ); int ans = 0;
		rep( i, 1, N )
			AddEq( ans, Mul( pw[i], C( i ) ) );
		write( ans ), putchar( '\n' );
	} else {
		Init( K + 1 ); 
		int pw2 = Qkpow( 2, N );
		rep( i, 0, K ) {
			int res = Mul( C( i ), pw2 );
			i & 1 ? SubEq( f[0], res ) : AddEq( f[0], res );
			MulEq( pw2, inv2 );
		}
		int coe = Mul( Mul( ( K + 1 ) % mod, Qkpow( 2, N - K ) ), C( K + 1 ) );
		rep( r, 0, K - 1 ) {
			int res = Mul( ( N - r ) % mod, f[r] ),
				tmp = Mul( coe, C( K, r ) );
			( K - r + 1 ) & 1 ? SubEq( res, tmp ) : AddEq( res, tmp );
			f[r + 1] = Mul( inv[r + 1], res );
		}
		int ans = 0;
		rep( i, 0, K ) AddEq( ans, Mul( f[i], pw[i] ) );
		write( ans ), putchar( '\n' );
	}
	return 0;
}