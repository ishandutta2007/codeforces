#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> s[2048];
int md;
int dep[2048];
int p[2048];

void dfs( int v )
{
	int i, u;
	for ( i = 0; (unsigned)i < s[v].size(); i++ )
	{
		u = s[v][i];
		dep[u] = dep[v] + 1;
		if ( md < dep[u] ) md = dep[u];
		dfs( u );
	}
}

int main()
{
	int i;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &p[i] );
		if ( p[i] == -1 ) continue;
		s[p[i]].push_back( i );
	}
	
	md = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( p[i] == -1 )
		{
			dep[i] = 1;
			if ( dep[i] > md ) md = dep[i];
			dfs( i );
		}
	}
	printf( "%d\n", md );
	return 0;
}