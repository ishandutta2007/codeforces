#include <cstdio>
#include <cstring>

struct edge
{
	int t, ne, isl;
};

int n;
long long ans = 0;
int fed[100020];
edge ed[200020];

int par[100020];
int vis[100020];
int nn[100020];
int lc[100020];

void getLC( int v )
{
	int i, u;
	lc[v] = 0;
	nn[v] = 1;
	for ( i = fed[v]; i > 0; i = ed[i].ne )
	{
		u = ed[i].t;
		if ( lc[u] == -1 )
		{
			par[u] = v;
			getLC( u );
			if ( ed[i].isl )
				lc[v] = lc[v] + nn[u];
			else
				lc[v] = lc[v] + lc[u];
			nn[v] = nn[v] + nn[u];
		}
	}
}

void dfs( int v, long long lup )
{
	int i, u;
	long long sm = 0;
	for ( i = fed[v]; i > 0; i = ed[i].ne )
	{
		u = ed[i].t;
		if ( u != par[v] )
		{
			if ( ed[i].isl )
			{
				sm = sm + nn[u];
			}
			else sm = sm + lc[u];
		}
	}
	
	ans = ans + (sm+lup)*(sm+lup-1);
	
	for ( i = fed[v]; i > 0; i = ed[i].ne )
	{
		u = ed[i].t;
		if ( u == par[v] ) continue;
		if ( ed[i].isl )
		{
			dfs( u, n-nn[u] );
		}
		else
		{
			dfs( u, lup+sm-lc[u] );
		}
	}
}

int main()
{
	int i, j, k, l;
	char x[32];
	
	int le = 0;
	
	memset( fed, -1, sizeof( fed ) );
	
	scanf( "%d", &n );
	for ( i = 1; i < n; i++ )
	{
		scanf( "%d %d %s", &j, &k, x );
		for ( l = 0; (unsigned)l < strlen( x ); l++ )
		{
			if ( ( x[l] != '4' ) && ( x[l] != '7' ) )
				break;
		}
		if ( (unsigned)l < strlen( x ) )
		{
			l = 0;
		}
		else l = 1;
		
		le++;
		ed[le].t = k; ed[le].ne = fed[j]; ed[le].isl = l; fed[j] = le;
		
		le++;
		ed[le].t = j; ed[le].ne = fed[k]; ed[le].isl = l; fed[k] = le;
	}
	
	memset( lc, -1, sizeof( lc ) );
	memset( vis, 0, sizeof( vis ) );
	memset( par, -1, sizeof( par ) );
	lc[1] = 0; vis[1] = 1;
	getLC( 1 );
	dfs( 1, 0 );
	
	printf( "%I64d\n", ans );
	return 0;
}