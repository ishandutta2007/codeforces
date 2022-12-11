#include <cstdio>
#include <vector>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 1e9 + 7;
const int MAXN = 8005;

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

int f[MAXN], g[MAXN], C[MAXN];

std :: vector<int> dp[MAXN][2];
int tmp[2][MAXN];

int siz[MAXN], heavy[MAXN];
int head[MAXN], cnt = 1;

int N;

inline int Mul( int x, const int &v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int& MulEq( int &x, const int &v ) { return x = 1ll * x * v % mod; }
inline int& SubEq( int &x, const int &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline int& AddEq( int &x, const int &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

inline int Qkpow( int base, int indx ) {
    int ret = 1;
    while( indx ) {
        if( indx & 1 ) MulEq( ret, base );
        MulEq( base, base ), indx >>= 1;
    }
    return ret;
}

inline void AddEdge( const int &from, const int &to ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    head[from] = cnt;
}

void Init( const int &u, const int &fa ) {
    siz[u] = 1, heavy[u] = 0;
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa ) {
            Init( v, u ), siz[u] += siz[v];
            if( siz[heavy[u]] < siz[v] ) heavy[u] = v;
        }
}

void DFS( const int &u, const int &fa ) {
    siz[u] = 0;
    if( ! heavy[u] ) {
        dp[u][0].push_back( 1 );
        dp[u][1].push_back( 1 );
        return ;
    }
    DFS( heavy[u], u ); 
    siz[u] = siz[heavy[u]] + 1;
    dp[u][0].swap( dp[heavy[u]][0] );
    dp[u][1].swap( dp[heavy[u]][1] );
    // 
    rep( i, 0, siz[u] - 1 )
        tmp[0][i] = dp[u][0][i],
        tmp[1][i] = Add( dp[u][0][i], dp[u][1][i] );
    // 
    tmp[0][siz[u]] = tmp[1][siz[u]] = 0;
    rep( i, 0, siz[u] - 1 )
        AddEq( tmp[0][i + 1], dp[u][1][i] ),
        AddEq( tmp[1][i + 1], dp[u][1][i] );
    dp[u][0].push_back( 0 );
    dp[u][1].push_back( 0 );
    rep( i, 0, siz[u] ) 
        dp[u][0][i] = tmp[0][i],
        dp[u][1][i] = tmp[1][i];
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa && v ^ heavy[u] ) {
            DFS( v, u );
            rep( j, 0, siz[u] + siz[v] + 1 )
                tmp[0][j] = tmp[1][j] = 0;
            rep( j, 0, siz[u] ) rep( k, 0, siz[v] ) {
                // 
                AddEq( tmp[0][j + k], Mul( dp[u][0][j], dp[v][0][k] ) );
                AddEq( tmp[1][j + k], Add( Mul( dp[u][1][j], dp[v][0][k] ), Mul( dp[u][0][j], dp[v][1][k] ) ) );
                // 
                AddEq( tmp[0][j + k + 1], Mul( dp[u][0][j], dp[v][1][k] ) );
                AddEq( tmp[1][j + k + 1], Mul( dp[u][1][j], dp[v][1][k] ) );
            }
            // dp[v][0].clear(), dp[v][0].shrink_to_fit();
            // dp[v][1].clear(), dp[v][1].shrink_to_fit();
            dp[v][0].clear(), dp[v][1].clear();
            dp[u][0].resize( siz[u] + siz[v] + 2, 0 );
            dp[u][1].resize( siz[u] + siz[v] + 2, 0 );
            rep( j, 0, siz[u] + siz[v] + 1 ) 
                dp[u][0][j] = tmp[0][j], dp[u][1][j] = tmp[1][j];
            siz[u] += siz[v] + 1;
        }
}

int main() {
    Read( N );
    rep( i, 1, N - 1 ) {
        int u, v; Read( u ), Read( v );
        AddEdge( u, v ), AddEdge( v, u );
    }
    Init( 1, 0 );
    DFS( 1, 0 );
    rep( i, 1, N - 1 )
        f[N - 1 - i] = Mul( Qkpow( N, i - 1 ), dp[1][1][i] );
    f[N - 1] = 1, C[0] = 1;
    rep( i, 0, N - 1 ) {
        rep( j, 0, i ) {
            if( ( i & 1 ) ^ ( j & 1 ) )
                SubEq( g[j], Mul( C[j], f[i] ) );
            else
                AddEq( g[j], Mul( C[j], f[i] ) );
        }
        per( j, i + 1, 1 ) AddEq( C[j], C[j - 1] );
    }
    rep( i, 0, N - 1 ) Write( g[i] ), putchar( " \n"[i == N - 1] );
    #ifdef _DEBUG
    unsigned long long su = 0;
    rep( i, 1, N ) {
        su += dp[i][0].capacity();
        su += dp[i][1].capacity();
    }
    fprintf( stderr, "%llu\n", su );
    #endif
    return 0;
}