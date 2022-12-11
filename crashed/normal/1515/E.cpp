#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 405;

template<typename _T>
void read( _T &x )
{
    x = 0; char s = getchar(); int f = 1;
    while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    x *= f;
}

template<typename _T>
void write( _T x )
{
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) write( x / 10 );
    putchar( x % 10 + '0' );
}

int f[MAXN][MAXN];

int pw[MAXN];
int fac[MAXN], ifac[MAXN];
int N, mod;

inline int Qkpow( int, int );
inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int Qkpow( int base, int indx )
{
    int ret = 1;
    while( indx )
    {
        if( indx & 1 ) ret = Mul( ret, base );
        base = Mul( base, base ), indx >>= 1;
    }
    return ret;
}

void Init()
{
    pw[0] = 1; rep( i, 1, N ) pw[i] = Mul( pw[i - 1], 2 );
    fac[0] = 1; rep( i, 1, N ) fac[i] = Mul( fac[i - 1], i );
    ifac[N] = Inv( fac[N] ); per( i, N - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

int main()
{
    read( N ), read( mod ), Init();
    rep( i, 1, N )
    {
        f[i][i] = Mul( pw[i - 1], ifac[i] );
        rep( j, 0, i - 1 ) rep( k, 2, i - 1 )
            if( j >= i - k )
                f[i][j] = Add( f[i][j], Mul( f[k - 1][j - ( i - k )], Mul( pw[i - k - 1], ifac[i - k] ) ) );
    }
    int ans = 0;
    rep( j, 1, N )
        ans = Add( ans, Mul( f[N][j], fac[j] ) );
    write( ans ), putchar( '\n' );
    return 0;
}