#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef pair<int,int> pii;

int sg[100020];
int xr[100020];
int av[100];

int getSG( int x )
{
    if ( sg[x] != -1 )
        return sg[x];
    long long i, k, ak;
    int av[350];
    memset( av, 0, sizeof( av ) );
    for ( k = 2; k*k <= 2*x; k++ )
    {
        if ( (2*x-k*k)%k == 0 )
        {
            if ( ((2*x-k*k)/k+1)%2 == 0 )
            {
                ak = ((2*x-k*k)/k+1)/2;
            }
        }
    }
}

int main()
{
    int x;
    long long i, j, k, ak;
    int n;
    int bs;

    sg[0] = 0;
    sg[1] = 0;
    sg[2] = 0;

    xr[0] = 0;
    xr[1] = 0;
    xr[2] = 0;
    int mi = 0;

    /*getSG*/
    scanf( "%d", &n );
    for ( x = 3; x <= n; x++ )
    {
        memset( av, 0, sizeof( av ) );
        bs = 0;
        for ( k = 2; k*k <= 2*x; k++ )
        {
            if ( (2*x-k*k)%k == 0 )
            {
                if ( ((2*x-k*k)/k+1)%2 == 0 )
                {
                    ak = ((2*x-k*k)/k+1)/2;
                    av[ xr[ak+k-1]^xr[ak-1] ] = 1;
//                    mi = max( mi, (xr[ak+k-1]^xr[ak-1]) );
                    if ( ( (xr[ak+k-1]^xr[ak-1]) == 0 ) && ( bs == 0 ) )
                        bs = k;
                }
            }
        }
        i = 0;
        while ( av[i] == 1 )
            i++;
        mi = max( mi, (int)i );
        sg[x] = i;
        xr[x] = xr[x-1]^sg[x];
    }
//    cout << mi << endl;

    if ( getSG( n ) == 0 )
    {
        printf( "-1\n" );
    }
    else
        printf( "%d\n", bs );
    return 0;
}