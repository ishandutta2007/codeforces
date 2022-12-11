#include <bitset>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXV = 7005, MAXN = 1e5 + 5;

template<typename _T>
void read( _T &x ) {
    x = 0; char s = getchar(); bool f = false;
    while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    if( f ) x = -x;
}

template<typename _T>
void write( _T x ) {
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) write( x / 10 );
    putchar( x % 10 + '0' );
}

std :: bitset<MAXV> each[MAXN], org[MAXV], diff[MAXV];

int mu[MAXV];
int prime[MAXV], pn;
bool isPrime[MAXV];

int N, Q;

void EulerSieve( const int n ) {
    mu[1] = 1;
    for( int i = 2 ; i <= n ; i ++ ) {
        if( ! isPrime[i] ) mu[prime[++ pn] = i] = 1;
        for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= n ; j ++ ) {
            isPrime[i * prime[j]] = true;
            if( ! ( i % prime[j] ) ) break;
            mu[i * prime[j]] = mu[i];
        }
    }
}

void Init( const int n = 7000 ) {
    EulerSieve( n );
    for( int d = 1 ; d <= n ; d ++ )
        for( int k = d ; k <= n ; k += d )
            org[k].set( d ), diff[d].set( k, mu[k / d] );
}

int main() {
    Init();
    read( N ), read( Q );
    while( Q -- ) {
        int opt; read( opt );
        if( opt == 1 ) {
            int x, v;
            read( x ), read( v );
            each[x] = org[v];
        }
        if( opt == 2 ) {
            int x, y, z;
            read( x ), read( y ), read( z );
            each[x] = each[y] ^ each[z];
        }
        if( opt == 3 ) {
            int x, y, z;
            read( x ), read( y ), read( z );
            each[x] = each[y] & each[z];
        }
        if( opt == 4 ) {
            int x, v;
            read( x ), read( v );
            putchar( '0' + ( 1 & ( each[x] & diff[v] ).count() ) );
        }
    }
    puts( "" );
    return 0;
}