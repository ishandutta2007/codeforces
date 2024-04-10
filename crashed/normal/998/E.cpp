#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
const int MAXN = 1e6 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int fac[MAXN], ifac[MAXN];
int pw[MAXN];
int N;

inline int Qkpow( int, int );
inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }
inline int C( int n, int m ) { return n < m ? 0 : Mul( fac[n], Mul( ifac[m], ifac[n - m] ) ); }

inline int Qkpow( int base, int indx )
{
	int ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = Mul( ret, base );
		base = Mul( base, base ), indx >>= 1;
	}
	return ret;
}

inline void Init( const int n )
{
	fac[0] = 1; rep( i, 1, n ) fac[i] = Mul( fac[i - 1], i );
	ifac[n] = Inv( fac[n] ); per( i, n - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

int main()
{
	read( N ), pw[0] = 1, Init( N );
	rep( i, 1, N ) pw[i] = Mul( pw[i - 1], 3 );
	int ans = Qkpow( Sub( pw[N], 3 ), N ), res;
	rep( i, 1, N )
	{
		res = Mul( C( N, i ), Add( Mul( Qkpow( pw[N - i], N ), Sub( pw[i], 3 ) ), Mul( 3, Qkpow( Sub( pw[N - i], 1 ), N ) ) ) );
		ans = i & 1 ? Sub( ans, res ) : Add( ans, res );
	}
	write( Sub( Qkpow( pw[N], N ), ans ) ), putchar( '\n' );
	return 0;
}