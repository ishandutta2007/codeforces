#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e6 + 5;

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

template<typename _T>
_T MIN( const _T a, const _T b ) {
    return a < b ? a : b;
}

char str[MAXN];

int z[MAXN], tag[MAXN];

int N, K;

int main() {
    read( N ), read( K );
    scanf( "%s", str + 1 ), z[1] = N;
    for( int i = 2, l = 1, r = 1 ; i <= N ; i ++ ) {
        if( i < r ) z[i] = MIN( r - i, z[i - l + 1] );
        while( i + z[i] <= N && str[i + z[i]] == str[1 + z[i]] ) z[i] ++;
        if( i + z[i] > r ) l = i, r = i + z[i];
    }
    rep( i, 1, N ) {
        int k = z[i + 1] / i;
        if( k + 1 < K ) continue;
        tag[i * K] ++, tag[MIN( i * ( K + 1 ) + 1, i + 1 + z[i + 1] )] --;
    }
    rep( i, 1, N )
        putchar( ( tag[i] += tag[i - 1] ) ? '1' : '0' );
    return 0;
}