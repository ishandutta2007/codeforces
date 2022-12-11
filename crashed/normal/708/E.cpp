#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 1e9 + 7;
const int MAXN = 1505, MAXK = 1e5 + 5;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int nw[MAXN], s[MAXN];

int fac[MAXK], ifac[MAXK];
int possi[MAXN];

int N, M, P, K;

inline int Qkpow( int, int );
inline int Inv( const int &a ) { return Qkpow( a, mod - 2 ); }
inline int Mul( int x, const int &v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int& MulEq( int &x, const int &v ) { return x = 1ll * x * v % mod; }
inline int& SubEq( int &x, const int &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline int& AddEq( int &x, const int &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

inline int C( int n, int m ) { return n < m ? 0 : Mul( fac[n], Mul( ifac[m], ifac[n - m] ) ); }

inline int Qkpow( int base, int indx ) {
	int ret = 1;
	while( indx ) {
		if( indx & 1 ) MulEq( ret, base );
		MulEq( base, base ), indx >>= 1;
	}
	return ret;
}

inline void Init( const int &n ) {
	fac[0] = 1; rep( i, 1, n ) fac[i] = Mul( fac[i - 1], i );
	ifac[n] = Inv( fac[n] ); per( i, n - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

int main() {
	int A, B;
	read( M ), read( N );
	read( A ), read( B );
	read( K ), Init( K );
	P = Mul( A, Inv( B ) );
	for( int i = 0 ; i <= N && i <= K ; i ++ )
		possi[i] = Mul( C( K, i ), Mul( Qkpow( P, i ), Qkpow( Sub( 1, P ), K - i ) ) );
	s[N] = 1;
	rep( t, 1, M ) {
		int suP = 0, suPS = 0;
		rep( r, 1, N ) {
			AddEq( suP, possi[r - 1] );
			AddEq( suPS, Mul( possi[r - 1], s[r - 1] ) );
			nw[r] = Add( nw[r - 1], Mul( possi[N - r], Sub( Mul( s[N], suP ), Add( suPS, Mul( s[N - r], suP ) ) ) ) );
		}
		rep( r, 1, N ) s[r] = nw[r];
	}
	write( s[N] ), putchar( '\n' );
	return 0;
}