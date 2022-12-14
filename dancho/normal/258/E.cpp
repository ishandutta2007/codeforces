#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m;

vector<int> g[100020];
vector<int> oc[100020];
int ln;
int num[100020];
int end[100020];

int cov[1<<18];
int emp[1<<18];
int sz[1<<18];

int us[100020];
int c[100020];

void dfsnum( int v )
{
	int i, u;
	for ( i = 0; i < (int) g[v].size(); i++ )
	{
		u = g[v][i];
		if ( !num[u] )
		{
			num[u] = ++ln;
			dfsnum( u );
		}
	}
	end[v] = ln;
}

void cover( int nd, int nl, int nr, int l, int r )
{
	if ( ( l <= nl ) && ( nr <= r ) )
	{
		emp[nd] = 0;
		cov[nd]++;
		return;
	}
	if ( l > nr || nl > r ) return;
	
	cover( nd*2, nl, (nl+nr)/2, l, r );
	cover( nd*2+1, (nl+nr)/2+1, nr, l, r );
	
	if ( !cov[nd] )
		emp[nd] = emp[2*nd] + emp[2*nd+1];
	else
		emp[nd] = 0;
}

void cover( int l, int r )
{
	cover( 1, 1, (1<<17), l, r );
}

void uncover( int nd, int nl, int nr, int l, int r )
{
	if ( ( l <= nl ) && ( nr <= r ) )
	{
		cov[nd]--;
		if ( !cov[nd] )
		{
			if ( nl != nr )
				emp[nd] = emp[2*nd] + emp[2*nd+1];
			else
				emp[nd] = 1;
		}
		else
			emp[nd] = 0;
		return;
	}
	if ( l > nr || nl > r ) return;
	
	uncover( nd*2, nl, (nl+nr)/2, l, r );
	uncover( nd*2+1, (nl+nr)/2+1, nr, l, r );
	
	if ( !cov[nd] )
		emp[nd] = emp[2*nd] + emp[2*nd+1];
	else
		emp[nd] = 0;
}

void uncover( int l, int r )
{
	uncover( 1, 1, (1<<17), l, r );
}

int empty()
{
	return emp[1];
}

void dfs( int v )
{
	//printf( "DFS %d\n", v );
	int i, u;
	for ( i = 0; i < (int) oc[v].size(); i++ )
	{
		//printf( "COV1 %d %d\n", num[v], end[v] );
		cover( num[v], end[v] );
		u = oc[v][i];
		//printf( "COV %d (%d,%d) %d (%d,%d)\n", v, num[v], end[v], u, num[u], end[u] );
		cover( num[u], end[u] );
	}
	c[v] = n-empty();
	if ( c[v] )
		c[v]--;
	for ( i = 0; i < (int) g[v].size(); i++ )
	{
		u = g[v][i];
		//printf( "ED %d %d\n", v, u );
		if ( !us[u] )
		{
			us[u] = 1;
			dfs( u );
		}
	}
	for ( i = 0; i < (int) oc[v].size(); i++ )
	{
		uncover( num[v], end[v] );
		u = oc[v][i];
		uncover( num[u], end[u] );
	}
}

int main()
{
	int i, j, k;
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i < n; i++ )
	{
		scanf( "%d %d", &j, &k );
		g[j].push_back( k );
		g[k].push_back( j );
	}
	
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d", &j, &k );
		oc[j].push_back( k );
		oc[k].push_back( j );
	}
	
	memset( num, 0, sizeof( num ) );
	ln = 0;
	num[1] = ++ln;
	dfsnum( 1 );
	
	memset( cov, 0, sizeof( cov ) );
	memset( emp, 0, sizeof( emp ) );
	for ( i = n+(1<<17)-1; i >= (1<<17); i-- )
	{
		emp[i] = 1;
	}
	for ( i = (1<<17)-1; i > 0; i-- )
	{
		emp[i] = emp[2*i] + emp[2*i+1];
	}
	
	memcpy( sz, emp, sizeof( sz ) );
	
	memset( us, 0, sizeof( us ) );
	us[1] = 1;
	dfs( 1 );
	
	for ( i = 1; i < n; i++ )
	{
		printf( "%d ", c[i] );
	}
	printf( "%d\n", c[n] );
	return 0;
}