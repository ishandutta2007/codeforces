#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
const int MAXN = 1e6 + 5;

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
	if( x < 0 ) putchar( '-' ), x = - x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int inv[MAXN];
int A[MAXN], f[MAXN];
int N, M;

inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

void Init()
{
	inv[1] = 1;
	rep( i, 2, M ) inv[i] = Mul( inv[mod % i], mod - mod / i );
}

int main()
{
	read( N );
	rep( i, 1, N ) read( A[i] ), M += A[i]; Init();
	rep( i, 1, M - 1 ) 
	{
		int coe = Mul( Mul( N - 1, i ), inv[M - i] );
		f[i + 1] = Sub( Mul( Sub( Mul( Mul( N - 1, M ), inv[M - i] ), N - 2 ), f[i] ), 
			            Add( Mul( coe, f[i - 1] ), coe ) );
	}
	int beg = 0, ed = f[M];
	rep( i, 1, N ) beg = Add( beg, f[A[i]] );
	write( Sub( beg, ed ) ), putchar( '\n' );
	return 0;
}