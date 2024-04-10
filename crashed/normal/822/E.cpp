#include <set>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5, MAXLOG = 19, MAXX = 35;

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
_T Min( const _T &a, const _T &b ) {
    return a < b ? a : b;
}

template<typename _T>
_T Max( const _T &a, const _T &b ) {
    return a > b ? a : b;
}

int dp[MAXN][MAXX];

int RMQ[MAXN][MAXLOG], lg2[MAXN];

int buc[MAXN], tmp[MAXN];
int sa[MAXN], rnk[MAXN << 1];

char str[MAXN];
char S[MAXN], T[MAXN];

int N, M, K, L = 0;

inline bool Equal( const int &x, const int &y, const int &k ) {
    return rnk[x] == rnk[y] && rnk[x + k] == rnk[y + k];
}

inline int LCP( const int &x, const int &y ) {
    if( x == y ) return L - x + 1;
    int l = rnk[x], r = rnk[y];
    if( l > r ) std :: swap( l, r );
    l ++; int k = lg2[r - l + 1];
    return Min( RMQ[l][k], RMQ[r - ( 1 << k ) + 1][k] );
}

void SuffixSort( const int &n ) {
    static int bit[MAXN] = {};

    rep( i, 1, n ) bit[i] = str[i] - 'a' + 1;
    rep( i, 1, n ) buc[bit[i]] ++;
    rep( i, 1, 27 ) buc[i] += buc[i - 1];
    per( i, n, 1 ) sa[buc[bit[i]] --] = i;
    rep( i, 1, 27 ) buc[i] = 0;
    rep( i, 1, n ) buc[bit[i]] = 1;
    rep( i, 1, 27 ) buc[i] += buc[i - 1];
    rep( i, 1, n ) rnk[i] = buc[bit[i]];
    for( int k = 1, lst = buc[27] ; lst < n ; k <<= 1 ) {
        int tot = 0;
        rep( i, n - k + 1, n ) tmp[++ tot] = i;
        rep( i, 1, n ) if( sa[i] > k ) tmp[++ tot] = sa[i] - k;
        rep( i, 1, lst ) buc[i] = 0;
        rep( i, 1, n ) buc[rnk[i]] ++;
        rep( i, 1, lst ) buc[i] += buc[i - 1];
        per( i, n, 1 ) sa[buc[rnk[tmp[i]]] --] = tmp[i];
        lst = 0;
        rep( i, 1, n ) {
            lst += ! Equal( sa[i], sa[i - 1], k );
            tmp[sa[i]] = lst;
        }
        rep( i, 1, n ) rnk[i] = tmp[i];
    }
    for( int i = 1, j, k = 0 ; i <= n ; i ++ ) {
        if( k ) k --;
        if( rnk[i] == 1 ) continue;
        j = sa[rnk[i] - 1];
        while( i + k <= n && j + k <= n && str[i + k] == str[j + k] ) k ++;
        RMQ[rnk[i]][0] = k;
    }
    lg2[0] = -1; rep( i, 1, n ) lg2[i] = lg2[i >> 1] + 1;
    for( int j = 1 ; j <= lg2[n] ; j ++ )
        for( int i = 1 ; i + ( 1 << ( j - 1 ) ) <= n ; i ++ )
            RMQ[i][j] = Min( RMQ[i][j - 1], RMQ[i + ( 1 << ( j - 1 ) )][j - 1] );
}

int main() {
    read( N ), scanf( "%s", S + 1 );
    read( M ), scanf( "%s", T + 1 );
    read( K );
    rep( i, 1, N ) str[++ L] = S[i];
    str[++ L] = 'z' + 1;
    rep( i, 1, M ) str[++ L] = T[i];
    SuffixSort( L );
    rep( j, 0, K ) dp[0][j] = 0;
    rep( i, 0, N - 1 )
        rep( j, 0, K ) {
            if( dp[i][j] == M )
                return puts( "YES" ), 0;
            dp[i + 1][j] = Max( dp[i + 1][j], dp[i][j] );
            int lcp = LCP( i + 1, N + 1 + dp[i][j] + 1 );
            dp[i + lcp][j + 1] = Max( dp[i + lcp][j + 1], dp[i][j] + lcp );
        }
    rep( j, 0, K )
        if( dp[N][j] == M )
            return puts( "YES" ), 0;
    puts( "NO" );
    return 0;
}