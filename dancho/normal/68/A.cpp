#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int br[32000];
int a, b;
int p[8];

int main()
{
    int i, j, k;
    scanf( "%d %d %d %d %d %d", &p[1], &p[2], &p[3], &p[4], &a, &b );
    sort( p + 1, p + 4 + 1 );
    memset( br, 0, sizeof( br ) );
    do
    {
        for ( i = a; i <= b; i++ )
        {
            j = i;
            for ( k = 1; k <= 4; k++ )
            {
                j = j % p[k];
            }
            if ( j == i ) br[i]++;
        }
    }
    while ( next_permutation( p+1, p+4+1 ) );
    int sol = 0;
    for ( i = a; i <= b; i++ )
    {
        if ( br[i] >= 7 )
            sol++;
    }
    printf( "%d\n", sol );
    return 0;
}