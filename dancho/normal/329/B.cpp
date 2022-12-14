#include <cstdio>
#include <cstring>

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int r, c;
int sol = 0;
char t[1024][1024];
int di[1024][1024];
int qb, qe;
int qx[1<<20], qy[1<<20];

int ds = (1<<29);

void bfs()
{
	memset( di, -1, sizeof( di ) );
	int i, j, k, u, v;
	
	qb = 1;
	qe = 0;
	for ( i = 0; i < r; i++ )
	{
		for ( j = 0; j < c; j++ )
		{
			if ( t[i][j] == 'E' )
			{
				qx[++qe] = i;
				qy[qe] = j;
				di[i][j] = 0;
			}
		}
	}
	
	while ( qb <= qe )
	{
		v = qx[qb];
		u = qy[qb++];
		//printf( "BFS %d %d %d\n", v, u, di[v][u] );
		
		for ( k = 0; k < 4; k++ )
		{
			i = v + dx[k];
			j = u + dy[k];
			if ( i >= 0 && j >= 0 && i < r && j < c )
			{
			//printf( "ED %d %d %d %d\n", i, j, di[i][j], t[i][j] );
				if ( di[i][j] == -1 && t[i][j] != 'T' )
				{
					di[i][j] = di[v][u] + 1;
					qe++;
					qx[qe] = i;
					qy[qe] = j;
					if ( t[i][j] == 'S' )
						ds = di[i][j];
					else if ( di[i][j] <= ds )
					{
						sol += (t[i][j]-'0');
					}
				}
			}
		}
	}
}

int main()
{
	scanf( "%d %d", &r, &c );
	for (int i = 0; i < r; i++)
	{
		scanf( "%s", t[i] );
	}
	
	bfs();
	printf( "%d\n", sol );
	return 0;
}