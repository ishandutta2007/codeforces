#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 1e5 + 5, MAXM = 5005;

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
_T MAX( const _T a, const _T b ) {
    return a > b ? a : b;
}

std :: vector<int> chg[MAXM];

LL cur[MAXN];
int lst[MAXN];

int H[MAXN], A[MAXN];

int N, M, K, delt;

bool Chk( const LL ini ) {
    LL ned, t;
    rep( i, 1, M ) chg[i].clear();
    rep( i, 1, N ) {
        lst[i] = M + 1, cur[i] = ini, t = cur[i] / A[i];
        if( M + 1 - t > 1 ) 
            chg[M + 1 - t].push_back( i );
    }
    int rem = 0;
    per( i, M, 2 ) {
        rem += K;
        int n = chg[i].size(), u;
        for( int j = 0 ; j < n ; j ++ ) {
            u = chg[i][j];
            cur[u] -= 1ll * A[u] * ( lst[u] - i ), lst[u] = i;
            ned = ( A[u] - cur[u] + delt - 1 ) / delt;
            if( rem < ned ) { return false; } rem -= ned;
            cur[u] += 1ll * delt * ned, t = cur[u] / A[u];
            if( i - t > 1 ) 
                chg[i - t].push_back( u );
        }
        chg[i].clear();
    }
    rem += K;
    rep( i, 1, N ) {
        cur[i] -= 1ll * A[i] * ( lst[i] - 1 ), lst[i] = 1;
        if( cur[i] < H[i] ) {
            LL ned = ( H[i] - cur[i] + delt - 1 ) / delt;
            if( rem < ned ) { return false; } rem -= ned;
        }
    }
    return true;
}

signed main() {
    LL l = 0, r = 0, mid;
    read( N ), read( M ), read( K ), read( delt );
    rep( i, 1, N ) {
        read( H[i] ), read( A[i] );
        l = MAX( l, 1ll * A[i] ), r = MAX( r, 1ll * A[i] * M + H[i] );
    }
    while( l < r ) {
        mid = ( l + r ) >> 1;
        if( Chk( mid ) ) r = mid;
        else l = mid + 1;
    }
    write( l ), putchar( '\n' );
    return 0;
}