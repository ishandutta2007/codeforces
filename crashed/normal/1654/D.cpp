#include <cstdio>

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

template<typename _T>
_T Max( const _T a, const _T b ) {
    return a > b ? a : b;
}

struct Edge {
    int to, nxt, fz, fm;
} Graph[MAXN << 1];

int mnp[MAXN], inv[MAXN];
int prime[MAXN], pn;
bool isPrime[MAXN];

int cur[MAXN], mx[MAXN];
int head[MAXN], cnt = 1;

int su = 0;
int N;

inline int Mul( int x, const int v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int Qkpow( int base, int indx ) {
    int ret = 1;
    while( indx ) {
        if( indx & 1 ) ret = Mul( ret, base );
        base = Mul( base, base ), indx >>= 1;
    }
    return ret;
}

void EulerSieve( const int n ) {
    for( int i = 2 ; i <= n ; i ++ ) {
        if( ! isPrime[i] ) mnp[prime[++ pn] = i] = i;
        for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= n ; j ++ ) {
            mnp[i * prime[j]] = prime[j];
            isPrime[i * prime[j]] = true;
            if( ! ( i % prime[j] ) ) break;
        }
    }
}

void Init( const int n = 2e5 ) {
    EulerSieve( n );
    inv[1] = 1; rep( i, 2, n ) inv[i] = Mul( inv[mod % i], mod - mod / i );
}

inline void AddEdge( const int from, const int to, const int Z, const int M ) {
    Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
    Graph[cnt].fz = Z, Graph[cnt].fm = M, head[from] = cnt;
}

void DFS( const int u, const int fa, const int rat ) {
    su = Add( su, rat );
    for( int i = head[u], v ; i ; i = Graph[i].nxt )
        if( ( v = Graph[i].to ) ^ fa ) {
            for( int x = Graph[i].fz ; x > 1 ; ) {
                int p = mnp[x];
                while( ! ( x % p ) ) x /= p, cur[p] --;
            }
            for( int x = Graph[i].fm ; x > 1 ; ) {
                int p = mnp[x];
                while( ! ( x % p ) ) x /= p, cur[p] ++;
                mx[p] = Max( mx[p], cur[p] );
            }

            DFS( v, u, Mul( rat, Mul( Graph[i].fz, inv[Graph[i].fm] ) ) );

            for( int x = Graph[i].fm ; x > 1 ; ) {
                int p = mnp[x];
                while( ! ( x % p ) ) x /= p, cur[p] --;
            }
            for( int x = Graph[i].fz ; x > 1 ; ) {
                int p = mnp[x];
                while( ! ( x % p ) ) x /= p, cur[p] ++;
            }
        }
}

int main() {
    // freopen( ".in", "r", stdin );
    // freopen( ".out", "w", stdout );
    int T; read( T );
    Init();
    while( T -- ) {
        read( N ), cnt = 1;
        rep( i, 1, N ) head[i] = 0;
        rep( i, 1, N ) cur[i] = mx[i] = 0;
        rep( i, 1, N - 1 ) {
            int u, v, a, b;
            read( u ), read( v ), read( a ), read( b );
            AddEdge( u, v, b, a ), AddEdge( v, u, a, b );
        }
        su = 0, DFS( 1, 0, 1 );
        int low = 1;
        rep( i, 1, N ) if( ! isPrime[i] )
            low = Mul( low, Qkpow( i, mx[i] ) );
        write( Mul( low, su ) ), putchar( '\n' );
    }
    return 0;
}