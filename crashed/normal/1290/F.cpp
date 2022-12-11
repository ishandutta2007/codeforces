#include <cmath>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
const int MAXN = 10, MAXSU = 45, MAXS = ( 1 << 5 ) + 5;

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

int dp[2][MAXSU][MAXSU][MAXSU][MAXSU][2][2];

int suPX[MAXS], suPY[MAXS], suNX[MAXS], suNY[MAXS];
int X[MAXN], Y[MAXN];

int N, M;

inline int Mul( int x, const int v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int v ) { return ( x += v ) >= mod ? x - mod : x; }

inline void Upt( int &x, const int v ) { x = Add( x, v ); }

int main() {
    read( N ), read( M );
    int px = 0, nx = 0, py = 0, ny = 0;
    rep( i, 0, N - 1 ) {
        read( X[i] ), read( Y[i] );
        if( X[i] > 0 ) px += X[i];
        if( X[i] < 0 ) nx -= X[i];
        if( Y[i] > 0 ) py += Y[i];
        if( Y[i] < 0 ) ny -= Y[i];
    }
    for( int S = 0 ; S < ( 1 << N ) ; S ++ )
        rep( i, 0, N - 1 ) if( S >> i & 1 ) {
            if( X[i] > 0 ) suPX[S] += X[i];
            if( X[i] < 0 ) suNX[S] -= X[i];
            if( Y[i] > 0 ) suPY[S] += Y[i];
            if( Y[i] < 0 ) suNY[S] -= Y[i];
        }
    int pre = 1, nxt = 0, np, nq;
    dp[nxt][0][0][0][0][1][1] = 1;
    for( int i = 0 ; ( 1 << i ) <= M ; ++ i ) {
        pre ^= 1, nxt ^= 1;
        rep( pxs, 0, px ) rep( nxs, 0, nx )
            rep( pys, 0, py ) rep( nys, 0, ny )
                rep( p, 0, 1 ) rep( q, 0, 1 ) {
                    if( ! dp[pre][pxs][nxs][pys][nys][p][q] ) continue;
                    int &cur = dp[pre][pxs][nxs][pys][nys][p][q];
                    for( int S = 0 ; S < ( 1 << N ) ; S ++ ) {
                        if( ( ( pxs + suPX[S] ) & 1 ) != ( ( nxs + suNX[S] ) & 1 ) ) continue;
                        if( ( ( pys + suPY[S] ) & 1 ) != ( ( nys + suNY[S] ) & 1 ) ) continue;
                        np = ( M >> i & 1 ) == ( ( pxs + suPX[S] ) & 1 ) ? p : 
                             ( M >> i & 1 ) >= ( ( pxs + suPX[S] ) & 1 );
                        nq = ( M >> i & 1 ) == ( ( pys + suPY[S] ) & 1 ) ? q : 
                             ( M >> i & 1 ) >= ( ( pys + suPY[S] ) & 1 );
                        Upt( dp[nxt][( pxs + suPX[S] ) >> 1][( nxs + suNX[S] ) >> 1]
                                    [( pys + suPY[S] ) >> 1][( nys + suNY[S] ) >> 1]
                                    [np][nq], cur );
                    }
                    cur = 0;
                }
    }
    write( Sub( dp[nxt][0][0][0][0][1][1], 1 ) ), putchar( '\n' );
    return 0;
}