#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair<int,int> pii;

int n, m;

vector<pii> g[1<<17];

bool mon[1<<17], us[1<<17];

int dup[1<<17];
int vup[1<<17];

int ddo[1<<17];
int vdo[1<<17];

int par[1<<17][18];
int dep[1<<17];
int sm[1<<17][18];
int lsm[1<<17];

void dfs( int v )
{
	int i, u, l;
	
	for ( i = 0; i < (int) g[v].size(); ++i )
	{
		u = g[v][i].first;
		l = g[v][i].second;
		if ( !us[u] )
		{
			us[u] = 1;
			par[u][0] = v;
			dep[u] = dep[v] + 1;
			dfs( u );
			
			if ( vdo[u] )
			{
				if ( ddo[v] < ddo[u] + l )
				{
					ddo[v] = ddo[u] + l;
					vdo[v] = vdo[u];
				}
				else if ( ddo[v] == ddo[u] + l )
				{
					vdo[v] = v;
				}
			}
			if ( mon[u] )
			{
				if ( ddo[v] < l )
				{
					ddo[v] = l;
					vdo[v] = u;
				}
				else if ( ddo[v] == l )
				{
					vdo[v] = v;
				}
			}
		}
	}
}

void dfsdo( int v )
{
	int i, u, l;
	int md = 0, sd = 0, sv = 0;
	set<int> S;

	if ( dup[v] )
	{
		md = dup[v];
		S.insert( vup[v] );
	}
	
	//printf( "DFS ST MD %d %d\n", v, md );
	for ( i = 0; i < (int) g[v].size(); ++i )
	{
		u = g[v][i].first;
		l = g[v][i].second;
		if ( par[u][0] == v )
		{
			if ( vdo[u] )
			{
				if ( ddo[u] + l > md )
				{
					sd = md;
					if ( (int) S.size() > 1 )
						sv = v;
					else
						sv = (*S.begin());
					
					S.clear();
					md = ddo[u] + l;
					S.insert( vdo[u] );
				}
				else if ( ddo[u] + l == md )
				{
					S.insert( vdo[u] );
				}
				else if ( ddo[u] + l > sd )
				{
					sd = ddo[u] + l;
					sv = vdo[u];
				}
				else if ( ddo[u] + l == sd )
				{
					sv = v;
				}
			}
			else if ( mon[u] )
			{
				if ( l > md )
				{
					sd = md;
					if ( (int) S.size() > 1 )
						sv = v;
					else
						sv = (*S.begin());
					
					S.clear();
					md = l;
					S.insert( u );
				}
				else if ( l == md )
				{
					S.insert( u );
				}
				else if ( l > sd )
				{
					sd = l;
					sv = u;
				}
				else if ( l == sd )
				{
					sv = v;
				}
			}
		}
	}
	
	//printf( "DFS UU %d :: %d %d ; %d %d\n", v, md, S.size(), sd, sv );

	for ( i = 0; i < (int) g[v].size(); ++i )
	{
		u = g[v][i].first;
		l = g[v][i].second;
		if ( par[u][0] == v )
		{
			if ( mon[v] )
			{
				dup[u] = l;
				vup[u] = v;
			}
			if ( md )
			{
				int in = 0;
				if ( S.find( u ) != S.end() )
					++in;
				else if ( S.find( vdo[u] ) != S.end() )
					++in;
				//printf( "IN %d %d %d __ %d %d : %d\n", v, u, in, S.size(), md, sd );
				if ( !in )
				{
					dup[u] = l + md;
					if ( (int) S.size() == 1 )
						vup[u] = (*S.begin());
					else
						vup[u] = v;
				}
				else //if ( in )
				{
					if ( S.size() == 1 )
					{
						if ( sd )
						{
							dup[u] = l + sd;
							vup[u] = sv;
						}
					}
					else if ( S.size() > 2 ) 
					{
						dup[u] = l + md;
						vup[u] = v;
					}
					else if ( S.size() == 2 )
					{
						int k = -1;
						for ( set<int>::iterator it = S.begin(); it != S.end(); ++it )
						{
							if ( ( (*it) != u ) && ( (*it) != vdo[u] ) )
								k = (*it);
						}
						dup[u] = l + md;
						vup[u] = k;
					}
				}
			}
			
			dfsdo( u );
		}
	}
}

