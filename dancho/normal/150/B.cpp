#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int mod = 1000000007;

vector<int> g[2048];
int n, m, k;

int us[2048];

void dfs( int v ){
	int i, u;
	for ( i = 0; i < (int)g[v].size(); i++ )
	{
		u = g[v][i];
		if ( us[u] == 0 )
		{
			us[u] = 1;
			dfs( u );
		}
	}
}

int main()
{
	int i, j;
	
	scanf( "%d %d %d", &n, &m, &k );
	
	for ( i = 1; i+k-1 <= n; i++ )
	{
		for ( j = 0; j < k; j++ )
		{
			g[i+j].push_back( i+k-1-j );
//			g[i+k-1-j].push_back( i+j );
		}
	}
	
	memset( us, 0, sizeof( us ) );
	
	long long sol = 1;
	for ( i = 1; i <= n; i++ )
	{
		if ( us[i] == 0 )
		{
			us[i] = 1;
			dfs( i );
			sol = (sol * m)%mod;
		}
	}
	
	i = sol;
	printf( "%d\n", i );
	return 0;
}