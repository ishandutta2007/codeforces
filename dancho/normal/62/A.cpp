#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int ia( int x )
{
    if ( x < 0 ) return -x;
    return x;
}

int main()
{
    int al, ar, bl, br;
    scanf( "%d %d %d %d", &al, &ar, &bl, &br );
    if ( ( al-1 <= br ) && ( (br+1)/2-1 <= al ) )
    {
        printf( "YES\n" );
    }
    else if ( ( ar-1 <= bl ) && ( (bl+1)/2-1 <= ar ) )
    {
        printf( "YES\n" );
    }
    else printf( "NO\n" );
    return 0;
}