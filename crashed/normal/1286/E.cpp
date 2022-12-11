#include <map>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef __int128 LLL;
typedef long long LL;

const int MAXN = 6e5 + 5, MAXLOG = 20;

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

std :: map<int, int> app;

int mn[MAXN][MAXLOG], lg2[MAXN];

int nxt[MAXN], fail[MAXN];
char str[MAXN];

int N;

inline int GetMin( const int &l, const int &r ) {
    int k = lg2[r - l + 1];
    return Min( mn[r][k], mn[l + ( 1 << k ) - 1][k] );
}

int main() {
    read( N );
    LLL ans = 0; LL res = 0;
    lg2[0] = -1; rep( i, 1, N ) lg2[i] = lg2[i >> 1] + 1;
    for( int i = 1, j = 0 ; i <= N ; i ++ ) {
        char buf[5]; int wei;
        scanf( "%s", buf ), read( wei );
        str[i] = ( buf[0] - 'a' + ans % 26 ) % 26 + 'a';
        mn[i][0] = ( wei ^= ( ans & ( ( 1 << 30 ) - 1 ) ) );
        for( int j = 1 ; ( 1 << j ) <= i ; j ++ )
            mn[i][j] = Min( mn[i][j - 1], mn[i - ( 1 << ( j - 1 ) )][j - 1] );
        if( i == 1 ) nxt[i] = j = 0;
        else {
            while( j && str[j + 1] != str[i] ) j = nxt[j];
            if( str[j + 1] == str[i] ) j ++;
            nxt[i] = j;

            fail[i - 1] = str[nxt[i - 1] + 1] == str[i] ? fail[nxt[i - 1]] : nxt[i - 1];
            for( int p = i - 1 ; p ; ) {
                if( str[p + 1] == str[i] ) p = fail[p];
                else {
                    app[GetMin( i - p, i - 1 )] --; 
                    res -= GetMin( i - p, i - 1 );
                    p = nxt[p];
                }
            }
            while( ! app.empty() && app.rbegin() -> first > wei ) {
                app[wei] += app.rbegin() -> second; 
                res += 1ll * app.rbegin() -> second * ( wei - app.rbegin() -> first );
                app.erase( -- app.end() );
            }
            if( str[i] == str[1] ) res += wei, app[wei] ++;
        }
        ans += GetMin( 1, i ) + res;
        write( ans ), putchar( '\n' );
    }
    return 0;
}