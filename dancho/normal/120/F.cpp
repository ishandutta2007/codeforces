#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

FILE * fin;
FILE * fout;

int n;
vector<int> g[128];
int dep[128];

void dfs( int v )
{
	int i, u;
	for ( i = 0; (unsigned)i < g[v].size(); i++ )
	{
		u = g[v][i];
		if ( dep[u] == -1 )
		{
			dep[u] = dep[v] + 1;
			dfs( u );
		}
	}
}

int solve()
{
	int i, j, k;
	memset( dep, -1, sizeof( dep ) );
	dep[1] = 0;
	dfs( 1 );
	k = 1;
	for ( i = 2; i <= n; i++ )
	{
		if ( dep[i] > dep[k] )
			k = i;
	}
	memset( dep, -1, sizeof( dep ) );
	dep[k] = 0;
	dfs( k );
	j = 0;
	for ( i = 1; i <= n; i++ )
		if ( dep[i] > j ) j = dep[i];
	return j;
}

void read()
{
	int i, j, k;
	fscanf( fin, "%d", &n );
	for ( i = 1; i <= n; i++ )
		g[i].clear();
	for ( i = 1; i < n; i++ )
	{
		fscanf( fin, "%d %d", &j, &k );
		g[j].push_back( k );
		g[k].push_back( j );
	}
}

int main()
{
	fin = fopen( "input.txt", "r" );
	fout = fopen( "output.txt", "w" );
	
	int t, T;
	int ans = 0;
	fscanf( fin, "%d", &T );
	for ( t = 0; t < T; t++ )
	{
		read();
		ans = ans + solve();
	}
	fprintf( fout, "%d\n", ans );
	
	fclose( fin );
	fclose( fout );
	return 0;
}