#include <cmath>
#include <cstdio>
#include <utility>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5, MAXS = 5e5 + 5, MAXLOG = 20;

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

typedef std :: pair<int, int> Segment;

Segment rogh[MAXN], elim[MAXN];

int nxt[MAXS][MAXLOG];
int pref[MAXS], tag[MAXS];

int N, M, lg2;

int main() {
    int lim = 0;
    read( N ), read( M );
    rep( i, 1, N ) {
        read( rogh[i].first ), read( rogh[i].second );
        rogh[i].first ++, rogh[i].second ++;
        lim = MAX( lim, rogh[i].second );
    }
    std :: sort( rogh + 1, rogh + 1 + N,
        [] ( const Segment &a, const Segment &b ) -> bool {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        } ); 
    int tot = 0, mx = -1;
    rep( i, 1, N )
        if( mx < rogh[i].second ) {
            elim[++ tot] = rogh[i];
            mx = rogh[i].second;
            tag[rogh[i].first] ++;
            tag[rogh[i].second] --;
        }
    N = tot;
    for( int i = 1, j = 0 ; i <= lim ; i ++ ) {
        if( j < N && i == elim[j + 1].first ) j ++;
        pref[i] = j;
    }
    lg2 = log2( N );
    rep( i, 1, lim ) tag[i] += tag[i - 1];
    rep( i, 1, lim ) tag[i] = tag[i - 1] + ( bool ) tag[i];
    rep( i, 1, lim ) nxt[i][0] = pref[i] ? elim[pref[i]].second : -1;
    rep( j, 1, lg2 ) rep( i, 1, lim ) {
        if( nxt[i][j - 1] == -1 ) {
            nxt[i][j] = -1; continue;
        }
        int p = elim[pref[nxt[i][j - 1]]].first;
        if( nxt[p][j - 1] == -1 ) {
            nxt[i][j] = -1; continue ;
        }
        nxt[i][j] = nxt[p][j - 1];
    }
    while( M -- ) {
        int l, r;
        read( l ), read( r ), l ++, r ++;
        if( tag[r - 1] - tag[l - 1] != r - l ) {
            puts( "-1" ); continue;
        } else {
            int ans = 0, p = l;
            for( int k = lg2 ; ~ k ; k -- )
                if( nxt[p][k] < r ) {
                    ans += 1 << k;
                    p = nxt[p][k];
                }
            write( ans + 1 ), putchar( '\n' );
        }
    }
    return 0;
}