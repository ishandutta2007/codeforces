#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, c, k;
int p[1024];

int main()
{
    int i, j;
    int sol = 0;
    int la;
    scanf( "%d %d %d", &n, &k, &c );
    for ( i = 1; i <= c; i++ )
    {
        scanf( "%d", &p[i] );
    }
    p[c+1] = (1<<29);

    la = 0;
    i = 1;

    for ( j = 1; j <= n; j++ )
    {
        if ( j == p[i] )
        {
            la = j;
            i++;
            sol++;
        }
        else if ( j - k == la )
        {
            la = j;
            sol++;
        }
    }
    printf( "%d\n", sol );
    return 0;
}