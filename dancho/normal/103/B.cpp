#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
vector<int> g[10000];
bool us[10000];

void dfs( int v )
{
	int i, u;
	for ( i = 0; i <(int) g[v].size(); i++ )
	{
		u = g[v][i];
		if ( us[u] == 0)
		{
			us[u] = 1;
			dfs( u );
		}
	}
}

int main()
{
	int i, j, k;
	scanf( "%d %d", &n, &m );
	if ( n != m )
	{
		printf( "NO\n" );
		return 0;
	}
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d", &j, &k );
		g[j].push_back( k );
		g[k].push_back( j );
	}
	
	memset( us, 0, sizeof us );
	dfs( 1 );
	
	for ( i = 1; i <= n; i++ )
	{
		if ( us[i] == 0 ) break;
	}
	if ( i <= n )
	{
		printf( "NO\n" );
		return 0;
	}
	printf( "FHTAGN!\n" );
	return 0;
}