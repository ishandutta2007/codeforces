#include <cstdio>
#include <utility>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e5 + 5, MAXLOG = 35;

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

int phi[MAXLOG], tot;

int A[MAXN];

int N, Q, P;

inline std :: pair<int, bool> Qkpow( int base, int indx, const int mod ) {
    int ret = 1; bool exce = false, alre = false;
    while( indx ) {
        if( indx & 1 ) {
            exce |= 1ll * ret * base >= mod || alre;
            ret = 1ll * ret * base % mod;
        }
        alre |= 1ll * base * base >= mod;
        base = 1ll * base * base % mod, indx >>= 1;
    }
    return std :: make_pair( ret, exce );
}

inline int Gcd( int x, int y ) { for( int z ; y ; z = x, x = y, y = z % y ); return x; }

int GetPhi( int x ) {
    int ret = 1;
    for( int i = 2 ; 1ll * i * i <= x ; i ++ ) {
        if( x % i ) continue;
        x /= i, ret *= i - 1;
        while( ! ( x % i ) ) x /= i, ret *= i;
    }
    if( x > 1 ) ret *= x - 1;
    return ret;
}

std :: pair<int, bool> Query( const int dep, const int l, const int r ) {
    int mod = phi[dep], phiMod = phi[dep + 1], x = A[l];
    if( l == r || mod == 1 ) return std :: make_pair( x % mod, x >= mod );
    std :: pair<int, bool> tmp = Query( dep + 1, l + 1, r );
    int idx = Gcd( x, mod ) != 1 && tmp.second ? tmp.first + phiMod : tmp.first;
    std :: pair<int, bool> ret = Qkpow( x, idx, mod );
    ret.second |= tmp.second && x != 1;
    return ret;
}

int main() {
    read( N ), read( P );
    rep( i, 1, N ) read( A[i] );
    read( Q );
    phi[tot = 0] = P;
    for( ; P > 1 ; )
        P = ( phi[++ tot] = GetPhi( P ) );
    while( Q -- ) {
        int l, r; read( l ), read( r );
        write( Query( 0, l, r ).first ), putchar( '\n' );
    }
    return 0;
}