#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e4 + 5, MAXLOG = 20;

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

template<typename _T>
inline _T Max( const _T &a, const _T &b ) {
    return a > b ? a : b;
}

int dp[MAXN];

int mn[MAXN][MAXLOG];
int lg2[MAXN];

int sa[MAXN], rnk[MAXN];
int tmp[MAXN], buc[MAXN];

char str[MAXN];

int N;

inline bool Equal( const int &x, const int &y, const int &k ) {
    return rnk[x] == rnk[y] && rnk[x + k] == rnk[y + k];
}

inline void Init() {
    rep( i, 0, 2 * N )
        sa[i] = rnk[i] = tmp[i] = buc[i] = 0;
    rep( i, 0, 25 ) buc[i] = 0;
    rep( i, 1, N ) buc[( int ) ( str[i] - 'a' )] ++;
    rep( i, 1, 25 ) buc[i] += buc[i - 1];
    per( i, N, 1 ) sa[buc[( int ) ( str[i] - 'a' )] --] = i;
    rep( i, 1, N ) rnk[sa[i]] = rnk[sa[i - 1]] + ( str[sa[i]] != str[sa[i - 1]] );
    for( int k = 1, lst = rnk[sa[N]] ; lst < N ; k <<= 1 ) {
        int tot = 0;
        rep( i, N - k + 1, N ) tmp[++ tot] = i;
        rep( i, 1, N ) if( sa[i] > k ) tmp[++ tot] = sa[i] - k;
        rep( i, 0, lst ) buc[i] = 0;
        rep( i, 1, N ) buc[rnk[i]] ++;
        rep( i, 1, lst ) buc[i] += buc[i - 1];
        per( i, N, 1 ) sa[buc[rnk[tmp[i]]] --] = tmp[i];
        lst = 0;
        rep( i, 1, N )
            tmp[sa[i]] = ( lst += ! Equal( sa[i], sa[i - 1], k ) );
        rep( i, 1, N ) rnk[i] = tmp[i];
    }
    for( int i = 1, j, k = 0 ; i <= N ; i ++ ) {
        if( k ) k --;
        if( rnk[i] == 1 ) continue;
        j = sa[rnk[i] - 1];
        while( i + k <= N && j + k <= N && str[i + k] == str[j + k] ) k ++;
        mn[rnk[i]][0] = k;
    }
    lg2[0] = -1; 
    rep( i, 1, N ) lg2[i] = lg2[i >> 1] + 1;
    for( int j = 1 ; j <= lg2[N] ; j ++ )
        for( int i = 1 ; i + ( 1 << ( j - 1 ) ) <= N ; i ++ )
            mn[i][j] = Min( mn[i][j - 1], mn[i + ( 1 << ( j - 1 ) )][j - 1] );
}

inline int LCP( const int &x, const int &y ) {
    int l = rnk[x], r = rnk[y];
    if( l > r ) std :: swap( l, r );
    int k = lg2[r - ( ++ l ) + 1];
    return Min( mn[l][k], mn[r - ( 1 << k ) + 1][k] );
}

int main() {
    int T; Read( T );
    while( T -- ) {
        Read( N );
        scanf( "%s", str + 1 );
        Init();
        rep( i, 1, N ) dp[i] = - 1e9;
        rep( i, 1, N ) {
            dp[i] = Max( dp[i], N - i + 1 );
            rep( j, i + 1, N ) 
                if( rnk[i] < rnk[j] ) {
                    int l = LCP( i, j );
                    dp[j] = Max( dp[j], dp[i] + ( N - j + 1 ) - l );
                }
        }
        int ans = - 1e9;
        rep( i, 1, N ) ans = Max( ans, dp[i] );
        Write( ans ), putchar( '\n' );
    }
    return 0;
}