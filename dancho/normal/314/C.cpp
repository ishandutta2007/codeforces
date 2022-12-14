#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int mod = 1000000007;
const int mval = 1000020;

long long it[ 1<<20 ];

void addIt( int pos, long long val )
{
	while ( val < 0 )
		val += (long long) mod*100;
	if ( val >= mod )
		val %= mod;
	pos++;
	for ( int i = pos; i <= mval; i += (i&(-i)) )
	{
		it[i] += val;
		if ( it[i] >= mod )
			it[i] %= mod;
	}
}

long long getIt( int pos )
{
	pos++;
	long long res = 0;
	for ( int i = pos; i > 0; i -= (i&(-i)) )
	{
		res += it[i];
		if ( res >= mod )
			res %= mod;
	}
	return res;
}

int n;
int a[100020];

long long gf[ 1<<20 ];
long long f[100020];
long long mul[ 1<<20 ];

int main()
{
	int i;
	long long ans;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
		mul[ a[i] ] = 1;
	}
	
	memset( it, 0, sizeof( it ) );
	memset( gf, 0, sizeof( gf ) );
	
	gf[0] = 1;
	f[0] = 1;
	addIt( 0, 1 );
	
	for ( i = 1; i <= n; i++ )
	{
		f[i] = getIt( a[i]-1 ) * a[i];
		if ( f[i] >= mod ) f[i] %= mod;
		
		addIt( a[i], mod-gf[ a[i] ] );
		
		gf[ a[i] ] = gf[ a[i] ]*a[i] + f[i];
		if ( gf[ a[i] ] >= mod )
			gf[ a[i] ] %= mod;

		addIt( a[i], gf[ a[i] ] );
	}
	
	ans = ( mod + getIt( 1000001 ) - 1 )%mod;
	printf( "%d\n", (int) ans );
	return 0;
}