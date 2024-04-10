#include <map>
#include <ctime>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long LL;

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

map<LL, int> mp;

LL a[MAXN], fac[MAXN];
int cnt[MAXN], tot;
int N;

LL gcd( const LL a, const LL b )
{
	return b ? gcd( b, a % b ) : a;
}

int main()
{
	srand( time( 0 ) );
	read( N ); LL ans = 1;
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] ); 
	for( int tims = 1 ; tims <= 10 ; tims ++ )
	{
		tot = 0; mp.clear();
		int p = 1ll * rand() * rand() % N + 1;
		for( LL i = 1 ; i * i <= a[p] ; i ++ )
			if( ! ( a[p] % i ) )
				tot ++, mp[fac[tot] = i] = tot;
		int lst = tot;
		if( 1ll * fac[lst] * fac[lst] == a[p] ) lst --;
		for( ; lst ; lst -- ) tot ++, mp[fac[tot] = a[p] / fac[lst]] = tot;
		for( int i = 1 ; i <= tot ; i ++ ) cnt[i] = 0;
		for( int i = 1 ; i <= N ; i ++ ) cnt[mp[gcd( a[i], a[p] )]] ++;
		for( int i = 1 ; i <= tot ; i ++ )
			for( int j = i + 1 ; j <= tot ; j ++ )
				if( ! ( fac[j] % fac[i] ) )
					cnt[i] += cnt[j];
		for( int i = 1 ; i <= tot ; i ++ ) 
			if( 2 * cnt[i] >= N )
				ans = MAX( ans, fac[i] );
	}
	write( ans ), putchar( '\n' );
	return 0;
}