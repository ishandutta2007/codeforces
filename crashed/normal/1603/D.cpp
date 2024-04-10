#include <cmath>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 1e5 + 5, MAXLOG = 25;

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

LL dp[MAXLOG][MAXN];

LL tmpSu[MAXN];
int tmp[MAXN], tot = 0;

std :: vector<LL> suSml[MAXN], suLrg[MAXN];
int hlf[MAXN];

LL prefPhi[MAXN];
int prime[MAXN], phi[MAXN], pn;
bool isPrime[MAXN];

int N, K;

#define GetAddr( x, y ) ( (y) <= hlf[x] ? suSml[x][y - 1] : suLrg[x][x / (y) - 1] )

inline void EulerSieve( const int &n ) {
    phi[1] = 1;
    for( int i = 2 ; i <= n ; i ++ ) {
        if( ! isPrime[i] ) phi[prime[++ pn] = i] = i - 1;
        for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= n ; j ++ ) {
            isPrime[i * prime[j]] = true;
            if( ! ( i % prime[j] ) ) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * ( prime[j] - 1 );
        }
    }
    rep( i, 1, n ) prefPhi[i] = prefPhi[i - 1] + phi[i];
}

inline LL Query( int l, const int &r ) {
    int k = r / ( r / l );
    LL ret = 1ll * ( k - l + 1 ) * prefPhi[r / l];
    if( k < r ) ret += GetAddr( r, r / ( k + 1 ) );
    return ret;
}

void Divide( const int &x, const int &L, const int &R, const int &tL, const int &tR ) {
    if( L > R || tL > tR ) return ;
    if( tL == tR ) {
        rep( i, L, R )
            dp[x][i] = dp[x - 1][tL] + Query( tL + 1, i );
        return ;
    }
    int mid = ( L + R ) >> 1, bst;
    dp[x][mid] = INF; LL tmpVal;
    for( int i = tL ; i < mid && i <= tR; i ++ ) {
        tmpVal = dp[x - 1][i] + Query( i + 1, mid );
        if( tmpVal < dp[x][mid] ) dp[x][mid] = tmpVal, bst = i;
    }
    Divide( x, L, mid - 1, tL, bst );
    Divide( x, mid + 1, R, bst, tR );
}

inline void Init( const int &n ) {
    EulerSieve( n );
    for( int r = 1 ; r <= n ; r ++ ) {
        hlf[r] = sqrt( r ), tot = 0;
        suSml[r].resize( hlf[r], 0 );
        suLrg[r].resize( hlf[r], 0 );
        for( int i = 1, j ; i <= r ; i = j + 1 ) {
            j = r / ( r / i );
            tot ++, tmp[tot] = r / i, tmpSu[tot] = prefPhi[r / i] * ( j - i + 1 );
        }
        LL val = 0;
        per( i, tot, 1 ) 
            GetAddr( r, tmp[i] ) = ( val += tmpSu[i] );
    }
    rep( i, 0, n ) dp[0][i] = ( i > 0 ) * INF;
    for( int i = 1 ; ( 1 << i ) <= n ; i ++ )
        Divide( i, 1, n, 0, n - 1 );
}

int main() {
    Init( 1e5 );

    int T; Read( T );
    while( T -- ) {
        Read( N ), Read( K );
        if( K >= 20 || N <= ( 1 << K ) - 1 ) {
            Write( N ), putchar( '\n' );
            continue;
        }
        Write( dp[K][N] ), putchar( '\n' );
    }
    return 0;
}