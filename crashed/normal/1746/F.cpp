// LUOGU_RID: 95194530
#include <cstdio>
#include <random>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 3e5 + 5;

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

LL BIT[MAXN], rnd[MAXN << 1];

int opt[MAXN], args[MAXN][3];
bool ans[MAXN];

int A[MAXN], ini[MAXN];
int val[MAXN << 1], tot = 0;

int N, Q;

inline int Lowbit( const int &x ) {
    return x & ( - x );
}

inline void Down( int &x ) { x &= x - 1; }
inline void Up( int &x ) { x += x & ( -x ); }
inline void Update( int x, LL d ) { for( ; x <= N ; Up( x ) ) BIT[x] += d; }
inline   LL Query( int x ) { LL ret = 0; for( ; x ; Down( x ) ) ret += BIT[x]; return ret; }
inline   LL Query( const int &l, const int &r ) { return Query( r ) - Query( l - 1 ); }

int main() {
    static std :: mt19937 rng( 1145141 );

    Read( N ), Read( Q );
    rep( i, 1, N ) Read( A[i] ), val[++ tot] = A[i];
    rep( i, 1, Q ) {
        Read( opt[i] );
        rep( j, 0, opt[i] ) Read( args[i][j] );
        if( opt[i] == 1 ) val[++ tot] = args[i][1];
        ans[i] = true;
    }
    std :: sort( val + 1, val + 1 + tot );
    tot = std :: unique( val + 1, val + 1 + tot ) - val - 1;
    rep( i, 1, N ) ini[i] = std :: lower_bound( val + 1, val + 1 + tot, A[i] ) - val;
    rep( i, 1, Q ) if( opt[i] == 1 )
        args[i][1] = std :: lower_bound( val + 1, val + 1 + tot, args[i][1] ) - val;
    rep( cas, 1, 40 ) {
        rep( i, 1, tot ) rnd[i] = rng();
        rep( i, 1, N ) BIT[i] = 0;
        rep( i, 1, N ) {
            BIT[i] += rnd[A[i] = ini[i]];
            if( i + Lowbit( i ) <= N )
                BIT[i + Lowbit( i )] += BIT[i];
        }
        rep( i, 1, Q ) { 
            if( opt[i] == 1 ) {
                Update( args[i][0], - rnd[A[args[i][0]]] );
                Update( args[i][0], rnd[A[args[i][0]] = args[i][1]] );
            }
            if( opt[i] == 2 )
                ans[i] &= Query( args[i][0], args[i][1] ) % args[i][2] == 0;
        }
    }
    rep( i, 1, Q )
        if( opt[i] == 2 ) 
            puts( ans[i] ? "YES" : "NO" );
    return 0;
}