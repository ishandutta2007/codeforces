#include <cstdio>
#include <cstring>

int dx[] = {-1,-1,-1,0,0,0,+1,+1,+1};
int dy[] = {-1,0,+1,-1,0,+1,-1,0,+1};

int n;
char b[16][16];
bool oc[16][16][16];
bool vis[16][16][16];

bool dfs( int x, int y, int mv )
{
	//printf( "DFS %d %d %d\n", x, y, mv );
	int nx, ny;
	int i;
	if ( b[x][y] == 'A' )
		return 1;
	for ( i = 0; i < 9; i++ )
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if ( ( nx < 0 ) || ( nx >= n ) || ( ny < 0 ) || ( ny >= n ) ) continue;
		if ( mv < 8 )
		{
			if ( ( vis[nx][ny][mv+1] == 0 ) && ( oc[nx][ny][mv+1] == 0 ) && ( oc[nx][ny][mv] == 0 ) )
			{
				vis[nx][ny][mv+1] = 1;
				if ( dfs( nx, ny, mv+1 ) == 1 ) return 1;
			}
		}
		else
		{
			if ( ( vis[nx][ny][10] == 0 ) )
			{
				vis[nx][ny][10] = 1;
				if ( dfs( nx, ny, 10 ) == 1 ) return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, k;
	n = 8;
	for ( i = 0; i < n; i++ )
	{
		scanf( "%s", b[i] );
	}
	
	memset( oc, 0, sizeof( oc ) );
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( b[i][j] == 'S' )
			{
				oc[i][j][0] = 1;
				k = 1;
				while ( i+k < n )
				{
					oc[i+k][j][k] = 1;
					k++;
				}
			}
		}
	}
	memset( vis, 0, sizeof( vis ) );
	vis[7][0][0] = 1;
	if ( dfs( 7, 0, 0 ) == 1 )
	{
		printf( "WIN\n" );
	}
	else
	{
		printf( "LOSE\n" );
	}
	return 0;
}