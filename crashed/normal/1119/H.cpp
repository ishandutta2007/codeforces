#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353, inv2 = 499122177;
const int MAXN = 1e6 + 5, MAXS = ( 1 << 20 ) + 5;

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

int F[MAXS], G[MAXS], dp[MAXS];
int bit[MAXS], coe[MAXS], su[MAXS];

int A[20], P[20];
int N, M, K;

inline int Lowbit( const int x ) { return x & ( - x ); }
inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

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

void FWT( int *coe, const int n, const int t )
{
	int a, b;
	for( int stp = 1 ; stp < n ; stp <<= 1 )
		for( int i = 0 ; i < n ; i += stp << 1 )
			for( int j = 0 ; j < stp ; j ++ )
			{
				a = coe[i + j], b = coe[i + j + stp];
				if( ~ t )
					coe[i + j] = Add( a, b ),
					coe[i + j + stp] = Sub( a, b );
				else
					coe[i + j] = Mul( inv2, Add( a, b ) ),
					coe[i + j + stp] = Mul( inv2, Sub( a, b ) );
			}
}

int main()
{
//	freopen( "nirvana.in", "r", stdin );
//	freopen( "nirvana.out", "w", stdout );
	read( N ), read( M ), K = 3; 
	int pwM = 1 << M, pwK = 1 << K;
	rep( i, 1, K ) bit[1 << ( i - 1 )] = i;
	rep( i, 1, K ) read( A[i] ), su[0] = Add( su[0], A[i] );
	rep( S, 1, pwK - 1 ) su[S] = Sub( su[S ^ Lowbit( S )], Mul( 2, A[bit[Lowbit( S )]] ) );
	
	rep( i, 1, N )
	{
		rep( j, 1, K ) read( P[j] );
		coe[0] = 0;
		rep( S, 1, pwK - 1 ) coe[S] = coe[S ^ Lowbit( S )] ^ P[bit[Lowbit( S )]];
		rep( S, 0, pwK - 1 ) F[S * pwM + coe[S]] = Add( F[S * pwM + coe[S]], 1 );
	}
	rep( S, 0, pwK - 1 ) FWT( F + S * pwM, pwM,  1 );
	rep( S, 0, pwK - 1 ) rep( T, 0, pwM - 1 ) G[T * pwK + S] = F[S * pwM + T];
	rep( T, 0, pwM - 1 ) 
	{
		dp[T] = 1;
		FWT( G + T * pwK, pwK, -1 );
		rep( S, 0, pwK - 1 ) 
			dp[T] = Mul( dp[T], Qkpow( su[S], G[T * pwK + S] ) );
	}
	FWT( dp, pwM, -1 );
	rep( i, 0, pwM - 1 ) write( dp[i] ), putchar( i == pwM - 1 ? '\n' : ' ' );
	return 0;
}