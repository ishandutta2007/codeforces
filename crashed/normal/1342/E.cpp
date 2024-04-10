#include <cstdio>

typedef long long LL;

const int mod = 998244353;
const int MAXN = 2e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
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

int N; LL K;

int Qkpow( int, int );
inline int Mul( LL x, int v ) { return x * v % mod; }
inline int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }
inline int C( int n, int m ) { return n < m ? 0 : Mul( fac[n], Mul( ifac[m], ifac[n - m] ) ); }

int Qkpow( int base, int indx )
{
	int ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = Mul( ret, base );
		base = Mul( base, base ), indx >>= 1;
	}
	return ret;
}

void Init()
{
	fac[0] = 1; for( int i = 1 ; i <= N ; i ++ ) fac[i] = Mul( fac[i - 1], i );
	ifac[N] = Inv( fac[N] ); for( int i = N - 1 ; ~ i ; i -- ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

int S( int n, int m )
{
	int ret = 0, coe;
	for( int i = 0 ; i <= m ; i ++ )
	{
		coe = Mul( C( m, i ), Qkpow( m - i, n ) );
		ret = i & 1 ? Sub( ret, coe ) : Add( ret, coe );
	}
	return ret;
}

int main()
{
	read( N ), read( K ), Init();
	if( K == 0 ) return write( fac[N] ), putchar( '\n' ), 0;
	if( K >= N ) return puts( "0" ), 0;
	write( 2ll * Mul( C( N, N - K ), S( N, N - K ) ) % mod ), putchar( '\n' );
	return 0;
}