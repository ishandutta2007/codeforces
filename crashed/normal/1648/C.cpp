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
_T MAX( const _T a, const _T b ) {
    return a > b ? a : b;
}

struct Element {
    int val[2];

    Element(): val{} {}
};

Element tre[MAXN << 2];

int fac[MAXN], ifac[MAXN];

int cntS[MAXN], cntT[MAXN];
int S[MAXN], T[MAXN];

int N, M;

inline int Qkpow( int, int );
inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int Qkpow( int base, int indx ) {
    int ret = 1;
    while( indx ) {
        if( indx & 1 ) ret = Mul( ret, base );
        base = Mul( base, base ), indx >>= 1;
    }
    return ret;
}

void Init( const int n ) {
    fac[0] = 1; rep( i, 1, n ) fac[i] = Mul( fac[i - 1], i );
    ifac[n] = Inv( fac[n] ); per( i, n - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

Element operator + ( const Element &a, const Element &b ) {
    Element ret;
    ret.val[0] = Mul( a.val[0], b.val[0] );
    ret.val[1] = Add( Mul( a.val[0], b.val[1] ), Mul( a.val[1], b.val[0] ) );
    return ret;
}

inline void Upt( const int x ) {
    tre[x] = tre[x << 1] + tre[x << 1 | 1];
}

void Build( const int x, const int l, const int r ) {
    if( l > r ) return ;
    if( l == r ) {
        int c = cntS[l];
        tre[x].val[0] = ifac[c];
        if( c ) tre[x].val[1] = ifac[c - 1];
        else tre[x].val[1] = 0;
        return ;
    }
    int mid = ( l + r ) >> 1;
    Build( x << 1, l, mid );
    Build( x << 1 | 1, mid + 1, r );
    Upt( x );
}

void Update( const int x, const int l, const int r, const int p ) {
    if( l == r ) {
        int c = cntS[l];
        tre[x].val[0] = ifac[c];
        if( c ) tre[x].val[1] = ifac[c - 1];
        else tre[x].val[1] = 0;
        return ;
    }
    int mid = ( l + r ) >> 1;
    if( p <= mid ) Update( x << 1, l, mid, p );
    else Update( x << 1 | 1, mid + 1, r, p );
    Upt( x );
}

Element Query( const int x, const int l, const int r, const int segL, const int segR ) {
    if( l > r || segL > segR ) return Element();
    if( segL <= l && r <= segR ) return tre[x];
    int mid = ( l + r ) >> 1;
    if( segR <= mid ) return Query( x << 1, l, mid, segL, segR );
    if( mid  < segL ) return Query( x << 1 | 1, mid + 1, r, segL, segR );
    return Query( x << 1, l, mid, segL, segR ) + Query( x << 1 | 1, mid + 1, r, segL, segR );
}

int main() {
    // freopen( ".in", "r", stdin );
    // freopen( ".out", "w", stdout );
    read( N ), read( M ), Init( MAX( N, M ) );
    rep( i, 1, N ) read( S[i] ), cntS[S[i]] ++;
    rep( i, 1, M ) read( T[i] ), cntT[T[i]] ++;
    Build( 1, 1, 2e5 );
    int ans = 0; bool flg = true;
    for( int i = 1 ; i <= N && i <= M ; i ++ ) {
        Element tmp1 = Query( 1, 1, 2e5, 1, T[i] - 1 ),
                tmp2 = Query( 1, 1, 2e5, T[i], 2e5 );
        ans = Add( ans, Mul( fac[N - i], Mul( tmp1.val[1], tmp2.val[0] ) ) );
        if( ! cntS[T[i]] ) { flg = false; break; }
        cntS[T[i]] --, Update( 1, 1, 2e5, T[i] );
    }
    if( flg && M > N ) ans = Add( ans, 1 );
    write( ans ), putchar( '\n' );
    return 0;
}