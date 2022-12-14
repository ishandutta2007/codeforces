#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int n, m, k, t;

pii w[1024];

int main()
{
    int i, j;
    int a, b;
    int all;
    pii x;

    scanf( "%d %d %d %d", &n, &m, &k, &t );
    for ( i = 1; i <= k; i++ )
    {
        scanf( "%d %d", &a, &b );
        w[i] = make_pair( a, b );
    }
    sort( w + 1, w + k + 1 );

    for ( i = 1; i <= t; i++ )
    {
        scanf( "%d %d", &a, &b );
        x = make_pair( a, b );
        j = lower_bound( w + 1, w + k + 1, x ) - w;
        if ( w[j] == x )
        {
            printf( "Waste\n" );
        }
        else
        {
            j--;
            all = (a-1)*m + b - j;
            all = all % 3;
            if ( all == 1 ) printf( "Carrots\n" );
            else if ( all == 2 ) printf( "Kiwis\n" );
            else printf( "Grapes\n" );
        }
    }
    return 0;
}