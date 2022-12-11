#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXN = 2e5 + 5;

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
inline _T Min( const _T &a, const _T &b ) {
    return a < b ? a : b;
}

int dp[MAXN][2];

int grid[2][MAXN];
char buf[MAXN];

int N;

int main() {
    int T; Read( T );
    while( T -- ) {
        Read( N );
        rep( i, 0, 1 ) {
            scanf( "%s", buf + 1 );
            rep( j, 1, N ) grid[i][j] = buf[j] == '*';
        }
        int fir, lst;
        rep( i, 1, N ) 
            if( grid[0][i] || grid[1][i] ) {
                fir = i; break;
            }
        per( i, N, 1 )
            if( grid[0][i] || grid[1][i] ) {
                lst = i; break;
            }
        dp[fir][0] = grid[1][fir];
        dp[fir][1] = grid[0][fir];
        rep( i, fir + 1, lst ) {
            dp[i][0] = Min( dp[i - 1][0] + 1 + grid[1][i], dp[i - 1][1] + 2 );
            dp[i][1] = Min( dp[i - 1][1] + 1 + grid[0][i], dp[i - 1][0] + 2 );
        }
        Write( Min( dp[lst][0], dp[lst][1] ) ), putchar( '\n' );
    }
    return 0;
}