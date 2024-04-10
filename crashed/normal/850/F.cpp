#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

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

template<typename _T>
inline _T Max( const _T &a, const _T &b ) {
	return a > b ? a : b;
}

int f[MAXN], g[MAXN];
int A[MAXN];

int N;

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

int main() {
	read( N ); 
	int mx = 0, s = 0;
	rep( i, 1, N ) {
		read( A[i] );
		mx = Max( mx, A[i] );
		s += A[i];
	}
	g[0] = Mul( Inv( s ), Mul( s - 1, s - 1 ) );
	rep( i, 1, mx )
		g[i] = Sub( g[i - 1], Mul( Inv( s - i ), s - 1 ) );
	f[0] = 0;
	rep( i, 1, mx )
		f[i] = Add( f[i - 1], g[i - 1] );
	int ans = 0;
	rep( i, 1, N ) AddEq( ans, f[A[i]] );
	write( ans ), putchar( '\n' );
	return 0;
}