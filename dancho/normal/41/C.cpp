#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

char e[1024];
string t;

int main()
{
    int i, j, k;
    int at = 0;
    int n;

    scanf( "%s", &e );

    n = strlen( e );
    t = "";
    for ( i = 0; i < n; )
    {
        k = 0;
        if ( i > 0 )
        {
            if ( i + 2 < n )
            {
                if ( ( e[i] == 'a' ) && ( e[i+1] == 't' ) && ( at == 0 ) )
                {
                    t = t + '@';
                    i = i + 2;
                    at++;
                    k++;
                }
            }
            if ( ( i + 3 < n ) && ( k == 0 ) )
            {
                if ( ( e[i] == 'd' ) && ( e[i+1] == 'o' ) && ( e[i+2] == 't' ) )
                {
                    t = t + '.';
                    i = i + 3;
                    k++;
                }
            }
        }
        if ( k == 0 )
        {
        t = t + e[i];
        i++;
        }
    }
    cout << t << endl;
    return 0;
}