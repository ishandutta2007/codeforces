#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
const int MAXN = 1e6 + 5;

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

struct MyGraph {
    struct Edge {
        int to, nxt;
    } Graph[MAXN << 1];

    int head[MAXN], deg[MAXN], cnt = 1;

    inline Edge operator [] ( const int &idx ) const { return Graph[idx]; }

    inline void AddE( const int &from, const int &to ) {
        AddEdge( from, to ), AddEdge( to, from );
    }

    inline void AddEdge( const int &from, const int &to ) {
        Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
        head[from] = cnt, deg[to] ++;
    }

    inline void Clear( const int &n ) {
        cnt = 1;
        rep( i, 1, n ) head[i] = deg[i] = 0;
    }
};

MyGraph virt, tre;

int each[MAXN];

int dp[MAXN][2];
int f[2][MAXN];

int brk[MAXN], seq[MAXN];
int fath[MAXN]; bool isRt[MAXN];

int N;

inline int Qkpow( int, int );
inline int Inv( const int &a ) { return Qkpow( a, mod - 2 ); }
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

inline void Clear() {
    tre.Clear( N );
    virt.Clear( N );
}

inline void Init( const int &u, const int &fa ) {
    fath[u] = fa;
    for( int i = tre.head[u], v ; i ; i = tre[i].nxt )
        if( ( v = tre[i].to ) ^ fa ) Init( v, u );
}

void DFS( const int &u, const int &fa, const int &lim ) {
    // dp[][0]: u -> fa
    // dp[][1]: fa -> u
    dp[u][0] = dp[u][1] = 0;
    for( int i = virt.head[u], v ; i ; i = virt[i].nxt )
        if( ( v = virt[i].to ) ^ fa ) DFS( v, u, lim );
    if( virt.deg[u] <= lim ) {
        // virt.deg[u] - 1 is equal to the number of sons it has.
        int pre = 1, nxt = 0;
        rep( i, 0, virt.deg[u] ) 
            f[0][i] = f[1][i] = 0;
        f[nxt][0] = 1; int curDeg = 0;
        for( int i = virt.head[u], v ; i ; i = virt[i].nxt )
            if( ( v = virt[i].to ) ^ fa ) {
                pre ^= 1, nxt ^= 1;
                rep( j, 0, curDeg ) {
                    if( ! f[pre][j] ) continue;
                    AddEq( f[nxt][j], Mul( f[pre][j], dp[v][1] ) );
                    AddEq( f[nxt][j + 1], Mul( f[pre][j], dp[v][0] ) );
                    f[pre][j] = 0;
                }
                curDeg ++;
            }
        rep( j, 0, curDeg ) {
            if( ( tre.deg[u] - j ) % lim == 0 )
                AddEq( dp[u][0], f[nxt][j] );
            if( ( tre.deg[u] - j - 1 ) % lim == 0 )
                AddEq( dp[u][1], f[nxt][j] );
        }
    } else {
        int pre = 1, nxt = 0;
        rep( i, 0, lim - 1 )
            f[0][i] = f[1][i] = 0;
        f[nxt][0] = 1;
        for( int i = virt.head[u], v ; i ; i = virt[i].nxt )
            if( ( v = virt[i].to ) ^ fa ) {
                pre ^= 1, nxt ^= 1;
                rep( j, 0, lim - 1 ) {
                    if( ! f[pre][j] ) continue;
                    AddEq( f[nxt][j], Mul( f[pre][j], dp[v][1] ) );
                    AddEq( f[nxt][( j + 1 ) % lim], Mul( f[pre][j], dp[v][0] ) );
                    f[pre][j] = 0;
                }
            }
        rep( j, 0, lim - 1 ) {
            if( ( tre.deg[u] - j ) % lim == 0 )
                AddEq( dp[u][0], f[nxt][j] );
            if( ( tre.deg[u] - j - 1 ) % lim == 0 )
                AddEq( dp[u][1], f[nxt][j] );
        }
    }
    virt.head[u] = 0, virt.deg[u] = 0;
}

int main() {
    int T; Read( T );
    while( T -- ) {
        Read( N ), Clear();
        rep( i, 1, N - 1 ) {
            int u, v; 
            Read( u ), Read( v );
            tre.AddE( u, v );
        }
        rep( i, 1, N ) seq[i] = i;
        std :: sort( seq + 1, seq + 1 + N,
            [] ( const int &a, const int &b ) -> bool {
                return tre.deg[a] < tre.deg[b];
            } );
        rep( i, 1, N ) brk[i] = N + 1, each[i] = 0;
        per( i, N, 1 ) brk[tre.deg[seq[i]]] = i;
        per( i, N - 1, 1 ) brk[i] = Min( brk[i], brk[i + 1] );

        Init( 1, 0 );
        rep( d, 1, N ) {
            if( brk[d] <= N ) {
                if( d == 1 ) each[d] = Qkpow( 2, N - 1 );
                else {
                    virt.cnt = 1;
                    rep( i, brk[d], N ) 
                        isRt[seq[i]] = false;
                    rep( i, brk[d], N ) 
                        if( tre.deg[fath[seq[i]]] >= d ) {
                            isRt[seq[i]] = true;
                            virt.AddE( seq[i], fath[seq[i]] );
                        }
                    each[d] = 1;
                    rep( i, brk[d], N )
                        if( ! isRt[seq[i]] ) {
                            DFS( seq[i], 0, d );
                            MulEq( each[d], dp[seq[i]][0] );
                        }
                }
                // Check the validity of newly removed nodes
            } else each[d] = 1;
            rep( i, brk[d], brk[d + 1] - 1 ) {
                int u = seq[i];
                for( int j = tre.head[u] ; j ; j = tre[j].nxt )
                    if( tre.deg[tre[j].to] <= d ) 
                        goto EndofLoop;
            }
        }
        EndofLoop:
        for( int d = N ; d >= 1 ; d -- ) 
            for( int k = d << 1 ; k <= N ; k += d )
                SubEq( each[d], each[k] );
        rep( i, 1, N ) Write( each[i] ), putchar( " \n"[i == N] );
    }
    return 0;
}