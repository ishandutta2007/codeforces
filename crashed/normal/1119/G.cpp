#include <cstdio>
#include <algorithm>

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

int hp[MAXN];

int N, M;

namespace SmallN {
    int seq[MAXN], tot;

    void Solve() {
        rep( i, 1, N ) putchar( '1' ), putchar( ' ' );
        rep( i, N + 1, M ) putchar( '0' ), putchar( ' ' );
        puts( "" );
        rep( i, 1, M ) {
            int tims = hp[i] / N;
            rep( j, 1, tims ) {
                rep( k, 1, M )
                    write( i ), putchar( ' ' );
                puts( "" );
            }
            hp[i] %= N;
            rep( j, 1, hp[i] )
                seq[++ tot] = i;
        }
        for( int i = 1 ; i <= tot ; i += N ) {
            int lim = MIN( N, tot - i + 1 );
            rep( j, 1, lim ) write( seq[i + j - 1] ), putchar( ' ' );
            rep( j, lim + 1, M ) putchar( '1' ), putchar( ' ' );
            puts( "" );
        }
    }
}

namespace LargeN {
    int pref[MAXN], val[MAXN], tmp[MAXN], pos[MAXN], tot;  

    void Solve() {
        rep( i, 1, M ) pref[i] = pref[i - 1] + hp[i];
        rep( i, 1, M - 1 ) tmp[++ tot] = pref[i] % N;
        std :: sort( tmp + 1, tmp + 1 + tot );
        tot = std :: unique( tmp + 1, tmp + 1 + tot ) - tmp - 1;
        rep( i, 1, tot ) { 
            val[i] = tmp[i] - tmp[i - 1];
            pos[tmp[i]] = i;
        }
        val[tot + 1] = N - tmp[tot];
        rep( i, 1, M ) write( val[i] ), putchar( i == M ? '\n' : ' ' );
        for( int i = 1, j ; i < M ; ) {
            for( ; i < M && ! hp[i] ; i ++ );
            if( i == M ) break;
            int su = 0, lst = 0;
            for( j = i ; j < M && ( su += hp[j] ) <= N ; j ++ );
            for( int k = i ; k <= j ; k ++ ) {
                while( lst < M && hp[k] >= val[lst + 1] ) {
                    hp[k] -= val[++ lst];
                    write( k ), putchar( ' ' );
                }
                if( lst == M ) break;
            }
            for( int i = lst + 1 ; i <= M ; i ++ )
                hp[M] -= val[i], write( M ), putchar( ' ' );
            puts( "" );
        }
        if( hp[M] > 0 ) {
            int tims = ( hp[M] + N - 1 ) / N;
            rep( j, 1, tims ) {
                rep( k, 1, M )
                    write( M ), putchar( ' ' );
                puts( "" );
            }
        }
    }
}

int main() {
    int su = 0;
    read( N ), read( M );
    rep( i, 1, M ) read( hp[i] ), su += hp[i];
    printf( "%d\n", ( su + N - 1 ) / N );
    if( N <= M ) 
        SmallN :: Solve();
    else 
        LargeN :: Solve();
    return 0;
}