#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 1e9 + 7;
const int MAXN = 55;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = - x;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int f[MAXN][MAXN], g[MAXN][MAXN], h[MAXN][MAXN];
int F[MAXN][MAXN], G[MAXN][MAXN];

int fac[MAXN], ifac[MAXN];

int N, M;

inline int Qkpow( int, int );
inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }
inline void Upt( int &x, const int v ) { x = Add( x, v ); }

void Init( const int n )
{
	fac[0] = 1; rep( i, 1, n ) fac[i] = Mul( fac[i - 1], i );
	ifac[n] = Inv( fac[n] ); per( i, n - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

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

int main()
{
	read( N ), read( M );
	if( N + 1 < M ) return puts( "0" ), 0;
	F[0][1] = f[0][1] = 1, h[0][0] = 1, Init( N );
	rep( i, 1, N )
	{
		per( j, N + 1, 1 )
		{
			G[i][j] = 0;
			rep( k, 0, i - 1 )
				Upt( G[i][j], Mul( F[k][j], F[i - k - 1][j] ) );
			g[i][j] = Sub( G[i][j], G[i][j + 1] );
			per( p, N, 0 ) per( q, N + 1, 0 )
			{
				int tmp = 0;
				for( int k = 0, up = 1 ; i * k <= p && j * k <= q ; k ++ )
					Upt( tmp, Mul( h[p - i * k][q - j * k], Mul( ifac[k], up ) ) ),
					up = Mul( up, Add( g[i][j], k ) );
				h[p][q] = tmp;
			}
		}
		per( j, N + 1, 1 ) F[i][j] = Add( F[i][j + 1], f[i][j] = h[i][j - 1] );
	}
	write( f[N][M] ), putchar( '\n' );
	return 0;
}