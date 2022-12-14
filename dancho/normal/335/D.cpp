#include <cstdio>
#include <cstring>

bool us[100020];

int n;

int X1[100020], Y1[100020], X2[100020], Y2[100020];

int ar[3020][3020], psar[3020][3020];
int hol[3020][3020], pshol[3020][3020];
int vel[3020][3020], psvel[3020][3020];
int hor[3020][3020], pshor[3020][3020];
int ver[3020][3020], psver[3020][3020];
int re[3020][3020];
bool an1[3020][3020], an2[3020][3020], an3[3020][3020], an4[3020][3020];

void genPS( int a[3020][3020], int psa[3020][3020] )
{
	int i, j;
	for ( i = 0; i <= 3000; i++ )
	{
		for ( j = 0; j <= 3000; j++ )
		{
			if ( i == 0 || j == 0 )
				psa[i][j] = a[i][j];
			psa[i][j] = a[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
		}
	}
}

int getSM( int psa[3020][3020], int x1, int y1, int x2, int y2 )
{
	if ( x1 && y1 )
		return psa[x2][y2] - psa[x1-1][y2] - psa[x2][y1-1] + psa[x1-1][y1-1];
	if ( x1 )
		return psa[x2][y2] - psa[x1-1][y2];
	if ( y1 )
		return psa[x2][y2] - psa[x2][y1-1];
	return psa[x2][y2];
}

bool chkSQ( int x1, int y1, int x2, int y2 )
{
	return getSM( psar, x1, y1, x2, y2 ) == (x2-x1+1)*(y2-y1+1) &&
			an1[x1][y1] && an2[x1][y2] && an3[x2][y1] && an4[x2][y2] &&
			getSM( pshol, x1, y1, x2, y1 ) == x2-x1+1 && getSM( pshor, x1, y2, x2, y2 ) == x2-x1+1 &&
			getSM( psvel, x1, y1, x1, y2 ) == y2-y1+1 && getSM( psver, x2, y1, x2, y2 ) == y2-y1+1;
}

int main()
{
	int i, j, k;
	
	memset( ar, 0, sizeof( ar ) );
	memset( hol, 0, sizeof( hol ) );
	memset( vel, 0, sizeof( vel ) );
	memset( hor, 0, sizeof( hor ) );
	memset( ver, 0, sizeof( ver ) );
	memset( an1, 0, sizeof( an1 ) );
	memset( an2, 0, sizeof( an2 ) );
	memset( an3, 0, sizeof( an3 ) );
	memset( an4, 0, sizeof( an4 ) );
	
	scanf( "%d", &n );
	for (i = 1; i <= n; i++)
	{
		scanf( "%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i] );
		X1[i]++;
		Y1[i]++;
	//	printf( "SET AN %d %d: 1\n", X1[i], Y1[i] );
		an1[ X1[i] ][ Y1[i] ] = 1;
		an2[ X1[i] ][ Y2[i] ] = 1;
//		printf( "SET AN %d %d: 3\n", X2[i], Y1[i] );
		an3[ X2[i] ][ Y1[i] ] = 1;
		an4[ X2[i] ][ Y2[i] ] = 1;
		for ( j = X1[i]; j <= X2[i]; j++ )
		{
			for ( k = Y1[i]; k <= Y2[i]; k++ )
			{
				ar[j][k]++;
				re[j][k] = i;
			}
		}
		
		for ( j = X1[i]; j <= X2[i]; j++ )
		{
			hol[j][Y1[i]]++;
			hor[j][Y2[i]]++;
		}

		for ( k = Y1[i]; k <= Y2[i]; k++ )
		{
			vel[X1[i]][k]++;
			ver[X2[i]][k]++;
		}
	}
	
	genPS( ar, psar );
	genPS( hol, pshol );
	genPS( hor, pshor );
	genPS( vel, psvel );
	genPS( ver, psver );
	
	for ( i = 1; i <= n; i++ )
	{
		j = X1[i];
		k = Y1[i];
		while ( j <= 3000 && k <= 3000 )
		{
			if ( an4[j][k] )
			{
				//printf( "CHK %d %d %d %d :: %d\n", X1[i], Y1[i], j, k, getSM( psho, X1[i], Y1[i], j, Y1[i] ) );
				if ( chkSQ( X1[i], Y1[i], j, k ) ) 
				{
					memset( us, 0, sizeof( us ) );
					for ( int s = X1[i]; s <= j; s++ )
					{
						for ( int l = Y1[i]; l <= k; l++ )
						{
							us[ re[s][l] ] = 1;
						}
					}
					int c = 0;
					for ( i = 1; i <= n; i++ )
						if (us[i])
							c++;
					printf( "YES %d\n", c );
					j = 0;
					for ( i = 1; i <= n; i++ )
					{
						if ( us[i] ) 
						{
							if ( ++j < c )
								printf( "%d ", i );
							else
								printf( "%d\n", i );
						}
					}
					return 0;
				}
			}
			j++;
			k++;
		}
	}
	printf( "NO\n" );
	return 0;
}