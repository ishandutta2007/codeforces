#include <cstdio>
#include <cstring>

int sg[128][4][4];

int getSG( int l, int x, int y )
{
	if ( l <= 0 ) return 0;
	if ( sg[l][x][y] != -1 )
		return sg[l][x][y];
	bool us[128];
	int i, j;
	
	memset( us, 0, sizeof( us ) );
	
	if ( l == 1 )
	{
		if ( x != 2 && y != 2 )
		{
			return sg[l][x][y] = (x == y);
		}
		return sg[l][x][y] = 1;
	}
	
	for ( i = 1; i <= l; i++ )
	{
		if ( i == 1 && x != 2 )
		{
			if ( x == 0 )
			{
				j = 1;
				us[ getSG( l-1, x, y ) ] = 1;
			}
			else if ( x == 1 )
			{
				j = 2;
				us[ getSG( l-1, x, y ) ] = 1;
			}
		}
		else if ( i == l && y != 2 )
		{
			if ( y == 0 )
			{
				j = 1;
				us[ getSG( l-1, x, y ) ] = 1;
			}
			else if ( y == 1 )
			{
				j = 2;
				us[ getSG( l-1, x, y ) ] = 1;
			}
		}
		else
		{
			us[ getSG( i-1, x, 0 ) ^ getSG( l-i, 0, y ) ] = 1;
			us[ getSG( i-1, x, 1 ) ^ getSG( l-i, 1, y ) ] = 1;
		}
	}
	
	j = 0;
	while ( us[j] == 1 )
		j++;
	return sg[l][x][y] = j;
}

int r, n;
bool used[128][3];

int gd( int ro )
{
	if ( ro > r )
		return -1;
	if ( used[ro][1] && used[ro][2] )
		return -1;
	if ( !used[ro][1] && !used[ro][2] )
		return 2;
	if ( !used[ro][1] && used[ro][2] )
		return 0;
	return 1;
}

int main()
{
	int i, j, k;
	
	int S = 0;
	
	memset( sg, -1, sizeof( sg ) );
	memset( used, 0, sizeof( used ) );
	
	scanf( "%d %d", &r, &n );
	
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &j, &k );
		used[j][k] = used[j-1][3-k] = used[j][3-k] = used[j+1][3-k] = 1;
	}
	
	int x, y;
	
	k = 0;
	for ( i = 1; i <= r; )
	{
		if ( (x=gd( i )) != -1 )
		{
			j = i+1;
			while ( (y=gd(j)) == 2 && j <= r )
			{
				j++;
			}
			if ( y != -1 )
			{
				j++;
			}
			else
				y = 2;
			S ^= getSG( j-i, x, y );
			//printf( "CALL %d %d %d\n", j-i, x, y );
			i = j;
		}
		else
			i++;
	}
	
	printf( "%s\n", S ? "WIN" : "LOSE" );
	return 0;
}