#include <ctime>
#include <cstdio>
#include <random>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e5 + 5;

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

unsigned aux[MAXN];
int lch[MAXN], rch[MAXN], fa[MAXN], siz[MAXN];

int p[MAXN];
bool vis[MAXN];

int N, Q;

inline unsigned GetSeed() {
    static char *tmp = new char;
    return time( 0 ) * ( unsigned long long ) tmp;
    // return 1145141u;
}

inline unsigned GetRand() {
    static std :: mt19937 rng( GetSeed() );
    static std :: uniform_int_distribution<> gen( 0, 4294967295u );
    return gen( rng );
}

inline bool Chk( const int x ) { return rch[fa[x]] == x; }

inline void Upt( const int &x ) { 
    if( ! x ) return ;
    siz[x] = siz[lch[x]] + siz[rch[x]] + 1; 
    if( lch[x] ) fa[lch[x]] = x;
    if( rch[x] ) fa[rch[x]] = x;
    fa[x] = 0;
}

void SplitRnk( const int u, const int k, int &x, int &y ) {
    if( ! u ) { x = y = 0; return ; }
    if( k <= siz[lch[u]] ) y = u, SplitRnk( lch[u], k, x, lch[y] ), Upt( y );
    else x = u, SplitRnk( rch[u], k - siz[lch[u]] - 1, rch[x], y ), Upt( x );
}

int Merge( const int u, const int v ) {
    if( ! u || ! v ) return u | v;
    if( aux[u] < aux[v] ) return rch[u] = Merge( rch[u], v ), Upt( u ), u;
    return lch[v] = Merge( u, lch[v] ), Upt( v ), v;
}

int GetRnk( int u ) {
    int ret = siz[lch[u]];
    for( ; fa[u] ; u = fa[u] )
        if( Chk( u ) ) ret += siz[lch[fa[u]]] + 1;
    return ret;
}

int FindRoot( int u ) {
    for( ; fa[u] ; u = fa[u] );
    return u;
}

int Kth( int u, int k ) {
    while( true ) {
        if( k < siz[lch[u]] ) u = lch[u];
        else {
            k -= siz[lch[u]];
            if( ! k ) break;
            k --, u = rch[u];
        }
    }
    return u;
}

int Query( const int x, const int k ) {
    int r = FindRoot( x );
    return Kth( r, ( GetRnk( x ) + k ) % siz[r] );
}

int main() {
    read( N ), read( Q );
    rep( i, 1, N ) { 
        read( p[i] );
        aux[i] = GetRand(), siz[i] = 1;
    }
    rep( i, 1, N ) {
        if( vis[i] ) continue;
        int rt = 0;
        for( int u = i ; ! vis[u] ; u = p[u] )
            rt = Merge( rt, u ), vis[u] = true;
    }
    int opt, a, b, l, r;
    while( Q -- ) {
        read( opt ), read( a ), read( b );
        if( opt == 1 ) {
            int u = FindRoot( a ), v = FindRoot( b );
            if( u ^ v ) {
                SplitRnk( u, GetRnk( a ) + 1, l, r );
                u = Merge( r, l );
                SplitRnk( v, GetRnk( b ) + 1, l, r );
                v = Merge( r, l );
                Merge( u, v );
            } else {
                SplitRnk( u, GetRnk( a ) + 1, l, r );
                u = Merge( r, l );
                SplitRnk( u, GetRnk( b ) + 1, l, r );
            }
        } else write( Query( a, b ) ), putchar( '\n' );
    }
    return 0;
}