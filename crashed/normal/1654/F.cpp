#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = ( 1 << 18 ) + 5;

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

char S[MAXN], T[MAXN];

int buc[MAXN];
int rnk[MAXN], tmp[MAXN], sa[MAXN];

int N;

int main() {
    read( N );
    scanf( "%s", S );
    rep( i, 0, ( 1 << N ) - 1 ) buc[S[i] - 'a'] = 1;
    rep( i, 1, 25 ) buc[i] += buc[i - 1];
    rep( i, 0, ( 1 << N ) - 1 ) rnk[i] = buc[S[i] - 'a']; 
    for( int k = 0 ; k < N ; k ++ ) {
        rep( i, 0, ( 1 << N ) - 1 ) sa[i] = i;
        std :: sort( sa, sa + ( 1 << N ), 
            [&] ( const int &a, const int &b ) -> bool {
                return rnk[a] != rnk[b] ? rnk[a] < rnk[b] :
                       ( rnk[a ^ ( 1 << k )] != rnk[b ^ ( 1 << k )] ?
                         rnk[a ^ ( 1 << k )] < rnk[b ^ ( 1 << k )] : a < b );
            } );
        int tot = 0;
        tmp[sa[0]] = 0;
        rep( i, 1, ( 1 << N ) - 1 ) {
            tot += rnk[sa[i]] != rnk[sa[i - 1]] || rnk[sa[i] ^ ( 1 << k )] != rnk[sa[i - 1] ^ ( 1 << k )];
            tmp[sa[i]] = tot;
        }
        rep( i, 0, ( 1 << N ) - 1 ) rnk[i] = tmp[i];
    }
    int x = sa[0];
    rep( i, 0, ( 1 << N ) - 1 ) T[i ^ x] = S[i];
    puts( T );
    return 0;
}