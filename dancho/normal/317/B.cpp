#include <cstdio>
#include <cstring>

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n;
int t[256][256];

int main()
{
	int i, j, k;
	bool fl;
	scanf( "%d", &n );
	
	memset( t, 0, sizeof( t ) );
	t[128][128] = n;
	
	int it = 0;
	while ( 1 )
	{
		it++;
		fl = 0;
		for ( i = 1; i < 255; i++ )
			for ( j = 1; j < 255; j++ )
			{
				if ( t[i][j] >= 4 )
				{
					fl = 1;
					int ad = t[i][j] / 4;
					for ( k = 0; k < 4; k++ )
					{
						t[i+dx[k] ][j+dy[k]] += ad;
					}
					t[i][j] &= 3;
				}
			}
		if ( !fl ) break;
	}
	
	int q;
	scanf( "%d", &q );
	for ( i = 0; i < q; i++ )
	{
		scanf( "%d %d", &j, &k );
		if ( k+128 >= 256 || j+128 >= 256 || k+128 < 1 || j + 128 < 1 )
		{
			printf( "0\n" );
		}
		else
			printf( "%d\n", t[j+128][k+128] );
	}
	
	return 0;
}