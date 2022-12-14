#include <cstdio>
#include <cstring>

const int mod = 1000000007;
const long long gr = 100000000000000LL;

int mp[128][128];
int mm[128][128];

int br[128];

long long ans;

int m;
int n;


void count( int cur,  int us[], long long coef )
{
	if ( cur > m/2 ) return;
	count( cur+1, us, coef );
	if ( us[cur] == 0 )
	{
		int i;
		int nus[64];
		memset( nus, 0, sizeof( nus ) );
		
		nus[cur] = 1;
//		nus[m-cur] = 1;
		for ( i = 0; i <= m/2; ++i )
		{
			if ( us[i] )
			{
				nus[i] = 1;
				nus[ mp[i][cur] ] = 1;
				nus[ mm[i][cur] ] = 1;
			}
		}

//			printf( "+ %d %d\n", cur, coef * ( br[cur] ) );
		long long nc = coef*br[cur];
		if ( nc >= gr ) nc = nc % mod;
		ans += nc;
		if ( ans >= gr ) ans = ans % mod;
		count( cur+1, nus, nc );
//			printf( "- %d\n", cur );
	}
}

int main()
{
	scanf( "%d", &m );
	scanf( "%d", &m );

	for (int i = 0; i <= m/2; i++)
	{
		for ( int j = 0; j <= m/2; j++ )
		{
			mp[i][j] = (i+j)%m;
			if ( mp[i][j] > m/2 ) mp[i][j] = m - mp[i][j];
			mm[i][j] = (i-j+m)%m;
			if ( mm[i][j] > m/2 ) mm[i][j] = m - mm[i][j];
		}
	}
	
	memset( br, 0, sizeof( br ) );
	scanf( "%d", &n );
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf( "%d", &k );
		br[k%m]++;
	}
	
//	for ( int i = 0; i < m; i++ )
//		printf( "%d %d\n", i, br[i] );

	for ( int i = 1; i < m/2; i++ )
	{
		br[i] += br[m-i];
		//printf( "BR %d %d\n", i, br[i] );
	}
	if ( m%2 == 1 )
		br[m/2] += br[m-m/2];
	//printf( "BF %d %d\n", m/2, br[m/2] );
	
	ans = 1;
	int us[64];
	memset( us, 0, sizeof( us ) );
	
//	fprintf( stderr, "END READ\n" );

	count( 1, us, 1 );
	ans = ans % mod;
	printf( "%d\n", (int)ans );
	return 0;
}