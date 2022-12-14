#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
vector<int> g[1<<17];

bool us[1<<17];

int sz[1<<17];

void dfs( int v )
{
	if ( us[v] ) return;
	us[v] = 1;
	int i;
	for ( i = 0; i < (int) g[v].size(); i++ )
	{
		dfs( g[v][i] );
	}
}

int main()
{
	int i, j, k;
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d", &j, &k );
		g[j].push_back( k );
		g[k].push_back( j );
	}
	
	memset( us, 0, sizeof( us ) );
	dfs( 1 );
	
	memset( sz, 0, sizeof( sz ) );
	
	for ( i = 1; i <= n; i++ )
	{
		sz[ g[i].size() ]++;
		if ( !us[i] )
		{
			printf( "unknown topology\n" );
			return 0;
		}
	}
	
	if ( sz[n-1] == 1 )
	{
		if ( sz[1] == n-1 )
		{
			printf( "star topology\n" );
			return 0;
		}
	}
	else if ( sz[2] == n )
	{
		printf( "ring topology\n" );
		return 0;
	}
	else if ( sz[1] == 2 && sz[2] == n-2 )
	{
		printf( "bus topology\n" );
		return 0;
	}
	
	printf( "unknown topology\n" );
	return 0;
}