#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m;
char c[1024][1024];

vector<int> g[2048];
queue<int> q;
int d[2048];

int bfs( int s, int t )
{
	int v, u, i;
	
	memset( d, -1, sizeof( d ) );
	
	d[s] = 0;
	q.push( s );
	while ( q.size() > 0 )
	{
		v = q.front();
		if ( v == t ) return d[t];
		q.pop();
		for ( i = 0; i < (int) g[v].size(); i++ )
		{
			u = g[v][i];
			if ( d[u] == -1 )
			{
				d[u] = 1+d[v];
				q.push( u );
			}
		}
	}
	return -1;
}

int main()
{
	int i, j;
	
	scanf( "%d %d", &n, &m );
	for ( i = 0; i < n; i++ )
	{
		scanf( "%s", c[i] );
	}
	
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
		{
			if ( c[i][j] == '#' )
			{
				g[i].push_back( n+j );
				g[n+j].push_back( i );
			}
		}
	}
	
	printf( "%d\n", bfs( n-1, 0 ) );
	return 0;
}