#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int a[1024][1024];

vector<int> rows[1024];
bool usr[1024];

int main()
{
	int l, r = -1, mi;
	int i, j, k;

	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= n; i++ )
		for ( j = 1; j <= m; j++ )
		{
			scanf( "%d", &a[i][j] );
			if ( r < a[i][j] )
				r = a[i][j];
		}
	
	l = 0; r++;
	//printf( "BR %d\n", r );
	while ( l + 1 < r )
	{
		mi = (l+r)/2;
		//printf( "%d %d %d\n", l, r, mi );
		for ( i = 0; i < m+1; ++i)
		{
			rows[i].clear();
		}
		
//		printf( "SLOOP!\n" );
		for ( i = n; i > 0; --i )
		{
			memset( usr, 0, sizeof( usr ) );
			for ( j = 1; j <= m; ++j )
			{
				if ( a[i][j] >= mi )
				{
//					printf( "ENT %d %d %d\n", i, j, rows[j].size() );
					for ( k = 0; k < (int) rows[j].size(); ++k )
					{
						if ( usr[ rows[j][k] ] )
						{
//							printf( "FOUND %d %d\n", i, rows[j][k] );
							goto success;
						}
						usr[ rows[j][k] ] = 1;
					}
					rows[j].push_back( i );
				}
			}
		}
		r = mi;
		continue;
		
		success:
		l = mi;
	}
	printf( "%d\n", l );
	return 0;
}