#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long lint;

int n, m, k;
lint a[100020], b[100020], c[100020];

int main()
{
    int i, j, l;
    lint p, ans;

    scanf( "%d %d %d", &n, &m, &k );
    for ( i = 1; i <= m; i++ )
    {
        scanf( "%I64d %I64d %I64d", &a[i], &b[i], &c[i] );
    }
    ans = 0;
    for ( i = 1; i <= k; i++ )
    {
        scanf( "%d", &j );
        for ( l = 1; l <= m; l++ )
        {
            if ( ( j >= a[l] ) && ( j <= b[l] ) )
            {
                p = j - a[l];
                ans = ans + p + c[l];
            }
        }
    }
        printf( "%I64d\n", ans );
    return 0;
}