#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long lint;
const int mod = 1000000007;

int n;
lint fac[1000020];

lint qpow( lint v, int pow )
{
    lint r = 1;
    while ( pow > 0 )
    {
        if ( pow%2 == 1 )
        {
            r = (r*v)%mod;
        }
        v = (v*v)%mod;
        pow = pow / 2;
    }
    return r;
}

int main()
{
    int i, j, k;

    scanf( "%d", &n );

    fac[0] = 1;
    for ( i = 1; i <= 3*n; i++ )
    {
        fac[i] = (fac[i-1]*i)%mod;
    }
    lint sol = fac[2*n-1];
    sol = ( sol * qpow( fac[n-1], mod-2 ) ) % mod;
    sol = ( sol * qpow( fac[n], mod-2 ) ) % mod;
    sol = (sol-n+mod)%mod;
    sol = ( sol * 2 ) % mod;
    sol = ( sol + n ) % mod;
    k = sol;
    printf( "%d\n", k );
    return 0;
}