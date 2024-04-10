#include <cstdio>
#include <vector>

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

struct Edge {
    int to, nxt;
} Graph[MAXN << 1];

std :: vector<int> qry[MAXN];

int qLim[MAXN], ans[MAXN];

int buc[MAXN], BIT[MAXN];
int app[MAXN], ntot = 0;

int siz[MAXN], heavy[MAXN];
int head[MAXN], cnt = 1;
int col[MAXN];

int N, M;

inline void Down( int &x ) { x &= x - 1; }
inline void Up( int &x ) { x += x & ( - x ); }
inline void Update( int x, int v ) { for( ; x <= 1e5 ; Up( x ) ) BIT[x] += v; }
inline  int Query( int x ) { int ret = 0; for( ; x ; Down( x ) ) ret += BIT[x]; return ret; }

inline void AddEdge( const int &from, const int &to ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    head[from] = cnt;
}

void DFS( const int u, const int fa ) {
    siz[u] = 1, heavy[u] = 0;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa ) {
            DFS( v, u ), siz[u] += siz[v];
            if( siz[heavy[u]] < siz[v] ) heavy[u] = v;
        }
}

inline void Add( const int &x ) {
    if( ! buc[x] ) app[++ ntot] = x;
    else Update( buc[x], -1 );
    Update( ++ buc[x], +1 );
}

void Obtain( const int u, const int fa ) {
    Add( col[u] );
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa )
            Obtain( v, u );
}

void DSU( const int u, const int fa, const bool flg ) {
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa && v ^ heavy[u] )
            DSU( v, u, false );
    if( heavy[u] ) DSU( heavy[u], u, true );
    Add( col[u] );
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa && v ^ heavy[u] )
            Obtain( v, u );
    for( const int &q : qry[u] )
        ans[q] = Query( N ) - Query( qLim[q] - 1 );
    if( ! flg ) {
        rep( i, 1, ntot )
            Update( buc[app[i]], -1 ), buc[app[i]] = 0;
        ntot = 0;
    }
} 

int main() {
    read( N ), read( M );
    rep( i, 1, N ) read( col[i] );
    rep( i, 1, N - 1 ) {
        int u, v; read( u ), read( v );
        AddEdge( u, v ), AddEdge( v, u );
    }
    rep( i, 1, M ) {
        int u;
        read( u ), read( qLim[i] );
        qry[u].push_back( i );
    }
    DFS( 1, 0 );
    DSU( 1, 0, true );
    rep( i, 1, M ) write( ans[i] ), putchar( '\n' );
    return 0;
}