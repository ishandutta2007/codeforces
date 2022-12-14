#include <cstdio>
#include <cstring>

const int mod = 1000000007;

long long dp[1024][1024];
long long sdp[1024][1024];
long long qdp[1024][1024];

long long getSDP( int x, int k );
long long getQDP( int x, int k );

long long getDP( int x, int k )
{
//    printf( "INDP %d %d\n", x, k );
    if ( ( k == 0 ) && ( x >= 0 ) ) return 1;
    if ( ( k < 0 ) || ( x <= 0 ) ) return 0;
    if ( dp[x][k] != -1 ) return dp[x][k];
    long long sol = 0;
    if ( k == 1 ) sol = sol + x;
    sol = sol + getDP( x-2, k-1 );
    if ( sol >= mod ) sol = sol % mod;
//    printf( "MIDDP %d %d %I64d\n", x, k, sol );
    sol = sol + getSDP( x-3, k-1 )*(x-1) - getQDP( x, k ) + mod;
    if ( sol >= mod ) sol = sol % mod;
    dp[x][k] = sol;
//    printf( "DP %d %d %I64d\n", x, k, dp[x][k] );
    return dp[x][k];
}

long long getSDP( int x, int k )
{
    if ( sdp[x][k] != -1 ) return sdp[x][k];
    if ( x < 0 ) return 0;
    sdp[x][k] = getSDP( x-1, k ) + getDP( x, k );
    if ( sdp[x][k] >= mod ) sdp[x][k] = sdp[x][k] % mod;
//    printf( "sDP %d %d %I64d\n", x, k, sdp[x][k] );
    return sdp[x][k];
}

long long getQDP( int x, int k )
{
    if ( qdp[x][k] != -1 ) return qdp[x][k];
    if ( x < 3 ) return 0;
    qdp[x][k] = getQDP( x-1, k ) + getDP( x-3, k-1 )*(x-3);
    if ( qdp[x][k] >= mod ) qdp[x][k] = qdp[x][k] % mod;
//    printf( "qDP %d %d %I64d\n", x, k, qdp[x][k] );
    return qdp[x][k];
}

int main()
{
    int n, m, k;
    scanf( "%d %d %d", &n, &m, &k );
    memset( dp, -1, sizeof( dp ) );
    memset( sdp, -1, sizeof( sdp ) );
    memset( qdp, -1, sizeof( qdp ) );
    printf( "%I64d\n", (getDP( n-2, k )*getDP( m-2, k ))%mod );
    return 0;
}