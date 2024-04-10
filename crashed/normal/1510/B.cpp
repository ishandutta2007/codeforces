#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXV = 1e4 + 5, MAXE = 5e6 + 5;

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

typedef std :: pair<int, int> Node;

struct Edge { 
    int to, nxt, c, w;
} Graph[MAXE << 1];

bool vis[MAXV];
int dist[MAXV], pot[MAXV], cur[MAXV];
int head[MAXV], cnt = 1, ntot = 0;

int nxt[MAXV];
int seq[MAXV], tot = 0;

char buf[20];
bool app[MAXV];

int D, N;

inline void AddEdge( const int &from, const int &to, const int &C, const int &W ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    Graph[cnt].c = C, Graph[cnt].w = W, head[from] = cnt;
}

inline void AddE( const int &from, const int &to, const int &C, const int &W ) {
    AddEdge( from, to, C, W ), AddEdge( to, from, 0, -W );
}

inline void Init( const int &S ) {
    static std :: queue<int> q;

    while( ! q.empty() ) q.pop();
    rep( i, 1, ntot ) pot[i] = INF, vis[i] = false;
    q.push( S ), pot[S] = 0, vis[S] = true;
    while( ! q.empty() ) {
        int u = q.front();
        q.pop(), vis[u] = false;
        for( int i = head[u], v ; i ; i = Graph[i].nxt )
            if( Graph[i].c && pot[v = Graph[i].to] > pot[u] + Graph[i].w ) {
                pot[v] = pot[u] + Graph[i].w;
                if( ! vis[v] ) q.push( v ), vis[v] = true;
            }
    }
}

inline bool Dijkstra( const int &S, const int &T ) {
    static std :: priority_queue<Node, std :: vector<Node>, std :: greater<Node> > q;
    
    while( ! q.empty() ) q.pop();
    rep( i, 1, ntot ) dist[i] = INF, vis[i] = false;
    q.push( Node( dist[S] = 0, S ) );
    while( ! q.empty() ) {
        int u = q.top().second; q.pop();
        if( vis[u] ) { continue; } vis[u] = true;
        for( int i = head[u], v ; i ; i = Graph[i].nxt ) {
            int w = Graph[i].w + pot[u] - pot[v = Graph[i].to];
            if( Graph[i].c && dist[v] > dist[u] + w )
                q.push( Node( dist[v] = dist[u] + w, v ) );
        }
    }
    rep( i, 1, ntot ) {
        dist[i] = Min( ( long long ) INF, ( long long ) dist[i] + pot[i] );
        pot[i] = dist[i];
    }
    return dist[T] < INF;
}

int DFS( const int &u, const int &lin, const int &T ) {
    if( u == T ) return lin;
    int used = 0, ret, v, c, w; vis[u] = true;
    for( int &i = cur[u] ; i ; i = Graph[i].nxt ) {
        c = Graph[i].c, v = Graph[i].to, w = Graph[i].w;
        if( c && ! vis[v] && dist[v] == dist[u] + w && 
            ( ret = DFS( v, Min( lin - used, c ), T ) ) ) {
            used += ret, Graph[i].c -= ret, Graph[i ^ 1].c += ret;
            if( used == lin ) break;
        }
    }
    if( used < lin ) dist[u] = INF;
    return vis[u] = false, used;
}

std :: pair<int, int> Dinic( const int &S, const int &T ) {
    Init( S );
    int flow = 0, cost = 0;
    while( Dijkstra( S, T ) ) {
        rep( i, 1, ntot ) cur[i] = head[i], vis[i] = false;
        int t = DFS( S, INF, T ); flow += t, cost += t * dist[T];
    }
    return std :: make_pair( flow, cost );
}

int main() {
    Read( D ), Read( N );
    rep( i, 1, N ) {
        int x = 0;
        scanf( "%s", buf );
        rep( j, 0, D - 1 )
            x |= ( buf[j] == '1' ) << j;
        if( ! app[x] ) seq[++ tot] = x;
        app[x] = true;
    }
    ntot = 2 * tot; int ans = 0;
    const int s = ++ ntot, t = ++ ntot;
    std :: sort( seq + 1, seq + 1 + tot );
    rep( i, 1, tot ) {
        int bitCnt = 0;
        rep( j, 0, D - 1 )
            bitCnt += seq[i] >> j & 1;
        ans += bitCnt + 1;
        AddE( s, i, 1, - bitCnt - 1 );
        AddE( i + tot, t, 1, 0 );
        rep( j, 1, tot ) 
            if( seq[i] != seq[j] && ( seq[j] & seq[i] ) == seq[i] )
                AddE( i, j + tot, 1, 0 );
    }
    ans += Dinic( s, t ).second;
    Write( ans - 1 ), putchar( '\n' );
    rep( u, 1, tot )
        for( int i = head[u] ; i ; i = Graph[i].nxt )
            if( tot < Graph[i].to && Graph[i].to <= 2 * tot && Graph[i].c == 0 ) {
                nxt[u] = Graph[i].to - tot;
                break;
            }
    bool flg = false;
    rep( i, 1, tot ) vis[i] = false;
    rep( i, 1, tot ) if( ! vis[i] ) {
        if( flg )
            putchar( 'R' ), putchar( ' ' );
        for( int x = 0, y = i ; y ; y = nxt[x = y] ) {
            int delt = seq[y] ^ seq[x];
            rep( j, 0, D - 1 )
                if( delt >> j & 1 )
                    Write( j ), putchar( ' ' );
            vis[y] = true;
        }
        flg = true;
    }
    puts( "" );
    return 0;
}