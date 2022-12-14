#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, x;
int par[1024];
int ne[1024];
vector<int> len;

int f[1024];

int main()
{
	memset( ne, 0, sizeof( ne ) );
	int i, j, k;
	int xp = 0;
	scanf( "%d %d", &n, &x );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &par[i] );
		ne[ par[i] ] = i;
	}
	
	for ( i = 1; i <= n; i++ )
	{
		if ( par[i] == 0 )
		{
			k = 0;
			j = i;
			int pos = -1;
			while ( j != 0 )
			{
				k++;
				if ( j == x )
					pos = k;
				j = ne[j];
			}
			if ( pos == -1 )
				len.push_back( k );
			else
				xp = pos;
		}
	}
	
	memset( f, 0, sizeof( f ) );
	f[0] = 1;
	for ( i = 0; i < (int) len.size(); i++ )
	{
		for ( j = n; j >= len[i]; j-- )
		{
			if ( f[j-len[i]] )
				f[j] = 1;
		}
	}
	
	for ( i = 0; i <= n; i++ )
	{
		if ( f[i] )
		{
			printf( "%d\n", i + xp );
		}
	}
	return 0;
}