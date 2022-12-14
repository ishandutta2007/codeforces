#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef unsigned long long ull;

ull a, b, x, y;

int l;
int ca[128], cb[128];
int npr[128];
int cpr[128];

int main()
{
    int i, j, k, fl;
    int pr = 0;
    ull s, t;

//    scanf( "%I64d %I64d", &a, &b );
    cin >> a >> b;
    if ( a < b )
    {
        printf( "-1\n" );
        return 0;
    }

    memset( npr, 0, sizeof( npr ) );
    memset( cpr, 0, sizeof( cpr ) );
    k = 0;
    s = a; t = b;
    l = 0;
    fl = 0;
    while ( s > 0 )
    {
        i = (s&1); j = (t&1);
        if ( i != j ) npr[k] = 1;
        if ( j == 0 ) cpr[k] = 1;
        if ( ( i == 0 ) && ( j == 1 ) ) cpr[k] = 2;
        ca[k] = i; cb[k] = j;
        if ( k > 0 )
        {
            if ( ( npr[k] == 1 ) && ( cpr[k-1] == 1 ) )
                fl = 1;
        }

//        cout << k << " " << ca[k] << " " << cb[k] << "   " << npr[k] << " " << cpr[k] << endl;

        k++;
        s = s / 2; t = t / 2;
    }
    l = k;

    x = 0; y = 0; pr = 0;
    for ( k = 0; k < l; k++ )
    {
//        cout << k << " " << npr[k] << " " << pr << endl;
        if ( npr[k] != pr )
            break;
        if ( cpr[k] == 2 )
        {
            pr = 1;
//            if ( ( fl == 0 ) && ( x == 0 ) )
//                x = x + (1LL<<k);
            y = y + (1LL<<k);
        }
        else if ( ( ca[k] == 1 ) && ( cb[k] == 0 ) )
        {
            if ( npr[k+1] == 1 )
            {
                pr = 1;
                x = x + (1LL<<k);
                y = y + (1LL<<k);
            }
            else pr = 0;
        }
        else if ( ( ca[k] == 0 ) && ( cb[k] == 0 ) )
        {
            if ( npr[k+1] == 1 )
            {
                pr = 1;
                x = x + (1LL<<k);
                y = y + (1LL<<k);
            }
            else pr = 0;
        }
        else if ( ( ca[k] == 1 ) && ( cb[k] == 1 ) )
        {
            pr = 0;
//            if ( ( fl == 0 ) && ( x == 0 ) )
//                x = x + (1LL<<k);
            y = y + (1LL<<k);
        }
    }
    if ( ( x + y != a ) || ( (x^y) != b ) )
        printf( "-1\n" );
    else
        cout << x << " " << y << endl;

    return 0;
}