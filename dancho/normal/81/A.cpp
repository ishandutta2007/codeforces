#include <iostream>
#include <cstring>
#include <cstdio>
#include <list>
using namespace std;

int n;
list<char> ls;
char x[300020];

int main()
{
    int i, j, k;
    list<char>::iterator it, jt, kt;

    scanf( "%s", x );
    n = strlen( x );
    for ( i = 0; i < n; i++ )
    {
        ls.push_back( x[i] );
    }

    it = ls.begin();
    jt = it; jt++;
    if ( jt == ls.end() )
    {
        printf( "%s\n", x );
        return 0;
    }

    for ( ; jt != ls.end() && it != ls.end(); )
    {
        if ( (*it) == (*jt) )
        {
            kt = it;
            if ( it != ls.begin() )
                it--;
            else
            {
                it++; it++;
            }
            ls.erase( kt );
            kt = jt;
            jt++;
            if ( jt == it ) jt++;
            ls.erase( kt );
        }
        else
        {
            it++; jt++;
        }
    }
    for ( it = ls.begin(); it != ls.end(); it++ )
    {
        printf( "%c", (*it) );
    }
    printf( "\n" );
    return 0;
}