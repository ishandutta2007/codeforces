#include <cstdio>
#include <vector>
#include <utility>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXN = 6005;

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
_T MAX( const _T a, const _T b ) {
    return a > b ? a : b;
}

template<typename _T>
_T MIN( const _T a, const _T b ) {
    return a < b ? a : b;
}

struct Edge {
    int to, nxt;
}Graph[MAXN << 1];

typedef std :: pair<int, int> Change;

int f[MAXN];
int head[MAXN], cnt = 1;

int val[MAXN];
int N, ans = 0;

inline void AddEdge( const int from, const int to ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    head[from] = cnt;
}

void DFS( const int u, const int fa ) {
    int p; Change tmp;
    p = std :: lower_bound( f + 1, f + 1 + N, val[u] ) - f - 1;
    ans = MAX( ans, p + 1 ), tmp = Change( p + 1, f[p + 1] );
    f[p + 1] = MIN( f[p + 1], val[u] );
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa ) DFS( v, u );
    f[tmp.first] = tmp.second;
}

int main() {
    read( N );
    rep( i, 1, N ) read( val[i] );
    rep( i, 1, N - 1 ) {
        int u, v;
        read( u ), read( v );
        AddEdge( u, v ), AddEdge( v, u );
    }
    rep( i, 1, N ) {
        rep( j, 0, N ) f[j] = INF;
        f[0] = - INF;
        DFS( i, 0 );
    }
    write( ans ), putchar( '\n' );
    return 0;
}