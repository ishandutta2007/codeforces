#include <iostream>
#include <cstdio>
using namespace std;

int n;
long long b, a[2048];

int main()
{
    int i, j, k;
    long long bsol, s;

    scanf( "%d %d", &n, &k );
    b = k;
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%d", &k );
        a[i] = k;
    }

    bsol = b;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = i+1; j <= n; j++ )
        {
            s = b/a[i];
            if ( s*a[j] + b-s*a[i] > bsol )
                bsol = s*a[j] + b-s*a[i];
        }
    }
    cout << bsol << endl;
    return 0;
}