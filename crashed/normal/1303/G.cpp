#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 1.5e5 + 5, MAXV = MAXN * 40;

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

struct Line {
    LL k, b;

    Line(): k( 0 ), b( - INF ) {}
    Line( LL K, LL B ): k( K ), b( B ) {}

    inline LL operator () ( const LL &x ) const {
        return k * x + b;
    }
};

struct Edge {
    int to, nxt;
} Graph[MAXN << 1];

struct LineSegTree {
    Line tre[MAXV];
    int lch[MAXV], rch[MAXV];
    int rt, ntot;

    LineSegTree(): rt( 0 ), ntot( 0 ) {}

    inline int NewNode() {
        int r = ++ ntot;
        tre[r] = Line();
        lch[r] = rch[r] = 0;
        return r;
    }

    void Modify( int &x, const LL &l, const LL &r, Line nw ) {
        if( l > r ) return ;
        if( ! nw.k && nw.b == - INF ) return ;
        LL mid = ( l + r ) >> 1; x = x ? x : NewNode();
        if( tre[x]( mid ) < nw( mid ) ) std :: swap( tre[x], nw );
        if( tre[x]( l ) < nw( l ) ) Modify( lch[x], l, mid - 1, nw );
        if( tre[x]( r ) < nw( r ) ) Modify( rch[x], mid + 1, r, nw );
    }

    LL Query( const int &x, const LL &l, const LL &r, const LL &p ) {
        if( ! x || l > r ) return - INF;
        LL mid = ( l + r ) >> 1, ret = tre[x]( p );
        if( p < mid ) ret = Max( ret, Query( lch[x], l, mid - 1, p ) );
        if( mid < p ) ret = Max( ret, Query( rch[x], mid + 1, r, p ) );
        return ret;
    }

    inline void Reset() { rt = ntot = 0; }
    inline LL Query( const LL &p ) { return Query( rt, 1, ( LL ) 1.5e11, p ); }
    inline void Modify( const Line &nw ) { Modify( rt, 1, ( LL ) 1.5e11, nw ); }
};

LineSegTree goDn, goUp;

int dep[MAXN], stk[MAXN], top = 0;
LL su[MAXN], toNod[MAXN], toRot[MAXN];

int siz[MAXN];
bool vis[MAXN];

int head[MAXN], A[MAXN], cnt = 1;

int N; LL ans = 0;

inline void AddEdge( const int &from, const int &to ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    head[from] = cnt;
}

int GetCen( const int &u, const int &fa, const int &all ) {
    siz[u] = 1; int ret = 0, mx = 0;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa && ! vis[v] ) {
            ret |= GetCen( v, u, all );
            siz[u] += siz[v], mx = Max( mx, siz[v] );
        }
    if( Max( all - siz[u], mx ) * 2 <= all ) ret = u;
    return ret;
}

void DFS( const int &u, const int &fa ) {
    stk[++ top] = u;
    dep[u] = dep[fa] + 1;
    su[u] = su[fa] + A[u];
    toNod[u] = toNod[fa] + su[fa] + A[u];
    toRot[u] = 1ll * dep[u] * A[u] + toRot[fa];
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa && ! vis[v] )
            DFS( v, u );
}

void Divide( const int &u, const int &all ) {
    goUp.Reset(), goDn.Reset();
    goDn.Modify( Line( 1, A[u] ) );
    goUp.Modify( Line( A[u], A[u] ) );
    vis[u] = true, dep[u] = su[u] = toNod[u] = toRot[u] = 0;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ! vis[v = Graph[i].to] ) {
            top = 0, DFS( v, u );
            rep( j, 1, top ) {
                int x = stk[j];
                ans = Max( ans, goDn.Query( su[x] ) + toRot[x] );
                ans = Max( ans, goUp.Query( dep[x] ) + toNod[x] );
            }
            rep( j, 1, top ) {
                int x = stk[j];
                goDn.Modify( Line( dep[x] + 1, toNod[x] + 1ll * ( dep[x] + 1 ) * A[u] ) );
                goUp.Modify( Line( su[x] + A[u], toRot[x] + su[x] + A[u] ) );
            }
        }
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ! vis[v = Graph[i].to] ) {
            int t = siz[v] > siz[u] ? all - siz[u] : siz[v];
            Divide( GetCen( v, u, t ), t );
        }
}

signed main() {
    Read( N );
    rep( i, 1, N - 1 ) {
        int u, v; Read( u ), Read( v );
        AddEdge( u, v ), AddEdge( v, u );
    }
    rep( i, 1, N ) Read( A[i] );
    Divide( GetCen( 1, 0, N ), N );
    Write( ans ), putchar( '\n' );
    return 0;
}