#include <cstdio>
#include <vector>
using namespace std;

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

vector<int> fac[MAXN];

int f[MAXN];
int mu[MAXN];
int prime[MAXN], pn;
bool isPrime[MAXN];

int N;

int Qkpow( int, int );
int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
int Sub( int x, int v ) { return x < v ? x + mod - v : x - v; }
int Mul( LL x, int v ) { x *= v; if( x >= mod ) x %= mod; return x; }
int Add( int x, int v ) { return x + v >= mod ? x + v - mod : x + v; }

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
	EulerSieve( N );
	for( int i = 1 ; i <= N ; i ++ )
		for( int k = i ; k <= N ; k += i )
			fac[k].push_back( i );
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

int main()
{
	read( N ), Init();
	int d, k, coe, inv = Inv( N );
	for( int i = 2 ; i <= N ; i ++ )
	{
		f[i] = 1;
		for( int j = 0 ; j < ( int ) fac[i].size() ; j ++ )
		{
			d = fac[i][j], coe = 0;
			for( int t = 0 ; t < ( int ) fac[i / d].size() ; t ++ )
			{
				k = fac[i / d][t];
				coe = Add( coe, Mul( mu[k], N / d / k ) );
			}
			if( d == i ) f[i] = Mul( f[i], Inv( Sub( 1, Mul( coe, inv ) ) ) );
			else f[i] = Add( f[i], Mul( Mul( coe, inv ), f[d] ) );
		}
	}
	int ans = 1;
	for( int i = 1 ; i <= N ; i ++ )
		ans = Add( ans, Mul( f[i], inv ) );
	write( ans ), putchar( '\n' );
	return 0;
}