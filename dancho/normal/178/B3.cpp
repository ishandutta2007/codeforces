#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int n, m, k;
vector<int> g[100020];

int ln, nn[100020], lp[100020];

set< pair<int,int> > S;
int col[100020];
vector<int> gc[100020];

int par[100020][18], dep[100020];

void dfsBI( int v, int p )
{
	nn[v] = ++ln;
	lp[v] = nn[v];
	int i, u;
	for ( i = 0; i < (int) g[v].size(); i++ )
	{
		u = g[v][i];
		if ( nn[u] == -1 )
		{
			dfsBI( u, v );
			lp[v] = min( lp[v], lp[u] );
			if ( lp[u] == nn[u] )
			{
				S.insert( make_pair( min(u,v), max(u,v) ) );
			}
		}
		else if ( u != p )
		{
			lp[v] = min( lp[v], nn[u] ); //min( lp[v], u ) ?
		}
	}
	
	//printf( "LP %d %d %d\n", v, nn[v], lp[v] );
}

void dfsCol( int v )
{
	int i, u;
	for ( i = 0; i < (int) g[v].size(); i++ )
	{
		u = g[v][i];
		if ( S.find( make_pair( min(u,v), max(u,v) ) ) != S.end() ) continue;
		if ( col[u] == -1 )
		{
			col[u] = col[v];
			dfsCol( u );
		}
	}
}

void dfsCPar( int v )
{
	int i, u;
	for ( i = 0; i < (int) gc[v].size(); i++ )
	{
		u = gc[v][i];
		if ( par[u][0] == -1 )
		{
			par[u][0] = v;
			dep[u] = dep[v] + 1;
			dfsCPar( u );
		}
	}
}

int lca( int v, int u )
{
	if ( dep[v] < dep[u] ) return lca( u, v );
	
	int k = 17;
	while ( dep[v] > dep[u] )
	{
		while ( ( k >= 0 ) && ( ( par[v][k] == -2 ) || ( dep[ par[v][k] ] < dep[u] ) ) )
			k--;
		v = par[v][k];
	}
	
	if ( v == u ) return u;
	
	k = 17;
	while ( par[v][0] != par[u][0] )
	{
		while ( ( par[v][k] == -2 ) || ( par[v][k] == par[u][k] ) )
			k--;
		v = par[v][k];
		u = par[u][k];
	}
	
	return par[v][0];
}

int dist( int u, int v )
{
	return dep[u] + dep[v] - 2*dep[ lca( v, u ) ];
}

int main()
{
	int i, j, l, sz;
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d", &j, &l );
		g[j].push_back( l );
		g[l].push_back( j );
	}
	
	memset( nn, -1, sizeof( nn ) );
	ln = 0;
	dfsBI( 1, 0 );
	
	memset( col, -1, sizeof( col ) );
	j = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( col[i] == -1 )
		{
			col[i] = ++j;
			dfsCol( i );
		}
	}
	
	sz = j;
	
	set<pair<int,int> >::iterator it;
	for ( it = S.begin(); it != S.end(); it++ )
	{
	//	printf( "EDGE! %d %d %d %d\n", col[ it->first ], col[ it->second ], it->first, it->second );
		gc[ col[ it->first ] ].push_back( col[ it->second ] );
		gc[ col[ it->second ] ].push_back( col[ it->first ] );
	}
	
	memset( par, -1, sizeof( par ) );
	par[1][0] = -2;
	dep[1] = 1;
	dfsCPar( 1 );
	
	/*for ( i = 1; i <= n; i++ )
	{
		printf( "%d %d %d\n", i, col[i], par[i][0] );
	}*/
	
	for ( i = 1; i <= 17; i++ )
	{
		for ( j = 1; j <= sz; j++ )
		{
			if ( par[j][i-1] == -2 ) par[j][i] = -2;
			else par[j][i] = par[ par[j][i-1] ][i-1];
			//printf( "PAR %d %d %d\n", j, i, par[j][i] );
		}
	}
	
	scanf( "%d", &k );
	for ( i = 1; i <= k; i++ )
	{
		scanf( "%d %d", &j, &l );
		printf( "%d\n", dist( col[j], col[l] ) );
	}
	return 0;
}