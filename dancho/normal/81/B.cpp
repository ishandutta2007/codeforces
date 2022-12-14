#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

string digs = "0123456789";
char s[10020];
string res;

int main()
{
    fgets( s, 1000, stdin );
    int i, j, k, isn, ln;
    ln = strlen( s );
    ln--;

    res = "";
    k = 0;
    isn = 0;
    for ( i = 0; i < ln; )
    {
        if ( s[i] == ' ' )
        {
            i++;
            continue;
        }
        if ( ( s[i] >= '0' ) && ( s[i] <= '9' ) )
        {
            if ( isn )
                res = res + ' ';
            j = i;
            while ( ( s[j] >= '0' ) && ( s[j] <= '9' ) )
            {
                res = res + s[j];
                j++;
            }
            isn = 1;
            i = j;
            k = 0;
            continue;
        }
            if ( ( s[i] == ',' ) && ( i+1 < ln ) )
            {
                res = res + ',';
                res = res + ' ';
                k = 1;
                i++;
                isn = 0;
                continue;
            }
        if ( ( s[i] == '.' ) && ( i > 0 ) )
        {
            if ( k == 0 )
                res = res + " ...";
            else
                res = res + "...";
            k = 0;
            isn = 0;
            i = i + 3;
            continue;
        }
        if ( ( s[i] == '.' ) && ( i == 0 ) )
        {
            res = res + "...";
            i = i + 3;
            isn = 0;
            k = 0;
            continue;
        }
        if ( ( s[i] == ',' ) && ( i+1 == ln ) )
        {
            res = res + ',';
            k = 1;
            isn = 0;
            i++;
            continue;
        }
    }
    cout << res << "\n";
    return 0;
}