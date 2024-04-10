#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;

int main()
{
    int i, j, k;
    int m;

    scanf( "%d", &n );
    m = (n/2)*(n-n/2);
    printf( "%d\n", m );
    for ( i = 1; i <= n/2; i++ )
    {
        for ( j = n/2+1; j <= n; j++ )
        {
            printf( "%d %d\n", i, j );
        }
    }
    return 0;
}