#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
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

int dp[MAXN], pre[MAXN], suf[MAXN], preSum[MAXN];

char A[MAXN], L[MAXN], R[MAXN];
int zL[MAXN], zR[MAXN], nxtL[MAXN], nxtR[MAXN];

int N, lenL, lenR;

void ExKMP( int *nxt, const char *tex, const char *pat, int *z ) {
    int n = strlen( tex + 1 ), m = strlen( pat + 1 );
    while( nxt[1] < n && nxt[1] < m && 
           tex[1 + nxt[1]] == pat[1 + nxt[1]] ) nxt[1] ++;
    for( int i = 2, l = 1, r = 1 ; i <= n ; i ++ ) {
        if( i < r ) nxt[i] = MIN( r - i, z[i - l + 1] );
        while( nxt[i] < m && i + nxt[i] <= n && tex[i + nxt[i]] == pat[1 + nxt[i]] ) nxt[i] ++;
        if( i + nxt[i] > r ) l = i, r = i + nxt[i];
    }
}

int main() {
    scanf( "%s%s%s", A + 1, L + 1, R + 1 );
    N = strlen( A + 1 ), lenL = strlen( L + 1 ), lenR = strlen( R + 1 );
    ExKMP( zL, L, L, zL );
    ExKMP( zR, R, R, zR );
    ExKMP( nxtL, A, L, zL );
    ExKMP( nxtR, A, R, zR );
    pre[1] = 0, suf[N] = N + 1;
    rep( i, 2, N + 1 ) pre[i] = A[i - 1] == '0' ? pre[i - 1] : i - 1;
    per( i, N - 1, 0 ) suf[i] = A[i + 1] == '0' ? suf[i + 1] : i + 1;
    dp[0] = preSum[0] = 1;
    rep( i, 1, N ) {
        int l, r;
        if( i < lenL ) l = - 1e9;
        else if( lenL == 1 && L[1] == '0' ) l = i;
        else {
            l = pre[i - lenL + 2];
            if( l == i - lenL + 1 && 
                nxtL[l] < lenL && A[l + nxtL[l]] < L[nxtL[l] + 1] ) 
                l = pre[l];
        }
        if( i < lenR ) r = suf[0];
        else if( lenR == 1 && R[1] == '0' ) 
            r = A[i] == '0' ? r : 1e9;
        else {
            r = suf[i - lenR];
            if( r == i - lenR + 1 && 
                nxtR[r] < lenR && A[r + nxtR[r]] > R[nxtR[r] + 1] )
                r = suf[r];
        }
        if( r <= l ) dp[i] = ( preSum[l - 1] - ( r == 1 ? 0 : preSum[r - 2] ) + mod ) % mod;
        if( lenL == 1 && L[1] == '0' && A[i] == '0' ) ( dp[i] += dp[i - 1] ) %= mod;
        preSum[i] = ( preSum[i - 1] + dp[i] * ( A[i + 1] != '0' ) ) % mod;
    }
    write( dp[N] ), putchar( '\n' );
    return 0;
}