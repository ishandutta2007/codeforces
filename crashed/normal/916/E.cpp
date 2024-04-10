#include <cstdio>
#include <utility>
#include <iostream>
    
#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )
    
typedef long long LL;

const int MAXN = 1e5 + 5, MAXLOG = 18;
    
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
_T Min( const _T a, const _T b ) {
    return a < b ? a : b;
}
    
struct Edge {
    int to, nxt;
} Graph[MAXN << 1];
    
LL su[MAXN << 2], tag[MAXN << 2];
    
int fath[MAXN][MAXLOG];
    
int DFN[MAXN], seq[MAXN], siz[MAXN], tot = 0;
    
int RMQ[MAXN << 1][MAXLOG], lg2[MAXN << 1];
int dep[MAXN], fir[MAXN], ID = 0;
    
int A[MAXN], head[MAXN], cnt = 1;
    
int N, Q, rt = 1;
    
inline void AddEdge( const int from, const int to ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    head[from] = cnt;
}
    
void Init( const int u, const int fa ) {
    seq[DFN[u] = ++ tot] = u;
    RMQ[fir[u] = ++ ID][0] = u;
    dep[u] = dep[fath[u][0] = fa] + 1, siz[u] = 1;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa ) {
            Init( v, u ); 
            RMQ[++ ID][0] = u, siz[u] += siz[v];
        }
}
    
inline int Jump( int x, int stp ) {
    for( ; stp ; stp &= stp - 1 )
        x = fath[x][__builtin_ctz( stp )];
    return x;
}
    
inline int LCA( const int u, const int v ) {
    int l = fir[u], r = fir[v];
    if( l > r ) std :: swap( l, r );
    int k = lg2[r - l + 1], a = RMQ[l][k],
        b = RMQ[r - ( 1 << k ) + 1][k];
    return dep[a] < dep[b] ? a : b;
}
    
inline void Upt( const int x ) {
    su[x] = su[x << 1] + su[x << 1 | 1];
}
    
void Build( const int x, const int l, const int r ) {
    if( l > r ) return ;
    if( l == r ) { su[x] = A[seq[l]]; return ; }
    int mid = ( l + r ) >> 1;
    Build( x << 1, l, mid );
    Build( x << 1 | 1, mid + 1, r );
    Upt( x );
}
    
inline void Add( const int x, const int l, const int r, const LL delt ) {
    tag[x] += delt, su[x] += 1ll * ( r - l + 1 ) * delt;
}
    
inline void Normalize( const int x, const int l, const int r ) {
    if( ! tag[x] ) return ;
    int mid = ( l + r ) >> 1;
    Add( x << 1, l, mid, tag[x] );
    Add( x << 1 | 1, mid + 1, r, tag[x] );
    tag[x] = 0;
}
    
void Update( const int x, const int l, const int r, const int segL, const int segR, const int delt ) {
    if( segL <= l && r <= segR ) { Add( x, l, r, delt ); return ; }
    int mid = ( l + r ) >> 1; Normalize( x, l, r );
    if( segL <= mid ) Update( x << 1, l, mid, segL, segR, delt );
    if( mid  < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR, delt );
    Upt( x );
}
    
LL Query( const int x, const int l, const int r, const int segL, const int segR ) {
    if( segL <= l && r <= segR ) return su[x];
    int mid = ( l + r ) >> 1; LL ret = 0; Normalize( x, l, r );
    if( segL <= mid ) ret += Query( x << 1, l, mid, segL, segR );
    if( mid  < segR ) ret += Query( x << 1 | 1, mid + 1, r, segL, segR );
    return ret;
}
    
void Init() {
    Init( 1, 0 ), lg2[0] = -1;
    rep( i, 1, ID ) lg2[i] = lg2[i >> 1] + 1;
    rep( j, 1, lg2[N] ) rep( i, 1, N )
        fath[i][j] = fath[fath[i][j - 1]][j - 1];
    for( int j = 1, a, b ; j <= lg2[ID] ; j ++ )
        for( int i = 1 ; i + ( 1 << ( j - 1 ) ) <= ID ; i ++ ) {
            a = RMQ[i][j - 1], b = RMQ[i + ( 1 << ( j - 1 ) )][j - 1];
            RMQ[i][j] = dep[a] < dep[b] ? a : b;
        }
    Build( 1, 1, N );
}
    
inline std :: pair<int, int> GetNear( int u, int v ) {
    if( dep[u] > dep[v] ) std :: swap( u, v );
    int lcaU = LCA( u, rt ), lcaV = LCA( v, rt );
    if( lcaV == v ) return std :: make_pair( dep[rt] - dep[v], v );
    if( lcaU == u ) return std :: make_pair( dep[rt] - dep[lcaV], lcaV );
    return std :: make_pair( dep[u] - dep[rt], u );
}
    
inline int GetLCA( const int u, const int v ) {
    int lca = LCA( u, v );
    return Min( GetNear( lca, u ), GetNear( lca, v ) ).second;
}
    
inline void Update( const int x, const int delt ) {
    if( x == rt ) Add( 1, 1, N, delt );
    else if( LCA( x, rt ) == x ) {
        int y = Jump( rt, dep[rt] - dep[x] - 1 );
        Add( 1, 1, N, delt );
        Update( 1, 1, N, DFN[y], DFN[y] + siz[y] - 1, - delt );
    } else Update( 1, 1, N, DFN[x], DFN[x] + siz[x] - 1, delt );
}

inline LL Query( const int x ) {
    if( x == rt ) return su[1];
    if( LCA( x, rt ) == x ) {
        int y = Jump( rt, dep[rt] - dep[x] - 1 );
        return su[1] - Query( 1, 1, N, DFN[y], DFN[y] + siz[y] - 1 );
    }
    return Query( 1, 1, N, DFN[x], DFN[x] + siz[x] - 1 );
}
    
int main() {
    read( N ), read( Q );
    rep( i, 1, N ) read( A[i] );
    rep( i, 1, N - 1 ) {
        int u, v; read( u ), read( v );
        AddEdge( u, v ), AddEdge( v, u );
    }
    Init();
    int opt, a, b, c;
    while( Q -- ) {
        read( opt ), read( a );
        if( opt == 1 ) rt = a;
        if( opt == 2 ) {
            read( b ), read( c );
            Update( GetLCA( a, b ), c );
        }
        if( opt == 3 ) write( Query( a ) ), putchar( '\n' );
    }
    return 0;
}