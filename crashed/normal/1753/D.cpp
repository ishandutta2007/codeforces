#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 4e18;
const int MAXN = 3e5 + 5, MAXE = 5e6 + 5;

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

typedef std :: pair<LL, int> Node;

struct Edge {
    int to, nxt, w;
} Graph[MAXE << 1];

int dir[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

std :: priority_queue<Node, std :: vector<Node>, std :: greater<Node> > q;

LL dist[MAXN];
bool vis[MAXN];
int head[MAXN], cnt = 1;

char buf[MAXN];
int grid[MAXN]; char mp[300];

int N, M, P, Q;

#define GetId( x, y ) ( ( (x) - 1 ) * M + (y) )

inline bool Inside( const int &x, const int &y ) {
    return 1 <= x && x <= N && 1 <= y && y <= M;
}

inline void AddEdge( const int &from, const int &to, const int &W ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    Graph[cnt].w = W, head[from] = cnt;
}

void Dijkstra() {
    while( ! q.empty() ) q.pop();
    rep( i, 1, N * M ) vis[i] = false, dist[i] = INF;
    rep( i, 1, N * M ) if( grid[i] == -1 ) q.push( { dist[i] = 0, i } );
    while( ! q.empty() ) {
        int u = q.top().second; q.pop();
        if( vis[u] ) { continue; } vis[u] = true;
        for( int i = head[u], v ; i ; i = Graph[i].nxt )
            if( ! vis[v = Graph[i].to] && dist[v] > dist[u] + Graph[i].w )
                q.push( { dist[v] = dist[u] + Graph[i].w, v } );
    }
}

int main() {
    mp[( int ) '.'] = -1, mp[( int ) '#'] = -2;
    mp[( int ) 'U'] = 0, mp[( int ) 'R'] = 1, mp[( int ) 'D'] = 2, mp[( int ) 'L'] = 3;

    Read( N ), Read( M );
    Read( P ), Read( Q );
    rep( i, 1, N ) {
        scanf( "%s", buf + 1 );
        rep( j, 1, M )
            grid[GetId( i, j )] = mp[( int ) buf[j]];
    }
    rep( i, 1, N ) rep( j, 1, M ) {
        int dx, dy, tx, ty, d;
        if( ( d = grid[GetId( i, j )] ) < 0 ) continue;  
        dx = i + dir[( d + 2 ) % 4][0];
        dy = j + dir[( d + 2 ) % 4][1];
        if( ! Inside( dx, dy ) ) continue;
        tx = i + dir[d][0], ty = j + dir[d][1];
        if( Inside( tx, ty ) && grid[GetId( tx, ty )] > -2 )
            AddEdge( GetId( tx, ty ), GetId( dx, dy ), Q );
        tx = i + dir[( d + 1 ) % 4][0], ty = j + dir[( d + 1 ) % 4][1];
        if( Inside( tx, ty ) && grid[GetId( tx, ty )] > -2 )
            AddEdge( GetId( tx, ty ), GetId( dx, dy ), P );
        tx = i + dir[( d + 3 ) % 4][0], ty = j + dir[( d + 3 ) % 4][1];
        if( Inside( tx, ty ) && grid[GetId( tx, ty )] > -2 )
            AddEdge( GetId( tx, ty ), GetId( dx, dy ), P );
    }
    Dijkstra(); LL ans = INF;
    rep( i, 1, N - 1 ) rep( j, 1, M ) {
        int u = GetId( i, j ), v = GetId( i + 1, j );
        if( grid[u] == -2 || grid[v] == -2 ) continue;
        if( dist[u] == INF || dist[v] == INF ) continue;
        ans = std :: min( ans, dist[u] + dist[v] );
    }
    rep( i, 1, N ) rep( j, 1, M - 1 ) {
        int u = GetId( i, j ), v = GetId( i, j + 1 );
        if( grid[u] == -2 || grid[v] == -2 ) continue;
        if( dist[u] == INF || dist[v] == INF ) continue;
        ans = std :: min( ans, dist[u] + dist[v] );
    }
    Write( ans == INF ? -1 : ans ), putchar( '\n' );
    return 0;
}