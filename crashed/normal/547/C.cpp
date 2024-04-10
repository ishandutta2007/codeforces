#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;

const int MAXN = 5e5 + 5;

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

vector<int> fact[MAXN];

int mu[MAXN];
int prime[MAXN], pn;
bool isPrime[MAXN];

int su[MAXN];
int a[MAXN];

int N, Q;
bool in[MAXN];

void EulerSieve( const int siz )
{
	mu[1] = 1;
	for( int i = 2 ; i <= siz ; i ++ )
	{
		if( ! isPrime[i] ) mu[prime[++ pn] = i] = - 1;
		for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= siz ; j ++ )
		{
			isPrime[i * prime[j]] = true;
			if( ! ( i % prime[j] ) ) break;
			mu[i * prime[j]] = - mu[i];
		}
	}
}

void Init()
{
	const int lim = 5e5;
	EulerSieve( lim );
	for( int i = 1 ; i <= N ; i ++ )
		for( int k = 1 ; 1ll * k * k <= a[i] ; k ++ )
			if( ! ( a[i] % k ) )
			{
				fact[i].push_back( k );
				if( k * k != a[i] )
					fact[i].push_back( a[i] / k );
			}
}

int Add( const int x, const int v )
{
	LL pre = su[x] * su[x]; su[x] += v;
	LL suf = su[x] * su[x];
	return suf - pre;
}

int main()
{
	read( N ), read( Q );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	Init();
	
	LL ans = 0;
	int cnt1 = 0, X, coe;
	while( Q -- )
	{
		read( X );
		if( in[X] ) coe = -1;
		else coe = 1;
		in[X] ^= 1;
		cnt1 += coe * ( a[X] == 1 );
		
		for( int i = 0 ; i < fact[X].size() ; i ++ )
		{
			int d = fact[X][i];
			ans += mu[d] * Add( d, coe );
		}
		write( ans - cnt1 >> 1 ), putchar( '\n' );
	}
	return 0;
}