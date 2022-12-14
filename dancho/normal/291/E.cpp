#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int sol = 0;
int n, m;
string s[1<<17];
vector<int> son[1<<17];

char t[1<<20];
int f[1<<20];

void dfs( int v, int st )
{
	int u, i, j, k;
	for ( i = 0; i < (int) son[v].size(); i++ )
	{
		u = son[v][i];
		
		k = st;
		for ( j = 0; j < (int) s[u].size(); j++ )
		{
			while ( 1 )
			{
				if ( s[u][j] == t[k+1] )
				{
					k++;
					break;
				}
				if ( k == 0 )
				{
					break;
				}
				k = f[k];
			}
			if ( k == m )
			{
				sol++;
				k = f[k];
			}
		}
		
		dfs( u, k );
	}
}

int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 2; i <= n; i++ )
	{
		scanf( "%d %s", &k, t );
		s[i] = t;
		son[k].push_back( i );
	}
	
	t[0] = '@';
	scanf( "%s", t+1 );
	m = strlen( t )-1;
	f[0] = f[1] = 0;
	
	for ( i = 2; i <= m; i++ )
	{
		j = f[i-1];
		while ( 1 )
		{
			if ( t[j+1] == t[i] )
			{
				f[i] = j+1;
				break;
			}
			if ( j == 0 )
			{
				f[i] = 0;
				break;
			}
			j = f[j];
		}
	}
	
	dfs( 1, 0 );
	
	printf( "%d\n", sol );
	return 0;
}