#include <cstdio>
#include <cstring>
//#include <map>
//using namespace std;

//typedef pair<int,int> pii;

int n, m, p;

int sol[5020][5020];
int le[1000020];
int sm[1000020];
int dp[10000020];
//map< pii, int > dp;
int sdp[1000020];

long long f[5020], fa[5020];

long long getSol( int le, int co )
{
	//printf( "IN SOL %d %d\n", le, co );
	if ( le < co ) return 0;
	if ( le == co ) return 1;
	if ( co == 1 )
	{
		if ( le == 1 ) return 1;
		return 0;
	}
	if ( le == 0 ) return 1;
	if ( sol[le][co] != -1 ) return sol[le][co];
	
	sol[le][co] = getSol( le-1, co-1 ) + ( (long long)getSol( le-1, co )*( co-1 ) ) % p;
	if ( sol[le][co] >= p ) sol[le][co] = sol[le][co] % p;
//	printf( "SOL SOL %d %d %d\n", le, co, sol[le][co] );
	return sol[le][co];
}

//getSol( le[j], k )*fa[k]*(fa[m]/(fa[k]*fa[m-k])-1)
//getSol( le[j], k )*f[k] - getSol( l

int getDP( int, int );

int getSDP( int j )
{
	//printf( "IN SDP %d\n", j );
	if ( sdp[j] != -1 ) return sdp[j];
	sdp[j] = 0;
	for ( int i = 1; i <= le[j]; i++ )
	{
		sdp[j] = sdp[j] + getDP( j, i );
		if ( sdp[j] >= p ) sdp[j] = sdp[j] % p;
	}
//	printf( "SOL SDP %d %d\n", j, sdp[j] );
	return sdp[j];
}

int getDP( int j, int k )
{
	//printf( "IN DP %d %d\n", j, k );
	if ( k > m ) return 0;
	if ( j == 0 ) return 1;
	if ( j == 1 )
	{
//		printf( "SOL DP %d %d %lld\n", j, k, ( getSol( le[j], k )*f[k] )%p );
		return ( getSol( le[j], k )*f[k] )%p;
	}
	if ( k > le[j] ) return 0;
//	pii a = make_pair( j, k );
	int a = sm[j-1] + k;
	if ( dp[a] != -1 )
		return dp[a];
	long long sol = (long long) getSol( le[j], k )*f[k], s2, s3;
	if ( sol >= p ) sol = sol % p;
	sol = sol*( (long long) getSDP( j-1 ) - (long long) getDP( j-1, k ) + p ); //choose(m,k) = f[m]/f[m-k] = (m-k+1)*(m-k+2)*....*(m-1)*m;
	if ( sol >= p ) sol = sol % p;
	s2 = getSol( le[j], k )*f[k];
	if ( s2 >= p ) s2 = s2 % p;
	s3 = getSol( le[j], k )*fa[k];
	if ( s3 >= p ) s3 = s3 % p;
	s2 = s2 + p - s3;
	if ( s2 >= p ) s2 = s2 % p;
	s2 = s2 * getDP( j-1, k );
	if ( s2 >= p ) s2 = s2 % p;
	sol = sol + s2;
	if ( sol >= p ) sol = sol % p;
	dp[a] = sol;
//	printf( "SOL DP %d %d %d _ %d\n", j, k, dp[a], a );
	return dp[a];
}

int main()
{
	int i, j, k;
	
	scanf( "%d %d %d", &n, &m, &p );
	sm[0] = 0;
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &le[i] );
		sm[i] = sm[i-1] + le[i];
	}
	
	fa[0] = 1;
	for ( i = 1; i <= 5000; i++ )
	{
		fa[i] = fa[i-1]*i;
		if ( fa[i] >= p ) fa[i] = fa[i] % p;
	}
	
	for ( i = 1; i <= 5000; i++ )
	{
		if ( i > m ) break;
		f[i] = 1;
		for ( j = 1, k = m; j <= i; j++, k-- )
		{
			f[i] = f[i]*k;
			if ( f[i] >= p ) f[i] = f[i] % p;
		}
//		printf( "F %d %lld\n", i, f[i] );
	}
	
	memset( sol, -1, sizeof( sol ) );
	memset( sdp, -1, sizeof( sdp ) );
	memset( dp, -1, sizeof( dp ) );
	
	printf( "%d\n", getSDP( n ) );
	return 0;
}