#include <cstdio>

typedef long long LL;

const int mod = 1e9 + 7;
const int MAXN = 255;

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

int C[MAXN][MAXN];
int N, K;

int Qkpow( int, int );
int Mul( LL x, int v ) { return x * v % mod; }
int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

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

int main()
{
	read( N ), read( K );
	for( int i = 0 ; i <= N ; i ++ )
	{
		C[i][0] = C[i][i] = 1;
		for( int j = 1 ; j < i ; j ++ )
			C[i][j] = Add( C[i - 1][j], C[i - 1][j - 1] );
	}
	int ans = 0, tmp;
	for( int i = 0 ; i <= N ; i ++ )
		for( int j = 0 ; j <= N ; j ++ )
		{
			tmp = Mul( Mul( C[N][i], C[N][j] ), Mul( Qkpow( K - 1, i * N + j * N - i * j ), Qkpow( K, ( N - i ) * ( N - j ) ) ) );
			ans = ( i + j ) & 1 ? Sub( ans, tmp ) : Add( ans, tmp );
		}
	write( ans ), putchar( '\n' );
	return 0;
}