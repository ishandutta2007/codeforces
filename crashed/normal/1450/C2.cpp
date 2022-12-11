#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 305;

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

char grid[MAXN][MAXN];

int N;

int main() {
    int T; Read( T );
    while( T -- ) {
        Read( N );
        int cnt[3][2] = {};
        rep( i, 1, N ) {
            scanf( "%s", grid[i] + 1 );
            rep( j, 1, N )
                if( grid[i][j] != '.' )
                    cnt[( i + j ) % 3][grid[i][j] == 'X'] ++;
        }
        int su = 1e9, a, b, c, d;
        rep( i, 0, 2 ) 
            rep( x, 0, 1 )
                rep( j, i + 1, 2 ) {
                    int v = cnt[i][x] + cnt[j][x ^ 1];
                    if( su > v ) 
                        su = v, a = i, b = x, c = j, d = x ^ 1;
                }
        rep( i, 1, N ) {
            rep( j, 1, N ) {
                if( ( i + j ) % 3 == a && ( b ? grid[i][j] == 'X' : grid[i][j] == 'O' ) )
                    grid[i][j] = b ? 'O' : 'X';
                if( ( i + j ) % 3 == c && ( d ? grid[i][j] == 'X' : grid[i][j] == 'O' ) )
                    grid[i][j] = d ? 'O' : 'X';
                putchar( grid[i][j] );
            }
            puts( "" );
        }
    }
    return 0;
}