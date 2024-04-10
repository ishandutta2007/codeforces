#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m, k;
char p[16][16][16];
int vis[16][16][16];

int dfs( int x, int y, int z )
{
    int nx, ny, nz;
    int sol = 0;
    for ( nx = x-1; nx <= x+1; nx++ )
    {
        ny = y; nz = z;
                if ( ( nx >= 0 ) && ( nz >= 0 ) && ( ny >= 0 ) )
                {
                    if ( ( nx < k ) && ( ny < n ) && ( nz < m ) )
                    {
                        if ( ( vis[nx][ny][nz] == 0 ) && ( p[nx][ny][nz] == '.' ) )
                        {
                            vis[nx][ny][nz] = 1;
                            sol = sol + dfs( nx, ny, nz );
                        }
                    }
                }
    }
        for ( ny = y-1; ny <= y+1; ny++ )
        {
            nx = x; nz = z;
                if ( ( nx >= 0 ) && ( nz >= 0 ) && ( ny >= 0 ) )
                {
                    if ( ( nx < k ) && ( ny < n ) && ( nz < m ) )
                    {
                        if ( ( vis[nx][ny][nz] == 0 ) && ( p[nx][ny][nz] == '.' ) )
                        {
                            vis[nx][ny][nz] = 1;
                            sol = sol + dfs( nx, ny, nz );
                        }
                    }
                }
        }
            for ( nz = z-1; nz <= z+1; nz++ )
            {
                nx = x; ny = y;
                if ( ( nx >= 0 ) && ( nz >= 0 ) && ( ny >= 0 ) )
                {
                    if ( ( nx < k ) && ( ny < n ) && ( nz < m ) )
                    {
                        if ( ( vis[nx][ny][nz] == 0 ) && ( p[nx][ny][nz] == '.' ) )
                        {
                            vis[nx][ny][nz] = 1;
                            sol = sol + dfs( nx, ny, nz );
                        }
                    }
                }
            }
    return sol + 1;
}

int main()
{
    int i, j, l;
    int x, y;
    scanf( "%d %d %d", &k, &n, &m );

    for ( i = 0; i < k; i++ )
    {
        for ( j = 0; j < n; j++ )
        {
            scanf( "%s", p[i][j] );
        }
    }
    scanf( "%d %d", &x, &y );
    memset( vis, 0, sizeof( vis ) );
    vis[0][x-1][y-1] = 1;
    printf( "%d\n", dfs( 0, x-1, y-1 ) );
    return 0;
}