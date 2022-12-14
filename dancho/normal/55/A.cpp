#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
bool vis[1024][1024];

int main()
{
    int i, j, k;

    scanf( "%d", &n );
    memset( vis, 0, sizeof( vis ) );
    i = 0; j = 0;
    while ( vis[i][j] == 0 )
    {
        vis[i][j] = 1;
        j = ( j + 1 ) % n;
        i = ( i + j ) % n;
    }
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < n; j++ )
        {
            if ( vis[i][j] ) break;
        }
        if ( j >= n )
            break;
    }
    if ( i < n )
    {
        printf( "NO\n" );
    }
    else
        printf( "YES\n" );
    return 0;
}