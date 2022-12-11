// LUOGU_RID: 91604712
#include <cstdio>
#include <vector>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXN = 5e5 + 5, MAXLOG = 20, MAXE = 2e6 + 5;

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

struct MyGraph {
    struct Edge {
        int to, nxt;
    } Graph[MAXE << 1];

    int head[MAXN << 1], cnt;

    MyGraph(): head{}, cnt( 1 ) {}

    inline const Edge& operator [] ( const int &idx ) const { return Graph[idx]; }

    inline void AddE( const int &from, const int &to ) {
        AddEdge( from, to ), AddEdge( to, from );
    }

    inline void AddEdge( const int &from, const int &to ) {
        Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
        head[from] = cnt;
    }
};

struct TwoMax {
    int x, y;

    TwoMax(): x( - INF ), y( - INF ) {}
    TwoMax( int X ): x( X ), y( - INF ) {}
    TwoMax( int X, int Y ): x( X ), y( Y ) {}

    inline void Upt( const int &z ) {
        if( z >= x ) y = x, x = z;
        else if( z > y ) y = z;
    }
};

int lg2[MAXN];
int mx1[MAXN][MAXLOG], mx2[MAXN][MAXLOG];

MyGraph org, tre;

int val[MAXN];
int cir[MAXN], tot = 0;
int pref[MAXN], suff[MAXN];

TwoMax dp[MAXN];
int slvRes[MAXN << 1];

int stk[MAXN], top = 0;
int DFN[MAXN], LOW[MAXN], ID = 0;

int N, M, ntot = 0;

void Solve1( const int &u, const int &fa ) {
    dp[u] = TwoMax( 0 );
    stk[++ top] = u, DFN[u] = LOW[u] = ++ ID;
    for( int i = org.head[u], v ; i ; i = org[i].nxt )
        if( ! DFN[v = org[i].to] ) {
            Solve1( v, u );
            LOW[u] = Min( LOW[u], LOW[v] );
            if( LOW[v] == DFN[u] ) {
                cir[tot = 1] = u;
                do cir[++ tot] = stk[top];
                while( stk[top --] ^ v );
                int res = INF;
                pref[1] = - INF, suff[tot + 1] = - INF;
                rep( j, 2, tot ) pref[j] = Max( pref[j - 1], dp[cir[j]].x + j );
                per( j, tot, 2 ) suff[j] = Max( suff[j + 1], dp[cir[j]].x - j );
                rep( j, 1, tot ) res = Min( res, Max( pref[j] - 1, suff[j + 1] + tot + 1 ) );
                dp[u].Upt( res );

                slvRes[++ ntot] = res;
                rep( j, 1, tot ) tre.AddE( cir[j], ntot );
            } else if( LOW[v] > DFN[u] ) {
                dp[u].Upt( dp[v].x + 1 );
                top --, tre.AddE( u, v );
            }
        } else if( v ^ fa ) LOW[u] = Min( LOW[u], DFN[v] );
}

inline int GetMax1( const int &l, const int &r ) {
    if( l > r ) return - INF;
    int k = lg2[r - l + 1];
    return Max( mx1[l][k], mx1[r - ( 1 << k ) + 1][k] );
}

inline int GetMax2( const int &l, const int &r ) {
    if( l > r ) return - INF;
    int k = lg2[r - l + 1];
    return Max( mx2[l][k], mx2[r - ( 1 << k ) + 1][k] );
}

inline int GetValue( const int &x, const int &y ) {
    int res = - INF;
    if( x <= y ) {
        res = Max( res, GetMax2( x + 1, y ) - x );
        res = Max( res, GetMax1( y + 1, tot ) + x + tot );
        res = Max( res, GetMax1( 1, x - 1 ) + x );
    } else {
        res = Max( res, GetMax1( y + 1, x - 1 ) + x );
        res = Max( res, GetMax2( x + 1, tot ) - x );
        res = Max( res, GetMax2( 1, y ) + tot - x );
    }
    return res;
}

inline void CircleTransform( const int &cen ) {
    tot = 0;
    for( int i = tre.head[cen] ; i ; i = tre[i].nxt )
        cir[++ tot] = tre[i].to;
    std :: reverse( cir + 1, cir + 1 + tot );
    rep( i, 2, tot ) val[i] = dp[cir[i]].x;
    val[1] = dp[cir[1]].x == slvRes[cen] ? dp[cir[1]].y : dp[cir[1]].x;
    lg2[0] = -1; rep( i, 1, tot ) lg2[i] = lg2[i >> 1] + 1;
    rep( i, 1, tot ) mx1[i][0] = val[i] - i, mx2[i][0] = val[i] + i;
    for( int j = 1 ; j <= lg2[tot] ; j ++ )
        for( int i = 1 ; i + ( 1 << ( j - 1 ) ) <= tot ; i ++ )
            mx1[i][j] = Max( mx1[i][j - 1], mx1[i + ( 1 << ( j - 1 ) )][j - 1] ),
            mx2[i][j] = Max( mx2[i][j - 1], mx2[i + ( 1 << ( j - 1 ) )][j - 1] );
    int d = tot >> 1;
    rep( i, 2, tot ) {
        int res = GetValue( i, ( i + d - 1 ) % tot + 1 );
        if( tot % 2 == 0 ) res = Min( res, GetValue( i, ( i + d - 2 ) % tot + 1 ) );
        dp[cir[i]].Upt( res );
    }
}

void Solve2( const int &u, const int &fa ) {
    if( u <= N ) {
        for( int i = tre.head[u], v ; i ; i = tre[i].nxt )
            if( ( v = tre[i].to ) ^ fa ) {
                if( v <= N ) { // normal node
                    int tmp = dp[u].x == dp[v].x + 1 ? dp[u].y : dp[u].x;
                    dp[v].Upt( tmp + 1 ), Solve2( v, u );
                } else {
                    CircleTransform( v );
                    Solve2( v, u );
                }
            }
    } else {
        for( int i = tre.head[u], v ; i ; i = tre[i].nxt )
            if( ( v = tre[i].to ) ^ fa ) Solve2( v, u );
    }
}

int main() {
    Read( N ), Read( M ), ntot = N;
    rep( i, 1, M ) {
        int u, v; 
        Read( u ), Read( v );
        org.AddE( u, v );
    }
    Solve1( 1, 0 );
    Solve2( 1, 0 );
    rep( i, 1, N ) Write( dp[i].x ), putchar( " \n"[i == N] );
    return 0;
}