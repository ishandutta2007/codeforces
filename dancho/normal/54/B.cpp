#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <string>
using namespace std;

int a, b;
int bsol;
int bx, by;
char p[32][32];

set<string> S;
string str, s2, s3, s4;

int main()
{
    int i, j, k;
    int s, t;
    int x, y;

    scanf( "%d %d", &a, &b );
    for ( i = 0; i < a; i++ )
    {
        scanf( "%s", &p[i] );
    }

    bx = a;
    by = b;

    bsol = 0;
    for ( x = 1; x <= a; x++ )
    {
        if ( a % x != 0 ) continue;
        for ( y = 1; y <= b; y++ )
        {
            if ( b % y != 0 ) continue;
            S.clear();
            for ( s = 0; s < a/x; s++ )
            {
                for ( t = 0; t < b/y; t++ )
                {
                    str = "";
                    for ( i = 0; i < x; i++ )
                    {
                        for ( j = 0; j < y; j++ )
                        {
                            str = str + p[s*x+i][t*y+j];
                        }
                    }
                    if ( S.find( str ) != S.end() )
                        break;
                    S.insert( str );
                    s2 = "";
                    for ( i = x-1; i >= 0; i-- )
                    {
                        for ( j = y-1; j >= 0; j-- )
                        {
                            s2 = s2 + p[s*x+i][t*y+j];
                        }
                    }
                    if ( s2 != str )
                    {
                        if ( S.find( s2 ) != S.end() )
                            break;
                        S.insert( s2 );
                    }
                    if ( x == y )
                    {
                        s3 = "";
                        s4 = "";
                        for ( i = x; i >= 0; i-- )
                        {
                            for ( j = 0; j < x; j++ )
                            {
                                s3 = s3 + p[s*x+j][t*y+i];
                            }
                        }
                        if ( ( s3 != s2 ) && ( s3 != str ) )
                        {
                            if ( S.find( s3 ) != S.end() )
                                break;
                            S.insert( s3 );
                        }

                        for ( i = 0; i < x; i++ )
                        {
                            for ( j = x-1; j >= 0; j-- )
                            {
                                s4 = s4 + p[s*x+j][t*y+i];
                            }
                        }
                        if ( ( s4 != s2 ) && ( s4 != str ) && ( s4 != s3 ) )
                        {
                            if ( S.find( s4 ) != S.end() )
                                break;
                            S.insert( s4 );
                        }
                    }
                }
                if ( t < b/y )
                    break;
            }
            if ( s < a/x ) continue;
            bsol++;
            if ( x*y < bx*by )
            {
                bx = x; by = y;
            }
            else if ( x*y == bx*by )
            {
                if ( x < bx )
                {
                    bx = x; by = y;
                }
            }
        }
    }
    printf( "%d\n", bsol );
    printf( "%d %d\n", bx, by );
    return 0;
}