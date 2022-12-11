#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 3e5 + 5;

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

bool lgt[MAXN];
int dep[MAXN], seq[MAXN];

int fa[MAXN];
int head[MAXN], cnt = 1;

int N, M;

inline void Clear() {
    cnt = 1;
    rep( i, 1, N ) dep[i] = head[i] = 0;
}

inline void AddEdge( const int &from, const int &to ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    head[from] = cnt;
}

inline void MakeSet( const int &n ) {
    rep( i, 1, n ) fa[i] = i;
}

int FindSet( const int &u ) {
    return fa[u] == u ? u : ( fa[u] = FindSet( fa[u] ) );
}

void UnionSet( int u, int v ) {
    fa[FindSet( u )] = FindSet( v );
}

void DFS1( const int &u, const int &fa ) {
    dep[u] = dep[fa] + 1;
    for( int i = head[u], v ; i ; i = Graph[i].nxt ) 
        if( ! dep[v = Graph[i].to] )
            DFS1( v, u );
}

void DFS2( const int &u, const int &fa ) {
    bool any = false;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( dep[v = Graph[i].to] < dep[u] )
            any |= lgt[v];
    lgt[u] = ! any;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( dep[v = Graph[i].to] == dep[u] + 1 )
            DFS2( v, u );
}

int main() {
    int T; Read( T );
    while( T -- ) {
        Read( N ), Read( M );
        Clear(), MakeSet( N );
        rep( i, 1, M ) {
            int u, v; Read( u ), Read( v );
            AddEdge( u, v ), AddEdge( v, u );
            UnionSet( u, v );
        }
        int comp = 0;
        rep( i, 1, N ) comp += fa[i] == i;
        if( comp > 1 ) {
            puts( "NO" );
            continue;
        }
        rep( i, 1, N ) lgt[i] = false;
        DFS1( 1, 0 );
        DFS2( 1, 0 );
        puts( "YES" ); int tot = 0;
        rep( i, 1, N )
            if( lgt[i] )
                seq[++ tot] = i;
        Write( tot ), putchar( '\n' );
        rep( i, 1, tot )
            Write( seq[i] ), putchar( " \n"[i == tot] );
    }
    return 0;
}