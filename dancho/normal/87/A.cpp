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

long long a, b;
long long k1, k2;
long long ta, tb, t;

int main()
{
    int i, j, k;

    scanf( "%I64d %I64d", &a, &b );
    if ( a < b )
    {
        k1 = 1; k2 = 1;
    }
    else
    {
        k2 = 1; k1 = 1;
    }
    ta = 0; tb = 0;
    t = 0;
    while ( k1*a != k2*b )
    {
//        cout << k1*a << " " << k2*b << " " << ta << " " << tb << " __ " << t << endl;
        if ( k1*a < k2*b )
        {
            ta = ta + k1*a - t;
            t = k1*a;
            k1++;
        }
        else
        {
            tb = tb + k2*b - t;
            t = k2*b;
            k2++;
        }
    }
    if ( a > b )
    {
        ta = ta + k1*a - t;
    }
    else
        tb = tb + k1*a-t;
    if ( ta > tb ) cout << "Dasha\n";
    else if ( ta < tb ) cout << "Masha\n";
    else cout << "Equal\n";
    return 0;
}