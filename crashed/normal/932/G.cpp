#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 1e9 + 7;
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

char buf[MAXN], str[MAXN];

int dp[MAXN], lnk[MAXN], diff[MAXN], val[MAXN];

int ch[MAXN][26], fail[MAXN], len[MAXN];
int ntot = 0, lst = 0;

int N;

int main() {
    scanf( "%s", buf + 1 );
    N = strlen( buf + 1 );
    rep( i, 1, N / 2 ) str[i * 2 - 1] = buf[i];
    rep( i, N / 2 + 1, N ) str[( N - i + 1 ) * 2] = buf[i];
    len[lst = fail[0] = ++ ntot] = -1, dp[0] = 1;
    rep( i, 1, N ) {
        int x = str[i] - 'a';
        while( str[i - len[lst] - 1] ^ str[i] ) lst = fail[lst];
        if( ! ch[lst][x] ) {
            int cur = ++ ntot, p = fail[lst];
            while( str[i - len[p] - 1] ^ str[i] ) p = fail[p];
            len[cur] = len[lst] + 2, fail[cur] = ch[p][x];
            ch[lst][x] = cur, diff[cur] = len[cur] - len[fail[cur]];
            lnk[cur] = diff[cur] == diff[fail[cur]] ? lnk[fail[cur]] : fail[cur];
        }
        lst = ch[lst][x];
        for( int p = lst ; p > 1 ; p = lnk[p] ) {
            int q = lnk[p];
            if( q == fail[p] ) val[p] = dp[i - len[p]];
            else val[p] = ( val[fail[p]] + dp[i - len[q] - diff[p]] ) % mod;
            if( i % 2 == 0 ) ( dp[i] += val[p] ) %= mod;
        }
    }
    write( dp[N] ), putchar( '\n' );
    return 0;
}