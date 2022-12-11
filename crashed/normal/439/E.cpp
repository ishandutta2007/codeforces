#include <cstdio>

typedef long long LL;

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

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

int fac[MAXN], ifac[MAXN];

int mu[MAXN];
int prime[MAXN], pn;
bool isPrime[MAXN];

int Qkpow( int, int );
int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
int Sub( int x, const int v ) { return x < v ? x + mod - v : x - v; }
int Mul( LL x, const int v ) { x *= v; if( x >= mod ) x %= mod; return x; }
int Add( int x, const int v ) { return x + v >= mod ? x + v - mod : x + v; }
int C( const int n, const int m ) { return n < m ? 0 : Mul( fac[n], Mul( ifac[m], ifac[n - m] ) ); }

void EulerSieve( const int siz )
{
	mu[1] = 1;
	for( int i = 2 ; i <= siz ; i ++ )
	{
		if( ! isPrime[i] ) mu[prime[++ pn] = i] = mod - 1;
		for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= siz ; j ++ )
		{
			isPrime[i * prime[j]] = true;
			if( ! ( i % prime[j] ) ) break;
			mu[i * prime[j]] = mod - mu[i];
		}
	}
}

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
	const int lim = 1e5;
	EulerSieve( lim ); fac[0] = 1;
	for( int i = 1 ; i <= lim ; i ++ ) fac[i] = Mul( fac[i - 1], i );
	ifac[lim] = Inv( fac[lim] );
	for( int i = lim - 1 ; ~ i ; i -- ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

int main()
{
	Init();
	int T, F, N;
	read( T );
	while( T -- )
	{
		int ans = 0;
		read( N ), read( F );
		for( int i = 1 ; 1ll * i * i <= N ; i ++ )
			if( ! ( N % i ) )
			{
				ans = Add( ans, Mul( C( N / i - 1, F - 1 ), mu[i] ) );
				if( i * i != N )
					ans = Add( ans, Mul( C( i - 1, F - 1 ), mu[N / i] ) );
			}
		write( ans ), putchar( '\n' );
	}
	return 0;
}