#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, k;
long long ans;
vector<int> g[50020];
int c[50020][512];

bool us[50020];

void dfs( int v )
{
	int i, u;
	int l;
	
	memset( c[v], 0, sizeof( c[v] ) );
	c[v][0] = 1;
	for ( i = 0; i < (int)g[v].size(); i++ )
	{
		u = g[v][i];
		if ( us[u] == 0 )
		{
			us[u] = 1;
			dfs( u );
			for ( l = 0; l < k; l++ )
			{
				ans = ans + (long long)c[v][l]*(long long)c[u][k-l-1];
			}
			for ( l = 1; l <= k; l++ )
			{
				c[v][l] = c[v][l] + c[u][l-1];
			}
		}
	}
}

int main()
{
	int i, a, b;
	
	scanf( "%d %d", &n, &k );
	for ( i = 1; i < n; i++ )
	{
		scanf( "%d %d", &a, &b );
		g[a].push_back( b );
		g[b].push_back( a );
	}
	
	ans = 0;
	memset( us, 0, sizeof( us ) );
	us[1] = 1;
	dfs( 1 );
	
	cout << ans << endl;
	return 0;
}