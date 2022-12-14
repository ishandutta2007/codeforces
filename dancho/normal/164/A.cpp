#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m;

vector<int> g[100020];
vector<int> gt[100020];

int f[100020];

int us[100020];

int r2[100020];

void dfst( int v )
{
	if ( f[v] == 1 ) return;
	int i, u;
	for ( i = 0; i < (int)gt[v].size(); i++ )
	{
		u = gt[v][i];
		if ( r2[u] == 0 )
		{
			r2[u] = 1;
			dfst( u );
		}
	}
}

void dfs( int v )
{
	int i, u;
	for ( i = 0; i < (int)g[v].size(); i++ )
	{
		u = g[v][i];
		if ( us[u] == 0 )
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
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &f[i] );
	}
	
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d", &j, &k );
		g[j].push_back( k );
		gt[k].push_back( j );
	}
	
	memset( r2, 0, sizeof( r2 ) );
	
	for ( i = 1; i <= n; i++ )
	{
		if ( ( f[i] == 2 ) && ( r2[i] == 0 ) )
		{
			r2[i] = 1;
			dfst( i );
		}
	}
	
	memset( us, 0, sizeof( us ) );
	
	for ( i = 1; i <= n; i++ )
	{
		if ( ( f[i] == 1 ) && ( us[i] == 0 ) )
		{
			us[i] = 1;
			dfs( i );
		}
	}
	
	for ( i = 1; i <= n; i++ )
	{
		if ( us[i] && r2[i] )
			printf( "1\n" );
		else printf( "0\n" );
	}
	return 0;
}