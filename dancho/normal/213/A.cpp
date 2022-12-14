#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n;
int used;
int vis[256];
int in[256];
int us[256];
int col[256];
vector<int> g[256];

void dfs( int v, int st )
{
	if ( vis[v] == 1 ) return;
	vis[v] = 1;
	used++;
	int i, u;
	for ( i = 0; i < (int) g[v].size(); i++ )
	{
		u = g[v][i];
		us[u]++;
		if ( ( us[u] == in[u] ) && ( vis[u] == 0 ) && ( col[u] == st ) )
			dfs( u, st );
	}
}

void put( int st )
{
	for ( int i = 1; i <= n; i++ )
	{
		if ( ( col[i] == st ) && ( vis[i] == 0 ) && ( in[i] == us[i] ) )
			dfs( i, st );
	}
}

int solve( int st )
{
	memset( us, 0, sizeof( us ) );
	memset( vis, 0, sizeof( vis ) );
	used = 0;
	int ans = 0;
	while ( used < n )
	{
		put( st );
		st++;
		if ( st > 3 ) st -= 3;
		ans++;
	}
	ans--;
	return ans;
}

int main()
{
	int i, j, k;
	
	memset( in, 0, sizeof( in ) );
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &col[i] );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &k );
		while ( k-- )
		{
			scanf( "%d", &j );
			g[j].push_back( i );
			in[i]++;
		}
	}
	
	int ans = (1<<29);
	for ( k = 1; k <= 3; k++ )
	{
		ans = min( ans, solve( k ) );
	}
	ans = ans + n;
	printf( "%d\n", ans );
	return 0;
}