void addPath( int v, int u )
{
	//printf( "PIL %d (%d) %d (%d)\n", v, dep[v], u, dep[u] );
	if ( dep[v] < dep[u] )
		swap( v, u );
	
	int k = 17;
	while ( dep[v] > dep[u] )
	{
		while ( dep[ par[v][k] ] < dep[u] )
		{
			k--;
		}
		++sm[v][k];
//		printf( "MV V %d %d %d %d\n", v, k, dep[ par[v][k] ], par[v][k] );
		v = par[v][k];
	}
	
	if ( v == u )
	{
		++sm[v][0];
		return;
	}
//	printf( "OPaa %d %d\n", v, u );
	
	k = 17;
	while ( par[v][0] != par[u][0] )
	{
		while ( par[v][k] == par[u][k] )
		{
			k--;
		}
		++sm[v][k];
		v = par[v][k];
		++sm[u][k];
		u = par[u][k];
	}
	++sm[v][0];
	++sm[u][0];
	++sm[ par[v][0] ][0];
}

int ans = 0, ss = 0;
int mp = 0;

int solve( int v )
{
	int i, u;
	int sms = 0;
	for ( i = 0; i < (int) g[v].size(); ++i )
	{
		u = g[v][i].first;
		if ( par[u][0] == v )
		{
			sms += solve( u );
		}
	}

	sms += lsm[v];
	for ( i = 0; i <= 17; i++ )
	{
		sms += sm[v][i];
		//if ( sm[v][i] )
			//printf( "ADD %d %d %d __ %d\n", v, i, sm[v][i], par[v][i] );
		if ( par[v][i] != 0 )
		{
			lsm[ par[v][i] ] -= sm[v][i];
		}
	}
	
	if ( !mon[v] )
	{
		if ( sms > mp )
		{
			mp = sms;
			//printf( "V %d (%d)\n", v, sms );
			ans = 1;
		}
		else if ( sms == mp )
		{
			//printf( "V %d (%d)\n", v, sms );
			ans++;
		}
	}
	
	return sms;
}

int main()
{
	int i, j, k, l;
	
	memset( mon, 0, sizeof( mon ) );
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d", &k );
		mon[k] = 1;
	}
	
	for ( i = 1; i < n; ++i )
	{
		scanf( "%d %d %d", &j, &k, &l );
		g[j].push_back( make_pair( k, l ) );
		g[k].push_back( make_pair( j, l ) );
	}
	
	memset( par, 0, sizeof( par ) );
	memset( us, 0, sizeof( us ) );
	memset( ddo, 0, sizeof( ddo ) );
	memset( vdo, 0, sizeof( vdo ) );
	memset( dup, 0, sizeof( dup ) );
	memset( vup, 0, sizeof( vup ) );

	us[1] = 1;
	dep[1] = 0;
	dep[0] = -1;
	dfs( 1 );
	dfsdo( 1 );
	
	for ( i = 1; i <= 17; ++i )
	{
		for ( j = 1; j <= n; ++j )
		{
			par[j][i] = par[ par[j][i-1] ][i-1];
		}
	}
	
	memset( sm, 0, sizeof( sm ) );
	memset( lsm, 0, sizeof( lsm ) );
	for ( i = 1; i <= n; ++i )
	{
		if ( mon[i] )
		{
			//printf( "OP %d :: %d %d ; %d %d\n", i, ddo[i], vdo[i], dup[i], vup[i] );
			if ( dup[i] > ddo[i] )
			{
				addPath( i, vup[i] );
			}
			else if ( ddo[i] > dup[i] )
			{
				addPath( i, vdo[i] );
			}
		}
	}
	
	solve( 1 );
	
	printf( "%d %d\n", mp, ans );
	
	return 0;
}