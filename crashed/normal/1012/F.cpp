// LUOGU_RID: 92608596
#include <cstdio>
#include <utility>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXN = 30, MAXS = ( 1 << 22 ) + 5;

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

typedef std :: pair<int, int> Interval;

Interval itv[MAXN]; int tot1 = 0;
int fir[MAXN], sec[MAXN], lef[MAXN], tot2 = 0;

int glbFir[MAXN], glbSec[MAXN], corr[MAXN], dif[MAXN], tot3 = 0;

int dp[MAXS], tsf[MAXS], pos[MAXS];

int portId[MAXN], portTim[MAXN];
int cosm[MAXN], beg[MAXN], dura[MAXN];

int seq1[MAXN], seq2[MAXN];

int N, P;

void FindWay( const int &S, const int &col ) {
    if( ! S ) return ;
    portId[tsf[S]] = col;
    portTim[tsf[S]] = dp[S] - cosm[tsf[S]];
    FindWay( S ^ ( 1 << tsf[S] ), col );
}

int main() {
    Read( N ), Read( P );
    rep( i, 0, N - 1 ) {
        seq1[i] = seq2[i] = i;
        Read( beg[i] ), Read( dura[i] ), Read( cosm[i] );
        itv[++ tot1] = { beg[i], beg[i] + dura[i] - 1 };
    }
    std :: sort( seq1, seq1 + N,
        [] ( const int &a, const int &b ) -> bool {
            return beg[a] < beg[b];
        } );
    std :: sort( itv + 1, itv + 1 + tot1 );
    if( 1 < itv[1].first ) 
        tot3 ++, glbFir[tot3] = 1, glbSec[tot3] = itv[1].first - 1;
    rep( i, 2, tot1 ) if( itv[i - 1].second + 1 < itv[i].first )
        tot3 ++, glbFir[tot3] = itv[i - 1].second + 1, glbSec[tot3] = itv[i].first - 1;
    int up = 1 << N; dp[0] = 1;
    for( pos[0] = 1 ; glbSec[pos[0]] < dp[0] ; pos[0] ++ );
    for( int S = 1 ; S < up ; S ++ ) {
        int veryLst = 0, lst, res, cur3, up, cost;
        tot1 = tot2 = 0, dp[S] = INF, tsf[S] = -1;
        rep( i, 0, N - 1 ) if( S >> seq1[i] & 1 ) {
            int l = beg[seq1[i]], r = dura[seq1[i]] + l - 1;
            if( veryLst + 2 < r ) tot2 ++, fir[tot2] = veryLst + 1, sec[tot2] = l - 1;
            veryLst = r;
        }
        rep( i, 1, tot3 ) {
            corr[i] = corr[i - 1];
            while( corr[i] < tot2 && fir[corr[i] + 1] <= glbFir[i] ) corr[i] ++;
        }
        rep( i, 1, tot3 ) corr[i] = sec[corr[i]], dif[i] = corr[i] - glbFir[i];
        for( int i = 0, j ; i < N ; i ++ ) if( S >> i & 1 ) {
            lst = dp[S ^ ( 1 << i )], res = INF, cost = cosm[i];
            if( lst > sec[tot2] || lst > glbSec[tot3] ) continue;
            cur3 = pos[S ^ ( 1 << i )];
            up = Min( beg[i], dp[S] ) - cost;
            if( lst >= glbFir[cur3] ) {
                if( lst + cost <= corr[cur3] )
                    res = lst + cost;
                cur3 ++;
            }
            if( res == INF ) {
                for( j = cur3 ; j <= tot3 && glbFir[j] < up ; j ++ ) 
                    if( cost <= dif[j] ) {
                        res = glbFir[j] + cost; break;
                    }
            }
            if( res < beg[i] && res < dp[S] )
                dp[S] = res, tsf[S] = i;
        }
        if( dp[S] < INF )
            for( pos[S] = 1 ; glbSec[pos[S]] < dp[S] ; pos[S] ++ );
    }
    if( P == 1 ) {
        if( dp[up - 1] == INF )
            return puts( "NO" ), 0;
        else FindWay( up - 1, 1 );
    } else {
        int bst = -1;
        rep( i, 0, up - 1 )
            if( dp[i] < INF && dp[( up - 1 ) ^ i] < INF ) {
                bst = i; break;
            }
        if( bst == -1 )
            return puts( "NO" ), 0;
        else {
            FindWay( bst, 1 );
            FindWay( ( up - 1 ) ^ bst, 2 );
        }
    }
    puts( "YES" );
    rep( i, 0, N - 1 )
        Write( portId[i] ), putchar( ' ' ),
        Write( portTim[i] ), putchar( '\n' );
    return 0;
}