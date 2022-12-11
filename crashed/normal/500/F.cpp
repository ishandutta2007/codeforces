#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXN = 4005, MAXA = 20005, MAXLOG = 16;

template<typename _T>
inline void Read( _T &x ) {
    x = 0; char s = getchar(); bool f = false;
    while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    if( f ) x = -x;
}

template<typename _T>
inline void Write( _T x ) {
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) Write( x / 10 );
    putchar( x % 10 + '0' );
}

template<typename _T>
inline _T Max( const _T &a, const _T &b ) {
    return a > b ? a : b;
}

template<typename _T>
inline _T Min( const _T &a, const _T &b ) {
    return a < b ? a : b;
}

int dpL[MAXN][MAXN], stkL[MAXN], topL;
int dpR[MAXN][MAXN], stkR[MAXN], topR;

std :: vector<int> arrv[MAXA], qry[MAXA];
int cost[MAXN], happ[MAXN], tim[MAXN];
int qB[MAXA], ans[MAXA];

int N, Q, P, mxA, mxB;

inline void Dump() {
    for( ; topR ; stkL[++ topL] = stkR[topR --] );
    rep( i, 1, topL ) {
        int c = cost[stkL[i]], h = happ[stkL[i]];
        rep( j, 0, mxB ) {
            dpL[i][j] = dpL[i - 1][j];
            if( j >= c ) 
                dpL[i][j] = Max( dpL[i][j], dpL[i - 1][j - c] + h );
        }
    }
}

inline int Front() {
    return topL ? stkL[topL] : stkR[1];
}

int main() {
    Read( N ), Read( P );
    rep( i, 1, N ) {
        Read( cost[i] ), Read( happ[i] ), Read( tim[i] );
        arrv[tim[i]].push_back( i );
    }
    Read( Q );
    rep( i, 1, Q ) {
        int a; Read( a ), Read( qB[i] );
        mxA = Max( mxA, a ), mxB = Max( mxB, qB[i] );
        qry[a].push_back( i ), ans[i] = - INF;
    }
    rep( i, 1, mxA ) {
        int n = arrv[i].size();
        rep( j, 0, n - 1 ) {
            stkR[++ topR] = arrv[i][j];
            int c = cost[stkR[topR]], h = happ[stkR[topR]];
            rep( k, 0, mxB ) {
                dpR[topR][k] = dpR[topR - 1][k];
                if( k >= c ) 
                    dpR[topR][k] = Max( dpR[topR][k], dpR[topR - 1][k - c] + h );
            }
        }
        while( ( topL || topR ) && tim[Front()] <= i - P ) {
            if( ! topL ) Dump();
            topL --;
        }
        n = qry[i].size();
        rep( j, 0, n - 1 ) {
            int q = qry[i][j], b = qB[q];
            rep( k, 0, b ) ans[q] = Max( ans[q], dpL[topL][k] + dpR[topR][b - k] );
        }
    }
    rep( i, 1, Q ) Write( ans[i] ), putchar( '\n' );
    return 0;
}