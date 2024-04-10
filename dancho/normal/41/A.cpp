#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char s[1024], t[1024];

int main()
{
    int i, j, k;
    int n, m;
    scanf( "%s", &s );
    scanf( "%s", &t );
    n = strlen( s );
    m = strlen( t );
    if ( n != m )
    {
        printf( "NO\n" );
        return 0;
    }
    for ( i = 0, j = n-1; i < n; i++, j-- )
    {
        if ( s[i] != t[j] )
            break;
    }
    if ( i >= n )
    {
        printf( "YES\n" );
        return 0;
    }
        printf( "NO\n" );
        return 0;
}