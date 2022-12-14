#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int oc[256];

int n, m;
char s[1024];

set<char> S;

int main()
{
	int i, j, k;
	scanf( "%s", s );
	scanf( "%d", &n );
	m = strlen( s );
	
	memset( oc, 0, sizeof( oc ) );
	
	for ( i = 0; i < m; i++ )
	{
		oc[ (int) s[i] ]++;
		S.insert( s[i] );
	}
		
	if ( (int) S.size() > n )
	{
		printf( "-1\n" );
		return 0;
	}
	
	for ( k = 1; k <= m+10; k++ )
	{
		j = 0;
		for ( i = 0; i < 256; i++ )
		{
			j += (oc[i]+k-1)/k;
		}
		
		if ( j <= n )
		{
			printf( "%d\n", k );
			int pr = 0;
			for ( i = 0; i < 256; i++ )
			{
				for ( j = 0; j < (oc[i]+k-1)/k; j++ )
				{
					printf( "%c", (char) i );
					pr++;
				}
			}
			while ( pr < n )
			{
				printf( "x" );
				pr++;
			}
			printf( "\n" );
			return 0;
		}
	}
	return 0;
}