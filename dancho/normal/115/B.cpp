#include <cstring>
#include <cstdio>

int min( int a, int b )
{
	if ( a < b ) return a;
	return b;
}

int max( int a, int b )
{
	if ( a > b ) return a;
	return b;
}

int r, c;
int le = 0;
char l[256][256];

int miy[256], may[256];

int solve( int x, int y )
{
	if ( le == 0 ) return 0;
	if ( l[x][y] == 'W' ) le--;
	if ( le == 0 ) return 0;
	if ( x % 2 == 0 )
	{
		if ( ( y < may[x] ) && ( may[x] != -1 ) )
			return 1 + solve( x, y+1 );
		if ( ( y < may[x+1] ) && ( may[x+1] != -1 ) )
			return 1 + solve( x, y+1 );
		return 1 + solve( x+1, y );
	}
	else
	{
		if ( ( y > miy[x] ) && ( miy[x] != -1 ) )
			return 1 + solve( x, y-1 );
		if ( ( y > miy[x+1] ) && ( miy[x+1] != -1 ) )
			return 1 + solve( x, y-1 );
		return 1 + solve( x+1, y );
	}
}

int main()
{
	int i, j;
	
	
	memset( miy, -1, sizeof( miy ) );
	memset( may, -1, sizeof( may ) );
	
	scanf( "%d %d", &r, &c );
	for ( i = 0; i < r; i++ )
	{
		scanf( "%s", l[i] );
		miy[i] = -1; may[i] = -1;
		for ( j = 0; j < c; j++ )
		{
			if ( l[i][j] == 'W' )
			{
				le++;
				may[i] = j;
				if ( miy[i] == -1 )
					miy[i] = j;
			}
		}
	}
	
	printf( "%d\n", solve( 0, 0 ) );
	return 0;
}