#include <cmath>
#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 4e18;
const int MAXN = 3e5 + 5, MAXLOG = 20;

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

struct Edge {
    int to, nxt;
    LL w1, w2;
} Graph[MAXN << 1];

LL chg[MAXN];

struct Element {
    int u, v;
    LL wei[2][2];

    Element(): u( 0 ), v( 0 ), wei{ { INF, INF }, { INF, INF } } {}
    Element( int U ): u( U ), v( U ), wei{ { 0, chg[U] }, { chg[U], 0 } } {}
    Element( int U, int V ): u( U ), v( V ), wei{ { INF, INF }, { INF, INF } } {}

    Element( int U, int V, LL W1, LL W2 ) {
        u = U, v = V;
        wei[0][0] = MIN( W1, chg[u] + W2 + chg[v] );
        wei[0][1] = MIN( W1 + chg[v], chg[u] + W2 );
        wei[1][0] = MIN( W2 + chg[v], chg[u] + W1 );
        wei[1][1] = MIN( chg[u] + W1 + chg[v], W2 );
    }

    friend Element operator + ( const Element &p, const Element &q );

    void Reverse() {
        std :: swap( u, v );
        std :: swap( wei[0][1], wei[1][0] );
    }
};

struct MinValue {
    LL mn, sm;

    MinValue(): mn( INF ), sm( INF ) {}
    MinValue( LL v ): mn( v ), sm( INF ) {}

    inline void Upt( const LL &s ) {
        if( s <= mn ) sm = mn, mn = s;
        else if( s < sm ) sm = s;
    }
};

Element pat[MAXN][MAXLOG];
int dep[MAXN], lg2;

MinValue dp[MAXN];

LL swt[MAXN];
int head[MAXN], cnt = 1;

int N, Q;

Element operator + ( const Element &p, const Element &q ) {
    Element ret( p.u, q.v );
    rep( i, 0, 1 ) rep( j, 0, 1 ) rep( k, 0, 1 )
        ret.wei[i][j] = MIN( ret.wei[i][j], p.wei[i][k] + q.wei[k][j] );
    return ret;
}

void AddEdge( const int from, const int to, const LL W1, const LL W2 ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    Graph[cnt].w1 = W1, Graph[cnt].w2 = W2, head[from] = cnt;
}

void DFS1( const int u, const int fa ) {
    dp[u] = MinValue( swt[u] );
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa ) {
            DFS1( v, u );
            dp[u].Upt( dp[v].mn + Graph[i].w1 + Graph[i].w2 );
        }
}

void DFS2( const int u, const int fa ) {
    chg[u] = dp[u].mn;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa ) {
            LL w = Graph[i].w1 + Graph[i].w2;
            LL tmp = dp[u].mn == dp[v].mn + w ? dp[u].sm : dp[u].mn;
            dp[v].Upt( tmp + w );
            DFS2( v, u );
        }
}

void Init( const int u, const int fa ) {
    dep[u] = dep[fa] + 1;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa ) {
            pat[v][0] = Element( v, u, Graph[i].w1, Graph[i].w2 );
            Init( v, u );
        }
}

void Init() {
    DFS1( 1, 0 );
    DFS2( 1, 0 );
    Init( 1, 0 ), lg2 = log2( N );
    rep( j, 1, lg2 ) rep( i, 1, N )
        pat[i][j] = pat[i][j - 1] + pat[pat[i][j - 1].v][j - 1];
}

inline void Balance( int &u, const int stp ) {
    for( int i = 0 ; ( 1 << i ) <= stp ; i ++ )
        if( stp >> i & 1 ) u = pat[u][i].v;
}

int LCA( int u, int v ) {
    if( dep[u] > dep[v] ) Balance( u, dep[u] - dep[v] );
    if( dep[v] > dep[u] ) Balance( v, dep[v] - dep[u] );
    if( u == v ) return u;
    per( i, lg2, 0 ) if( pat[u][i].v != pat[v][i].v ) 
        u = pat[u][i].v, v = pat[v][i].v;
    return pat[u][0].v;
}

Element Obtain( const int u, const int stp ) {
    Element ret( u );
    for( int i = 0 ; ( 1 << i ) <= stp ; i ++ )
        if( stp >> i & 1 )
            ret = ret + pat[ret.v][i];
    return ret;
}

int main() {
    read( N );
    rep( i, 1, N ) read( swt[i] );
    rep( i, 1, N - 1 ) {
        int u, v; LL w1, w2;
        read( u ), read( v ), read( w1 ), read( w2 );
        AddEdge( u, v, w1, w2 ), AddEdge( v, u, w1, w2 );
    }
    Init();
    read( Q );
    while( Q -- ) {
        int x, y;
        read( x ), read( y );
        int s1 = ! ( x & 1 ), s2 = ! ( y & 1 );
        x = ( x + 1 ) >> 1, y = ( y + 1 ) >> 1;
        int lca = LCA( x, y );
        Element patX = Obtain( x, dep[x] - dep[lca] ),
                patY = Obtain( y, dep[y] - dep[lca] );
        patY.Reverse();
        write( ( patX + patY ).wei[s1][s2] ), putchar( '\n' );
    }
    return 0;
}