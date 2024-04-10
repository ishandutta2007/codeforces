#include <cstdio>
#include <vector>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 3005;

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

std :: vector<int> app[MAXN];

int pref[MAXN][MAXN];

int pre[MAXN], nxt[MAXN], cnt[MAXN];

int R, C, N, K;

int main() {
    read( R ), read( C ), read( N ), read( K );
    rep( i, 1, N ) {
        int x, y; read( x ), read( y );
        pref[x][y] ++, app[x].push_back( y );
    }
    rep( i, 1, R ) rep( j, 1, C ) pref[i][j] += pref[i - 1][j];
    LL ans = 0;
    rep( i, 1, R ) {
        int lst = 0;
        rep( j, 1, C ) {
            cnt[j] = pref[R][j] - pref[i - 1][j];
            if( ! cnt[j] ) continue;
            pre[j] = lst, nxt[lst] = j, lst = j;
        }
        int res = 0;
        nxt[lst] = C + 1, pre[C + 1] = lst;
        for( int p = nxt[0], q ; p <= C ; p = nxt[p] ) {
            q = p; 
            for( int su = cnt[p] ; su < K && q <= C ; su += cnt[q = nxt[q]] );
            if( q > C ) { break; } res += ( p - pre[p] ) * ( C - q + 1 );
        }
        ans += res;
        per( j, R, i ) {
            int n = app[j].size();
            for( int k = 0 ; k < n ; k ++ ) {
                int cur = app[j][k], p = app[j][k], r, su;
                for( su = 0 ; p && su < K ; su += cnt[p = pre[p]] );
                for( r = p = nxt[p], su = cnt[p] ; p <= cur ; su -= cnt[p], p = nxt[p] ) {
                    for( ; r <= C && su < K ; su += cnt[r = nxt[r]] );
                    if( r > C ) continue;
                    if( su == K ) res -= ( p - pre[p] ) * ( nxt[r] - r );
                }
                cnt[cur] --;
                if( ! cnt[cur] ) {
                    pre[nxt[cur]] = pre[cur];
                    nxt[pre[cur]] = nxt[cur];
                }
            }
            ans += res;
        }
    }
    write( ans ), putchar( '\n' );
    return 0;
}