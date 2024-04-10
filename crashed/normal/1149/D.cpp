// LUOGU_RID: 95143283
#include <queue>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXN = 75, MAXM = 205, MAXS = ( 1 << 17 ) + 5;

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

template<typename _T>
inline _T Max( const _T &a, const _T &b ) {
    return a > b ? a : b;
}

typedef std :: pair<int, int> State;
typedef std :: pair<int, State> Node;

std :: priority_queue<Node, std :: vector<Node>, std :: greater<Node> > q;

int dp[MAXS][MAXN];
bool vis[MAXS][MAXN];

int grph[MAXN][MAXN];

int nwId[MAXN], ID = 0;
int bel[MAXN], siz[MAXN], tot = 0;
int fa[MAXN];

int N, M, A, B;

inline void MakeSet( const int &n ) {
    rep( i, 1, n ) fa[i] = i;
}

int FindSet( const int &u ) {
    return fa[u] == u ? u : ( fa[u] = FindSet( fa[u] ) );
}

inline void UnionSet( const int &u, const int &v ) {
    fa[FindSet( u )] = FindSet( v );
}

int main() {
    Read( N ), Read( M ), Read( A ), Read( B );
    rep( i, 1, N ) rep( j, 1, N )
        grph[i][j] = i == j ? 0 : INF;
    MakeSet( N );
    rep( i, 1, M ) {
        int u, v, w;
        Read( u ), Read( v ), Read( w );
        if( w == A ) UnionSet( u, v );
        grph[u][v] = Min( grph[u][v], w );
        grph[v][u] = Min( grph[v][u], w );
    }
    rep( i, 1, N ) if( fa[i] == i ) bel[i] = ++ tot;
    rep( i, 1, N ) siz[bel[i] = bel[FindSet( i )]] ++;
    rep( i, 1, tot ) if( siz[i] >= 4 ) nwId[i] = ID ++;

    int U = 1 << ID;
    rep( S, 0, U - 1 ) rep( j, 1, N ) 
        dp[S][j] = INF, vis[S][j] = false;
    if( siz[bel[1]] >= 4 ) {
        int S = 1 << nwId[bel[1]];
        q.push( { dp[S][1] = 0, { S, 1 } } );
    } else 
        q.push( { dp[0][1] = 0, { 0, 1 } } );
    while( ! q.empty() ) {
        int S = q.top().second.first,
            u = q.top().second.second; q.pop();
        if( vis[S][u] ) { continue; } vis[S][u] = true;
        rep( v, 1, N ) 
            if( u ^ v && grph[u][v] < INF ) {
                int T = S;
                if( grph[u][v] == B ) {
                    if( bel[u] == bel[v] ) continue;
                    if( siz[bel[v]] >= 4 ) {
                        if( T >> nwId[bel[v]] & 1 ) continue;
                        T |= 1 << nwId[bel[v]];
                    }
                }
                if( ! vis[T][v] && dp[T][v] > dp[S][u] + grph[u][v] )
                    q.push( { dp[T][v] = dp[S][u] + grph[u][v], { T, v } } );
            }
    }
    rep( i, 1, N ) {
        int ans = INF;
        rep( S, 0, U - 1 )
            ans = Min( ans, dp[S][i] );
        Write( ans ), putchar( " \n"[i == N] );
    }
    return 0;
}