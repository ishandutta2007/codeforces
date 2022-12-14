#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m, k;

vector<int> g[100020];
int us[1000000];

vector<long long> b;

long long dfs( int v )
{
	int i, u;
	long long r = 1;
	for ( i = 0; i < (int) g[v].size(); i++ )
	{
		u = g[v][i];
		if ( us[u] == 0 )
		{
			us[u] = 1;
			r = r + dfs( u );
		}
	}
	return r;
}

int main()
{
	int i, a, c;
	long long ans, sm;
	
	scanf( "%d %d %d", &n, &m, &k );
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d", &a, &c );
		g[a].push_back( c );
		g[c].push_back( a );
	}
	
	memset( us, 0, sizeof( us ) );
	for ( i = 1; i <= n; i++ )
	{
		if ( us[i] == 0 )
		{
			us[i] = 1;
			b.push_back( dfs( i ) );
		}
	}
	
	sm = 0;
	ans = 1;
	for ( i = 0; i < (int) b.size(); i++ )
	{
		ans = ans * b[i];
		if ( ans >= k ) ans = ans % k;
		if ( i >= 2 )
		{
			ans = ans * n;
			if ( ans >= k ) ans = ans % k;
		}
	}
	
	if ( b.size() > 1 )
		printf( "%d\n", (int) ans );
	else printf( "%d\n", 1%k );
	return 0;
}