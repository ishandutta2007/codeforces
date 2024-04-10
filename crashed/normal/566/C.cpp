#include <cmath>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5;

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

struct Edge {
    int to, nxt, w;
} Graph[MAXN << 1];

int dist[MAXN];
double deri[MAXN];

int siz[MAXN];
bool vis[MAXN];

int wei[MAXN], head[MAXN], cnt = 1;

int N;

void AddEdge( const int from, const int to, const int W ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    Graph[cnt].w = W, head[from] = cnt;
}

int GetCen( const int u, const int fa, const int all ) {
    siz[u] = 1; int mx = 0, ret = 0;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa && ! vis[v] ) {
            ret |= GetCen( v, u, all );
            siz[u] += siz[v], mx = MAX( mx, siz[v] );
        }
    if( MAX( mx, all - siz[u] ) * 2 <= all ) ret = u;
    return ret;
}

double GetDist( const int u, const int fa, const int d ) {
    dist[u] = d;
    double de = 1.5 * sqrt( d ) * wei[u];
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa )
            de += GetDist( v, u, d + Graph[i].w );
    return de;
}

int main() {
    read( N );
    rep( i, 1, N ) read( wei[i] );
    rep( i, 1, N - 1 ) {
        int u, v, w;
        read( u ), read( v ), read( w );
        AddEdge( u, v, w ), AddEdge( v, u, w );
    }
    int ansF; double ansC = 1e30;
    int u = GetCen( 1, 0, N ), all = N;
    while( true ) {
        double res = 0, deSu = 0;
        vis[u] = true, dist[u] = 0;
        for( int i = head[u], v ; i ; i = Graph[i].nxt )
            v = Graph[i].to, deSu += ( deri[v] = GetDist( v, u, Graph[i].w ) );
        rep( i, 1, N ) res += pow( dist[i], 1.5 ) * wei[i];
        if( res < ansC ) ansF = u, ansC = res;

        bool flg = false;
        for( int i = head[u], v ; i ; i = Graph[i].nxt )
            if( ! vis[v = Graph[i].to] ) {
                if( deSu - 2 * deri[v] < 0 ) {
                    all = siz[u] > siz[v] ? siz[v] : all - siz[u];
                    u = GetCen( v, u, all ), flg = true;
                    break;
                }
            }
        if( ! flg ) break;
    }
    printf( "%d %.12f\n", ansF, ansC );
    return 0;
}