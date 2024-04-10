#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m, K;
int px[128], py[128];

int main()
{
    int i, j, k;
    bool vw = 0;

    scanf( "%d %d %d", &n, &m, &K );
    for ( i = 1; i <= K; i++ )
    {
        scanf( "%d %d", &px[i], &py[i] );
        if ( ( px[i] <= 5 ) || ( px[i] >= n-4 ) )
        {
            vw = 1;
        }
        if ( ( py[i] <= 5 ) || ( py[i] >= m-4 ) )
        {
            vw = 1;
        }
    }

    if ( vw == 1 )
    {
        printf( "YES\n" );
        return 0;
    }
    printf( "NO\n" );
    return 0;
}