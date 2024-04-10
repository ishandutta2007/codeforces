#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 1e5 + 5, MAXS = MAXN * 20;

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

struct Edge {
    int to, nxt;
} Graph[MAXN << 1];

struct Line {
    LL k, b;

    Line(): k( 0 ), b( INF ) {}
    Line( LL K, LL B ): k( K ), b( B ) {}

    inline LL operator () ( const LL &x ) const {
        return k * x + b;
    }
};

LL dp[MAXN];

Line tre[MAXS];
int lch[MAXS], rch[MAXS];
int rt[MAXN], ntot = 0;

int val[MAXN], tot = 0;
int A[MAXN], B[MAXN];

int head[MAXN], cnt = 1;

int N;

inline void AddEdge( const int &from, const int &to ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    head[from] = cnt;
}

void Modify( int &x, const int &l, const int &r, Line nw ) {
    if( l > r ) return ;
    if( ! nw.k && nw.b == INF ) return ;
    int mid = ( l + r ) >> 1; x = x ? x : ++ ntot;
    if( tre[x]( val[mid] ) > nw( val[mid] ) ) std :: swap( tre[x], nw );
    if( tre[x]( val[l] ) > nw( val[l] ) ) Modify( lch[x], l, mid - 1, nw );
    if( tre[x]( val[r] ) > nw( val[r] ) ) Modify( rch[x], mid + 1, r, nw );
}

LL Query( const int &x, const int &l, const int &r, const int &p ) {
    if( ! x || l > r ) return INF;
    int mid = ( l + r ) >> 1; LL ret = tre[x]( val[p] );
    if( p < mid ) ret = std :: min( ret, Query( lch[x], l, mid - 1, p ) );
    if( p > mid ) ret = std :: min( ret, Query( rch[x], mid + 1, r, p ) );
    return ret;
}

int Merge( const int &u, const int &v, const int &l, const int &r ) {
    if( ( ! u && ! v ) || l > r ) return 0;
    if( ! u || ! v ) return u | v;
    Line nw = tre[v]; int mid = ( l + r ) >> 1;
    if( tre[u]( val[mid] ) > nw( val[mid] ) ) std :: swap( tre[u], nw );
    if( tre[u]( val[l] ) > nw( val[l] ) ) Modify( lch[u], l, mid - 1, nw );
    if( tre[u]( val[r] ) > nw( val[r] ) ) Modify( rch[u], mid + 1, r, nw );
    lch[u] = Merge( lch[u], lch[v], l, mid - 1 );
    rch[u] = Merge( rch[u], rch[v], mid + 1, r );
    return u;
}

void DFS( const int &u, const int &fa ) {
    rt[u] = 0;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa ) 
            DFS( v, u ), rt[u] = Merge( rt[u], rt[v], 1, tot );
    if( ! rt[u] ) dp[u] = 0;
    else dp[u] = Query( rt[u], 1, tot, A[u] );
    Modify( rt[u], 1, tot, Line( B[u], dp[u] ) );
}

int main() {
    Read( N );
    rep( i, 1, N ) Read( A[i] );
    rep( i, 1, N ) Read( B[i] );
    rep( i, 1, N - 1 ) {
        int u, v; Read( u ), Read( v );
        AddEdge( u, v ), AddEdge( v, u );
    }
    rep( i, 1, N ) val[++ tot] = A[i];
    std :: sort( val + 1, val + 1 + tot );
    tot = std :: unique( val + 1, val + 1 + tot ) - val - 1;
    rep( i, 1, N ) A[i] = std :: lower_bound( val + 1, val + 1 + tot, A[i] ) - val;
    DFS( 1, 0 );
    rep( i, 1, N ) Write( dp[i] ), putchar( " \n"[i == N] );
    return 0;
}