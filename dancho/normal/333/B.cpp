#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
bool usr[1024];
bool usc[1024];

int a[8][8];

bool bad[1<<8];

bool f( int j, int i )
{
	if ( j & 1 )
	{
		if ( j == 1 || j == 5 )
			return usr[n-i+1];
		else
			return usc[n-i+1];
	}
	else
	{
		if ( j == 0 || j == 4 )
			return usr[i];
		else
			return usc[i];
	}
}

int main()
{
	int i, j, k;
	
	memset( usr, 0, sizeof( usr ) );
	memset( usc, 0, sizeof( usc ) );
	
	scanf( "%d %d", &n, &k );
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf( "%d %d", &x, &y );
		
		usr[x] = 1;
		usc[y] = 1;
	}
	
	memset( a, 0, sizeof( a ) );
	
	a[0][2] = a[0][4] = a[0][7] = 1;
	a[1][6] = a[1][5] = a[1][3] = 1;
	a[2][0] = a[2][6] = a[2][5] = 1;
	a[3][1] = a[3][7] = a[3][4] = 1;
	a[4][3] = a[4][0] = a[4][6] = 1;
	a[5][2] = a[5][1] = a[5][7] = 1;
	a[6][1] = a[6][2] = a[6][4] = 1;
	a[7][0] = a[7][3] = a[7][5] = 1;
	
	memset( bad, 0, sizeof( bad ) );
	for ( i = 0; i < (1<<8); i++ )
	{
		for ( j = 0; j < 8; j++ )
		{
			for ( k = 0; k < 8; k++ )
			{
				if ( (i&(1<<j)) && (i&(1<<k)) && a[j][k] )
				{
					bad[i] = 1;
				}
			}
		}
	}
	
	int sol = 0;
	for ( i = 2; i <= n-i+1 && i < n; i++ )
	{
		if ( i == n-i+1 )
		{
			if ( !usr[i] || !usc[i] )
				sol++;
		}
		else
		{
			int bc = 0;
			for ( k = 0; k < (1<<8); k++ )
			{
				if ( bad[k] ) continue;
				int c = 0;
				for ( j = 0; j < 8; j++ )
				{
					if ( ( k&(1<<j) ) )
					{
						c++;
						if ( f( j, i ) )
							break;
					}
				}
				if ( j >= 8 )
				{
					if ( c > bc )
					{
						bc = c;
					}
				}
			}
			sol += bc;
		}
	}
	
	printf( "%d\n", sol );
	return 0;
}