#include <cstdio>
#include <utility>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int mod = 998244353;
const int MAXN = 5e5 + 5, MAXM = 605;

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

typedef std :: pair<int, int> Lanterns;

int pref[MAXM][MAXM], suff[MAXM][MAXM];

int f[MAXM], g[MAXM];
int coe[MAXM][MAXM];

Lanterns lnt[MAXN];
int lntX[MAXN], lntD[MAXN];
int imp[MAXN];

int L, N, M, Q;

inline int Mul( int x, const int &v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int& MulEq( int &x, const int &v ) { return x = 1ll * x * v % mod; }
inline int& SubEq( int &x, const int &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline int& AddEq( int &x, const int &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

int main() {
    Read( L ), Read( N ), Read( M );
    rep( i, 1, N ) Read( lnt[i].first ), lnt[i].second = L;
    rep( i, 1, M ) Read( imp[i] );
    imp[++ M] = - INF, imp[++ M] = INF;
    std :: sort( lnt + 1, lnt + 1 + N );
    std :: sort( imp + 1, imp + 1 + M );
    rep( i, 1, M ) rep( j, i + 1, M ) coe[i][j] = 1;
    rep( i, 1, N ) lntX[i] = lnt[i].first, lntD[i] = lnt[i].second;
    rep( i, 1, M - 1 ) {
        int prod = 1, p = std :: lower_bound( lntX + 1, lntX + 1 + N, imp[i] ) - lntX;
        rep( j, i + 1, M ) {
            while( p <= N && lntX[p] < imp[j] && lntX[p] - imp[i] <= imp[j] - lntX[p] )
                MulEq( prod, Min( lntX[p] - imp[i] - 1, lntD[p] ) + 1 ), p ++;
            MulEq( coe[i][j], prod );
        }
    }
    rep( i, 2, M ) {
        int prod = 1, p = std :: lower_bound( lntX + 1, lntX + 1 + N, imp[i] ) - lntX - 1;
        per( j, i - 1, 1 ) {
            while( p >= 1 && imp[j] <= lntX[p] && lntX[p] - imp[j] > imp[i] - lntX[p] )
                MulEq( prod, Min( imp[i] - lntX[p] - 1, lntD[p] ) + 1 ), p --;
            MulEq( coe[j][i], prod );
        }
    }
    f[1] = 1;
    rep( i, 2, M ) {
        f[i] = 0;
        rep( j, 1, i - 1 )
            AddEq( f[i], Mul( coe[j][i], f[j] ) );
        if( i < M ) MulEq( f[i], mod - 1 );
    }
    g[M] = 1;
    per( i, M - 1, 1 ) {
        g[i] = 0;
        rep( j, i + 1, M )
            AddEq( g[i], Mul( coe[i][j], g[j] ) );
        if( i > 1 ) MulEq( g[i], mod - 1 );
    }
    rep( i, 1, M ) per( j, M, i + 1 )
        suff[i][j] = Add( suff[i][j + 1], Mul( Mul( f[i], g[j] ), coe[i][j] ) );
    rep( i, 1, M ) rep( j, 1, i - 1 )
        pref[j][i] = Add( pref[j - 1][i], Mul( Mul( f[j], g[i] ), coe[j][i] ) );
    for( Read( Q ) ; Q -- ; ) {
        int ans = 0, b, v; Read( b ), v = L;
        int p = std :: upper_bound( imp + 1, imp + 1 + M, b ) - imp - 1;
        for( int j = p, i = p + 1 ; i <= M ; i ++ ) {
            while( j >= 1 && b - imp[j] <= imp[i] - b ) j --;
            if( j >= 1 ) AddEq( ans, Mul( Min( v, imp[i] - b - 1 ) + 1, pref[j][i] ) );
        }
        for( int i = p, j = p + 1 ; i >= 1 ; i -- ) {
            while( j <= M && b - imp[i] > imp[j] - b ) j ++;
            if( j <= M ) AddEq( ans, Mul( Min( v, b - imp[i] - 1 ) + 1, suff[i][j] ) );
        }
        Write( ans ), putchar( '\n' );
    }
    return 0;
}