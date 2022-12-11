#include <queue>
#include <cstdio>
#include <utility>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXK = 505;

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

typedef std :: pair<int, int> Node;

std :: priority_queue<Node, std :: vector<Node>, std :: greater<Node> > q;

int dist[MAXK][MAXK];
bool vis[MAXK][MAXK];

int dn[MAXK][MAXK], rg[MAXK][MAXK];

int N, K;

#define ID( x, y ) ( (x) * ( K + 1 ) + (y) )

inline bool Inside( const int x, const int y ) {
    return 0 <= x && x <= K && 0 <= y && y <= K;
}

int main() {
    // freopen( ".in", "r", stdin );
    // freopen( ".out", "w", stdout );
    int T; read( T );
    while( T -- ) {
        read( N ), read( K );
        rep( i, 0, K ) rep( j, 0, K )
            dn[i][j] = rg[i][j] = 0;
        rep( i, 1, N ) {
            int r1, c1, r2, c2;
            read( r1 ), read( c1 );
            read( r2 ), read( c2 );
            if( r1 == r2 ) {
                if( c2 == c1 + 1 ) dn[r1 - 1][c1] ++;
                if( c2 == c1 - 1 ) dn[r1 - 1][c1 - 1] ++;
            } else {
                if( r2 == r1 + 1 ) rg[r1][c1 - 1] ++;
                if( r2 == r1 - 1 ) rg[r1 - 1][c1 - 1] ++;
            }
        }
        rep( i, 0, ( K >> 1 ) - 1 ) rep( j, 0, K ) {
            int a = dn[i][j], b = dn[K - 1 - i][K - j];
            dn[i][j] = dn[K - 1 - i][K - j] = a + b;
        }
        rep( i, 0, K ) rep( j, 0, ( K >> 1 ) - 1 ) {
            int a = rg[i][j], b = rg[K - i][K - 1 - j];
            rg[i][j] = rg[K - i][K - 1 - j] = a + b;
        }
        rep( i, 0, K ) rep( j, 0, K )
            vis[i][j] = false, dist[i][j] = INF;
        q.push( Node( dist[K >> 1][K >> 1] = 0, ID( K >> 1, K >> 1 ) ) );
        int ans = INF, tx, ty;
        while( ! q.empty() ) {
            int ux = q.top().second / ( K + 1 ),
                uy = q.top().second % ( K + 1 );
            q.pop(); if( vis[ux][uy] ) continue;
            vis[ux][uy] = true;
            if( ux == 0 || uy == 0 || ux == K || uy == K )
            { ans = MIN( ans, dist[ux][uy] ); continue; }
            if( Inside( tx = ux - 1, ty = uy ) )
                if( ! vis[tx][ty] && dist[tx][ty] > dist[ux][uy] + dn[tx][ty] )
                    q.push( Node( dist[tx][ty] = dist[ux][uy] + dn[tx][ty], ID( tx, ty ) ) );
            if( Inside( tx = ux, ty = uy - 1 ) )
                if( ! vis[tx][ty] && dist[tx][ty] > dist[ux][uy] + rg[tx][ty] )
                    q.push( Node( dist[tx][ty] = dist[ux][uy] + rg[tx][ty], ID( tx, ty ) ) );
            if( Inside( tx = ux + 1, ty = uy ) )
                if( ! vis[tx][ty] && dist[tx][ty] > dist[ux][uy] + dn[ux][uy] )
                    q.push( Node( dist[tx][ty] = dist[ux][uy] + dn[ux][uy], ID( tx, ty ) ) );
            if( Inside( tx = ux, ty = uy + 1 ) )
                if( ! vis[tx][ty] && dist[tx][ty] > dist[ux][uy] + rg[ux][uy] )
                    q.push( Node( dist[tx][ty] = dist[ux][uy] + rg[ux][uy], ID( tx, ty ) ) );
        }
        write( N - ans ), putchar( '\n' );
    }
    return 0;
}