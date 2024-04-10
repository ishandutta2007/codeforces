#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 1e9 + 7;
const int MAXN = 700 + 5, MAXK = 10;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int low[MAXK];

int fac[MAXN], ifac[MAXN];

int V[MAXN], pw[MAXN], spw[MAXN];

int X[MAXN];
char str[MAXN];
int N, ans = 0, inv9;

inline int Qkpow( int, int );
inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

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
	spw[0] = pw[0] = 1, V[0] = 0;
	rep( i, 1, N ) 
	{
		pw[i] = Mul( pw[i - 1], 10 ); 
		V[i] = Add( V[i - 1], pw[i - 1] );
	}
	inv9 = Inv( 9 );	
	fac[0] = 1; rep( i, 1, N ) fac[i] = Mul( fac[i - 1], i );
	ifac[N] = Inv( fac[N] ); per( i, N - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

int Calc( const int L )
{
	int ret = 0, prod = 1;
	per( k, 9, 1 )
	{
		int coe = Mul( inv9, Sub( Mul( Qkpow( 100 - 9 * k, L ), ifac[L] ), Mul( Qkpow( 91 - 9 * k, L ), ifac[L] ) ) );
		ret = Add( ret, Mul( Mul( prod, k ), Add( Mul( coe, pw[low[k]] ), 
			                                      Mul( V[low[k]], Mul( Qkpow( 90 - 9 * k + 1, L ), ifac[L] ) ) ) ) );
		prod = Mul( prod, pw[low[k]] );
	}
	return Mul( ret, fac[L] );
}

int main()
{
//	freopen( "sum.in", "r", stdin );
//	freopen( "sum.out", "w", stdout );
	scanf( "%s", str + 1 ), N = strlen( str + 1 );
	rep( i, 1, N ) X[N - i + 1] = str[i] - '0';
	Init();
	per( i, N, 1 )
	{
		rep( j, 0, X[i] - 1 )
		{
			low[j] ++; 
			ans = Add( ans, Calc( i - 1 ) ); 
			low[j] --;
		}
		low[X[i]] ++;
	}
	ans = Add( ans, Calc( 0 ) );
	write( ans ), putchar( '\n' );
	return 0;
}