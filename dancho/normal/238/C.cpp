#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
bool a[3020][3020];
vector<int> g[3020];
vector<int> ug[3020];

int bup[3020];
int bl[3020];
bool us[3020];
int bsol = (1<<29);
int par[3020];
int S;

void dfs( int v )
{
	int i, u;
	bup[v] = 0;
	for ( i = 0; i < (int) ug[v].size(); i++ )
	{
		u = ug[v][i];
		if ( bup[u] == -1 )
		{
			bup[u] = 0;
			if ( !bl[v] && !a[v][u] )
				bl[u] = 1;
			par[u] = v;
			dfs( u );
			bup[v] = bup[v] + (1-a[v][u]) + bup[u];
		}
	}
}

int dfs2( int v )
{
	int i, u, j;
	int sol = 0;
	for ( i = 0; i < (int) ug[v].size(); i++ )
	{
		u = ug[v][i];
		if ( par[u] == v )
		{
			us[u] = 1;
			j = 0;
			if ( a[v][u] ) j++;
			else j--;
			sol = min( sol, dfs2( u ) + j );
		}
	}
	if ( sol < S )
	{
		S = sol;
// 		printf( "%d %d\n", v, S );
	}
	return sol;
}

int main()
{
	int i, j, k;
	memset( a, 0, sizeof( a ) );
	
	scanf( "%d", &n );
	for ( i = 1; i < n; i++ )
	{
		scanf( "%d %d", &j, &k );
		a[j][k] = 1;
		ug[j].push_back( k );
		ug[k].push_back( j );
	}
	
	for ( i = 1; i <= n; i++ )
	{
		//probvai i za koren a.k.a. brat;
		memset( bup, -1, sizeof( bup ) );
		memset( bl, 0, sizeof( bl ) );
		memset( par, -1, sizeof( par ) );
		bup[i] = 0;
		dfs( i );
		
		memset( us, 0, sizeof( us ) );
		S = 0;
		dfs2( i );
		bsol = min( bsol, bup[i] + S );
		/*if ( bsol == 2 )
		{
			printf( "%d %d\n", i, bup[i] );
			break;
		}*/
	}
	if ( bsol < 0 ) bsol = 0;
	printf( "%d\n", bsol );
	return 0;
}