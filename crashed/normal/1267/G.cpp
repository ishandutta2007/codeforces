#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 105, MAXC = 10005;

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

long double dp[MAXN][MAXC];

int C[MAXN];

double x;
int N;

int main() {
    read( N ), scanf( "%lf", &x );
    rep( i, 1, N ) read( C[i] );
    dp[0][0] = 1; int S = 0;
    for( int i = 1 ; i <= N ; i ++ ) {
        S += C[i];
        for( int j = i ; j ; j -- )
            for( int k = S ; k >= C[i] ; k -- )
                dp[j][k] += dp[j - 1][k - C[i]];
    }
    long double ans = 0, bin = 1;
    for( int i = 0 ; i < N ; i ++ ) {
        for( int s = 0 ; s <= S ; s ++ )
            ans += dp[i][s] / bin * std :: min( ( long double ) ( S - s ) / ( N - i ), 
                                                ( long double ) x / 2 * ( 1 + 1.0 * N / ( N - i ) ) );
        bin = bin / ( i + 1 ) * ( N - i );
    }
    printf( "%.12Lf\n", ans );
    return 0;
}