#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
int b[4020];
int sol = -1;

int dp[4020][4020];
int ne[4020];

vector<int> v[1000020];

int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &b[i] );
		v[b[i]].push_back( i );
	}
	
	for ( i = 1; i <= 1000000; i++ )
	{
		for ( j = v[i].size()-1; j >= 0; j-- )
		{
			if ( j == (int) v[i].size()-1 )
				ne[v[i][j]] = -1;
			else
				ne[ v[i][j] ] = v[i][j+1];
		}
	}
	
	int l, r, m;
	memset( dp, 0, sizeof( dp ) );
	for ( int ii = n; ii > 0; ii-- )
	{
//		printf( "%d\n", ii );
		l = 0; r = v[ b[ii] ].size();
		while ( l+1 < r )
		{
			m = (l+r)/2;
//			printf( "BS %d %d %d\n", l, r, m );
			if ( v[ b[ii] ][m] <= ii )
				l = m;
			else
				r = m;
		}
		i = b[ii];
		j = l;
//		printf( "%d %d %d\n", ii, i, j );
		if ( (int) v[i].size() > sol )
			sol = v[i].size();
			for ( k = ii+1; k <= n; k++ )
			{
//				printf( "GOGO %d\n", k );
				dp[ii][k] = 2;
				l = j; r = v[i].size()-1;
				while ( l+1 < r )
				{
					m = (l+r)/2;
					if ( v[i][m] > k )
						r = m;
					else
						l = m;
				}
				if ( ( r < (int) v[i].size() ) && ( v[i][r] > k ) )
				{
					dp[ ii ][k] = dp[k][ v[i][r] ] + 1;
				}
				if ( sol < dp[ v[i][j] ][k] )
					sol = dp[ v[i][j] ][k];
			}
	}
	printf( "%d\n", sol );
	return 0;
}