#include <cmath>
#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 2e5 + 5, MAXLOG = 20;

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

int lg2[MAXN];
int stk[MAXN], top;

LL tag1[MAXN], tag2[MAXN], pref[MAXN];

int nxt[MAXN][MAXLOG]; LL su[MAXN][MAXLOG];
int forw[MAXN][MAXLOG];
int A[MAXN], val[MAXN];

int N, Q;

int main() {
    Read( N );
    rep( i, 1, N ) {
        Read( A[i] ), val[i] = std :: max( i - A[i], 0 ) + 1;
        forw[i][0] = val[i];
    }
    lg2[0] = -1; rep( i, 1, N ) lg2[i] = lg2[i >> 1] + 1;
    per( i, N, 1 ) {
        while( top && val[stk[top]] <= val[i] ) top --;
        nxt[i][0] = top ? stk[top] : N + 1; 
        su[i][0] = 1ll * ( nxt[i][0] - i ) * val[i];
        stk[++ top] = i;
    }
    nxt[N + 1][0] = N + 1;
    for( int j = 1 ; j <= lg2[N] ; j ++ ) {
        int stp = 1 << ( j - 1 );
        for( int i = 1 ; i + stp <= N ; i ++ )
            forw[i][j] = std :: max( forw[i][j - 1], forw[i + stp][j - 1] );
        for( int i = 1 ; i <= N + 1 ; i ++ ) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            su[i][j] = su[i][j - 1] + su[nxt[i][j - 1]][j - 1];
        }
    }
    LL glb = 0;
    for( int l = 1 ; l <= N ; l ++ ) {
        int p = l;
        for( int k = lg2[N - l + 1] ; ~ k ; k -- ) {
            if( p + ( 1 << k ) > N ) continue;
            if( forw[p + 1][k] > l ) continue;
            p += 1 << k;
        }
        glb += p - l + 1;
        tag1[l] += p - l + 1;
        tag2[l + 1] -= 1, tag2[p + 2] += 1;
    }
    rep( i, 1, N ) tag2[i] += tag2[i - 1];
    rep( i, 1, N ) tag1[i] += tag2[i];
    rep( i, 1, N ) tag1[i] += tag1[i - 1];
    rep( i, 1, N ) pref[i] = pref[i - 1] + val[i];
    for( Read( Q ) ; Q -- ; ) {
        int p, x;
        Read( p ), Read( x );
        LL ans = glb - tag1[p];
        int mx = std :: max( p - x, 0 ) + 1, lef = p;
        for( int k = lg2[p] ; ~ k ; k -- ) {
            if( lef - 1 < ( 1 << k ) ) continue;
            if( std :: max( mx, forw[lef - ( 1 << k )][k] ) > lef - ( 1 << k ) ) continue;
            mx = std :: max( mx, forw[lef -= ( 1 << k )][k] );
        }
        int p1 = p;
        for( int k = lg2[N - p + 1] ; ~ k ; k -- ) {
            if( p1 + ( 1 << k ) > N ) continue;
            if( forw[p1 + 1][k] > lef ) continue;
            p1 += 1 << k;
        }
        ans += 1ll * ( p1 - p + 1 ) * ( p - lef + 1 );
        if( ++ p1 <= N && val[p1] <= p ) {
            for( int k = lg2[N - p1 + 1] ; ~ k ; k -- )
                if( nxt[p1][k] <= N && val[nxt[p1][k]] <= p ) {
                    ans += 1ll * ( p + 1 ) * ( nxt[p1][k] - p1 ) - su[p1][k];
                    p1 = nxt[p1][k];
                }
            ans += 1ll * ( p + 1 - val[p1] ) * ( nxt[p1][0] - p1 );
        }
        Write( ans ), putchar( '\n' );
    }
    return 0;
}