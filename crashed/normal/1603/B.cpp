#include <cstdio>

typedef long long LL;

int main() {
    int T;
    scanf( "%d", &T );
    while( T -- ) {
        LL x, y;
        scanf( "%lld%lld", &x, &y );
        if( x > y ) printf( "%lld\n", x + y );
        else printf( "%lld\n", ( y / x ) * x + ( y % x ) / 2 );
    }
    return 0;
}