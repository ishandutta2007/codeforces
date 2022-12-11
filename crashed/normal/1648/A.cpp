#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 1e5 + 5;

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

LL su[MAXN], cnt[MAXN];
int col[MAXN];

int N, M;

#define ID( x, y ) ( ( (x) - 1 ) * M + (y) )

int main() {
    // freopen( ".in", "r", stdin );
    // freopen( ".out", "w", stdout );
    read( N ), read( M );
    rep( i, 1, N ) rep( j, 1, M ) read( col[ID( i, j )] );
    rep( i, 1, 1e5 ) su[i] = cnt[i] = 0;
    LL ans = 0;
    rep( i, 1, N ) rep( j, 1, M ) {
        int c = col[ID( i, j )];
        ans += 1ll * cnt[c] * i - su[c];
        cnt[c] ++, su[c] += i;
    }
    rep( i, 1, 1e5 ) su[i] = cnt[i] = 0;
    rep( j, 1, M ) rep( i, 1, N ) {
        int c = col[ID( i, j )];
        ans += 1ll * cnt[c] * j - su[c];
        cnt[c] ++, su[c] += j;
    }
    write( ans ), putchar( '\n' );
    return 0;
}