#include <cstdio>

typedef long long LL;

const int mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

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

int mu[MAXN];
int prime[MAXN], pn;
bool isPrime[MAXN];

int pw[MAXN], coe[MAXN];

int b[MAXN];
int N, M;

int Sub( int x, const int v ) { return x < v ? x + mod - v : x - v; }
int Mul( LL x, const int v ) { x *= v; if( x >= mod ) x %= mod; return x; }
int Add( int x, const int v ) { return x + v >= mod ? x + v - mod : x + v; }

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

void Init()
{
	const int lim = 1e6;
	EulerSieve( lim ); pw[0] = 1;
	for( int i = 1 ; i <= lim ; i ++ ) pw[i] = Mul( pw[i - 1], 2 );
	for( int i = 1 ; i <= lim ; i ++ ) coe[i] = Add( Mul( coe[i - 1], 2 ), pw[i - 1] );
}

int main()
{
	read( N );
	for( int i = 1, a ; i <= N ; i ++ )
		read( a ), M = MAX( a, M ), b[a] ++;
	Init();
	for( int i = 1 ; i <= M ; i ++ )
		for( int k = i << 1 ; k <= M ; k += i )
			b[i] = Add( b[k], b[i] );
	int ans = 0;
	for( int d = 2 ; d <= M ; d ++ )
		for( int k = d ; k <= M ; k += d )
			ans = Add( ans, Mul( mu[k / d], Mul( d, coe[b[k]] ) ) );
	write( ans ), putchar( '\n' );
	return 0;
}