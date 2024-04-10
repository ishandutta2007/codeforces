#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5;

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

std :: vector<int> each[2];

int len = 1e9, ed = -1;
int dep[MAXN], fath[MAXN];

int head[MAXN], cnt = 1;

int N, M, K;

inline void AddEdge( const int &from, const int &to ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    head[from] = cnt;
}

void DFS( const int &u, const int &fa ) {
    dep[u] = dep[fa] + 1, fath[u] = fa;
    for( int i = head[u], v ; i ; i = Graph[i].nxt ) {
        if( ( v = Graph[i].to ) == fa ) continue;
        if( ! dep[v] ) DFS( v, u );
        else if( dep[v] < dep[u] ) {
            int d = dep[u] - dep[v] + 1;
            if( len > d ) len = d, ed = u;
        }
    }
}

int main() {
    // freopen( ".in", "r", stdin );
    // freopen( ".out", "w", stdout );
    Read( N ), Read( M ), Read( K );
    rep( i, 1, M ) {
        int u, v; Read( u ), Read( v );
        AddEdge( u, v ), AddEdge( v, u );
    }
    DFS( 1, 0 );
    if( len == 1e9 ) {
        puts( "1" ), K = ( K + 1 ) / 2;
        rep( i, 1, N )
            each[dep[i] % 2].push_back( i );
        int r = ( int ) each[1].size() >= K;
        rep( i, 0, K - 1 )
            Write( each[r][i] ), putchar( " \n"[i == K - 1] );
    } else if( len <= K ) {
        puts( "2" );
        Write( len ), putchar( '\n' );
        for( int i = 1, x = ed ; i <= len ; i ++, x = fath[x] )
            Write( x ), putchar( " \n"[i == len] );
    } else {
        puts( "1" ), K = ( K + 1 ) / 2;
        for( int i = 1, x = ed ; i <= K ; i ++, x = fath[fath[x]] )
            Write( x ), putchar( " \n"[i == K] );
    }
    return 0;
}