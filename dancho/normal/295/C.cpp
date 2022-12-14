#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int mod = 1000000007;

struct el
{
	int s, e, d;
	el() {}
	el( int _s, int _e, int _d )
	{
		s = _s;
		e = _e;
		d = _d;
	}
};

queue<el> q;

int n, m;
int be, bd;

int di[2][64][64];

void bfs()
{
	int i, l, j, k;
	memset( di, 127, sizeof( di ) );
//	printf( "%d\n", di[0][0][0] );
	q.push( el( 1, 0, 0 ) );
	di[1][0][0] = 0;
	while ( q.size() )
	{
		el a = q.front();
		q.pop();
		int s = a.s;
		if ( s == 1 )
		{
			j = be-a.e;
			k = bd-a.d;
		}
		else
		{
			j = a.e;
			k = a.d;
		}
		
		//printf( "ST %d %d %d :: %d %d\n", s, a.e, a.d, j, k );
		for ( i = 0; i <= j; i++ )
		{
			for ( l = 0; l <= k; l++ )
			{
				if ( i + 2*l <= m && i + l > 0 )
				{
					int nj, nk;
					if ( s == 0 )
					{
						nj = a.e - i;
						nk = a.d - l;
					}
					else
					{
						nj = a.e + i;
						nk = a.d + l;
					}
					
//					printf( "MOVE! %d %d %d -> %d %d %d\n", s, a.e, a.d, 1-s, nj, nk );
					if ( di[1-s][nj][nk] > 1 + di[s][a.e][a.d] )
					{
						di[1-s][nj][nk] = 1 + di[s][a.e][a.d];
						q.push( el( 1-s, nj, nk ) );
					}
				}
			}
		}
	}
}

long long co[128][128];
long long gc( int n, int k )
{
	if ( n < k ) return 0;
	if ( k == 0 ) return 1;
	if ( n == 0 ) return 0;
	if ( co[n][k] != -1 )
		return co[n][k];
	co[n][k] = gc( n-1, k ) + gc( n-1, k-1 );
	if ( co[n][k] >= mod )
		co[n][k] -= mod;
	return co[n][k];
}

long long dp[2][64][64];

long long getDP( int s, int e, int d )
{
	if ( s == 1 && e == 0 && d == 0 )
	{
		return 1;
	}
	if ( dp[s][e][d] != -1 )
		return dp[s][e][d];

	long long sol = 0;
	long long p;
	int i, l, j, k;

	if ( s == 1 )
	{
		j = be-e;
		k = bd-d;
	}
	else
	{
		j = e;
		k = d;
	}
	
	//printf( "IN dp %d %d %d :: %d %d\n", s, e, d, j, k );
	for ( i = 0; i <= j; i++ )
	{
		for ( l = 0; l <= k; l++ )
		{
			if ( i + 2*l <= m && i + l > 0 )
			{
				int nj, nk;
				if ( s == 0 )
				{
					nj = e - i;
					nk = d - l;
				}
				else
				{
					nj = e + i;
					nk = d + l;
				}
				//printf( "nFOUND?? %d %d %d -> %d %d %d\n", s, e, d, 1-s, nj, nk );
				if ( di[s][e][d] == 1 + di[1-s][nj][nk] )
				{
					//printf( "FOUND?? %d %d %d -> %d %d %d ::: %d %d\n", s, e, d, 1-s, nj, nk, di[s][j][k], di[1-s][nj][nk] );
					p = gc( j, i ) * gc( k, l );
					if ( p >= mod ) p %= mod;
					//printf( "CH %lld\n", p );
					p = p * getDP( 1-s, nj, nk );
					if ( p >= mod )
						p = p % mod;
					sol += p;
					if ( sol >= mod )
						sol -= mod;
				}
			}
		}
	}
	dp[s][e][d] = sol;
	return dp[s][e][d];
}

int main()
{
	int i, j;
	
	scanf( "%d %d", &n, &m );
	m = m / 50;
	be = 0; bd = 0;
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &j );
		if ( j == 50 )
			be++;
		else
			bd++;
	}
	
	memset( co, -1, sizeof( co ) );
	
	bfs();
	
	memset( dp, -1, sizeof( dp ) );
	if ( di[0][60][60] == di[0][be][bd] )
		printf( "-1\n0\n" );
	else
		printf( "%d\n%d\n", di[0][be][bd], (int) getDP( 0, be, bd ) );
	return 0;
}