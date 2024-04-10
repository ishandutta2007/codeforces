#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5, MAXLOG = 19;

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

struct Edge {
    int to, nxt;
} Graph[MAXN << 1];

int dep[MAXN];

struct Path {
    int u, v;

    Path(): u( 0 ), v( 0 ) {}
    Path( int n ): u( n ), v( n ) {}
    Path( int U, int V ): u( U ), v( V ) {
        if( dep[u] > dep[v] ) std :: swap( u, v );
    }

    friend Path operator + ( const Path &p, const Path &q );
};

Path tre[MAXN << 2];
int perm[MAXN], val[MAXN];

int RMQ[MAXLOG][MAXN << 1], lg2[MAXN << 1];
int Euler[MAXN << 1], fir[MAXN], ID = 0;
int DFN[MAXN], siz[MAXN], tot = 0;

int head[MAXN], cnt = 1;

int N, Q;

void AddEdge( const int from, const int to ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    head[from] = cnt;
}

void Init( const int u, const int fa ) {
    dep[u] = dep[fa] + 1;
    Euler[fir[u] = ++ ID] = u;
    DFN[u] = ++ tot, siz[u] = 1;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa ) 
            Init( v, u ), Euler[++ ID] = u, siz[u] += siz[v];
}

void Init() {
    Init( 1, 0 ), lg2[0] = -1; 
    rep( i, 1, ID ) lg2[i] = lg2[i >> 1] + 1;
    rep( i, 1, ID ) RMQ[0][i] = Euler[i];
    for( int j = 1, a, b ; j <= lg2[ID] ; j ++ )
        for( int i = 1 ; i + ( 1 << ( j - 1 ) ) <= ID ; i ++ ) {
            a = RMQ[j - 1][i], b = RMQ[j - 1][i + ( 1 << ( j - 1 ) )];
            RMQ[j][i] = dep[a] < dep[b] ? a : b;
        }
}

int LCA( const int u, const int v ) {
    int l = fir[u], r = fir[v];
    if( l > r ) std :: swap( l, r );
    int k = lg2[r - l + 1];
    int a = RMQ[k][l], b = RMQ[k][r - ( 1 << k ) + 1];
    return dep[a] < dep[b] ? a : b;
}

inline bool Inside( const int x, const int u ) {
    return DFN[u] <= DFN[x] && DFN[x] < DFN[u] + siz[u];
}

Path operator + ( const Path &p, const Path &q ) {
    if( ! p.u ) return q;
    if( ! q.u ) return p;
    if( p.u == -1 || q.u == -1 ) return Path( -1 );
    int siC, siD;
    int a = p.u, b = p.v, c = q.u, d = q.v;
    // dep[a] < dep[b]
    if( Inside( b, a ) ) {
             if( Inside( b, c ) && Inside( c, a ) ) siC = 0;
        else if( Inside( c, b ) ) siC = 1;
        else if( ! Inside( c, a ) || LCA( c, b ) == a ) siC = -1;
        else { return Path( -1 ); }
             if( Inside( b, d ) && Inside( d, a ) ) siD = 0;
        else if( Inside( d, b ) ) siD = 1;
        else if( ! Inside( d, a ) || LCA( d, b ) == a ) siD = -1;
        else { return Path( -1 ); }
    } else {
             if( Inside( a, c ) && LCA( c, b ) == LCA( a, b ) ) siC = 0;
        else if( Inside( b, c ) && LCA( a, c ) == LCA( a, b ) ) siC = 0;
        else if( Inside( c, a ) ) siC = -1;
        else if( Inside( c, b ) ) siC = 1;
        else { return Path( -1 ); }
             if( Inside( a, d ) && LCA( d, b ) == LCA( a, b ) ) siD = 0;
        else if( Inside( b, d ) && LCA( a, d ) == LCA( a, b ) ) siD = 0;
        else if( Inside( d, a ) ) siD = -1;
        else if( Inside( d, b ) ) siD = 1;
        else { return Path( -1 ); }
    }
    if( siC == siD ) {
        if( ! siC ) return p;
        if( siC > 0 ) {
            if( ! Inside( d, c ) ) return Path( -1 );
            return Path( d, a );
        } else {
            if( ! Inside( b, a ) ) {
                if( ! Inside( d, c ) ) return Path( -1 );
                return Path( d, b );
            } else {
                if( Inside( a, c ) ) {
                    if( ! Inside( d, c ) ) return Path( b, d );
                    else if( Inside( a, d ) ) return Path( b, c );
                    else if( LCA( a, d ) == c ) return Path( b, d );
                    else { return Path( -1 ); }
                } else if( Inside( a, d ) ) {
                    return Path( b, c );
                } else if( Inside( d, c ) ) {
                    return Path( b, d );
                } else { return Path( -1 ); }
            }
        }
    } else {
        if( ! siC ) return siD < 0 ? Path( d, b ) : Path( a, d );
        if( ! siD ) return siC < 0 ? Path( c, b ) : Path( a, c );
        return q;
    }
}

inline void Upt( const int x ) { tre[x] = tre[x << 1] + tre[x << 1 | 1]; }

void Build( const int x, const int l, const int r ) {
    if( l > r ) return ;
    if( l == r ) { tre[x] = Path( perm[l] ); return ; }
    int mid = ( l + r ) >> 1;
    Build( x << 1, l, mid );
    Build( x << 1 | 1, mid + 1, r );
    Upt( x );
}

void Update( const int x, const int l, const int r, const int p, const int nw ) {
    if( l == r ) { tre[x] = Path( nw ); return ; }
    int mid = ( l + r ) >> 1;
    if( p <= mid ) Update( x << 1, l, mid, p, nw );
    else Update( x << 1 | 1, mid + 1, r, p, nw );
    Upt( x );
}

int Search( const int x, const int l, const int r, const Path alr ) {
    if( l == r ) {
        if( ~ ( alr + tre[x] ).u ) return l;
        return l - 1;
    }
    int mid = ( l + r ) >> 1;
    if( ~ ( alr + tre[x << 1] ).u )
        return Search( x << 1 | 1, mid + 1, r, alr + tre[x << 1] );
    return Search( x << 1, l, mid, alr );
}

int main() {
    read( N );
    rep( i, 1, N ) read( val[i] ), perm[++ val[i]] = i;
    rep( i, 2, N ) {
        int fa; read( fa );
        AddEdge( fa, i ), AddEdge( i, fa );
    }
    Init();
    Build( 1, 1, N ), read( Q );
    int opt, x, y;
    while( Q -- ) {
        read( opt );
        if( opt == 1 ) {
            read( x ), read( y );
            Update( 1, 1, N, val[x], y );
            Update( 1, 1, N, val[y], x );
            std :: swap( val[x], val[y] );
        } 
        if( opt == 2 )
            write( Search( 1, 1, N, Path() ) ), putchar( '\n' );
    }
    return 0; 
}