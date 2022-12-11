#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int INF = 0x3f3f3f3f;
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

template<typename _T>
_T MIN( const _T a, const _T b ) {
    return a < b ? a : b;
}

template<typename _T>
_T MAX( const _T a, const _T b ) {
    return a > b ? a : b;
}

struct Edge {
    int to, nxt;
} Graph[MAXN << 1];

int stk[MAXN], top;

LL pref[MAXN];
int dep[MAXN], head[MAXN];
int cnt = 0;

int N, L, ans = 0; LL S;

inline void AddEdge( const int from, const int to ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    head[from] = cnt;
}

int DFS( const int u, const int fa ) {
    int mn = INF;
    pref[u] += pref[fa];
    stk[dep[u] = ++ top] = u;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa ) 
            mn = MIN( mn, DFS( v, u ) );
    if( mn > dep[u] ) {
        int l = MAX( 1, dep[u] - L + 1 ), r = dep[u], mid;
        while( l < r ) {
            mid = ( l + r ) >> 1;
            if( pref[u] - pref[stk[mid - 1]] <= S ) r = mid;
            else l = mid + 1;
        }
        mn = l, ans ++;
    }
    return top --, mn;
}

int main() {
    read( N ), read( L ), read( S );
    rep( i, 1, N ) {
        read( pref[i] );
        if( pref[i] > S )
            return puts( "-1" );
    }
    rep( i, 2, N ) {
        int p; read( p );
        AddEdge( i, p ), AddEdge( p, i );
    }
    DFS( 1, 0 );
    write( ans ), putchar( '\n' );
    return 0;
}