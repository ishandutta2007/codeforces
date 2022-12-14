#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> g[50020];

int sz[50020];

bool issol[50020];

vector<int> sol;

void solve( int v )
{
	int i, u;
	bool cr[5020];
	sz[v] = 1;
	
	memset( cr, 0, sizeof( cr ) );
	cr[0] = 1;
	for ( i = 0; i < (int) g[v].size(); i++ )
	{
		u = g[v][i];
		if ( sz[u] == -1 )
		{
			solve( u );
			sz[v] += sz[u];
			
			for ( int j = n-sz[u]; j >= 0; j-- )
			{
				if ( cr[j] ) cr[ j+sz[u] ] = 1;
			}
		}
	}
	
	if ( g[v].size() == 1 && sz[v] == 1 ) return;
	
	for ( int j = n-(n-sz[v]); j >= 0; j-- )
	{
		if ( cr[j] ) cr[j+(n-sz[v])] = 1;
	}
	
	for ( int j = 1; j < n-1; j++ )
	{
		if ( cr[j] == 0 ) continue;
		if ( !issol[ j ] )
		{
			issol[ j ] = 1;
			sol.push_back( j );
		}
	}
}

int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 1; i < n; i++ )
	{
		scanf( "%d %d", &j, &k );
		g[j].push_back( k );
		g[k].push_back( j );
	}
	
	memset( sz, -1, sizeof( sz ) );
	memset( issol, 0, sizeof( issol ) );
	solve( 1 );
	
	printf( "%d\n", sol.size() );
	sort( sol.begin(), sol.end() );
	for ( i = 0; i < (int) sol.size(); i++ )
	{
		printf( "%d %d\n", sol[i], n-sol[i]-1 );
	}
	return 0;
}