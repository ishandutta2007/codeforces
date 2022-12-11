#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
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

std :: vector<int> son[MAXN];

int f[MAXN], g[MAXN];
// f 
// g  lca 

int N;

inline int Mul( int x, const int v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int v ) { return ( x += v ) >= mod ? x - mod : x; }

void DFS( const int u ) {
    if( son[u].size() == 0u )
        f[u] = g[u] = 1;
    else {
        int n = son[u].size();
        int tmp[3] = { 1, 0, 0 };
        for( int i = 0, v ; i < n ; i ++ ) {
            DFS( v = son[u][i] );
            tmp[2] = Add( Mul( tmp[2], Add( f[v], g[v] ) ), Mul( tmp[1], g[v] ) );
            tmp[1] = Add( Mul( tmp[1], f[v] ), Mul( tmp[0], g[v] ) );
            tmp[0] = Mul( tmp[0], f[v] );
        }
        f[u] = Add( tmp[0], tmp[2] );
        g[u] = Add( tmp[1], tmp[2] );
    }
}

int main() {
    read( N );
    rep( i, 2, N ) {
        int fa; read( fa );
        son[fa].push_back( i );
    }
    DFS( 1 );
    write( f[1] ), putchar( '\n' );
    return 0;
}